// Bài 395: Dịch lên xoay vòng các hàng trong ma trận

#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("%5d", arr[i]);
        if((i + 1) % m == 0){
            printf("\n");
        }
    }
}

void dichLenNhieuHang(int *arr, int n, int m){
    int k; 
    printf("Nhập số lượng dòng cần dịch lên: "); 
    scanf("%d", &k);
    
    if(k < 1){
        printf("Số lượng dòng dịch chuyển không thể âm.");
        return;
    }

    k = k % n;
    if(k == 0) return;

    int *temp = (int*) malloc(k * m * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ."); 
        exit(1);
    }

    // B1: Sao chép k dòng đầu vào mảng tạm
    for(int  i = 0; i < k * m; i++){
        temp[i] = arr[i];
    }

    // B2: Đẩy các dòng còn lại lên đầu
    for(int  i = 0; i < (n - k) * m; i++){
        arr[i] = arr[k * m + i];
    }

    // B3: Dán k dòng đầu vừa cất xuống cuối
    for(int  i = 0; i < k * m; i++){
        arr[(n - k) * m + i] = temp[i];
    }

    free(temp);
}

// Hàm đảo ngược các phần tử từ vị trí left đến right trong mảng 1 chiều
void daoNguoc(int *arr, int left, int right){
    while(left < right){
        // Hoán đổi phần tử ở hai đầu
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // Tiến vào giữa
        left++;
        right--;
    }
}

// Hàm dịch lên k dòng trong ma trận (cách 2: dùng kỹ thuật đảo ngược)
void dichLenNhieuHangCach2(int *arr, int n, int m){
    int k; 
    printf("\nNhập số lượng dòng muốn dịch lên: "); 
    scanf("%d", &k);

    // Đảm bảo số dòng dịch không vượt quá số dòng hiện có
    k = k % n;
    if(k == 0) return; // Nếu không cần dịch thì thoát luôn

    int tongPhanTu = n * m;              // Tổng số phần tử trong ma trận
    int soPhanTu = k * m;                // Số phần tử cần dịch lên (tương ứng với k dòng đầu)

    // Bước 1: Đảo k dòng đầu tiên (từ vị trí 0 đến soPhanTu-1)
    daoNguoc(arr, 0, soPhanTu - 1);

    // Bước 2: Đảo phần còn lại (từ soPhanTu đến hết mảng)
    daoNguoc(arr, soPhanTu, tongPhanTu - 1);

    // Bước 3: Đảo toàn bộ mảng để hoàn thành dịch lên
    daoNguoc(arr, 0, tongPhanTu - 1);
}


int main(){
    int n, m; 
    printf("Nhập số dòng (n) và số cột (m): ");
    scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ"); exit(1);
    }

    nhap(arr, n , m);
    printf("\nMa trận vừa nhập là: \n");
    xuat(arr,n,m);

    if(n < 2){
        printf("\nKhông thể dịch hàng ma trận.");
    } else{
        dichLenNhieuHangCach2(arr, n, m);
        printf("\nMa trận mới là: \n");
        xuat(arr,n,m);
    }

    free(arr);
    return 0;
}