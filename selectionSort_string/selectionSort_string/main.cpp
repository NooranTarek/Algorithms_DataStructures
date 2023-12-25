#include <iostream>
#include <algorithm>  //header is for the swap function

using namespace std;


void selectionSort(string arr[], int arrSize)
{
    int minIndex;

    for (int j = 0; j < arrSize - 1; j++)
    {
        minIndex = j; // starts with the first element in the array
        for (int i = j + 1; i < arrSize; i++)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i; // if the second is greater than the first, assign the second as minIndex
            }
        }
        swap(arr[minIndex], arr[j]);
    }
}

void arrayBeforeSelectionSort(string arr[], int arrSize)
{
    cout << "Please enter the elements of the array:" << endl;
    for (int index = 0; index < arrSize; index++)
    {
        cin >> arr[index];
    }

    cout << "Array elements before sorting: ";
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void arrayAfterSelectionSort(string arr[], int arrSize)
{
    selectionSort(arr, arrSize);

    cout << "Array elements after sorting: ";
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arrSize;
    cout << "Please enter the size of the array: ";
    cin >> arrSize;

    string arr[arrSize];
    arrayBeforeSelectionSort(arr, arrSize);
    arrayAfterSelectionSort(arr, arrSize);

    return 0;
}
