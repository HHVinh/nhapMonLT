#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   // cần include nếu dùng bool

void sangSoNguyenTo(int n){
    bool* laSoNT = (bool*) malloc((n+1) * sizeof(bool));
    if(laSoNT == NULL){
        printf("Lỗi cấp phát bộ nhớ"); 
        exit(1);
    }

    for(int i = 0; i <= n; i++){    // sửa <= n để gán đủ
        laSoNT[i] = true;
    }
    laSoNT[0] = false;
    laSoNT[1] = false;

    for(int i = 2; i * i <= n; i++){  // tối ưu chỉ chạy đến sqrt(n)
        if(laSoNT[i]){
            for(int j = i * i; j <= n; j += i){
                laSoNT[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(laSoNT[i]){
            printf("%5d", i);
        }
    }
    printf("\n");

    free(laSoNT);
}

int main(){
    int n;
    printf("Nhập n: "); 
    scanf("%d", &n);

    printf("Các số nguyên tố từ 2 đến %d là: ", n);
    sangSoNguyenTo(n);

    return 0;
}
