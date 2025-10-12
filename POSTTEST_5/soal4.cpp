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

// Fungsi insert untuk menambah node ke BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // nilai kecil ke kiri
    } else if (val > root->data) {
        root->right = insert(root->right, val); // nilai besar ke kanan
    }
    return root;
}

// Fungsi untuk traversal post-order: kiri ke kanan ke root
void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return; 
    }

    // Telusuri subtree kiri
    postOrderTraversal(root->left);
    // Lalu subtree kanan
    postOrderTraversal(root->right);
    // cetak data root
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); 
    cout << endl;
    cin.get();
    return 0;
}
