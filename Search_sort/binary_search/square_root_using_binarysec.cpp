#include <iostream>
using namespace std;
int sqrtInt(int x)
{
    int s = 0, e = x, m = s + (e - s) / 2;
    int ans;
    // x==key;
    while (s <= e)
    {
        if (m * m == x)
        {
            ans = m;
            break;
        }
        else if (m * m < x)
        {
            ans = m;
            s = m + 1;
        }
        else if (m * m > x)
        {
            e = m - 1;
        }

        m = s + (e - s) / 2;
    }
    return ans;
}
double morePrecision(int key, int precision, int tempsol)
{
    double factor = 1;
    double ans = (double)tempsol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < key; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{   int x=50;
    int tempans = sqrtInt(x);

    cout << morePrecision(x, 10, tempans);
}