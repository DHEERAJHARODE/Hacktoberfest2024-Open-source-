#include <iostream>
#include <stack>
using namespace std;
class queue
{
    stack<int> s1, s2;
    public:
    void enqueue(int data)
    {
        s1.push(data);
    }
    void dequeue()
    {
        while (!s1.empty())
        {
            int x = s1.top();
            s1.pop();
            s2.push(x);
        }
        cout << s2.top()<<endl;
        s2.pop();

        while (!s2.empty())
        {
            int y = s2.top();
            s2.pop();
            s1.push(y);
        }
    }
};
int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();
}