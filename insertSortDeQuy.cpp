#include <stdio.h>
#include <stdlib.h>

int timMinIndex(int* arr, int start, int n){
    int minIndex = start;
    for(int i = start + 1; i < n; i++){
        if(arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }
    return minIndex;
}

void bai3(int* arr, int n, int index){
    if(index >= n-1) return;
    int minIndex = timMinIndex(arr, index, n);

    if(arr[minIndex] != index){
        int temp  = arr[index];
        arr[index] = arr[minIndex];
        arr[minIndex] = temp;
    }

    bai3(arr, n, index + 1);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inHoanVi(int* arr, int n){
    for(int i = 0; i<n; i++){
        printf("%5d", arr[i]);
    }
    printf("\n");
}

void sinhHoanVi(int* arr, int left, int right){
    if(left == right){
        inHoanVi(arr, right);
        return;
    }
    for(int i = left; i < right; i++){
        swap(&arr[i], &arr[left]);
        sinhHoanVi(arr, left + 1, right);
        swap(&arr[left], &arr[i]);
    }

}