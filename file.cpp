#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v = {1, 2, 3, 4, 5};

    cout << "Original vector" << endl;
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    /* Remove first two element */
    v.erase(v.begin(), v.begin() + 3);

    cout << "Modified vector" << endl;
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    return 0;
}