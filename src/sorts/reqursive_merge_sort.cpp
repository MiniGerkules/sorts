#include "sorts.hpp"

#include <iostream>

namespace {
    std::vector<int> Merge(const std::vector<int> &arr1, const std::vector<int> &arr2) {
        auto res = std::vector<int>(arr1.size() + arr2.size());
        size_t res_ptr = 0, arr1_ptr = 0, arr2_ptr = 0;
        size_t arr1_end = arr1.size() - 1, arr2_end = arr2.size() - 1;

        for (; arr1_ptr <= arr1_end && arr2_ptr <= arr2_end; ++res_ptr) {
            if (arr1[arr1_ptr] <= arr2[arr2_ptr]) {
                res[res_ptr] = arr1[arr1_ptr++];
            } else {
                res[res_ptr] = arr2[arr2_ptr++];
            }
        }

        auto copy = [&res, &res_ptr](auto &from, const size_t start, const size_t end) {
            for (size_t i = start; i <= end; ++i, ++res_ptr)
                res[res_ptr] = from[i];
        };

        copy(arr1, arr1_ptr, arr1_end);
        copy(arr2, arr2_ptr, arr2_end);

        return res;
    }

    std::vector<int> ReqursiveMergeSort(std::vector<int> &arr, const size_t start, const size_t end) {
        if (start == end) return { arr[start] };

        size_t mid = start + (end - start)/2;
        auto left = ReqursiveMergeSort(arr, start, mid);
        auto right = ReqursiveMergeSort(arr, mid + 1, end);

        return Merge(left, right);
    }
}

void Sorts::ReqursiveMergeSort(std::vector<int> &arr) {
    if (arr.size() < 2) return;

    auto res = ::ReqursiveMergeSort(arr, 0, arr.size() - 1);
    std::swap(arr, res);
}
