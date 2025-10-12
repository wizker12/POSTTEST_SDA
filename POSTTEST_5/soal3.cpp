#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // buat node baru kalau kosong
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // nilai lebih kecil ke kiri
    } else if (val > root->data) {
        root->right = insert(root->right, val); // nilai lebih besar ke kanan
    }
    return root;
}

// Fungsi untuk mencari nilai terbesar di tree
int findMaxValue(Node* root) {
    if (root == nullptr) {
        return -1; // kalau tree kosong, kembalikan -1
    }

    Node* current = root; // mulai dari root
    // selama masih ada anak kanan, terus jalan ke kanan
    while (current->right != nullptr) {
        current = current->right;
    }

    // node paling kanan adalah nilai terbesar
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl;
    cin.get();

    return 0;
}
