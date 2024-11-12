#include <stdio.h>

int main(){
    int n, tong = 0;
    printf("Nhập số tự nhiên bất kì: ");
    scanf("%d",&n);
    for(int i = 1; i <= n/2; i ++){
        if(n%i==0){
            tong += i;
        }
    }
    if(tong == n){
        printf("Tong các ước là: %d\n", tong);
        printf("%d là số hoàn thiện\n", n);
    }
    else{
        printf("Tong các ước là: %d\n", tong);
        printf("%d không là số hoàn thiện\n", n);
    }
    return 0;
}