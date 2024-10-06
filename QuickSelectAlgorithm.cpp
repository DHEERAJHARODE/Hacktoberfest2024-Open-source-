#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(std::vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to implement the Select Algorithm
int select(std::vector<int>& arr, int low, int high, int k, int& comparisons, int& recursions) {
    recursions++;

    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high, comparisons);

    comparisons++;

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return select(arr, low, pivotIndex - 1, k, comparisons, recursions);
    } else {
        return select(arr, pivotIndex + 1, high, k, comparisons, recursions);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Input sizes
    int inputSizes[] = {500, 1000, 5000, 15000, 30000, 50000, 100000};

    // k values
    int kValues[] = {10, 50, 100};

    for (int n : inputSizes) {
        std::vector<int> arr(n);

        // Generate random input data
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }

        for (int k : kValues) {
            int comparisons = 0;
            int recursions = 0;

            // Call the select function and count comparisons and recursions
            int result = select(arr, 0, n - 1, k - 1, comparisons, recursions);

            std::cout << "Input size: " << n << ", k: " << k << std::endl;
            std::cout << "Number of comparisons: " << comparisons << std::endl;
            std::cout << "Number of recursions: " << recursions << std::endl;
            std::cout << "Result: " << result << std::endl;
            std::cout << std::endl;
        }
    }

    return 0;
}
