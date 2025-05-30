// Viết hàm sắp xếp danh sách liên kết đơn tăng dần theo giá trị của mỗi node
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

void khoiTaoDSLK(LinkedList* l) {
    l->pHead = l->pTail = NULL;
}

Node* taoNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ\n");
        exit(1);
    }
    newNode->Data = x;
    newNode->pNext = NULL;
    return newNode;
}

void chenCuoiDSLK(LinkedList* l, int x) {
    Node* newNode = taoNode(x);
    if (l->pHead == NULL) {
        l->pHead = l->pTail = newNode;
    } else {
        l->pTail->pNext = newNode;
        l->pTail = newNode;
    }
}

void sapXepTangDan(LinkedList* l) {
    for (Node* i = l->pHead; i != NULL; i = i->pNext) {
        for (Node* j = i->pNext; j != NULL; j = j->pNext) {
            if (i->Data > j->Data) {
                // Hoán đổi giá trị
                int temp = i->Data;
                i->Data = j->Data;
                j->Data = temp;
            }
        }
    }
}

void inDSLK(LinkedList l) {
    Node* temp = l.pHead;
    while (temp != NULL) {
        printf("%d -> ", temp->Data);
        temp = temp->pNext;
    }
    printf("NULL\n");
}

int main() {
    LinkedList l;
    khoiTaoDSLK(&l);

    int n, x;
    printf("Nhap so luong node: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri node %d: ", i + 1);
        scanf("%d", &x);
        chenCuoiDSLK(&l, x);
    }

    printf("\nDanh sach truoc khi sap xep:\n");
    inDSLK(l);

    sapXepTangDan(&l);

    printf("\nDanh sach sau khi sap xep tang dan:\n");
    inDSLK(l);

    return 0;
}
