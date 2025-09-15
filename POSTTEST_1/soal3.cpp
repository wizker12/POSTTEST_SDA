#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int n = 5;
    Mahasiswa mhs[n];

    // input data
    for(int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nama : "; cin >> mhs[i].nama;
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk;
        cout << endl;
    }

    // cari IPK tertinggi
    int idx = 0;
    for(int i = 1; i < n; i++) {
        if(mhs[i].ipk > mhs[idx].ipk) {
            idx = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:\n";
    cout << "Nama : " << mhs[idx].nama << endl;
    cout << "NIM  : " << mhs[idx].nim << endl;
    cout << "IPK  : " << mhs[idx].ipk << endl;
}
