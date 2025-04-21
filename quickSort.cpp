#include <stdio.h>
#include <stdlib.h>

void xuatMang(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%5d", arr[i]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int phanHoach1(int *arr, int left, int right){
    int pivot = arr[left];
    int i = left;
    for(int j = left + 1; j <= right; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[left]);

    return i;
}

int phanHoach2(int *arr, int left, int right){
    
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i],&arr[right]);

    return i;
}

int phanHoach3(int *arr, int left, int right) {
    int pivot = arr[(left + right) / 2];
    int l = left, r = right;

    while (1) {
        while (arr[l] < pivot) l++;
        while (arr[r] > pivot) r--;

        if (l >= r) break;

        swap(&arr[l], &arr[r]);
        l++;
        r--;
    }

    return r;  // Trả về r
}

void quickSort1(int *arr, int left, int right){
    if(left < right){
        int mid = phanHoach1(arr,left,right);
        quickSort1(arr,left, mid - 1);
        quickSort1(arr, mid + 1, right);
    }
}

void quickSort2(int *arr, int left, int right){
    if(left < right){
        int mid = phanHoach2(arr,left,right);
        quickSort2(arr,left, mid - 1);
        quickSort2(arr, mid + 1, right);
    }
}

void quickSort3(int *arr, int left, int right) {
    if (left < right) {
        int mid = phanHoach3(arr, left, right);
        quickSort3(arr, left, mid);
        quickSort3(arr, mid + 1, right);
    }
}

int main(){
    int n = 10;
    int arr[10] = {23, 5, 17, 1, 42, 8, 31, 3, 19, 12};
    int arr1[10] = {23, 5, 17, 1, 42, 8, 31, 3, 19, 12};
    int arr2[10] = {23, 5, 17, 1, 42, 8, 31, 3, 19, 12};

    quickSort1(arr,0,n-1);
    printf("\nMảng Pivot Trái vừa sắp xếp là: \n");
    xuatMang(arr, n);

    quickSort2(arr1,0,n-1);
    printf("\nMảng Pivot phải vừa sắp xếp là: \n");
    xuatMang(arr1, n);

    quickSort3(arr2,0,n-1);
    printf("\nMảng Pivot Giữa vừa sắp xếp là: \n");
    xuatMang(arr2, n);

    return 0;
}