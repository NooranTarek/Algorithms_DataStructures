#include <iostream>

using namespace std;

int sentinelLinearSearch(int arr[], int size, int target)
{
    // add sentinel at the end
    int lastElement = arr[size - 1];
    arr[size - 1] = target;
    int i = 0;
    while (arr[i] != target)
    {
        ++i;
    }

    //retrieve the last element
    arr[size - 1] = lastElement;

    if (i < size - 1 || arr[size - 1] == target)
    {
        return i;  // Return the index if found
    }
    else
    {
        return -1;  // Return -1 if not found
    }
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

    int returnedIndex = sentinelLinearSearch(arr, arrSize, number);

    if (returnedIndex != -1)
    {
        cout << "number exist in index " << returnedIndex << endl;
    }
    else
    {
        cout << "number not exist." << endl;
    }

    return 0;
}
