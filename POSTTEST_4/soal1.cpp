#include <iostream>
#include <string>
using namespace std;


// Struktur node buat nyimpan karakter
struct Node {
    char data;
    Node* next;
};

// Fungsi push buat masukin data ke paling atas stack
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

// Fungsi pop buat ngambil data paling atas stack
char pop(Node*& top) {
    if (top == nullptr) return '\0'; // kalau kosong, balikin karakter null
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Fungsi buat ngebalik string pakai stack
string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // Masukin semua karakter dari string ke stack
    for (char c : s) {
        push(stackTop, c);
    }

    // Keluarkan lagi dari stack biar urutannya jadi terbalik
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    cin.get();
    return 0;



}

