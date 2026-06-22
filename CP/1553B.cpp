#include <bits/stdc++.h>
using namespace std;

void solution()
{
    string s, t;
    cin >> s >> t;
    vector<int> firstCharPos;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == t[0])
        {
            firstCharPos.push_back(i);
        }
    }
    for (int i = 0; i < firstCharPos.size(); i++)
    {
        int pos = firstCharPos[i];
        int j = 0;
        int tempPos = pos;
        int tempJ = j;
        while (tempPos < s.size() && tempJ < t.size())
        {
            if (s[tempPos-1] == t[tempJ+1] && tempPos -1 >= 0 && tempJ+1 < t.size())
            {
                tempPos--;
                tempJ++;
            }
            else
            {
                break;
            }
        }
        if (tempJ == t.size() - 1)
        {
            cout << "YES\n";
            return;
        }
        while (pos < s.size() && j < t.size())
        {   
            if (s[pos + 1] == t[j + 1] && pos + 1 < s.size() && j + 1 < t.size())
            {
                pos++;
                j++;
                int tempPos = pos;
                int tempJ = j;
                while (tempPos > 0 && tempJ < t.size())
                {
                    if (s[tempPos - 1] == t[tempJ + 1] && tempPos - 1 >= 0 && tempJ + 1 < t.size())
                    {
                        tempPos--;
                        tempJ++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (tempJ == t.size() - 1)
                {
                    cout << "YES\n";
                    return;
                }
            }
            else
            {
                break;
            }
        }
        while (pos > 0 && j < t.size())
        {
            if (s[pos - 1] == t[j + 1] && pos - 1 >= 0 && j + 1 < t.size())
            {
                pos--;
                j++;
            }
            else
            {
                break;
            }
        }
        if (j == t.size() - 1)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
}