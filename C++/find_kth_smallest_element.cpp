#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Function to find the k'th smallest element in an array using max-heap
int findKthSmallest(vector<int> const &input, int k)
{
    // base case
    if (input.size() < k) {
        exit(-1);
    }
 
    // create a max-heap using `std::priority_queue` and
    // insert the first `k` array elements into the heap
    priority_queue<int, vector<int>> pq(input.begin(), input.begin() + k);
 
    // do for remaining array elements
    for (int i = k; i < input.size(); i++)
    {
        // if the current element is less than the root of the heap
        if (input[i] < pq.top())
        {
            // replace root with the current element
            pq.pop();
            pq.push(input[i]);
        }
    }
 
    // return the root of max-heap
    return pq.top();
}
 
int main()
{
    vector<int> input = { 7, 4, 6, 3, 9, 1 };
    int k = 3;
 
    cout << "k'th smallest array element is " << findKthSmallest(input, k);
 
    return 0;
}
