#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int Data;
    struct Node *pNext;
} Node;

typedef struct LinkedList{
    Node *pHead;
    Node *pTail;
} LinkedList;

Node *TaoNode(){
    int x; printf("Nhập giá trị : "); scanf("%d",&x);
    Node *p = (Node*) malloc(sizeof(Node));
    if (p == NULL) {  // Kiểm tra nếu malloc thất bại
        printf("Lỗi cấp phát bộ nhớ!\n");
        return NULL;
    }
    p->Data = x;
    p->pNext = NULL;
    return p;
}

void khoiTaoDanhSachLienKet(LinkedList *l){
    l->pHead = NULL;
    l->pTail = NULL;
}

void inDanhSachLienKet(LinkedList *l){
    printf("\nDanh sách liên kết: ");
    for(Node *p = l->pHead; p != NULL; p = p->pNext){
        printf("%5d", p->Data);
    }
    printf("\n");
}

int kiemTraDanhSachRong(LinkedList *l){
    if(l->pHead != NULL){
        return 0;
    }
    return 1;
}

void themDauDSLK(LinkedList *l, Node *p){
    if(kiemTraDanhSachRong(l)){
        l->pHead = p;
        l->pTail = p;
    } else{
        p->pNext = l->pHead;
        l->pHead = p;
    }
}

void themCuoiDSLK(LinkedList *l, Node *p){
    if(kiemTraDanhSachRong(l)){
        themDauDSLK(l,p);
    } else{
        l->pTail->pNext = p;
        l->pTail = p; 
    }
}

int main(){

    LinkedList list;
    khoiTaoDanhSachLienKet(&list);

    Node *p1 = TaoNode();
    Node *p2 = TaoNode();
    Node *p3 = TaoNode();
    Node *p4 = TaoNode();


    p1->pNext = p2;
    p2->pNext = p3;
    p3->pNext = p4;

    list.pHead = p1;
    list.pTail = p4;

    inDanhSachLienKet(&list);

    printf("\n\nThêm vào danh sách\n");
    Node *p5 = TaoNode();
    themDauDSLK(&list, p5);

    Node *p6 = TaoNode();
    themCuoiDSLK(&list, p6);
    inDanhSachLienKet(&list);

    return 0;
}