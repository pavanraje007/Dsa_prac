#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    traversal(root->left);
    traversal(root->right);
}

Node* insert(Node* &root, int x) {
    if (root == NULL) {
        root = new Node(x);
    } else if (x >= root->data) {
        root->right = insert(root->right, x);
    } else {
        root->left = insert(root->left, x);
    }
    return root;
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left_subtree = height(root->left);
    int right_subtree = height(root->right);
    return max(left_subtree, right_subtree) + 1; // height of the tree
}

int minimum(Node* root) {
    if (root == NULL) {
        return INT_MAX; // returning the maximum integer value for safety in case of an empty tree
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

void search(Node* root, int key, bool &present) {
    if (root == NULL) {
        return;
    }
    if (root->data == key) {
        present = true;
        return; // return early if the key is found
    } else if (root->data > key) {
        search(root->left, key, present);
    } else {
        search(root->right, key, present);
    }
}

void mirror(Node* &root) {
    if (root == NULL) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right); // swap left and right children at each node
}

int main() {
    Node* root = NULL;
    int n;
    cout << "Enter the number of nodes to be inserted in the BST-\n";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int element;
        cout << "Enter the data value to be inserted-\n";
        cin >> element;
        insert(root, element);
    }
    
    cout << "Displaying the elements of the BST-\n";
    traversal(root);
    cout << endl;

    cout << "Height of the tree is (Longest Path): " << height(root) << endl;
    cout << "Minimum value in the BST is: " << minimum(root) << endl;

    // Mirror the tree
    mirror(root);
    cout << "After mirroring, BST elements (Preorder Traversal):\n";
    traversal(root);
    cout << endl;

    int key;
    cout << "Enter the data value to be searched in the BST-\n";
    cin >> key;
    bool present = false;
    search(root, key, present);
    if (present) {
        cout << "Key " << key << " is present in the BST!" << endl;
    } else {
        cout << "Key is not present in the BST!" << endl;
    }

    return 0;
}
