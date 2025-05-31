// Viết chương trình cho phép:
// Nhập danh sách liên kết đơn các số nguyên.
// Viết hàm tìm và xóa phần tử có giá trị nhỏ nhất trong danh sách.
// Gợi ý: cần cập nhật cả pHead nếu phần tử nhỏ nhất nằm ở đầu.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Data;
    struct Node* pNext;
} Node;

typedef struct LinkedList {
    Node* pHead;
    Node* pTail;
} LinkedList;

// Khởi tạo danh sách rỗng
void khoiTaoDanhSach(LinkedList* l) {
    l->pHead = NULL;
    l->pTail = NULL;
}

// Tạo node mới
Node* taoNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không cấp phát được bộ nhớ.\n");
        return NULL;
    }
    newNode->Data = x;
    newNode->pNext = NULL;
    return newNode;
}

// Thêm node vào cuối danh sách
void themCuoi(LinkedList* l, int x) {
    Node* newNode = taoNode(x);
    if (newNode == NULL) return;

    if (l->pHead == NULL) {
        l->pHead = l->pTail = newNode;
    } else {
        l->pTail->pNext = newNode;
        l->pTail = newNode;
    }
}

// Hiển thị danh sách
void hienThi(LinkedList l) {
    Node* temp = l.pHead;
    while (temp != NULL) {
        printf("%d -> ", temp->Data);
        temp = temp->pNext;
    }
    printf("NULL\n");
}

// Tìm và xóa phần tử có giá trị nhỏ nhất
void xoaGiaTriNhoNhat(LinkedList* l) {
    if (l->pHead == NULL) {
        return;
    }

    Node* min = l->pHead;
    Node* truocMin = NULL;
    Node* temp = l->pHead;
    Node* truoc = NULL;

    while (temp != NULL) {
        if (temp->Data < min->Data) {
            min = temp;
            truocMin = truoc;
        }
        truoc = temp;
        temp = temp->pNext;
    }

    if (truocMin == NULL) {
        // min là phần tử đầu
        l->pHead = min->pNext;
        if (l->pHead == NULL) {
            l->pTail = NULL;
        }
    } else {
        truocMin->pNext = min->pNext;
        if (min == l->pTail) {
            l->pTail = truocMin;
        }
    }

    free(min);
}

// Hàm main để chạy chương trình
int main() {
    LinkedList l;
    khoiTaoDanhSach(&l);

    int n, x;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhập phần tử %d: ", i + 1);
        scanf("%d", &x);
        themCuoi(&l, x);
    }

    printf("Danh sách ban đầu:\n");
    hienThi(l);

    xoaGiaTriNhoNhat(&l);

    printf("Danh sách sau khi xóa phần tử nhỏ nhất:\n");
    hienThi(l);

    return 0;
}
