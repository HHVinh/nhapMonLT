#include <stdio.h>

// Hàm này in ra tên chữ số của một số đơn vị (0-9)
void hangDonVi(int a){
    if (a == 1) {
        printf("một");
    } else if (a == 2) {
        printf("hai");
    } else if (a == 3) {
        printf("ba");
    } else if (a == 4) {
        printf("bốn");
    } else if (a == 5) {
        printf("năm");
    } else if (a == 6) {
        printf("sáu");
    } else if (a == 7) {
        printf("bảy");
    } else if (a == 8) {
        printf("tám");
    } else if (a == 9) {
        printf("chín");
    }
}

// Hàm này in ra cách đọc của một số có 2 chữ số (từ 10 đến 99)
void hangChuc(int b){
    // Trường hợp số có 1 chữ số (0 - 9)
    if(b < 10){
        hangDonVi(b); // Gọi hàm hangDonVi để in chữ số đơn vị
    }
    
    // Trường hợp số từ 10 đến 19
    if(b >= 10 && b < 20){
        if(b == 10){
            printf("mười");  // Đặc biệt, 10 đọc là "mười"
        } else if (b == 15) {
            printf("mười lăm"); // Số 15 có cách đọc đặc biệt là "mười lăm"
        } else {
            printf("mười ");  // Với các số còn lại trong khoảng từ 11 đến 19, ta sẽ luôn bắt đầu với "mười"
            hangDonVi(b%10); // In ra chữ số đơn vị
        }
    }
    
    // Trường hợp số từ 20 đến 99
    if(b >= 20 && b < 100){
        if(b % 10 == 0){
            hangDonVi(b/10); // In ra chữ số hàng chục
            printf(" mươi"); // Với các số chia hết cho 10, ta chỉ cần thêm "mươi"
        }
        else {
            hangDonVi(b/10); // In ra chữ số hàng chục
            if(b % 10 == 1){
                printf(" mươi mốt"); // Trường hợp số có đơn vị là 1, ta đọc là "mươi mốt"
            }
            else if (b % 10 == 5) {
                printf(" mươi lăm"); // Trường hợp số có đơn vị là 5, ta đọc là "mươi lăm"
            }
            else {
                printf(" mươi "); // Trường hợp số có đơn vị khác 1 và 5, ta thêm "mươi"
                hangDonVi(b%10); // In ra chữ số đơn vị
            }
        }    
    }
}

int main() {
    int n;
    printf("Hãy nhập số bất kì: ");
    scanf("%d", &n); // Nhập vào số nguyên từ 0 đến 99
    printf("%d được đọc là: ", n);
    hangChuc(n); // Gọi hàm hangChuc để in cách đọc của số đã nhập
    return 0;
}
