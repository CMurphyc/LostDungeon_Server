#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int>v;

int main()
{
    for (int i = 1; i <= 10; ++i) {
        v.push_back(i);
    }
    for (int i : v) {
        if (i == 5) {
            v.erase(find(v.begin(), v.end(), 5));
        }
        cout << i << endl;
    }

    return 0;
}