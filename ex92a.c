#include <stdio.h>

// Hàm tính Ước số chung lớn nhất (UCLN) của hai số a và b
int UCLN(int a, int b){
    while (b != 0)
    {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
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