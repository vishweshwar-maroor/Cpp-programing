#include <iostream>
using namespace std;
void pasctri(int n)
{
    int a = 1;
    int b;
    for (int i = 1; i <= n; i++)
    {
        a = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << a<<" ";
            a = a * (i - j) / (j);
        }
         cout << endl;
    }
}
int main()
{
    pasctri(6);
}