#include <iostream>
#include <queue>

/*std::queue::back() references the last element of a queue container*/

int main()
{
    std::queue<int> myqueue;
    myqueue.push(3);
    myqueue.push(4);
    myqueue.push(1);
    myqueue.push(7);
 
    // Queue becomes 3, 4, 1, 7
 
    std::cout << myqueue.back();
    return 0;
}
