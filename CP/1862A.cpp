#include <bits/stdc++.h>

void solution(){
    int n , m ;
    std::cin >> n >> m;
    std::vector<std::string> vika(n, std::string (m,'\n'));
    for(int i = 0 ; i < n ; i++){
            std::cin >> vika[i] ;
    }
    int count = 0 ;
    for(int i = 0 ; i< m ; i++){

        for(int j = 0 ; j < n ; j++){
            int ini = count ;
            switch (count)
            {
            case 0:
                if(vika[j][i]=='v') count++;
                break;
            case 1:
                if(vika[j][i]=='i') count++;
                break;
            case 2 : 
                if(vika[j][i]=='k') count++;
                break;
            case 3 :
                if(vika[j][i]=='a') count++;
            default :
                break;
            }
            if(ini != count ) break;

        }
    }
    // std::cout << count << " ";
    if(count==4) std::cout << "YES\n" ;
    else std:: cout << "NO\n" ;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std:: cin >> t;
    while(t--){
        solution();
    }
}