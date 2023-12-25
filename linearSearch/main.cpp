#include <iostream>
#include <string>

using namespace std;

class Employee {
    public:
    int id;
    string name;
    double salary;
};

//by name
int linearSearchByName(Employee arr[], int arrSize,string& searchedName) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i].name == searchedName) {
            return i;
        }
    }
    return -1;
}

//by id
int linearSearchById(Employee arr[], int arrSize, int searchedId) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i].id == searchedId) {
            return i;
        }
    }
    return -1;
}

//by salary
int linearSearchBySalary(Employee arr[], int arrSize, double searchedSalary) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i].salary == searchedSalary) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter the size of the employee array: ";
    cin >> size;

    Employee employees[size];
    for (int i = 0; i < size; i++) {
        cout << "please enter employee data "<< endl;
        cout << "ID: ";
        cin >> employees[i].id;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Salary: ";
        cin >> employees[i].salary;
    }
    while (1){

    int userChoice;
    cout << "select what you want to search about \n"
         << "1. By name\n"
         << "2. By id\n"
         << "3. By salary\n";

        cin >> userChoice;

    switch (userChoice) {
        case 1: {
            string name;
            cout << "Enter the name to search: ";
            cin >> name;
            int returnIndex = linearSearchByName(employees, size, name);
            if (returnIndex != -1) {
                cout << "employee name '" << name << "exist in index " << returnIndex << endl;
            } else {
                cout << "employee name '" << name << "not exist" << endl;
            }
            break;
        }
        case 2: {
            int id;
            cout << "Enter the ID to search: ";
            cin >> id;
            int returnIndex = linearSearchById(employees, size, id);
            if (returnIndex != -1) {
                cout << "employee ID " << id << "exist in index " << returnIndex << endl;
            } else {
                cout << "employee ID " << id << "not exist" << endl;
            }
            break;
        }
        case 3: {
            double salary;
            cout << "Enter the salary to search: ";
            cin >> salary;
            int returnIndex = linearSearchBySalary(employees, size, salary);
            if (returnIndex != -1) {
                cout << "employee salary" << salary << "exist in index " << returnIndex << endl;
            } else {
                cout << "employee salary" << salary << "not exist" << endl;
            }
            break;
        }
        default:
            cout << "invalid choice" << endl;
            break;
    }

    }
    return 0;
}
