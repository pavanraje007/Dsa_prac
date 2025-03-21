
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    
    
    cout << "Enter the number of students: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid number of students!" << endl;
        return 1;
    }
    
    vector<int> marks(n);
    
    
    cout << "Enter the marks of students: ";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }
    
   
    priority_queue<int> maxHeap;
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    
    for (int mark : marks) {
        maxHeap.push(mark);
        minHeap.push(mark);
    }
    
   
    cout << "\nResults:\n";
    cout << "Maximum marks obtained: " << maxHeap.top() << endl;
    cout << "Minimum marks obtained: " << minHeap.top() << endl;
    
    return 0;
}
