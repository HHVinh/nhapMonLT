// Bài 316: Kiểm tra ma trận có số chẵn nhỏ hơn 2015 không? (kèm đếm số lượng)
#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i/m, i%m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    printf("\nMa trận là: \n");
    for(int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i+1) % m == 0) printf("\n");
    }
}

void kiemTraCoSoChanNhoHon2015(int *arr, int n, int m){
    int count = 0;
    
    printf("\nCác số chẵn nhỏ hơn 2015 trong ma trận là: ");
    for(int i = 0; i < n*m; i++){
        if(arr[i] % 2 == 0 && arr[i] < 2015){
            printf("%5d", arr[i]);
            count++;
        }
    }

    if (count == 0) {
        printf("Không có số chẵn nhỏ hơn 2015.");
    } else {
        printf("\nTổng số lượng số chẵn nhỏ hơn 2015 là: %d", count);
    }
}

int main(){
    int n, m; 
    printf("Nhập n dòng và m cột: "); 
    scanf("%d %d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    xuat(arr, n, m);
    kiemTraCoSoChanNhoHon2015(arr, n, m);

    free(arr);
    return 0;
}
