#include <bits/stdc++.h>
using namespace std;
using namespace chrono;  // For time measurement

// Node structure for a Threaded Binary Tree
struct Node {
    int data;
    Node *left, *right;
    bool isThreaded;  // True if the right pointer is a thread

    Node(int val) {
        data = val;
        left = right = NULL;
        isThreaded = false;
    }
};

// Global variable to track space usage (total nodes created)
int nodeCount = 0;

// Function to create a threaded binary tree
void createThreaded(Node* root, Node* &prev) {
    if (root == NULL) return;

    // Recursive call to the left subtree
    createThreaded(root->left, prev);

    // Convert the right NULL pointer to a thread
    if (prev && prev->right == NULL) {
        prev->right = root;
        prev->isThreaded = true;
    }

    // Update previous node to the current node
    prev = root;

    // Recursive call to the right subtree
    createThreaded(root->right, prev);
}

// Function to find the leftmost node in a tree (starting point of in-order traversal)
Node* leftmost(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Function to perform in-order traversal using threading
void inorderTraversal(Node* root) {
    Node* current = leftmost(root);

    while (current != NULL) {
        cout << current->data << " ";

        // If the node is threaded, follow the thread
        if (current->isThreaded)
            current = current->right;
        else
            current = leftmost(current->right);
    }
}

// Function to insert a node into the binary tree
Node* insert(Node* root, int key) {
    if (root == NULL) {
        nodeCount++;  // Increase node count when a new node is created
        return new Node(key);
    }
    
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    
    return root;
}

int main() {
    // Start time measurement
    auto start = high_resolution_clock::now();

    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 25);

    // Convert the binary tree to a threaded binary tree
    Node* prev = NULL;
    createThreaded(root, prev);

    // Measure end time
    auto end = high_resolution_clock::now();

    cout << "Inorder Traversal using Threaded Binary Tree: ";
    inorderTraversal(root);
    cout << endl;

    // Calculate execution time
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    // Space complexity estimation
    int spaceUsed = nodeCount * sizeof(Node);
    cout << "Total Nodes Created: " << nodeCount << endl;
    cout << "Approximate Space Used: " << spaceUsed << " bytes" << endl;

    return 0;
}
