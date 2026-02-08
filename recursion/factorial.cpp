#include <iostream>
using namespace std;
int fact(int n)
{
    if (n >= 1)
    {
        n = n * fact(n - 1);
    }
    else
    {
        return 1;
    }
    return n;
}
int main()
{
    cout << "input number";
    int n;
    cin >> n;
    cout << fact(n);
}