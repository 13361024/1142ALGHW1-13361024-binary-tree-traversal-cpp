#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " "; 
    preorder(root->left); 
    preorder(root->right);
}

void inorder(Node* root) {
   if (root == nullptr) return;
    
    inorder(root->left);       
    cout << root->data << " ";
    inorder(root->right);  
}

void postorder(Node* root) {
    if (root == nullptr) return;
    
    postorder(root->left);    
    postorder(root->right); 
    cout << root->data << " "; 
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    deleteTree(root);
    return 0;
}
