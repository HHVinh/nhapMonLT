#include <stdio.h>

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

void hangChuc(int b){
    if(b < 10){
        hangDonVi(b);
    }
    if(b >= 10 && b < 20){
        if(b == 10){
            printf("mười");
        } else if (b == 15)
        {
            printf("mười lăm");
        } else {
            printf("mười ");
            hangDonVi(b%10);
        }
    }
    if(b >= 20 && b <100){
        if(b % 10 == 0){
            hangDonVi(b/10);
            printf(" mươi");
        }
        else {
            hangDonVi(b/10);

            if(b % 10 == 1){
                printf(" mươi mốt");
            }
            else if (b % 10 == 5)
            {
                printf(" mươi lăm");
            }
            else {
                printf(" mươi ");
                hangDonVi(b%10);
            }
        }    
    }
}

// Hàm này in ra cách đọc của một số có 3 chữ số (từ 100 đến 999)
void hangTram(int c){
    if (c < 10)
    {
        hangDonVi(c); // Nếu số chỉ có 1 chữ số, gọi hàm hangDonVi
    } 
    else if (c < 100)
    {
        hangChuc(c); // Nếu số có 2 chữ số, gọi hàm hangChuc
    } 
    else if (c < 1000){
        if (c % 100 == 0)
        {
            hangDonVi(c/100); 
            printf(" trăm"); // Nếu số chia hết cho 100, ta in chữ số trăm và "trăm"
        }
        else if (c % 100 < 10)
        {
            hangDonVi(c/100); 
            printf(" trăm lẻ "); // Nếu phần dư là số lẻ (ví dụ 105 -> "một trăm lẻ năm")
            hangDonVi(c % 100);
        }
        else
        {
            hangDonVi(c/100); 
            printf(" trăm "); // Nếu phần dư có 2 chữ số, ta in phần trăm và "trăm"
            hangChuc(c % 100); // Gọi hàm hangChuc để in phần 2 chữ số còn lại
        }
    }
}


int main() {
    int n;
    printf("Hãy nhập số bất kì: ");
    scanf("%d", &n);
    printf("%d được đọc là: ", n);
    hangTram(n);
    return 0;
}
