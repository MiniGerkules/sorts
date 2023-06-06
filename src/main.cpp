#include <iostream>
#include <fstream>
#include <optional>
#include <functional>
#include <time.h>

#include "sorts.hpp"

namespace {
    const char *file_name = "data.txt";

    std::optional<std::vector<int>> ReadFromFile() {
        std::ifstream file{ file_name };
        if (!file) return std::nullopt;

        size_t size;
        file >> size;

        std::vector<int> arr; arr.reserve(size);
        for (size_t i = 0; i < size; ++i) {
            int tmp; file >> tmp;
            arr.push_back(tmp);
        }

        return arr;
    }

    std::optional<size_t> GetTimeOfExecution(std::function<void(std::vector<int>&)> func,
                                             std::vector<int> &data) {
        struct timespec start, end;
        int clock_start = clock_gettime(CLOCK_MONOTONIC, &start);
        func(data);
        int clock_end = clock_gettime(CLOCK_MONOTONIC, &end);

        if (clock_start == -1 || clock_end == -1)
            return std::nullopt;

        size_t start_time = start.tv_sec*1000 + start.tv_nsec/1000000;
        size_t end_time = end.tv_sec*1000 + end.tv_nsec/1000000;

        return end_time - start_time;
    }
}

int main(void) {
    auto opt_arr = ReadFromFile();
    if (!opt_arr.has_value()) {
        std::cerr << "ERROR! Can't read data from \"" << file_name << "\" file!\n";
        return EXIT_FAILURE;
    }

    auto &arr = opt_arr.value();
    std::optional<size_t> time;

#if defined(BUBBLE)
    time = GetTimeOfExecution(Sorts::BubbleSort, arr);
#elif defined(QUICK)
    time = GetTimeOfExecution(Sorts::ReqursiveQuickSort, arr);
#else
    return EXIT_SUCCESS;
#endif

    if (!time.has_value()) {
        std::cerr << "ERROR! Can't get time!\n";
        return EXIT_FAILURE;
    }

    std::cerr << "Time of execution = " << time.value() << " ms\n";
    std::cout << '[';
    for (size_t i = 0, endI = arr.size() - 1; i < endI; ++i)
        std::cout << arr[i] << ", ";
    std::cout << arr.back() << "]\n";

    return EXIT_SUCCESS;
}
