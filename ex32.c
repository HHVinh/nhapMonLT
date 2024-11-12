#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Nhập một số bất kì: ");
    scanf("%d",&n);
    int canBac = (int) sqrt(n);
    if(canBac*canBac == n){
        printf("%d là số chính phương\n", n);
    } else{
        printf("%d không là số chính phương\n", n);
    }
    return 0;
}