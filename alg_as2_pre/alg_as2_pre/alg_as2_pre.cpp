#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int middle = left + (right - left) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void swapSound() {
    std::cout << "Swapping..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
}

int main() {
    std::vector<int> arr = {11, 1, 30, 2, 51, 6, 29, 7, 67, 15, 118, 4, 89, 23};
    std::cout << "Original Array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);


    std::cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}
