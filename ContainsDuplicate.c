#include <stdio.h>
#include <stdbool.h>

bool containsDuplicate(int nums[], int n) {
    // Dùng mảng đánh dấu giá trị từ 1 đến 1000
    int seen[1001] = {0};

    for (int i = 0; i < n; i++) {
        if (seen[nums[i]] == 1) {
            return true;
        }
        seen[nums[i]] = 1;
    }

    return false;
}

int main() {
    int nums[1000];
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n < 1 || n > 1000) {
        printf("So luong khong hop le.\n");
        return 1;
    }

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (containsDuplicate(nums, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
