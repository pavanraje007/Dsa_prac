#include <iostream>
#include <vector>
#include <string>
#include <chrono>  
using namespace std;
using namespace std::chrono;

// Structure to represent a tree node
struct Node 
{
    string name;                
    vector<Node*> children;     

    // Constructor to initialize the node
    Node(string nodeName) : name(nodeName)
     {
     }
};

// Function to print the tree structure
void printTree(Node* root, int level = 0) 
{
    if (!root) return;

    // Print the current node with indentation
    for (int i = 0; i < level; i++) cout << "  ";
    cout << root->name << endl;

    // Recursively print child nodes
    for (Node* child : root->children) 
    {
        printTree(child, level + 1);
    }
}

// Function to delete the entire tree and free memory
void deleteTree(Node* root) 
{
    if (!root) return;

    // Recursively delete child nodes
    for (Node* child : root->children) 
    {
        deleteTree(child);
    }

    // Delete the current node
    delete root;
}

// Function to count the total number of nodes in the tree
int countNodes(Node* root) 
{
    if (!root) return 0;

    int count = 1; // Count the current node
    for (Node* child : root->children) 
    {
        count += countNodes(child); // Add child nodes recursively
    }
    return count;
}

// Function to calculate the total space used by the tree
int calculateSpace(Node* root) 
{
    if (!root) return 0;

    int space = sizeof(*root); // Space for the current node
    for (Node* child : root->children) 
    {
        space += calculateSpace(child); 
    }
    return space;
}

// Function to measure the time taken for an operation
template <typename Func, typename... Args>
double measureTime(Func&& func, Args&&... args) 
{
    auto start = high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    return duration.count();  
}

int main() 
{
    // Input the book name
    cout << "Enter the name of the book: ";
    string bookName;
    getline(cin, bookName);

    // Create the root node for the book
    Node* book = new Node("Book: " + bookName);

    // Input the number of chapters
    int numChapters;
    cout << "Enter the number of chapters: ";
    cin >> numChapters;

    for (int i = 1; i <= numChapters; i++) 
    {
        // Input chapter name
        cout << "Enter the name of Chapter " << i << ": ";
        cin.ignore();
        string chapterName;
        getline(cin, chapterName);

        // Create a chapter node
        Node* chapter = new Node("Chapter: " + chapterName);
        book->children.push_back(chapter);

        // Input the number of sections in the chapter
        int numSections;
        cout << "Enter the number of sections in " << chapterName << ": ";
        cin >> numSections;

        for (int j = 1; j <= numSections; j++) 
        {
            // Input section name
            cout << "Enter the name of Section " << j << ": ";
            cin.ignore();
            string sectionName;
            getline(cin, sectionName);

            // Create a section node
            Node* section = new Node("Section: " + sectionName);
            chapter->children.push_back(section);

            // Input the number of subsections in the section
            int numSubsections;
            cout << "Enter the number of subsections in " << sectionName << ": ";
            cin >> numSubsections;

            for (int k = 1; k <= numSubsections; k++) 
            {
                // Input subsection name
                cout << "Enter the name of Subsection " << k << ": ";
                cin.ignore();
                string subsectionName;
                getline(cin, subsectionName);

                // Create a subsection node
                Node* subsection = new Node("Subsection: " + subsectionName);
                section->children.push_back(subsection);
            }
        }
    }

    // Measure the time taken to print the tree structure
    double printTime = measureTime([&]() 
    {
        cout << "\nThe hierarchical structure of the book is:\n";
        printTree(book);
    });

    // Measure the time taken to count the total number of nodes
    double countTime = measureTime([&]() 
    {
        int totalNodes = countNodes(book);
        cout << "\nTotal number of nodes in the tree: " << totalNodes << endl;
    });

    // Measure the time taken to calculate space requirements
    double spaceTime = measureTime([&]()
    {
        int spaceRequired = calculateSpace(book);
        cout << "\nTotal space required for the tree (in bytes): " << spaceRequired << endl;
    });

    // Print the time taken for each operation
    cout << "\nTime taken to print the tree: " << printTime << " seconds" << endl;
    cout << "Time taken to count nodes: " << countTime << " seconds" << endl;
    cout << "Time taken to calculate space: " << spaceTime << " seconds" << endl;

    // Time and space requirements
    cout << "\nTime Complexity: O(n), where n is the total number of nodes." << endl;
    cout << "Space Complexity: O(n), due to the memory used by nodes and the recursive stack during tree traversal." << endl;

    // Delete the tree to free memory
    deleteTree(book);
    cout << "\nTree deleted successfully.\n";

    return 0;
}
