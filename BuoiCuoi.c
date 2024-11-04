#include <stdio.h>

void GhiTapTin() {
    FILE *fp = fopen("/Users/vinh/Documents/nhapMonLT/myfile.txt", "wt");
    if (fp == NULL) {
        printf("Mo tap tin khong thanh cong");
    } else {
        int a = 100;
        fprintf(fp, "Gia tri la %d", a);
        fclose(fp);
        printf("Ghi file thanh cong\n");
    }
}

void DocTapTin() {
    FILE *fp = fopen("/Users/vinh/Documents/nhapMonLT/myfile.txt", "rt");
    if (fp == NULL) {
        printf("Mo tap tin khong thanh cong");
    } else {
        char ch;
        while ((ch = fgetc(fp)) != EOF){
            printf("%c", ch);
        }
        fclose(fp);
    }
}

void DocTapTin2() {
    FILE *fp = fopen("/Users/vinh/Documents/nhapMonLT/myfile.txt", "rt");
    if (fp == NULL) {
        printf("Mo tap tin khong thanh cong");
    } else {
        char s[20];
        while ((fgets(s, 20, fp)) != NULL){
            printf("%s", s);
        }
        fclose(fp);
    }
}

int main() {
    DocTapTin2();
    return 0;
}
