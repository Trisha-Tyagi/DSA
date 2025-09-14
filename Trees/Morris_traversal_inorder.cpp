#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Morris Inorder Traversal: prints nodes in inorder (L, Root, R)
void morrisInorder(Node* root) {
    Node* curr = root;
    while (curr) {
        if (!curr->left) {
            cout << curr->val << " ";
            curr = curr->right;
        } else {
            // Find predecessor (rightmost in left subtree)
            Node* pred = curr->left;
            while (pred->right && pred->right != curr) pred = pred->right;

            if (!pred->right) {
                // Make thread to current
                pred->right = curr;
                curr = curr->left;
            } else {
                // Thread already exists -> remove it and visit current
                pred->right = nullptr;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

Node* sampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = sampleTree();

    cout << "Morris Inorder: ";
    morrisInorder(root);    // expected: 4 2 5 1 3 6
    cout << "\n";

    return 0;
}