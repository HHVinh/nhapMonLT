#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("%5d", arr[i]);
        if ((i + 1) % m == 0) printf("\n");
    }
}

// Hàm sao chép biên ma trận vào mảng 1 chiều
void saoChepBien(const int *arr, int *bien, int n, int m) {
    int index = 0;
    
    // Biên trên (trái → phải)
    for (int i = 0; i < m; i++) 
        bien[index++] = arr[i];
    
    // Biên phải (trên → dưới, bỏ góc dưới)
    for (int i = 1; i < n - 1; i++) 
        bien[index++] = arr[i * m + m - 1];
    
    // Biên dưới (phải → trái, nếu có >1 dòng)
    if (n > 1) 
        for (int i = m - 1; i >= 0; i--) 
            bien[index++] = arr[(n - 1) * m + i];
    
    // Biên trái (dưới → trên, bỏ góc trên)
    for (int i = n - 2; i >= 1; i--) 
        bien[index++] = arr[i * m];
}

// Hàm gán lại biên từ mảng 1 chiều vào ma trận
void ganLaiBien(int *arr, const int *bien, int n, int m) {
    int index = 0;
    
    // Biên trên (trái → phải)
    for (int i = 0; i < m; i++) 
        arr[i] = bien[index++];
    
    // Biên phải (trên → dưới, bỏ góc dưới)
    for (int i = 1; i < n - 1; i++) 
        arr[i * m + m - 1] = bien[index++];
    
    // Biên dưới (phải → trái)
    if (n > 1) 
        for (int i = m - 1; i >= 0; i--) 
            arr[(n - 1) * m + i] = bien[index++];
    
    // Biên trái (dưới → trên, bỏ góc trên)
    for (int i = n - 2; i >= 1; i--) 
        arr[i * m] = bien[index++];
}

// Hàm dịch phải mảng 1 chiều k phần tử
void dichPhaiMang(int *bien, int size, int k) {
    k = k % size;
    if (k == 0) return;
    
    int *temp = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) 
        temp[i] = bien[size - k + i];
    
    for (int i = size - 1; i >= k; i--) 
        bien[i] = bien[i - k];
    
    for (int i = 0; i < k; i++) 
        bien[i] = temp[i];
    
    free(temp);
}

void dichPhaiBienMaTran(int *arr, int n, int m, int k) {
    if (n < 2 || m < 2) {
        printf("Ma trận phải có ít nhất 2 dòng và 2 cột!\n");
        return;
    }
    
    int size = 2 * (n + m) - 4;
    k = (k % size + size) % size; // Xử lý k âm
    
    if (k == 0) return;
    
    int *bien = (int*)malloc(size * sizeof(int));
    saoChepBien(arr, bien, n, m);
    dichPhaiMang(bien, size, k);
    ganLaiBien(arr, bien, n, m);
    
    free(bien);
}

int main() {
    int n, m, k;
    printf("Nhập số dòng và cột: ");
    scanf("%d %d", &n, &m);
    
    int *arr = (int*)malloc(n * m * sizeof(int));
    nhap(arr, n, m);
    
    printf("\nMa trận ban đầu:\n");
    xuat(arr, n, m);
    
    printf("\nNhập số lần dịch phải: ");
    scanf("%d", &k);
    
    dichPhaiBienMaTran(arr, n, m, k);
    
    printf("\nMa trận sau khi dịch biên:\n");
    xuat(arr, n, m);
    
    free(arr);
    return 0;
}