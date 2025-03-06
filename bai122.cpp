#include <stdio.h>
#include<stdlib.h>

void nhapMang(int **a, int n){
    *a = (int*) malloc(n * sizeof(int));
    if(*a == NULL){
        printf("Lỗi cấp phát bộ nhớ");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử %d: ", i+1);
        scanf("%d", &(*a)[i]);
    }
}

void xuatMang(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("\nPhần tử thứ %d là: %d\n", i+1 ,a[i]);
    }
}

int giaTriLonNhat(int *a, int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

// Hàm tìm giá trị lớn nhất trong mảng dùng con trỏ
int giaTriLonNhat2(int *a, int n) {
    int *max = a; // Con trỏ `max` trỏ đến phần tử đầu tiên của mảng

    for (int *p = a + 1; p < a + n; p++) { // Duyệt mảng bằng con trỏ
        if (*p > *max) { // So sánh giá trị tại con trỏ `p` với giá trị tại `max`
            max = p; // Nếu `*p` lớn hơn `*max`, cập nhật `max` trỏ đến `p`
        }
    }

    return *max; // Trả về giá trị lớn nhất của mảng
}

int main(){
    
    int n;
    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", &n);

    int *a = NULL;
    nhapMang(&a,n);
    xuatMang(a,n);
    int KQ = giaTriLonNhat(a,n);
    int KQ2 = giaTriLonNhat2(a,n);

    printf("\nGiá trị lớn nhất của mảng CÁCH 1 là: %d", KQ);
    printf("\nGiá trị lớn nhất của mảng CÁCH 2 là: %d", KQ);

    free(a);
    return 0;
}