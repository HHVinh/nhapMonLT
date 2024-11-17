#include <stdio.h>

// Hàm tìm giá trị lớn nhất giữa hai số
int max(int a, int b){
    if(a >= b){
        return a;
    }
    return b;
}

// Hàm tìm giá trị nhỏ nhất giữa hai số
int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}

// Hàm tính Ước số chung lớn nhất (UCLN) của hai số a và b
int UCLN(int a, int b){
    // Nếu một trong hai số chia hết cho số còn lại, trả về giá trị nhỏ hơn
    if (a % b == 0 || b % a == 0) {
        return min(a, b);
    }
    
    // Tính Ước số chung lớn nhất bằng vòng lặp
    int ketQua = 1;
    for (int i = 2; i <= min(a, b) / 2; i++) {
        if (a % i == 0 && b % i == 0) {
            ketQua = i;
        }
    }
    return ketQua;
}

int main(){
    int a, b;
    printf("Nhập hai số a và b bất kì: ");
    scanf("%d %d", &a, &b);

    // Tính và in kết quả UCLN
    int ketQua = UCLN(a, b);
    printf("UCLN của %d và %d là: %d\n", a, b, ketQua);

    return 0;
}




