#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int matriks[n][n];

    // input matriks
    cout << "Input matriks 3x3:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matriks[i][j];
        }
    }

    int jumlahDiagonal = 0;
    for(int i = 0; i < n; i++) {
        jumlahDiagonal += matriks[i][i];             // diagonal utama
        jumlahDiagonal += matriks[i][n-1-i];         // diagonal sekunder
    }

    // kalau ada elemen tengah dihitung 2x, kurangi sekali
    if(n % 2 == 1) {
        jumlahDiagonal -= matriks[n/2][n/2];
    }

    cout << "\nMatriks:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jumlah diagonal utama + diagonal sekunder = " << jumlahDiagonal << endl;
}
