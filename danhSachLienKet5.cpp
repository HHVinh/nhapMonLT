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

void khoiTaoDSLK(LinkedList *l) {
    l->pHead = NULL;
    l->pTail = NULL;
}

Node* taoNode(int x){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Lỗi cấp phát!");
        exit(1);
    }

    newNode->Data = x;
    newNode->pNext = NULL;

    return newNode; 
}

void themCuoiDSLK(LinkedList* l, Node* newNode){
    if(l->pHead == NULL){
        l->pHead = l->pTail = newNode;
    } else {
        l->pTail->pNext = newNode;
        l->pTail = newNode;
    }
}

void nhapDSLK(LinkedList *l){
    int n;
    printf("Nhập số lượng Node: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x;
        printf("Nhập giá trị Node(%d): ", i+1);
        scanf("%d", &x);

        Node* newNode = taoNode(x);
        themCuoiDSLK(l, newNode);
    }
}

void xuatDSLK(LinkedList l){
    for(Node* temp = l.pHead; temp != NULL; temp = temp->pNext){
        printf("%5d", temp->Data);
    }
}

void themDauDSLK(LinkedList* l, Node* newNode){
    if(l->pHead == NULL){
        l->pHead = l->pTail = newNode;
    } else {
        newNode->pNext = l->pHead;
        l->pHead = newNode;
    }
}

int demSoLuongNode(LinkedList* l){
    int count = 0;
    for(Node* temp = l->pHead; temp != NULL; temp = temp->pNext){
        count++;
    }
    return count;
}

void themGiuaDSLK(LinkedList* l, Node* newNode){
    int k;
    printf("\nNhập vị trí cần thêm Node (Tính từ 1): ");
    scanf("%d", &k);

    int soLuongNode = demSoLuongNode(l);
    if(soLuongNode == 0 || k <= 1){
        themDauDSLK(l, newNode);
    } else if(k > soLuongNode){
        themCuoiDSLK(l, newNode);
    } else {
        Node* nodeTruoc = NULL;
        Node* temp = l->pHead;

        for(int i = 1; i < k; i++){
            nodeTruoc = temp;
            temp = temp->pNext;
        }

        nodeTruoc->pNext = newNode;
        newNode->pNext = temp;
    }
}

void themGiuaDSLK2(LinkedList* l, Node* newNode){
    int k;
    printf("\nNhập vị trí cần thêm Node (Tính từ 1): ");
    scanf("%d", &k);

    int soLuongNode = demSoLuongNode(l);
    if(soLuongNode == 0 || k <= 1){
        themDauDSLK(l, newNode);
    } else if(k > soLuongNode){
        themCuoiDSLK(l, newNode);
    } else {
        Node* temp = l->pHead;

        for(int i = 1; i < k - 1; i++){
            temp = temp->pNext;
        }

        newNode->pNext = temp->pNext;
        temp->pNext = newNode;
    }
}

int main(){

    LinkedList l;
    khoiTaoDSLK(&l);
    nhapDSLK(&l);
    printf("\nDanh sách liên kết là: \n");
    xuatDSLK(l);

    Node* p1 = taoNode(999);
    themGiuaDSLK2(&l, p1);
    printf("\nDanh sách liên kết sau khi thêm vào giữa là: \n");
    xuatDSLK(l);

    return 0;
}

