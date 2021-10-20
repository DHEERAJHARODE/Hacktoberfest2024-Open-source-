#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

namespace sorting {
    namespace cycle_sort {
        template < typename T >
            std::vector < T > cycleSort(const std::vector < T > & in_arr) {
                std::vector < T > arr(in_arr);
                for (size_t cycle_start = 0; cycle_start <= arr.size() - 1; cycle_start++) {

                    T item = arr[cycle_start];

                    int pos = cycle_start;
                    for (size_t i = cycle_start + 1; i < arr.size(); i++) {
                        if (arr[i] < item) {
                            pos++;
                        }
                    }

                    if (pos == cycle_start) {
                        continue;
                    }

                    while (item == arr[pos]) pos += 1;
                    std::swap(item, arr[pos]);

                    while (pos != cycle_start) {
                        pos = cycle_start;

                        for (size_t i = cycle_start + 1; i < arr.size(); i++) {
                            if (arr[i] < item) {
                                pos += 1;
                            }
                        }

                        while (item == arr[pos]) pos += 1;
                        std::swap(item, arr[pos]);
                    }
                }
                return arr;
            }
    }
}

static void test() {
    // [506, 48, 123, 79, 0, 362, 951, 500, 0] return [0, 0, 48, 79, 123, 362, 500, 506, 951]
    std::vector<int> array1 = {506, 48, 123, 79, 0, 362, 951, 500, 0};
    std::cout << "Test 1... ";
    std::vector<int> arr1  = sorting::cycle_sort::cycleSort(array1);
    assert(std::is_sorted(std::begin(arr1), std::end(arr1)));
    std::cout << "passed" << std::endl;

    // [4.3, -6.5, -7.4, 0, 2.7, 1.8] return [-7.4, -6.5, 0, 1.8, 2.7, 4.3]
    std::vector<double> array2 = {4.3, -6.5, -7.4, 0, 2.7, 1.8};
    std::cout << "Test 2... ";
    std::vector<double> arr2 = sorting::cycle_sort::cycleSort(array2);
    assert(std::is_sorted(std::begin(arr2), std::end(arr2)));
    std::cout << "passed" << std::endl;
}

int main() {
    test();  // execute the test
    return 0;
}