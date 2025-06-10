#include <iostream>
using namespace std;

void conquer(int arr[], int si, int mid, int ei) {
    int size = ei - si + 1;
    int merged_array[size];
    int i = si;       // Pointer for the left half
    int j = mid + 1;  // Pointer for the right half
    int k = 0;        // Pointer for the merged array

    // Merge the two halves
    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            merged_array[k++] = arr[i++];
        } else {
            merged_array[k++] = arr[j++];
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        merged_array[k++] = arr[i++];
    }

    // Copy remaining elements from the right half
    while (j <= ei) {
        merged_array[k++] = arr[j++];
    }

    // Copy the merged array back into the original array
    for (int l = 0; l < size; l++) {
        arr[si + l] = merged_array[l];
    }
}

void divide(int arr[], int si, int ei) {
    if (si < ei) {
        int mid = si + (ei - si) / 2;  // Find the middle index
        divide(arr, si, mid);         // Sort the left half
        divide(arr, mid + 1, ei);     // Sort the right half
        conquer(arr, si, mid, ei);    // Merge the two halves
    }
}

int main() {
    int arr[5] = {5, 4, 32, 9, 39};
    int size = 5;

    divide(arr, 0, size - 1);  // Correctly specify the range of the array

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {  // Correct loop bounds
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
