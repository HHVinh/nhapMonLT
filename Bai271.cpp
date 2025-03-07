#include <stdio.h>
#include <stdlib.h>
//	Bài 271: Xóa phần tử có chỉ số k trong mảng
void nhapMang(int **p, int n){
    *p = (int*) malloc(n * sizeof(int));
    if(*p == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("Nhập phần tử %d: ", i+1);
        scanf("%d", &(*p)[i]);
    }
}

void xuatMang(int *p, int n){
    printf("Mảng là: ");
    for(int i = 0; i < n; i++){
        printf("%3d", p[i]);
    }
    printf("\n");
}

void xoaPhanTu(int **p, int *n, int k) {
    if (k < 0 || k >= *n) { // Kiểm tra nếu k không hợp lệ
        printf("Vị trí không hợp lệ!\n");
        return;
    }

    int *pb = (int*) malloc((*n - 1) * sizeof(int));
    if (pb == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }

    // Copy các phần tử trước vị trí k
    for (int i = 0; i < k; i++) {
        pb[i] = (*p)[i];
    }

    // Copy các phần tử sau vị trí k
    for (int i = k; i < *n - 1; i++) {
        pb[i] = (*p)[i + 1];
    }

    free(*p);  // Giải phóng vùng nhớ cũ
    *p = pb;   // Gán con trỏ mới cho p
    (*n)--;    // Giảm kích thước mảng
}


int main() {
    
    int n;
    printf("Nhập số lượng phần tử mảng: ");
    scanf("%d", &n);

    int *p = NULL;
    nhapMang(&p, n);
    xuatMang(p, n);

    int k;
    printf("Nhập vị trí cần xóa (0 đến %d): ", n - 1);
    scanf("%d", &k);

    xoaPhanTu(&p, &n, k); // Gửi địa chỉ của `n` để cập nhật số lượng phần tử
    xuatMang(p, n);

    free(p);
    return 0;
}
