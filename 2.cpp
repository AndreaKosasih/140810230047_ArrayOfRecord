#include <iostream>
#include <iomanip>
using namespace std;

struct mahasiswa {
    char NPM[8];
    char nama[20];
    int nilai;
};

typedef mahasiswa LarikMhs[10];

void banyakData(int &n);
void inputMahasiswa(LarikMhs &mhs, int n);
void cetakMahasiswa(LarikMhs mhs, int n);

int main() {
    LarikMhs mhs;
    int n;
    banyakData(n);
    inputMahasiswa(mhs, n);
    cetakMahasiswa(mhs, n);
    return 0;
}

void banyakData(int &n) {
    cout << "Banyak data : ";
    cin >> n;
}

void inputMahasiswa(LarikMhs &mhs, int n) {
    cin.ignore(); // Membersihkan buffer setelah membaca n
    for (int i = 0; i < n; i++) {
        cout << "Masukkan data mahasiswa ke - " << i + 1 << endl;
        cout << "NPM   : ";
        cin >> mhs[i].NPM;
        cin.ignore(); // Membersihkan buffer setelah membaca NPM
        cout << "Nama  : ";
        cin.getline(mhs[i].nama, sizeof(mhs[i].nama));
        cout << "Nilai : ";
        cin >> mhs[i].nilai;
    }
}

void cetakMahasiswa(LarikMhs mhs, int n) {
    cout << "-----------------------------" << endl;
    cout << "| PERCETAKAN DATA MAHASISWA |" << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << mhs[i].NPM << setw(20) << mhs[i].nama << setw(10) << mhs[i].nilai << endl;
    }
}
