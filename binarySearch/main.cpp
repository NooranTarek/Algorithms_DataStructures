#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target)
        {
            return middle;
        }
        else if (arr[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;  //return -1 if not found
}

int main()
{
    int arrSize;
    cout << "Please enter the size of the array: ";
    cin >> arrSize;
    int arr[arrSize];
    cout << "Please enter the elements of the array:" << endl;
    for (int index = 0; index < arrSize; index++)
    {
        cin >> arr[index];
    }
    int number;
    cout << "enter the number to search about : ";
    cin >> number;
    int returnedIndex = binarySearch(arr, arrSize, number);

    if (returnedIndex != -1)
    {
        cout << "Number found at index " << returnedIndex << endl;
    }
    else
    {
        cout << "Number not found." << endl;
    }

    return 0;
}
