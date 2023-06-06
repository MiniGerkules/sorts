#include "sorts.hpp"

void Sorts::BubbleSort(std::vector<int> &arr) {
    for (size_t i = 1, end = arr.size(); i < end; ++i) {
        for (size_t j = 1; j <= end - i; ++j) {
            if (arr[j - 1] > arr[j])
                std::swap(arr[j - 1], arr[j]);
        }
    }
}
