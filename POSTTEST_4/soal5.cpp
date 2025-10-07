#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Fungsi buat nukar node head sama tail, bukan datanya tapi pointer-nya
void exchangeHeadAndTail(Node *&head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref) return; // kalau list kosong / cuma 1 node

    Node* head = head_ref;
    Node* tail = head_ref->prev;
    Node* headNext = head->next;
    Node* tailPrev = tail->prev;

    // Kalau cuma dua node, cukup tukar head-nya aja
    if (headNext == tail) {
        head_ref = tail;
        return;
    }

    // Update koneksi node di sekitar head dan tail
    headNext->prev = tail;
    tailPrev->next = head;

    // Ubah pointer next dan prev antara head dan tail
    tail->next = headNext;
    tail->prev = head->prev;
    head->next = tail->next;
    head->prev = tailPrev;

    // Update pointer tetangga biar koneksinya bener
    tail->prev->next = tail;
    head->next->prev = head;

    // Terakhir, ganti head ke tail
    head_ref = tail;
}

// Fungsi buat nampilin isi list
void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

// Fungsi bantu buat nambah data di akhir list
void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    // Bikin list 1 - 2 - 3 - 4 - 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    // Tukar head dan tail
    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);
    cin.get();

    return 0;
}
