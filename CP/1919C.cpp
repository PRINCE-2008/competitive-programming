#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ;
    cin >> n ;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
    }

    int end1  = INT_MAX ;
    int end2 = INT_MAX ;
    int penalty = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(end1 > end2)
        {
            swap(end1,end2) ;
        }

        if(end1 >= v[i])
        {
            end1 = v[i] ;
        }
        else if(end2 >= v[i])
        {
            end2 = v[i] ;
        }
        else
        {
            penalty++ ;
            end1 = v[i] ;
        }
        
    }
    cout << penalty << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}