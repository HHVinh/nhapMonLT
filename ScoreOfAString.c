#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score_of_string(const char *s) {
    int score = 0;
    for (int i = 0; i < strlen(s) - 1; i++) {
        score += abs(s[i] - s[i + 1]);
    }
    return score;
}

int main() {
    char s[101];
    printf("Nhap chuoi (chi chua chu cai thuong): ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    if (strlen(s) < 2) {
        printf("Chuoi qua ngan.\n");
    } else {
        int result = score_of_string(s);
        printf("Score = %d\n", result);
    }

    return 0;
}
