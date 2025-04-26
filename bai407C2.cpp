#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuatMang(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i+1) % m == 0){
            printf("\n");
        }
    }
}

// Đổi chỗ
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Phân hoạch
int partition(int *arr, int left, int right){
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[right]);

    return i;
}

// Sắp xếp tăng dần
void quickSort(int *arr, int left, int right){
    if(left < right){
        int mid = partition(arr, left, right);
        quickSort(arr, left, mid - 1);
        quickSort(arr, mid + 1, right);
    }
}

int main(){
    int n, m;
    printf("Nhập số lượng dòng - cột: ");
    scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát.");
        exit(1);
    }

    nhapMang(arr, n, m);

    for(int i = 0; i < n; i++){
        quickSort(arr, i * m, i * m + m - 1);
    }

    printf("\nMa trận sau khi sắp xếp tăng dần từng dòng là: \n");
    xuatMang(arr, n, m);

    free(arr);
    return 0;
}
