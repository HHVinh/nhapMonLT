// Bài 370: Tìm giá trị âm lớn nhất trong ma trận
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i/m, i%m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr,int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i + 1) % m == 0){
            printf("\n");
        }
    }
}

int timSoAmLonNhat(int *arr, int n, int m){
    int size = n*m;
    int *temp = (int*) malloc((size+1) * sizeof(int));
    if( temp == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    for(int i = 0; i <n*m; i++){
        temp[i] = arr[i];
    }
    temp[size] = INT_MIN;

    int min = INT_MIN;
    int daGapSoAm = 0;
    int i = 0;
    while(temp[i] != INT_MIN){
        if(temp[i] < 0){
            if(!daGapSoAm){ // Nếu chưa có số âm nào thì temp[i] là số đầu tiên
                min = temp[i];
                daGapSoAm = 1;
            } else if(temp[i] > min){ // Nếu đã có số âm trước, thì temp[i] phải > min hiện tại
                min = temp[i];
            }
        }
        i++;
    }
    
    free(temp);
    
    if(!daGapSoAm){
        return 0; // Không có số âm nào
    }
    return min;
}

int main(){

    int n, m;
    printf("Nhập số dòng và cột: "); scanf("%d%d", &n,&m);

    int *arr = (int*) malloc((n*m +1) *sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    printf("\n Ma trận vừa nhập là: \n");
    xuat(arr, n, m);

    int ketQua = timSoAmLonNhat(arr, n,m);
    if(ketQua == 0){
        printf("\nTrong ma trận không có số âm.");
    } else{
        printf("\n Số âm lớn nhất trong ma trận là %d.", ketQua);
    }

    free(arr);
    return 0;
}

