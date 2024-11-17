#include <stdio.h>

int Min(int a,int b){
    return(a<b) ? a:b;
}

int main() {
    int n, ketQua = 9;
    printf("Hãy nhập số bất kì: ");
    scanf("%d",&n);
    while (n>0)
    {
        ketQua = Min(n%10,ketQua);
        n/=10;
    }
    printf("Kết quả là: %d", ketQua);
    return 0;
}
