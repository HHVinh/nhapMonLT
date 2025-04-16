// Bài 396: Dịch trái xoay vòng các cột trong ma trận

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

void daoNguoc(int *arr, int left, int right){
    while(left < right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

int xoayTraiNhieuCot(int *arr, int n, int m){
    if(m < 1){
        printf("Số lượng cột ma trận phải lớn hơn 1.");
        return 0;
    }

    int k;
    printf("Nhập số cột cần xoay trái: ");
    scanf("%d", &k);

    if(k < 1){
        printf("Số lượng cột xoay trái không thể âm.");
        return 0;
    }

    // Đảm bảo k không lớn hơn m
    k = k % m;
    if(k == 0) return 1;  // Xoay k = 0 thì không cần làm gì

    // Với mỗi hàng trong ma trận
    for(int i = 0; i < n; i++){
        /*
            Ý tưởng: Xoay trái k phần tử đầu tiên trong hàng
            bằng cách áp dụng kỹ thuật "đảo 3 lần":
            Ví dụ: A B C D E F, xoay trái 2 phần tử (k = 2)
            Bước 1: đảo A B      → B A C D E F
            Bước 2: đảo C → F    → B A F E D C
            Bước 3: đảo cả dòng  → C D E F A B  ✅ Kết quả đúng
        */

        // Đảo k phần tử đầu tiên (từ chỉ số i*m đến i*m + k - 1)
        daoNguoc(arr, i * m, i * m + k - 1);

        // Đảo phần còn lại (từ i*m + k đến i*m + m - 1)
        daoNguoc(arr, i * m + k, i * m + m - 1);

        // Đảo toàn bộ dòng (từ i*m đến i*m + m - 1)
        daoNguoc(arr, i * m, i * m + m - 1);
    }

    return 1;
}


int main(){

    int n, m; printf("Nhập số lượng dòng và cột: "); scanf("%d%d", &n,&m);
    
    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ."); exit(1);
    }

    nhap(arr,n,m);
    printf("\nMa trận vừa nhập là: \n");
    xuat(arr, n, m);

    if(xoayTraiNhieuCot(arr,n,m)){
        printf("\nMa trận sau khi xoay trái là: \n");
        xuat(arr, n, m);
    }

    free(arr);
    return 0;
    
}