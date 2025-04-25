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

int phanHoachTrai(int *arr, int l, int r){
    int pivot = arr[l];
    int i = l;

    for(int j = l + 1; j <= r; j++){
        if(arr[j] > pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i], &arr[l]);
    return i;
}

void quickSort1(int *arr, int l, int r){
    if(l < r){
        int mid = phanHoachTrai(arr, l, r);
        quickSort1(arr, l, mid - 1);
        quickSort1(arr, mid + 1, r);
    }
}

int phanHoachPhai(int *arr, int l, int r){
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(arr[j] > pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[r]);

    return i;
}

void quickSort2(int *arr, int l, int r){
    if(l < r){
        int mid = phanHoachPhai(arr,l,r);
        quickSort2(arr, l, mid - 1);
        quickSort2(arr, mid + 1, r);
    }
}

int phanHoachGiua(int *arr, int left, int right){
    int pivot = arr[(left+right) / 2];
    int l = left, r = right;

    while(1){
        while(arr[l] > pivot) l++;
        while(arr[r] < pivot) r--;
        if(l >= r) break;
        swap(&arr[l], &arr[r]);
        l++;
        r--;
    }
    return r;
}

void quickSort3(int *arr, int l, int r){
    if(l < r){
        int mid = phanHoachGiua(arr,l,r);
        quickSort3(arr,l,mid);
        quickSort3(arr,mid + 1, r);
    }
}

int main(){
    int n = 10;
    int arr1[10] = {23, 5, 17, 1, 42, 8, 31, 3, 19, 12};
    int arr2[10] = {23, 5, 17, 1, 42, 8, 31, 3, 19, 12};
    int arr3[10] = {23, 5, 17, 1, 42, 8, 31, 3, 19, 12};

    quickSort1(arr1,0,n-1);
    printf("\nMảng Pivot Trái vừa sắp xếp giảm là: \n");
    xuatMang(arr1, n);

    quickSort2(arr2,0,n-1);
    printf("\nMảng Pivot Phải vừa sắp xếp giảm là: \n");
    xuatMang(arr2, n);

    quickSort3(arr3,0,n-1);
    printf("\nMảng Pivot Giữa vừa sắp xếp giảm là: \n");
    xuatMang(arr3, n);

    return 0;
}