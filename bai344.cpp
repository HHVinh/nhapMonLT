// Bài 344(*): Đếm số lượng giá trị phân biệt có trong ma trận các số thực. 
// Chú ý: Nếu có k phần tử (k >= 1) trong ma trận bằng nhau thì ta chỉ tính là 1

#include <stdio.h>
#include <stdlib.h>

// Hàm nhập ma trận
void nhap(float *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhập phần tử A[%d][%d]: ", i, j);
            scanf("%f", &arr[i * m + j]);
        }
    }
}

// Hàm xuất ma trận
void xuat(float *arr, int n, int m) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%8.2f", arr[i * m + j]);
        }
        printf("\n");
    }
}

// Hàm đếm số lượng giá trị phân biệt trong ma trận
int demGiaTriPhanBiet(float *arr, int n, int m) {
    int dem = 0;
    
    for (int i = 0; i < n * m; i++) {
        int daDem = 0; // Biến kiểm tra xem giá trị này đã được tính chưa
        
        // Kiểm tra từ đầu đến phần tử trước đó xem đã có chưa
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                daDem = 1; // Đã xuất hiện trước đó
                break;
            }
        }
        
        if (!daDem) { // Nếu chưa xuất hiện, tăng biến đếm
            dem++;
        }
    }

    return dem;
}

int main() {
    int n, m;
    printf("Nhập số dòng và số cột: ");
    scanf("%d %d", &n, &m);

    float *arr = (float *)malloc(n * m * sizeof(float));
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    int ketQua = demGiaTriPhanBiet(arr, n, m);
    printf("\nSố lượng giá trị phân biệt trong ma trận là: %d\n", ketQua);

    free(arr);
    return 0;
}
