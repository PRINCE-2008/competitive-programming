#include <bits/stdc++.h>

using namespace std;

void solution()
{
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string arr;
        cin >> arr;
        if (m.find(arr) == m.end())
        {
            m[arr] = 1;
            cout << "OK\n";
        }
        else
        {
            m[arr]++;
            cout << arr << m[arr] - 1 << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    solution();
}