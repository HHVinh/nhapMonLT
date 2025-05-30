// Kiểm tra chuỗi có đối xứng không?
#include <stdio.h>
#include <string.h>
#include <ctype.h> // Nếu muốn bỏ qua chữ hoa/thường hoặc khoảng trắng

// Hàm đệ quy kiểm tra chuỗi đối xứng
int kiemTraChuoiDoiXung(char str[], int left, int right) {
    if (left >= right) return 1; // Đã kiểm tra hết, đối xứng
    if (str[left] != str[right]) return 0; // Ký tự không giống nhau -> không đối xứng
    return kiemTraChuoiDoiXung(str, left + 1, right - 1); // Kiểm tra tiếp phần trong
}

// Nếu kiểm tra số đối xứng thì chuyển số thành chuỗi
int laSoDoiXung(int n) {
    char str[20];
    sprintf(str, "%d", n); // Chuyển số thành chuỗi
    return kiemTraChuoiDoiXung(str, 0, strlen(str) - 1);
}


int main() {
    char chuoi[100];
    
    printf("Nhap chuoi: ");
    gets(chuoi); // Hoặc dùng fgets(chuoi, sizeof(chuoi), stdin);

    int len = strlen(chuoi);
    
    if (kiemTraChuoiDoiXung(chuoi, 0, len - 1)) {
        printf("La chuoi doi xung.\n");
    } else {
        printf("Khong phai chuoi doi xung.\n");
    }

    int so;
    printf("Nhap so: ");
    scanf("%d", &so);

    if (laSoDoiXung(so)) {
        printf("La so doi xung.\n");
    } else {
        printf("Khong phai so doi xung.\n");
    }
    
    return 0;
}
