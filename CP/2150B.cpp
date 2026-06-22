#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> bCells(m), resBCells(m);
    for (int i = 0; i < m; i++)
    {
        cin >> bCells[i];
        resBCells[i] = bCells[i];
    }
    
    for(int i = 0 ; i < n ; i++){
        int it = 0;
        int idx = 0;
    for (int i = 1; i <= 1e9 && idx <= i; i++)
    {
        if (s[idx] == 'A')
        {
            if (it < m && bCells[it] == i)
            {
                it++;
                idx++;
            }
            else
            {
                idx++;
                // resBCells.push_back(i);
            }
        }
        else
        {
            if (it < m && bCells[it] != i)
            {
                idx++;
                // resBCells.push_back(i);
            }
            else
            {
                while (it < m && bCells[it] <= i)
                {
                    i++;
                    it++;
                }
                i--;
            }
         }
         if(bCells[it-1] == i && idx == i){
             resBCells.push_back(i);
            
         }
    }}
    cout << resBCells.size() << "\n";
    for (int i = 0; i < resBCells.size(); i++)
    {
        cout << resBCells[i] << ' ';
    }
    cout << "\n";
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