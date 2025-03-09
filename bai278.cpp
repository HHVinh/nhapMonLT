#include <stdio.h>
#include <stdlib.h>
//	Bài 278: Xóa tất cả các phần tử trùng nhau trong mảng và chỉ giữ lại duy nhất 1 phần tử
// Hàm nhập mảng
void nhapMang(int **arr2, int *n){
    *arr2 = (int*) malloc(*n * sizeof(int));
    if(*arr2 == NULL){
        printf("Lỗi cấp phát bộ nhớ."); 
        exit(1);
    }
    for(int i = 0; i < *n; i++){
        printf("Nhập phần tử %d: ", i+1);
        scanf("%d", &(*arr2)[i]);
    }
}

// Hàm xuất mảng
void xuatMang(int *arr1, int n){
    printf("\nMảng là: ");
    for(int i = 0; i < n; i++){
        printf("%3d", arr1[i]);
    }
}

// Hàm xóa phần tử trùng nhau
void xoaPhanTuTrungNhau(int **arr2, int *n){
    // Sắp xếp mảng theo thứ tự tăng dần (Bubble Sort)
    for(int i = 0; i < *n-1; i++){
        for(int j = i+1; j < *n; j++){
            if((*arr2)[i] > (*arr2)[j]){
                int temp = (*arr2)[i];
                (*arr2)[i] = (*arr2)[j];
                (*arr2)[j] = temp;
            }
        }
    }

    // Đếm số phần tử trùng nhau
    int count = 0;
    for(int i = 1; i < *n; i++){
        if((*arr2)[i] == (*arr2)[i-1]){
            count++;
        }
    }

    // Nếu không có phần tử trùng nhau, chỉ cần thông báo và return
    if(count == 0){
        printf("\nKhông có giá trị trùng nhau.");
        return;
    }

    // Cấp phát mảng mới với kích thước nhỏ hơn
    int *arr1 = (int*) malloc((*n - count) * sizeof(int));
    if(arr1 == NULL){
        printf("Lỗi cấp phát bộ nhớ khi xóa phần tử trùng nhau."); 
        exit(1);
    }

    printf("\nXóa %d phần tử trùng nhau.", count);

    // Lưu các phần tử không trùng vào mảng mới
    arr1[0] = (*arr2)[0];
    int j = 0;
    for(int i = 1; i < *n; i++){
        if((*arr2)[i] != arr1[j]){
            arr1[++j] = (*arr2)[i];
        }
    }

    // Giải phóng mảng cũ và cập nhật lại con trỏ
    free(*arr2);
    *arr2 = arr1;
    *n -= count;
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);

    int *arr = NULL;
    nhapMang(&arr, &n);
    xuatMang(arr, n);

    xoaPhanTuTrungNhau(&arr, &n);
    xuatMang(arr, n);

    free(arr);
    return 0;
}
