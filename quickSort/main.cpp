#include <iostream>
#include <algorithm>  //this header for the swap function


using namespace std;

//partition the array and return the partitioning index
int partitioning(int arr[], int startElement, int endElement)
{
    //make the start element as the pivot
    int pivot = startElement;

    // using loop to organize elements which are smaller than pivot are in left
    //and greater than pivot are in right
    while (startElement < endElement)
    {
        while (arr[startElement] <= arr[pivot])
        {
            startElement++;
        }
        while (arr[endElement] > arr[pivot])
        {
            endElement--;
        }

        // swap the elements
        if (startElement < endElement)
        {
            swap(arr[startElement], arr[endElement]);
        }
    }

    // swap pivot with endElement
    swap(arr[pivot], arr[endElement]);

    //pivott
    return endElement;
}


void quickSort(int arr[], int startElement, int endElement)
{
    if (startElement < endElement)
    {
        int pivot = partitioning(arr, startElement, endElement);

        // using recursive we sort the sub arrays on the left and right of the pivot
        quickSort(arr, startElement, pivot - 1);
        quickSort(arr, pivot + 1, endElement);
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

    cout << "Array elements before sorting: ";
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, arrSize - 1);
    cout << "\nArray elements after sorting: ";
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
