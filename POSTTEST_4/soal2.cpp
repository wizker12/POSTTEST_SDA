#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi push dan pop sama kayak di soal 1
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

// Fungsi bantu buat ngecek pasangan kurungnya cocok atau enggak
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Fungsi utama buat ngecek kurung seimbang
bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // Loop semua karakter satu-satu
    for (char c : expr) {
        // Kalau ketemu kurung buka, simpan ke stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        } 
        // Kalau ketemu kurung tutup, harus cocok sama yang di atas stack
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false; // kalau kosong, langsung false
            char topChar = pop(stackTop);
            if (!isMatchingPair(topChar, c)) return false;
        }
    }

    // Kalau stack kosong di akhir, berarti semua kurung udah berpasangan
    bool balanced = (stackTop == nullptr);
    while (stackTop != nullptr) pop(stackTop); // bersihin sisa node
    return balanced;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;

    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;
    cin.get();

    return 0;
}
