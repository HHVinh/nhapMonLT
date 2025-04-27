#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *arr, int n, int m) {
    for(int i = 0; i < n*m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuatMang(int *arr, int n, int m) {
    for(int i = 0; i < n*m; i++) {
        printf("%5d", arr[i]);
        if((i+1) % m == 0) {
            printf("\n");
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++) {
        if(arr[j] > pivot) { // Sắp giảm dần
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[r]);
    return i;
}

void quickSort(int *arr, int l, int r) {
    if(l < r) {
        int mid = partition(arr, l, r);
        quickSort(arr, l, mid - 1);
        quickSort(arr, mid + 1, r);
    }
}

void xuatGiaTriChanGiamDan(int *arr, int n, int m) {
    int soPhanTuChan = 0;

    // Đếm số phần tử chẵn
    for(int i = 0; i < n*m; i++) {
        if(arr[i] % 2 == 0) {
            soPhanTuChan++;
        }
    }

    if(soPhanTuChan == 0) {
        printf("Không có phần tử chẵn nào.\n");
        return;
    }

    // Cấp phát mảng phụ chứa số chẵn
    int *temp = (int*) malloc(soPhanTuChan * sizeof(int));
    if(temp == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }

    int j = 0;
    for(int i = 0; i < n*m; i++) {
        if(arr[i] % 2 == 0) {
            temp[j++] = arr[i];
        }
    }

    // Sắp xếp giảm dần
    quickSort(temp, 0, soPhanTuChan - 1);

    // Xuất mảng temp
    printf("Các phần tử chẵn theo thứ tự giảm dần:\n");
    for(int i = 0; i < soPhanTuChan; i++) {
        printf("%5d", temp[i]);
    }
    printf("\n");

    free(temp);
}

int main() {
    int n, m;
    printf("Nhập số lượng dòng và cột: ");
    scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ!\n");
        exit(1);
    }

    nhapMang(arr, n, m);

    printf("\nMa trận vừa nhập:\n");
    xuatMang(arr, n, m);

    printf("\n");
    xuatGiaTriChanGiamDan(arr, n, m);

    free(arr);
    return 0;
}
