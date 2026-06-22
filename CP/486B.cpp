#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m ;
    cin >> n >> m ;
    int arr[n][m] , result[n][m] ;
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) 
    {
        cin >> arr[i][j] ;
        result[i][j] = arr[i][j] ;
    }
    set<int> rowSet;
    set<int> colSet;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] == 0)
            {
            for(int k = 0 ; k < m ; k++){
                result[i][k] = 0 ;

            }
            for(int k = 0 ; k < n ; k++){
                result[k][j] = 0 ;
            }
        }
    }
}
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            bool currOR = 0 ;
            for(int k = 0 ; k < m ; k++){
                currOR |= result[i][k] ;
            }
            for(int k = 0 ; k < n ; k++){
                currOR |= result[k][j] ;
            }
            if(currOR != arr[i][j]){
                cout << "NO\n";
                return 0 ;
            }
        }
    }

    cout << "YES\n";

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << result[i][j] << ' ' ;
        }
        cout << "\n";
    }

}
