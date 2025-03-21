#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add student details
void addStudent() {
    ofstream file("students.txt", ios::app); // Open in append mode
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;
    cin.ignore(); // To clear buffer
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Division: ";
    getline(cin, s.division);
    cout << "Enter Address: ";
    getline(cin, s.address);

    file << s.rollNumber << "," << s.name << "," << s.division << "," << s.address << endl;
    file.close();
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayAllStudents() {
    ifstream file("students.txt"); // Open the file for reading
    if (!file) {
        cout << "No records found!\n";
        return;
    }

    string line;
    bool found = false;
    
    cout << "\nStudent Records:\n";
    cout << "-------------------------------------------\n";
    cout << "Roll No | Name | Division | Address\n";
    cout << "-------------------------------------------\n";

    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        string rollStr;

        getline(ss, rollStr, ',');
        getline(ss, s.name, ',');
        getline(ss, s.division, ',');
        getline(ss, s.address, ',');

        s.rollNumber = stoi(rollStr);

        cout << s.rollNumber << " | " << s.name << " | " << s.division << " | " << s.address << endl;
        found = true;
    }
    
    file.close();
    
    if (!found) {
        cout << "No student records found!\n";
    }
}

// Function to display a specific student by roll number
void displayStudent(int roll) {
    ifstream file("students.txt");
    if (!file) {
        cout << "No records found!\n";
        return;
    }

    Student s;
    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string rollStr;

        getline(ss, rollStr, ',');
        getline(ss, s.name, ',');
        getline(ss, s.division, ',');
        getline(ss, s.address, ',');

        s.rollNumber = stoi(rollStr);

        if (s.rollNumber == roll) {
            cout << "\nStudent Found:\n";
            cout << "Roll Number: " << s.rollNumber << "\nName: " << s.name
                 << "\nDivision: " << s.division << "\nAddress: " << s.address << endl;
            found = true;
            break;
        }
    }
    
    file.close();

    if (!found) {
        cout << "Student record not found!\n";
    }
}

// Function to delete a student record
void deleteStudent(int roll) {
    ifstream file("students.txt");
    if (!file) {
        cout << "No records found!\n";
        return;
    }

    ofstream temp("temp.txt");
    Student s;
    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string rollStr;

        getline(ss, rollStr, ',');
        getline(ss, s.name, ',');
        getline(ss, s.division, ',');
        getline(ss, s.address, ',');

        s.rollNumber = stoi(rollStr);

        if (s.rollNumber == roll) {
            found = true;
            continue;  // Skip writing this record to the temp file
        }
        temp << line << endl;
    }
    
    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        cout << "Student record deleted successfully!\n";
    } else {
        cout << "Student record not found!\n";
    }
}

int main() {
    int choice, roll;
    
    do {
        cout << "\nStudent Information System\n";
        cout << "1. Add Student\n2. Display All Students\n3. Display Student by Roll Number\n4. Delete Student\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                cout << "Enter Roll Number to Search: ";
                cin >> roll;
                displayStudent(roll);
                break;
            case 4:
                cout << "Enter Roll Number to Delete: ";
                cin >> roll;
                deleteStudent(roll);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
