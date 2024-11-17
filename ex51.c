#include <stdio.h>

int numMax(int a,int b){
    if(a>b){
        return a;
    }
    else
    {
        return b;
    }
    
}

int main() {
    int n, ketQua = 0;
    printf("Hãy nhập số bất kì: ");
    scanf("%d",&n);
    while (n>0)
    {
        ketQua = numMax(n%10,ketQua);
        n/=10;
    }
    printf("Kết quả là: %d", ketQua);
    return 0;
}
