#ifndef LABIRENT_HPP
#define LABIRENT_HPP

#include "Konum.hpp"
#include <iostream>

#define YUKSEKLIK 20
#define GENISLIK 50

typedef enum {
    ASAGI, SOL, YUKARI, SAG
} Yon;

class Labirent {
private:
    char harita[YUKSEKLIK][GENISLIK];
    Konum baslangic;
    Konum bitis;

public:
    Labirent();
    void haritaOku();     
    void ekranaYaz();     
    void coz();         
    
    bool hareketEdebilirMi(int r, int c);
};

#endif