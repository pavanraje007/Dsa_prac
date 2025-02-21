#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

class OBST {
    vector<int> keys, freq;
    vector<vector<int>> cost, root;
    int n;

public:
    void getInput();
    void buildOBST();
    void printPreorder(int, int);
};

// Function to get input keys and frequencies
void OBST::getInput() {
    cout << "\nEnter number of keys: ";
    cin >> n;

    keys.resize(n);
    freq.resize(n);
    cost.assign(n, vector<int>(n, 0));
    root.assign(n, vector<int>(n, 0));

    cout << "\nEnter keys: ";
    for (int i = 0; i < n; i++)
        cin >> keys[i];

    cout << "\nEnter corresponding frequencies: ";
    for (int i = 0; i < n; i++)
        cin >> freq[i];
}

// Function to build the Optimal Binary Search Tree
void OBST::buildOBST() {
    // Step 1: Initialize cost and root tables
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];  // Only one node in the subtree
        root[i][i] = i;        // Root of a single node is the node itself
    }

    // Step 2: Build the OBST using dynamic programming
    for (int len = 2; len <= n; len++) {  // len is the length of the subtree
        for (int i = 0; i <= n - len; i++) {  // i is the start index
            int j = i + len - 1;  // j is the end index
            cost[i][j] = INT_MAX;

            int sum = 0;  // Sum of frequencies in the range [i, j]
            for (int k = i; k <= j; k++) {
                sum += freq[k];
            }

            for (int r = i; r <= j; r++) {  // Try each node as the root
                int leftCost = (r > i) ? cost[i][r - 1] : 0;  // Left subtree cost
                int rightCost = (r < j) ? cost[r + 1][j] : 0;  // Right subtree cost
                int totalCost = leftCost + rightCost + sum;

                if (totalCost < cost[i][j]) {
                    cost[i][j] = totalCost;
                    root[i][j] = r;  // Store the root of the subtree
                }
            }
        }
    }

    cout << "\nOptimal BST Cost: " << cost[0][n - 1] << endl;
    cout << "\nPreorder Traversal of OBST: ";
    printPreorder(0, n - 1);
    cout << endl;
}

// Function to print Preorder traversal
void OBST::printPreorder(int i, int j) {
    if (i > j) return;
    int r = root[i][j];
    cout << keys[r] << " ";  // Print the root of this subtree
    printPreorder(i, r - 1);  // Left subtree
    printPreorder(r + 1, j);  // Right subtree
}

// Main function
int main() {
    OBST tree;
    cout << "\n-----*** Optimal BST Construction ***-----";
    tree.getInput();
    tree.buildOBST();
    return 0;
}
