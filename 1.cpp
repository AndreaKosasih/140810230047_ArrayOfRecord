#include <iostream>
#include <iomanip>
using namespace std;

struct waktu {
    int hari;
    int jam;
    int menit;
    int detik;
};

void getWaktu(waktu &wkt) {
    cout << "Masukkan jam   = "; cin >> wkt.jam;
    cout << "Masukkan menit = "; cin >> wkt.menit;
    cout << "Masukkan detik = "; cin >> wkt.detik; 
}

void printWaktu(waktu wkt) {
    wkt.hari = 0; 
    while(wkt.jam >= 24){
        wkt.hari++;
        wkt.jam -= 24; 
    }
    while(wkt.menit >= 60) {
        wkt.jam++;
        wkt.menit -= 60;
    }
    while(wkt.detik >= 60) {
        wkt.menit++;
        wkt.detik -= 60;
    }

    if(wkt.hari > 0){
        cout << wkt.hari << " hari" << endl; 
    }
    cout << setw(2) << setfill('0') << wkt.jam << " : " << setw(2) << setfill('0') << wkt.menit << " : " << setw(2) << setfill('0') << wkt.detik;
}

int main() {
    waktu wkt;
    getWaktu(wkt);
    printWaktu(wkt);
}