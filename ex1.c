#include <stdio.h>

int main(){
    int n, tong = 0;
    printf("Hay nhap so bat ki: ");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        tong +=i;
    }
    printf("Tong cua cac so tu 1 den %d la: %d ",n, tong);
    return 0;
}