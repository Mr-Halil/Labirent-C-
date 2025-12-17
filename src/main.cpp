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
    cin.get(); // Kullanıcıdan Enter tuşuna basması için komut bekliyoruz, haritayı görmesi için.
    
    labirent.coz();

     // Kullanıcıdan Enter tuşuna basması için komut bekliyoruz, Sonucu görmesi için.
    cout << "Cikmak icin Enter'a basiniz..." << endl;
    cin.ignore(); 
    cin.get();  
    
    return 0;
}