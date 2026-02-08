#include <bits/stdc++.h>
using namespace std;
int main()
{
   string s;
   getline(cin, s);
   int n = s.size();

   vector<int> v(26);
   for (int i = 0; i < n; i++)
   {
      v[(int)s[i] - 97]++;
   }
   int max = 0; char a = '\0';
   for (int i = 0; i < 26; i++)
   {
      if (v[i] > max)
      {
         max = v[i];
         a = (char)(i + 97);
      }
   }
   cout<<max<<"  "<<a;
}