#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original array: ";
    for (int num : data) std::cout << num << " ";
    std::cout << std::endl;

    quickSort(data, 0, data.size() - 1);

    std::cout << "Sorted array:   ";
    for (int num : data) std::cout << num << " ";
    std::cout << std::endl;
    return 0;
}
