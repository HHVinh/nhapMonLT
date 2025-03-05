#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main() { // Dùng mảng 2 chiều
    int **a;
    int n, m;

    printf("Nhập số lượng hàng và cột: ");
    scanf("%d %d", &n, &m);

    // Cấp phát động mảng 2 chiều
    a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    // Nhập mảng 2 chiều
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhập dòng %d cột %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]); // ✅ Lấy địa chỉ của a[i][j]
        }
    }

    // Xuất mảng 2 chiều
    printf("Mảng vừa nhập:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; i++) {
        free(a[i]); // Giải phóng từng hàng
    }
    free(a); // Giải phóng mảng con trỏ

    return 0;
}


// int main(){ // Dùng mảng 1 chiều

//     int n, m;

//     printf("Nhập số lượng hàng và cột: ");
//     scanf("%d %d", &n,&m);
    
//     int a[n][m];

//     int *p = (int *) a;

//     // NHẬP MẢNG 2 chiều bằng con trỏ
//     for(int i = 0; i < n*m; i++){
//         int d = i / m;
//         int c = i % m;

//         printf("Nhập dòng %d cột %d: ", d+1, c+1);
//         scanf("%d", &p[i]);

//     }

//     // NHẬP MẢNG 2 chiều bằng con trỏ như kiểu 1 chiều
//     // for(int i = 0; i < n*m ; i++){
//     //     printf("Nhập phần tử p[%d]: ", i);
//     //     scanf("%d", &p[i]);
//     //     scanf("%d", p + (i * m + j)); // Nghĩa là địa chỉ tại hàng i * cột m + vị trí cụ thể j
//     // }

//     // NHẬP MẢNG
//     // for(int i = 0; i < n; i++){
//     //     for(int j = 0; j < m; j++){
//     //         printf("Nhập phần tử dòng %d cột %d: ", i+1, j+1);
//     //         scanf("%d", &a[i][j]);
//     //     }
//     // }

//     // XUẤT MẢNG
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             // printf("%5d", a[i][j]);
//             // printf("%5d", *(a[i] + j));
//             printf("%5d", *(*(a + i) + j));
//         }
//         printf("\n");
//     }

//     return 0;
// }