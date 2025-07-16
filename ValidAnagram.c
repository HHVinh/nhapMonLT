#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CHAR_RANGE 256

bool isAnagram(char s[], char t[]) {
    // Nếu độ dài khác nhau thì chắc chắn không phải
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int count[CHAR_RANGE] = {0};

    // Đếm ký tự chuỗi s và t
    for (int i = 0; s[i] != '\0'; i++) {
        count[(unsigned char)s[i]]++;
        count[(unsigned char)t[i]]--;
    }

    // Kiểm tra xem tất cả phần tử có về 0 không
    for (int i = 0; i < CHAR_RANGE; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char s[1001], t[1001];

    printf("Nhap chuoi thu nhat: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';  // Xóa ký tự '\n'

    printf("Nhap chuoi thu hai: ");
    fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0';  // Xóa ký tự '\n'

    if (isAnagram(s, t)) {
        printf("=> Hai chuoi la anagram.\n");
    } else {
        printf("=> Hai chuoi KHONG phai la anagram.\n");
    }

    return 0;
}
