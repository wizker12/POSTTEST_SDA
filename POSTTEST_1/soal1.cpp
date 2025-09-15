#include <iostream>
using namespace std;

void balikArray(int *arr, int n) {
    for(int i = 0; i < n/2; i++) {
        int temp = *(arr+i);
        *(arr+i) = *(arr+(n-1-i));
        *(arr+(n-1-i)) = temp;
    }
}

int main() {
    const int n = 7;
    int arr[n];

    // isi array kelipatan 3
    for(int i = 0; i < n; i++) {
        arr[i] = (i+1) * 3;
    }

    cout << "Array sebelum dibalik: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    balikArray(arr, n);

    cout << "Array sesudah dibalik: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
