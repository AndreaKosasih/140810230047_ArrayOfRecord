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
    cout << "Masukkan jam  = "; cin >> wkt.jam;
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
    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    waktu wktMasuk[n], wktKeluar[n];
    int biayaJamPertama = 2000;
    int biayaJamBerikutnya = 1000;
    int totalWaktu, totalBiaya;

    cout << endl; 
    for(int i = 0; i < n; i++) {
        cout << "Kendaraan ke - " << i + 1 << endl;
        cout << "Masukkan waktu masuk (jam, menit, detik)" << endl; 
        getWaktu(wktMasuk[i]); 
        printWaktu(wktMasuk[i]); cout << endl << endl; 
        cout << "Masukkan waktu keluar (jam, menit, detik)" << endl;
        getWaktu(wktKeluar[i]);
        printWaktu(wktKeluar[i]); cout << endl << endl; 
        totalWaktu = wktKeluar[i].jam - wktMasuk[i].jam;
        if(wktKeluar[i].menit < wktMasuk[i].menit) {
            totalWaktu--;
        } else if(wktKeluar[i].menit == wktMasuk[i].menit && wktKeluar[i].detik < wktMasuk[i].detik) {
            totalWaktu--;
        }

        int totalWaktuDetik = (wktKeluar[i].jam - wktMasuk[i].jam)*3600 + (wktKeluar[i].menit - wktMasuk[i].menit)*60 + (wktKeluar[i].detik - wktMasuk[i].detik);
        totalBiaya = biayaJamPertama + (totalWaktu-1)*biayaJamBerikutnya;
        cout << "total waktu parkir adalah: " << (wktKeluar[i].jam - wktMasuk[i].jam) << " jam " << (wktKeluar[i].menit - wktMasuk[i].menit) << " menit " << (wktKeluar[i].detik - wktMasuk[i].detik) << " detik " << " atau "<< totalWaktuDetik << endl; 
        cout << "Total biaya parkir adalah: " << totalBiaya << endl << endl; 
    }
    return 0;
}
