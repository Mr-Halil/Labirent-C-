#include "Labirent.hpp"
#include <iostream>

using namespace std;

int main() {
    Labirent labirent;
    
    // Haritayı Dosyadan okuyoruz
    labirent.haritaOku();
    
    // ekranaYaz() fonksiyonu ile haritayı gösteriyoruz
    labirent.ekranaYaz();
    
    cout << "Labirent cozumu basliyor... (Devam etmek icin Enter'a bas)" << endl;
    cin.get(); // Kullanıcıdan Enter tuşuna basması için komut bekledim, çünkü bana göre daha iyi oldu.
    
    // 3. Komutun ardından labirenti çözüyoruz ve kullanıcıya sonucu gösteriyoruz
    labirent.coz();
    
    return 0;
}