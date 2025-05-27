#include <stdio.h>
#include <stdlib.h>

void nhapMang(int* arr, int n){
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử A[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void xuatMang(int* arr, int n){
    for(int i = 0; i < n; i++){
        printf("%5d", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InterchangeSort(int* arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void InsertSort(int* arr, int n){
    int pos, x;
    for(int i = 1; i < n; i++){
        x = arr[i];
        pos = i;
        while(pos > 0 && arr[pos - 1] > x){
            arr[pos] = arr[pos - 1];
            pos--;
        }
        arr[pos] = x;
    }
}


void SelectionSort(int* arr, int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(i != minIndex){
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

int Partition(int* arr, int l, int r){
    int midIndex = (l+r) / 2;
    int pivot = arr[midIndex];

    while(l <= r){
        while(arr[l] < pivot) l++;
        while(arr[r] > pivot) r--;

        if(l <= r){
            swap(&arr[l], &arr[r]);
            l++;
            r--;
        }
    }

    return l;
}
void QuickSort(int* arr, int l, int r){
    if(l < r){
        int mid = Partition(arr, l, r);
        QuickSort(arr, l, mid - 1);
        QuickSort(arr, mid, r);
    }
}

int main(){
    int n;
    printf("Nhập n: "); 
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ\n");
        exit(1);
    }

    nhapMang(arr, n);
    printf("\nMảng vừa nhập là: ");
    xuatMang(arr, n);

    QuickSort(arr, 0, n-1);
    printf("\nMảng sau khi sắp xếp là: ");
    xuatMang(arr, n);

    free(arr);
    return 0;
}
