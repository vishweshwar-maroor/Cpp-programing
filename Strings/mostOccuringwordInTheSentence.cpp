#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> strs;
    string str;
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        strs.push_back(str);
    }
    sort(strs.begin(), strs.end());
    int i=0;
    for( i=0;i<n;i++)
    {
        if(strs[0][i]!=strs[n-1][i]){
            i--;
            break;
        }
    }
    
    if (i > 0)
    {
        cout << strs[0].substr(0, i);
    }
    else
    {
        cout << "No common prefix";
    }
    return 0;
}