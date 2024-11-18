#include <stdio.h>

int main() {
    int a, b, c;

    // Duyệt qua tất cả các khả năng tờ 1000 đồng (a), 2000 đồng (b), 5000 đồng (c)
    for (a = 0; a <= 200; a++) { // số tờ 1000 đồng từ 0 đến 200 (vì 200000 / 1000 = 200)
        for (b = 0; b <= 100; b++) { // số tờ 2000 đồng từ 0 đến 100 (vì 200000 / 2000 = 100)
            for (c = 0; c <= 40; c++) { // số tờ 5000 đồng từ 0 đến 40 (vì 200000 / 5000 = 40)
                if (a * 1000 + b * 2000 + c * 5000 == 200000) {
                    // In kết quả khi tổng đúng là 200000
                    printf("%d tờ 1000 đồng, %d tờ 2000 đồng, %d tờ 5000 đồng\n", a, b, c);
                }
            }
        }
    }

    return 0;
}
