// Viết hàm đệ quy để đảo ngược một chuỗi ký tự char*. Không dùng hàm strrev
#include <stdio.h>
#include <string.h>

// Hàm đệ quy để đảo chuỗi
void daoChuoi(char* str, int left, int right) {
    if (left >= right) return;

    // Hoán đổi 2 ký tự ở vị trí trái và phải
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    // Gọi đệ quy cho phần giữa
    daoChuoi(str, left + 1, right - 1);
}

int main() {
    char s[100];
    printf("Nhập chuỗi: ");
    fgets(s, sizeof(s), stdin);

    // Xóa ký tự newline nếu có
    s[strcspn(s, "\n")] = '\0';

    int len = strlen(s);
    daoChuoi(s, 0, len - 1);

    printf("Chuỗi sau khi đảo: %s\n", s);
    return 0;
}

