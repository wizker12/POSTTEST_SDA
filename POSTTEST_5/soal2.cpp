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

// Fungsi untuk menambahkan data ke dalam BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // buat node baru kalau kosong
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // masuk ke kiri
    } else if (val > root->data) {
        root->right = insert(root->right, val); // masuk ke kanan
    }
    return root;
}

// Fungsi untuk mencari nilai terkecil di tree
int findMinValue(Node* root) {
    if (root == nullptr) {
        return -1; // kalau tree kosong, kembalikan -1
    }

    Node* current = root; // mulai dari root
    // selama masih ada anak kiri, terus jalan ke kiri
    while (current->left != nullptr) {
        current = current->left;
    }

    // node paling kiri adalah nilai terkecil
    return current->data;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl;
    cin.get();

    return 0;
}
