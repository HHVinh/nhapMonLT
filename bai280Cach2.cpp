//	Bài 280: Hãy đưa số 1 về đầu mảng không giữ nguyên vị trí
#include <stdio.h>
#include <stdlib.h>

void nhap(int **arr2, int n){
    *arr2 = (int*) malloc(n * sizeof(int));
    if(*arr2 == NULL){
        printf("\nLỗi cấp phát bộ nhớ."); exit(1);
    }
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử A[%d]: ", i+1);
        scanf("%d", &(*arr2)[i]);
    }
}

void xuat(int *arr, int n){
    printf("\nMảng là: ");
    for(int i = 0; i < n; i++){
        printf("%3d", arr[i]);
    }
}

void duaSo1VeDauMangKhongGiuNguyenViTri(int *arr1, int n){
    int left = 0;
    int right = n - 1;
    while (left < right) {
        if (arr1[left] == 1) {
            left++;
        } else if (arr1[right] != 1) {
            right--;
        } else {  // Chỉ hoán đổi khi left chưa phải 1 và right là 1
            int temp = arr1[left];
            arr1[left] = arr1[right];
            arr1[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int *arr;

    nhap(&arr, n);
    xuat(arr, n);

    printf("\nSau khi đưa số 1 về đầu không giữ nguyên vị trí:");
    duaSo1VeDauMangKhongGiuNguyenViTri(arr, n);
    xuat(arr, n);

    free(arr);
    return 0;
}
