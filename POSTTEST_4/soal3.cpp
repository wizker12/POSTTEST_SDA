#include <iostream>
#include <string>
using namespace std;

// Node buat nyimpen nama dokumen di antrian
struct Node {
    string document;
    Node* next;
};

// Fungsi buat nambah dokumen ke antrian (enqueue)
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};
    if (front == nullptr) {
        // Kalau antrian kosong, front dan rear sama-sama newNode
        front = rear = newNode;
    } else {
        // Kalau udah ada, sambungin di belakang
        rear->next = newNode;
        rear = newNode;
    }
}

// Fungsi buat ngambil dokumen dari antrian (dequeue)
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // antrian kosong
    Node* temp = front;
    string data = temp->document;
    front = front->next; // geser ke depan
    if (front == nullptr) rear = nullptr; // kalau habis, reset rear
    delete temp;
    return data;
}

// Fungsi buat proses semua dokumen satu per satu
void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // Tambah dokumen ke antrian printer
    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);
    cin.get();

    return 0;
}
