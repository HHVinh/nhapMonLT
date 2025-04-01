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

Node* TaoNode(int x){
    Node *p = (Node*) malloc(sizeof(Node));
    p->Data = x;
    p->pNext = NULL;
    return p;
}

void khoiTaoDanhSachLienKet(LinkedList *l){
    l->pHead = NULL;
    l->pTail = NULL;
}

void inDanhSachLienKet(LinkedList *l){
    for(Node *p = l->pHead; p != NULL; p = p->pNext){
        printf("%5d", p->Data);
    }
}

int kiemTraDSLKRong(LinkedList *l) {
    if(l->pHead != NULL) {
        return 0;  // Danh sách không rỗng
    }
    return 1;  // Danh sách rỗng
}

void themVaoDauDSLK(LinkedList *l) {
    int x;
    printf("\nNhập giá trị muốn thêm đầu DSLK: "); scanf("%d", &x);

    Node *p = TaoNode(x);

    if(kiemTraDSLKRong(l)) {
        // Nếu danh sách rỗng, p trở thành cả đầu và đuôi của danh sách
        l->pHead = p;
        l->pTail = p;
    } else {
        // Nếu danh sách không rỗng, p trở thành đầu danh sách mới
        p->pNext = l->pHead;  // Đặt p->pNext trỏ tới node đầu tiên hiện tại
        l->pHead = p;  // Cập nhật p làm node đầu danh sách
    }
}

void themVaoCuoiDSLK(LinkedList *l) {
    int x;
    printf("\nNhập giá trị muốn thêm cuối DSLK: ");
    scanf("%d", &x);

    Node *p = TaoNode(x);  // Tạo node mới với giá trị nhập vào
    
    if(kiemTraDSLKRong(l)) {  // Nếu danh sách rỗng
        l->pHead = p;
        l->pTail = p;
    } else {  // Nếu danh sách không rỗng
        l->pTail->pNext = p;  // Cập nhật pNext của node cuối hiện tại trỏ tới node mới
        l->pTail = p;  // Cập nhật pTail trỏ tới node mới
    }
    p->pNext = NULL;  // Đảm bảo node mới là node cuối nên pNext của nó phải là NULL
}


int main(){

    Node *p1 = TaoNode(1);
    Node *p2 = TaoNode(2);
    Node *p3 = TaoNode(3);
    Node *p4 = TaoNode(4);
    Node *p5 = TaoNode(5);

    p1->pNext = p2;
    p2->pNext = p3;
    p3->pNext = p4;

    LinkedList(list);
    khoiTaoDanhSachLienKet(&list);
    list.pHead = p1;
    list.pTail = p4;

    printf("\nDSLK hiện tại: ");
    inDanhSachLienKet(&list);

    themVaoDauDSLK(&list);
    printf("\nDSLK đã thêm phần tử vào đầu: ");
    inDanhSachLienKet(&list);

    themVaoCuoiDSLK(&list);
    printf("\nDSLK đã thêm phần tử vào cuối: ");
    inDanhSachLienKet(&list);


    return 0;

}
