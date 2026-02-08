#include <iostream>
using namespace std;

int main()
{
    int CP, SP;//cost price selling price
    cout << "put cost price and selling price";
    cin >> CP >> SP;
    int D = SP - CP; //difference
    if (D > 0)
    {
        cout << "profit =" << D;
    }
    else if(D<0)
    {
        cout << "loss =" << -D;
    }
    else {cout <<"no loss no profit";}
}