// Câu 1 Cho một mảng số nguyên (mảng động), viết hàm xóa các phần tử âm trong mảng
#include <stdio.h>
#include <stdlib.h>

void xoaPhanTuAm(int** arr, int* n) {
    int dem = 0;

    // Đếm số phần tử không âm
    for (int i = 0; i < *n; i++) {
        if ((*arr)[i] >= 0) {
            dem++;
        }
    }

    // Nếu không có phần tử âm thì không cần làm gì
    if (dem == *n) {
        printf("Mảng không có phần tử âm nào. Không cần xóa.\n");
        return;
    }

    // Cấp phát mảng mới chỉ chứa phần tử không âm
    int* temp = (int*)malloc(dem * sizeof(int));
    if (temp == NULL) {
        printf("Lỗi cấp phát bộ nhớ\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < *n; i++) {
        if ((*arr)[i] >= 0) {
            temp[j++] = (*arr)[i];
        }
    }

    free(*arr);      // Giải phóng mảng cũ
    *arr = temp;     // Gán con trỏ mới cho mảng chính
    *n = dem;        // Cập nhật lại số lượng phần tử
}

int main(){
    int n; printf("Nhập số lượng phần tử: "); scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát"); exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("Nhập A[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    xoaPhanTuAm(&arr, &n);
    printf("\nMang sau khi xoa so am la: \n");

    for(int i = 0; i < n; i++){
        printf("%5d", arr[i]);
    }

    free(arr);
    return 0;
}