#include <iostream>

#include "sorts.hpp"

namespace {
    // The function sets in the mid position median of start, end and mid elements
    void MakeMidPivot(std::vector<int> &arr, const size_t start, const size_t end) {
        const size_t mid = start + (end - start)/2;

        if (arr[start] > arr[mid])
            std::swap(arr[start], arr[mid]);
        if (arr[mid] > arr[end])
            std::swap(arr[mid], arr[end]);
        if (arr[start] > arr[mid])
            std::swap(arr[start], arr[mid]);
    }

    // The function divides the array into two parts
    size_t Partition(std::vector<int> &arr, const size_t start, const size_t end) {
        const int pivot = arr[start + (end - start)/2];
        size_t l = start, r = end;

        while (true) {
            while (l < end && arr[l] < pivot) ++l;
            while (r > start && arr[r] > pivot) --r;

            if (l >= r) return r;

            std::swap(arr[l++], arr[r--]);
        }
    }

    void ReqursiveQuickSort(std::vector<int> &arr, const size_t start, const size_t end) {
        if (start < end) {
            MakeMidPivot(arr, start, end);
            const size_t pivot = Partition(arr, start, end);

            ReqursiveQuickSort(arr, start, pivot);
            ReqursiveQuickSort(arr, pivot + 1, end);
        }
    }
}

void Sorts::ReqursiveQuickSort(std::vector<int> &arr) {
    if (arr.size() < 2) return;

    ::ReqursiveQuickSort(arr, 0, arr.size() - 1);
}
