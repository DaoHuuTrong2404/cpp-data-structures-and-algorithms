/**
 * @file binary_search.cpp
 * @brief High-Performance Binary Search, Lower Bound, and Upper Bound
 * @author Dao Huu Trong (DTrongVIP) - Can Tho University
 */

#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int lowerBound(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    std::cout << "=== Binary Search & Boundary Search (DTrongVIP) ===\n";
    std::vector<int> sortedArr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

    int target = 23;
    int idx = binarySearch(sortedArr, target);
    std::cout << "Target " << target << " found at index: " << idx << "\n";

    int lb = lowerBound(sortedArr, 25);
    std::cout << "Lower bound for 25 is at index: " << lb << " (val: " << sortedArr[lb] << ")\n";

    return 0;
}
