// Bài 375: Tìm số chẵn lớn nhất
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i/m, i%m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i+1) % m == 0) printf("\n");
    }
}

int timSoChanLonNhat(int *arr, int n, int m){
    int size = n * m;

    // Tạo mảng mới có thêm 1 phần tử cho lính canh
    int *temp = (int*) malloc((size + 1) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát.\n");
        exit(1);
    }

    // Sao chép dữ liệu
    for(int i = 0; i < size; i++){
        temp[i] = arr[i];
    }

    // Đặt lính canh cuối mảng
    temp[size] = INT_MIN; // không phải số chẵn, không ảnh hưởng đến kết quả

    int maxChan = INT_MIN;
    int daTimThay = 0;
    int i = 0;

    while(temp[i] != INT_MIN){
        if(temp[i] % 2 == 0){
            if(!daTimThay || temp[i] > maxChan){
                maxChan = temp[i];
                daTimThay = 1;
            }
        }
        i++;
    }

    free(temp);

    if(daTimThay)
        return maxChan;
    else
        return -1;
}

int main(){
    int n, m;
    printf("Nhập số dòng và cột: ");
    scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    nhap(arr, n, m);
    printf("\nMa trận vừa nhập:\n");
    xuat(arr, n, m);

    int kq = timSoChanLonNhat(arr, n, m);
    if(kq != -1)
        printf("\nSố chẵn lớn nhất trong ma trận là: %d\n", kq);
    else
        printf("\nKhông có số chẵn nào trong ma trận.\n");

    free(arr);
    return 0;

}
