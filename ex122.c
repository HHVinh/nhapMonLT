#include <stdio.h>

// Hàm nhập mảng
void NhapMang(int a[100], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhập giá trị tại vị trí A[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

// Hàm in mảng
void InMang(int a[100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm tìm giá trị lớn nhất trong mảng
int GiaTriLonNhat(int a[100], int n) {
    int GiaTriMax = a[0]; // Khởi tạo giá trị lớn nhất là phần tử đầu tiên
    for (int i = 1; i < n; i++) { // Bắt đầu từ phần tử thứ 2
        if (a[i] > GiaTriMax) {
            GiaTriMax = a[i];
        }
    }
    return GiaTriMax;
}

int GiaTriNhoNhat(int a[100], int n){
    int Min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (Min > a[i])
        {
            Min = a[i];
        }  
    }
    return Min;
}

int main() {
    int a[100];
    int n;

    // Nhập số lượng phần tử
    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", &n);

    // Nhập mảng
    NhapMang(a, n);

    // In mảng (nếu cần kiểm tra)
    printf("Mảng vừa nhập: ");
    InMang(a, n);

    // Tìm giá trị lớn nhất
    int max = GiaTriLonNhat(a, n);
    int min = GiaTriLonNhat(a, n);
    printf("Giá trị lớn nhất trong mảng: %d\n", max);
    printf("Giá trị nhỏ nhất trong mảng: %d\n", min);

    return 0;
}
