// Chèn số 0 vào sau các phần tử lẻ có trong mảng 1 chiều số nguyên dương cấp phát động
#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử A[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void xuatMang(int *arr, int n){
    for(int i = 0; i < n ; i++){
        printf("%5d", arr[i]);
    }
    printf("\n");
}

// Chèn 0 sau các phần tử lẻ
void chen0SauPhanTuLe(int** arr, int* n){
    int soPhanTuLe = 0;

    // Đếm số phần tử lẻ
    for(int i = 0; i < *n; i++){
        if((*arr)[i] % 2 != 0){
            soPhanTuLe++;
        }
    }

    // Nếu không có phần tử lẻ thì không làm gì
    if(soPhanTuLe == 0){
        printf("\nMảng không có phần tử lẻ nên giữ nguyên là:\n");
        return;
    }

    // Cấp phát mảng mới đủ chỗ
    int* temp = (int*) malloc((*n + soPhanTuLe) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }

    // Chèn phần tử và 0
    int k = 0;
    for(int i = 0; i < *n; i++){
        temp[k++] = (*arr)[i];
        if((*arr)[i] % 2 != 0){
            temp[k++] = 0;
        }
    }

    // Giải phóng mảng cũ và cập nhật mảng mới
    free(*arr);
    *arr = temp;
    *n = *n + soPhanTuLe;

    printf("\nMảng sau khi chèn 0 sau các phần tử lẻ là:\n");
}

int main(){
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ!\n");
        return 1;
    }

    nhapMang(arr, n);

    printf("\nMảng ban đầu là:\n");
    xuatMang(arr, n);

    chen0SauPhanTuLe(&arr, &n);
    xuatMang(arr, n);

    free(arr);
    return 0;
}
