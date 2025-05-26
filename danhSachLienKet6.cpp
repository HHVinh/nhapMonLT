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

Node* taoNode(int x){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Loi"); exit(1);
    }

    newNode->Data = x;
    newNode->pNext = NULL;

    return newNode;
}

void khoiTaoDSLK(LinkedList *l){
    l->pHead = NULL;
    l->pTail = NULL;
}

void themCuoiDSLK(LinkedList *l, Node* newNode){
    if(l->pHead == NULL){
        l->pHead = l->pTail = newNode;
    } else {
        l->pTail->pNext = newNode;
        l->pTail = newNode;
    }
}

void xuatDSLK(LinkedList *l){
    if(l->pHead == NULL){
        printf("\nDanh sach lien ket rong!");
    } else {
        printf("\nDanh sach lien ket la: \n");
        for(Node* temp = l->pHead; temp != NULL; temp = temp->pNext){
            printf("%5d", temp->Data);
        }
    }
}

void giaiPhongDSLK(LinkedList *l){
    for(Node* temp = l->pHead; temp != NULL;){
        Node* temp2 = temp;
        temp = temp->pNext;
        free(temp2);
    }
    l->pHead = l->pTail = NULL;
}

void xoaDauDSLK(LinkedList *l){
    if(l->pHead != NULL){
        Node* temp = l->pHead;           // lưu node đầu hiện tại
        l->pHead = l->pHead->pNext;      // chuyển sang node tiếp theo
        free(temp);                      // giải phóng node cũ

        // Nếu danh sách chỉ có 1 phần tử thì sau khi xóa, phải cập nhật cả pTail
        if(l->pHead == NULL){
            l->pTail = NULL;
        }
    }
}

void xoaCuoiDSLK(LinkedList *l){
    if(l->pHead == NULL){
        // Danh sách rỗng, không làm gì
        printf("\nDSLK rong!");
        return;
    }

    // Nếu danh sách chỉ có 1 node
    if(l->pHead == l->pTail){
        free(l->pHead);
        l->pHead = l->pTail = NULL;
        return;
    }

    Node* nodeTruoc = NULL;
    Node* temp;

    // Duyệt để tìm node cuối và node kế cuối bằng for
    for (temp = l->pHead; temp->pNext != NULL; temp = temp->pNext) {
        nodeTruoc = temp;
    }

    // temp là node cuối, nodeTruoc là node kế trước node cuối
    free(temp);
    nodeTruoc->pNext = NULL;
    l->pTail = nodeTruoc;
}

void xoaGiuaDSLK(LinkedList *l, int k) {
    if (l->pHead == NULL || k <= 0) {
        printf("\nDanh sach rong hoac vi tri khong hop le!");
        return;
    }

    // XÓA NODE ĐẦU
    if (k == 1) {
        Node* temp = l->pHead;
        l->pHead = l->pHead->pNext;
        free(temp);

        // Nếu danh sách chỉ có 1 phần tử
        if (l->pHead == NULL) {
            l->pTail = NULL;
        }
        return;
    }

    // XÓA NODE GIỮA hoặc CUỐI
    int dem = 1;
    Node* prev = NULL;
    Node* curr = l->pHead;

    while (curr != NULL && dem < k) {
        prev = curr;
        curr = curr->pNext;
        dem++;
    }

    // Nếu vị trí k vượt quá độ dài danh sách
    if (curr == NULL) {
        printf("\nVi tri vuot qua do dai danh sach!");
        return;
    }

    // Nếu node bị xóa là node cuối
    if (curr == l->pTail) {
        l->pTail = prev;
    }

    prev->pNext = curr->pNext;
    free(curr);
}


int main() {

    LinkedList l;
    khoiTaoDSLK(&l);

    Node* p1 = taoNode(1);
    Node* p2 = taoNode(2);
    Node* p3 = taoNode(3);
    Node* p4 = taoNode(4);
    Node* p5 = taoNode(5);

    themCuoiDSLK(&l, p1);
    themCuoiDSLK(&l, p2);
    themCuoiDSLK(&l, p3);
    themCuoiDSLK(&l, p4);
    themCuoiDSLK(&l, p5);

    xuatDSLK(&l);
    xoaGiuaDSLK(&l, 3);
    xuatDSLK(&l);

    giaiPhongDSLK(&l);
    return 0;
}