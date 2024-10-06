#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include<math.h>
#include<limits.h>

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to calculate distance between two points
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Naive algorithm to find the closest pair
double closestPairNaive(std::vector<Point>& points, int& numDistances) {
    double minDistance = INT_MAX;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            numDistances++;
            double dist = distance(points[i], points[j]);
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }
    return minDistance;
}

// Divide-and-conquer approach to find the closest pair
double closestPairDivideConquer(std::vector<Point>& points, int& numDistances) {
    // Base case: If there are 3 or fewer points, use the naive algorithm
    if (points.size() <= 3) {
        return closestPairNaive(points, numDistances);
    }

    // Divide the points into two halves
    int mid = points.size() / 2;
    std::vector<Point> left(points.begin(), points.begin() + mid);
    std::vector<Point> right(points.begin() + mid, points.end());

    // Recursively find the closest pair in each half
    int numDistancesLeft = 0, numDistancesRight = 0;
    double minDistanceLeft = closestPairDivideConquer(left, numDistancesLeft);
    double minDistanceRight = closestPairDivideConquer(right, numDistancesRight);

    // Find the minimum distance between the two halves
    double minDistance = std::min(minDistanceLeft, minDistanceRight);

    // Find the points in the middle strip
    std::vector<Point> middleStrip;
    for (const Point& point : points) {
        if (abs(point.x - points[mid].x) < minDistance) {
            middleStrip.push_back(point);
        }
    }

    // Find the closest pair in the middle strip
    for (int i = 0; i < middleStrip.size(); i++) {
        for (int j = i + 1; j < std::min(i + 7, (int)middleStrip.size()); j++) {
            numDistances++;
            double dist = distance(middleStrip[i], middleStrip[j]);
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }

    numDistances += numDistancesLeft + numDistancesRight;
    return minDistance;
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Input sizes
    int inputSizes[] = {100, 200, 300, 400, 500};

    for (int n : inputSizes) {
        std::vector<Point> points(n);

        // Generate random points within a rectangular region
        for (int i = 0; i < n; i++) {
            points[i].x = rand() % 1000;
            points[i].y = rand() % 1000;
        }

        // Sort the points by x-coordinate
        std::sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
            return p1.x < p2.x;
        });

        int numDistancesNaive = 0, numDistancesDivideConquer = 0;
        double timeNaive, timeDivideConquer;

        // Measure the runtime of the naive algorithm
        clock_t startNaive = clock();
        double minDistanceNaive = closestPairNaive(points, numDistancesNaive);
        clock_t endNaive = clock();
        timeNaive = (double)(endNaive - startNaive) / CLOCKS_PER_SEC;

        // Measure the runtime of the divide-and-conquer approach
        clock_t startDivideConquer = clock();
        double minDistanceDivideConquer = closestPairDivideConquer(points, numDistancesDivideConquer);
        clock_t endDivideConquer = clock();
        timeDivideConquer = (double)(endDivideConquer - startDivideConquer) / CLOCKS_PER_SEC;

        std::cout << "Input size: " << n << std::endl;
        std::cout << "Naive algorithm:" << std::endl;
        std::cout << "Number of distances computed: " << numDistancesNaive << std::endl;
        std::cout << "Runtime: " << timeNaive << " seconds" << std::endl;
        std::cout << "Minimum distance: " << minDistanceNaive << std::endl;

        std::cout << "Divide-and-conquer approach:" << std::endl;
        std::cout << "Number of distances computed: " << numDistancesDivideConquer << std::endl;
        std::cout << "Runtime: " << timeDivideConquer << " seconds" << std::endl;
        std::cout << "Minimum distance: " << minDistanceDivideConquer << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
