#include <stdio.h>
#include <stdlib.h>

int tinhTong(int n){
    if(n == 0){
        return 0;
    }

    int kq = tinhTong(n-1) + n;
    return kq;
}

int Fibonacy(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    return Fibonacy(n-1) + Fibonacy(n-2);
}

// 1 vi khuẩn sau 2h là x2, ban đầu có 2 con thì sau 5h là?
int viKhuan(int h){
    if(h == 0){
        return 2;
    }
    // Các giờ sau = giờ trước đó *2
    int kq = viKhuan(h-1) * 2;
    return kq;
}

// Gửi 1000USD lãi suất 12%, sau 30 năm số tiền là bao nhiêu?
float tien(int n){
    if(n == 0){
        return 1000;
    }

    return (float) tien(n-1) * 112 / 100;
}

// Tìm vị trí X trong 1 dãy xếp tăng
int timViTriX(int *arr, int n, int left, int right, int x) {
    if (left > right) {
        return -1;  // Không tìm thấy
    }

    int mid = (left + right) / 2;

    if (arr[mid] == x) {
        return mid;  // Trả về vị trí tìm thấy
    } else if (arr[mid] > x) {
        return timViTriX(arr, n, left, mid - 1, x);  // Tìm bên trái
    } else {
        return timViTriX(arr, n, mid + 1, right, x); // Tìm bên phải
    }
}

void nhapMang(int** arr, int n){
    *arr = (int*) malloc(n * sizeof(int));
    if(*arr == NULL){
        printf("Lỗi cấp phát bộ nhớ!"); exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("Nhập phần tử A[%d]: ", i);
        scanf("%d", &((*arr)[i]));
    }
}

void xuatMang(int* arr, int n){
    for(int i = 0; i < n; i++){
        printf("%5d", arr[i]);
    }
    printf("\n");
}

// Tìm số hoán vị từ 1 đến n
void hoanDoi(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm đệ quy để sinh hoán vị
void sinhHoanVi(int* arr, int n, int i) {
    if (i == n) {
        // In ra hoán vị hiện tại
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
        return;
    }

    for (int j = i; j < n; j++) {
        hoanDoi(&arr[i], &arr[j]);
        sinhHoanVi(arr, n, i + 1);
        hoanDoi(&arr[i], &arr[j]); // Hoàn tác (backtrack)
    }
}

// Chuyển đĩa từ A sang C, có 3 vị trí A, B, C, mỗi lần 1 đĩa và đĩa nhỏ trên lớn dưới
void chuyenDia(int n, char cotNguon, char cotTrungGian, char cotDich) {
    if (n == 1) {
        printf("Chuyển đĩa 1 từ %c sang %c\n", cotNguon, cotDich);
        return;
    }

    // Bước 1: Chuyển n-1 đĩa từ nguồn sang trung gian
    chuyenDia(n - 1, cotNguon, cotDich, cotTrungGian);

    // Bước 2: Chuyển đĩa còn lại sang đích
    printf("Chuyển đĩa %d từ %c sang %c\n", n, cotNguon, cotDich);

    // Bước 3: Chuyển n-1 đĩa từ trung gian sang đích
    chuyenDia(n - 1, cotTrungGian, cotNguon, cotDich);
}

int main() {
    int n;
    printf("Nhập số đĩa: ");
    scanf("%d", &n);

    printf("Các bước chuyển:\n");
    chuyenDia(n, 'A', 'B', 'C');

    return 0;
}