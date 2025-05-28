// Câu 3. Viết hàm phát sinh hoán vị của N phần tử từ 1 đến N
#include <stdio.h>
// Hàm hoán đổi 2 giá trị
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Hàm in mảng hiện tại
void inHoanVi(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Hàm đệ quy sinh hoán vị
void sinhHoanVi(int* arr, int left, int right) {
    if (left == right) {
        inHoanVi(arr, right);
        return;
    }

    for (int i = left; i < right; i++) {
        swap(&arr[left], &arr[i]);                 // Hoán đổi
        sinhHoanVi(arr, left + 1, right);          // Gọi đệ quy
        swap(&arr[left], &arr[i]);                 // Quay lui (backtrack)
    }
}

int main() {
    int n;
    printf("Nhập N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("N phải > 0\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Các hoán vị của %d phần tử:\n", n);
    sinhHoanVi(arr, 0, n);

    return 0;
}

