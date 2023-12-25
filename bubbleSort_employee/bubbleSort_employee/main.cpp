#include <iostream>

using namespace std;

class Employee
{
    int id;
    string name;
    int age;

public:
    Employee(int _id = 0, string _name = " ", int _age = 1)
    {
        id=_id;
        name=_name;
        age=_age;
    }

    int getId() const
    {
        return id;
    }
};

void bubbleSort(Employee arr[], int arrSize)
{
    for (int j = 0; j < arrSize; j++)
    {
        for (int i = 0; i < arrSize - j - 1; i++)
        {
            if (arr[i + 1].getId() < arr[i].getId())
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void arrayBeforeBubbleSort(Employee arr[], int arrSize)
{
    cout << "Please enter the details of the employees:" << endl;
    for (int index = 0; index < arrSize; index++)
    {
        int id;
        string name;
        int age;

        cout << "Employee " << index + 1 << " ID: ";
        cin >> id;
        cout << "Employee " << index + 1 << " Name: ";
        cin >> name;
        cout << "Employee " << index + 1 << " Age: ";
        cin >> age;

        arr[index] = Employee(id, name, age);
    }

    cout << "Employees before sorting: " << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << "ID: " << arr[i].getId() << endl;
    }
}

void arrayAfterBubbleSort(Employee arr[], int arrSize)
{
    bubbleSort(arr, arrSize);

    cout << "Employees after sorting: " << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << "ID: " << arr[i].getId() << endl;
    }
}

int main()
{
    int arrSize;
    cout << "Please enter the number of employees: ";
    cin >> arrSize;

    Employee arr[arrSize];
    arrayBeforeBubbleSort(arr, arrSize);
    arrayAfterBubbleSort(arr, arrSize);

    return 0;
}
