#include <stdio.h>

void solution(){
    int x ;
    scanf("%d", &x);
    for(int i = 0 ; 111*i <= x ; i++){
        if((x - 111*i) % 11 == 0 && (x - 111*i) >= 0){
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main(){
    int t ;
    scanf("%d", &t);
    while(t--){
        solution();
    }
    return 0;
}