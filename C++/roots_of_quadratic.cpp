#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;

    float root1, root2;

    cout << "enter the values of a,b and c";

    cin >> a >> b >> c;

    // quadratic formula for both the roots

    root1 = (-b + (sqrt(b * b - 4 * a * c))) / (2 * a * c);

    root2 = (-b - (sqrt(b * b - 4 * a * c))) / (2 * a * c);

    cout << "The roots of the given values would be " << root1 << " and " << root2;

    return 0;
}