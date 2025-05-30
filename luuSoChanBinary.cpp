// Viết chương trình tạo file "sochan.dat" chứa các số chẵn từ 2 đến 100 dưới dạng nhị phân.
// Sau đó đọc file và in ra các số
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* f = fopen("sochan.dat", "wb");
    if (f == NULL) {
        printf("Không thể tạo file.\n");
        return 1;
    }

    // Ghi các số chẵn từ 2 đến 100 vào file
    for (int i = 2; i <= 100; i += 2) {
        fwrite(&i, sizeof(int), 1, f);
    }
    fclose(f);

    // Mở lại file để đọc và in ra
    f = fopen("sochan.dat", "rb");
    if (f == NULL) {
        printf("Không thể mở file để đọc.\n");
        return 1;
    }

    int x;
    printf("Các số chẵn từ file:\n");
    while (fread(&x, sizeof(int), 1, f) == 1) {
        printf("%d ", x);
    }

    fclose(f);
    return 0;
}
