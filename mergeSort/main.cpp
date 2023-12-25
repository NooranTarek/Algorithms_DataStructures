#include <iostream>

using namespace std;
//0  1  2  3  4  5  6
//30 20 40 5  90 80 10

//middle=start+end/2 =>3
//merge two sorted sub arrays [start, middle] and [middle+1, end] //30 20 40 5 //90 80 10
void merge(int originalArr[], int start, int middle, int end) {
    int n1 = (middle - start) + 1; // array 1 size =>4
    int n2 = end - middle; // array 2 size =>3

    // create two arrays to store the two halves
    int L[n1];
    int R[n2];

    // copy data from the two halves to two another arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = originalArr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = originalArr[middle + 1 + j];

    // Merge the two halves back into the original array arr[]
    int i = 0; //first array index
    int j = 0; //second array index
    int k = start; //merged array index

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            originalArr[k] = L[i];
            i++;
        } else {
            originalArr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy the remaining elements of L[]
    while (i < n1) {
        originalArr[k] = L[i];
        i++;
        k++;
    }

    //copy the remaining elements of R[]
    while (j < n2) {
        originalArr[k] = R[j];
        j++;
        k++;
    }
}

// merge sort function
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int middle = start + (end - start) / 2; //3 -start is not important if the start is 0.

        // recursive calls for two halves
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);

        // merge the sorted halves
        merge(arr, start, middle, end);
    }
}

int main() {
    int arrSize;
    cout << "Please enter the size of the array: ";
    cin >> arrSize;

    int arr[arrSize];

    cout << "Please enter the elements of the array:" << endl;
    for (int index = 0; index < arrSize; index++) {
        cin >> arr[index];
    }
    cout << "Array elements before sorting: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }

    mergeSort(arr, 0, arrSize - 1);
    cout << "\nArray elements after sorting: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
