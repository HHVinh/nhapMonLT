// Viết hàm chèn node mới vào vị trí k bất kỳ trong danh sách liên kết đơn.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *pNext;
} Node;

typedef struct {
    Node *pHead;
    Node *pTail;
} LinkedList;

// Hàm chèn node mới vào vị trí k (vị trí bắt đầu từ 1)
void chenGiuaDSLK(LinkedList *l, Node* newNode, int k) {
    if (k < 1) {
        printf("Vi tri khong hop le\n");
        return;
    }

    // Nếu danh sách rỗng
    if (l->pHead == NULL) {
        if (k == 1) {
            l->pHead = l->pTail = newNode;
            newNode->pNext = NULL;
        } else {
            printf("Vi tri khong hop le\n");
        }
        return;
    }

    // Chèn ở đầu danh sách
    if (k == 1) {
        newNode->pNext = l->pHead;
        l->pHead = newNode;
        return;
    }

    // Duyệt tới vị trí k-1
    int demNode = 1;
    Node* temp = l->pHead;
    while (temp != NULL && demNode < k - 1) {
        temp = temp->pNext;
        demNode++;
    }

    // Nếu vị trí không tồn tại
    if (temp == NULL) {
        printf("Vi tri khong hop le\n");
        return;
    }

    // Chèn vào giữa hoặc cuối
    newNode->pNext = temp->pNext;
    temp->pNext = newNode;

    // Cập nhật pTail nếu chèn vào cuối
    if (newNode->pNext == NULL) {
        l->pTail = newNode;
    }
}

Node* taoNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->pNext = NULL;
    return newNode;
}

int main() {
    LinkedList list = {NULL, NULL};

    // Thêm vài node
    chenGiuaDSLK(&list, taoNode(10), 1);
    chenGiuaDSLK(&list, taoNode(20), 2);
    chenGiuaDSLK(&list, taoNode(15), 2); // chèn vào giữa

    // In danh sách
    Node* temp = list.pHead;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->pNext;
    }
    printf("NULL\n");

    return 0;
}
