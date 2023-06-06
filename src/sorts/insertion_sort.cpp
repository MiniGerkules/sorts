#include "sorts.hpp"

void Sorts::InsertionSort(std::vector<int> &arr) {
    for (size_t i = 1, end = arr.size(); i < end; ++i) {
        int to_insert = arr[i];
        ssize_t j = i - 1;

        for (; j >= 0 && arr[j] > to_insert; --j)
            arr[j + 1] = arr[j];

        arr[j + 1] = to_insert;
    }
}
