// Bài 319: Viết hàm sắp xếp ma trận các số thực tăng dần từ trên xuống dưới và từ trái sang phải
#include <stdio.h>
#include <stdlib.h>

void nhapMang(float** arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Nhập phần tử A[%d][%d]: ", i, j);
            scanf("%f", &arr[i][j]);
        }
    }
}

void xuatMang(float** arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%8.2f", arr[i][j]);
        }
        printf("\n");
    }
}

void sapXepTangDan(float** arr, int n, int m){
    // Thêm mảng phụ 1 chiều
    float* arr2 = (float*) malloc(n * m * sizeof(float));
    if(arr2 == NULL){
        printf("Lỗi"); return;
    }
    // Chuyển mảng 2 chiều thành 1 chiều
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr2[k++] = arr[i][j];
        }
    }
    // Sắp xếp tăng dần
    for(int i = 0; i < n*m - 1; i++){
        for(int j = i + 1; j < n*m; j++){
            if(arr2[i] > arr2[j]){
                float temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }
    // Chuyển về mảng 2 chiều
    k = 0;
    for(int j = 0; j < m; j++){ // Cột ngoài
        for(int i = 0; i < n; i++){ // Hàng trong
            arr[i][j] = arr2[k++];
        }
    }

    free(arr2);
}

int main(){

    int n, m;
    printf("Nhập số lượng dòng, cột: ");
    scanf("%d%d", &n,&m);
    

    float** arr = (float**) malloc(n * sizeof(float*));
    if(arr == NULL){
        printf("Lỗi!");
        return 1;
    }

    for(int i = 0; i < n; i++){
        arr[i] = (float*) malloc(m * sizeof(float));
        if(arr[i] == NULL){
        printf("Lỗi!");
        for(int j = 0; j < n; j++){
            free(arr[j]);
        }
        free(arr);
        return 1;
        }
    }

    nhapMang(arr, n, m);
    

    sapXepTangDan(arr, n, m); 
    printf("Ma trận vừa sắp xếp là: \n");
    xuatMang(arr, n, m);
    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}