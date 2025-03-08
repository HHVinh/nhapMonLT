#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Hàm kiểm tra số nguyên tố
int kiemTraSoNT(int n){
    if (n < 2) return 0;
    for(int i = 2; i <= (int)sqrt(n); i++){  // Sửa dấu < thành <=
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);

    // Cấp phát bộ nhớ động cho mảng
    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL){
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    // Nhập giá trị cho mảng
    for (int i = 0; i < n; i++){
        printf("Nhập phần tử %d: ", i+1);
        scanf("%d", &arr[i]);  // Sửa lại lỗi nhập phần tử
    }

    // Đếm số nguyên tố trong mảng
    int count = 0;
    for (int i = 0; i < n; i++){
        if (kiemTraSoNT(arr[i]) == 1){
            count++;
        }
    }

    // Kiểm tra xem có số nguyên tố nào không
    if (count == 0){
        printf("Không có số nguyên tố nào trong mảng.\n");
    } 
    else {
        printf("\nXóa %d số nguyên tố trong mảng.", count);

        // Xóa số nguyên tố và cập nhật mảng gốc mà không cần cấp phát mới
        int j = 0;
        for (int i = 0; i < n; i++){
            if (kiemTraSoNT(arr[i]) != 1){
                arr[j] = arr[i];
                j++;  // Tăng j khi gán giá trị
            }
        }
        
        n -= count;  // Cập nhật kích thước mới của mảng
    }

    // In mảng sau khi xóa số nguyên tố
    printf("\nMảng sau khi xóa số nguyên tố: ");
    for (int i = 0; i < n; i++){
        printf("%3d", arr[i]);
    }

    // Giải phóng bộ nhớ
    free(arr);

    return 0;
}
