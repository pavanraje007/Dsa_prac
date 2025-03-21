#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    float salary;
};

// Function to add an employee
void addEmployee() {
    ofstream file("employees.txt", ios::app); // Append mode
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, emp.name);
    cout << "Enter Designation: ";
    getline(cin, emp.designation);
    cout << "Enter Salary: ";
    cin >> emp.salary;

    file << emp.id << "," << emp.name << "," << emp.designation << "," << emp.salary << endl;
    file.close();
    cout << "Employee added successfully!\n";
}

// Function to search for an employee by ID
void searchEmployee(int empID) {
    ifstream file("employees.txt");
    if (!file) {
        cout << "No records found!\n";
        return;
    }

    Employee emp;
    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr;

        getline(ss, idStr, ',');
        getline(ss, emp.name, ',');
        getline(ss, emp.designation, ',');
        ss >> emp.salary;
        emp.id = stoi(idStr);

        if (emp.id == empID) {
            cout << "\nEmployee Found:\n";
            cout << "ID: " << emp.id << "\nName: " << emp.name
                 << "\nDesignation: " << emp.designation << "\nSalary: " << emp.salary << endl;
            found = true;
            break;
        }
    }
    
    file.close();
    if (!found) {
        cout << "Employee record not found!\n";
    }
}

// Function to delete an employee by ID
void deleteEmployee(int empID) {
    ifstream file("employees.txt");
    if (!file) {
        cout << "No records found!\n";
        return;
    }

    ofstream temp("temp.txt");
    Employee emp;
    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr;

        getline(ss, idStr, ',');
        getline(ss, emp.name, ',');
        getline(ss, emp.designation, ',');
        ss >> emp.salary;
        emp.id = stoi(idStr);

        if (emp.id == empID) {
            found = true; // Skip writing this record to delete it
            continue;
        }
        temp << line << endl;
    }

    file.close();
    temp.close();

    remove("employees.txt");
    rename("temp.txt", "employees.txt");

    if (found) {
        cout << "Employee record deleted successfully!\n";
    } else {
        cout << "Employee record not found!\n";
    }
}

int main() {
    int choice, empID;
    
    do {
        cout << "\nCompany Employee Management System\n";
        cout << "1. Add Employee\n2. Search Employee\n3. Delete Employee\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                cout << "Enter Employee ID to Search: ";
                cin >> empID;
                searchEmployee(empID);
                break;
            case 3:
                cout << "Enter Employee ID to Delete: ";
                cin >> empID;
                deleteEmployee(empID);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
