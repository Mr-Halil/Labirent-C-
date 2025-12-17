#include "Labirent.hpp"
#include <fstream>
#include <iostream>
#include <stack>
#include <thread>
#include <chrono>

// Kodlarken kullandığımız cihaz macOS tu, bu yüzden terminal temizleme komutunu platforma göre ayarlama kararı aldık.
// Windows'ta da çalışması için ek bir kontrol ekledik.
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_CMD "cls"
#else
    #define CLEAR_CMD "clear"
#endif


using namespace std;

// Yön karakterleri (PDF'te verilen ASCII kodları)
char YonChr[] = {31, 17, 30, 16}; 

Labirent::Labirent() {
    #ifdef _WIN32
        SetConsoleOutputCP(437);
    #endif
}

void Labirent::haritaOku() {
    FILE* fp = fopen("Harita.txt", "r");
    if (fp == NULL) {
        cout << "Harita.txt dosyasi acilamadi!" << endl;
        exit(1);
    }

    char satir[100];
    int r = 0;

    while (fgets(satir, sizeof(satir), fp) && r < YUKSEKLIK) {
        for (int c = 0; c < GENISLIK && satir[c] != '\n'; c++) {
            harita[r][c] = satir[c];

            if (harita[r][c] == 'S') {
                baslangic = Konum(r, c);
                harita[r][c] = ' ';
            }
            else if (harita[r][c] == 'E') {
                bitis = Konum(r, c);
                harita[r][c] = ' ';
            }
        }
        r++;
    }
    fclose(fp);
}

void Labirent::ekranaYaz() {
    system(CLEAR_CMD);

    cout << "==============================================" << endl;
    cout << "  IBRAHIM HALIL CIFTCIOGLU & MAHMUT ENES MERT - LABIRENT PROJESI  " << endl;
    cout << "==============================================" << endl;

    for (int i = 0; i < YUKSEKLIK; i++) {
        for (int j = 0; j < GENISLIK; j++) {
            cout << harita[i][j];
        }
        cout << endl;
    }
}

bool Labirent::hareketEdebilirMi(int r, int c) {
    if (r < 0 || r >= YUKSEKLIK || c < 0 || c >= GENISLIK)
        return false;

    if (harita[r][c] != ' ')
        return false;

    return true;
}

void Labirent::coz() {
    stack<Konum> yol;
    yol.push(baslangic);

    while (!yol.empty()) {
        Konum suan = yol.top();

        if (suan.x == bitis.x && suan.y == bitis.y) {
            harita[suan.x][suan.y] = 'O';
            ekranaYaz();
            cout << "\nCikis bulundu!" << endl;
            return;
        }

        bool ilerledi = false;

        if (hareketEdebilirMi(suan.x + 1, suan.y)) {
            harita[suan.x + 1][suan.y] = YonChr[ASAGI];
            yol.push(Konum(suan.x + 1, suan.y));
            ilerledi = true;
        }
        else if (hareketEdebilirMi(suan.x, suan.y - 1)) {
            harita[suan.x][suan.y - 1] = YonChr[SOL];
            yol.push(Konum(suan.x, suan.y - 1));
            ilerledi = true;
        }
        else if (hareketEdebilirMi(suan.x - 1, suan.y)) {
            harita[suan.x - 1][suan.y] = YonChr[YUKARI];
            yol.push(Konum(suan.x - 1, suan.y));
            ilerledi = true;
        }
        else if (hareketEdebilirMi(suan.x, suan.y + 1)) {
            harita[suan.x][suan.y + 1] = YonChr[SAG];
            yol.push(Konum(suan.x, suan.y + 1));
            ilerledi = true;
        }

        ekranaYaz();
        this_thread::sleep_for(chrono::milliseconds(80));

        if (!ilerledi) {
            harita[suan.x][suan.y] = '.';
            yol.pop();
        }
    }

    cout << "\nCikis bulunamadi." << endl;
}
