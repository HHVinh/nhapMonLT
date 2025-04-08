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
    int x;
    printf("\nNhap gia tri: ");
    scanf("%d", &x);
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

int kiemTraDanhSachRong(LinkedList *l){
    return (l->pHead == NULL);
}

int demSoLuongNode(LinkedList *l){
    int dem = 0;
    for(Node *p = l->pHead; p != NULL; p = p->pNext){
        dem++;
    }
    return dem;
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
        l->pHead = p;
        l->pTail = p;
    } else{
        l->pTail->pNext = p;
        l->pTail = p;
    }
}

void inDSLK(LinkedList *l){
    if(kiemTraDanhSachRong(l)){
        printf("\nDanh sach lien ket rong!");
    } else{
        for(Node *p = l->pHead; p != NULL; p = p->pNext){
            printf("%5d", p->Data);
        }
    }
}

int main(){

    LinkedList list;
    khoiTaoDanhSachLienKet(&list);

    Node *p1 = TaoNode();
    Node *p2 = TaoNode();
    Node *p3 = TaoNode();
    Node *p4 = TaoNode();

    list.pHead = p1;
    list.pTail = p1;

    themCuoiDSLK(&list, p2);
    themCuoiDSLK(&list, p3);
    themCuoiDSLK(&list, p4);

    printf("\nDanh sach lien ket la: ");
    inDSLK(&list);
    int luaChon;

    do{
        printf("\n\n===DANH SACH CHON===");
        printf("\n1: Them vao dau DSLK");
        printf("\n2: Them vao cuoi DSLK");
        printf("\n3: Them vao giua DSLK");
        printf("\n4: Them dau DSLK");
        printf("\n5: Them cuoi DSLK");
        printf("\n6: Them giua DSLK");
        printf("\n7: Tim theo gia tri");
        printf("\n8: Tim theo vi tri");
        printf("\n9: Sap xep DSLK");
        printf("\n0: Thoat chuong trinh");
        printf("\nNhập lựa chọn: ");
        scanf("%d", &luaChon);

        switch(luaChon){
            case 1:{
            Node *p5 = TaoNode();
            themDauDSLK(&list, p5);
            inDSLK(&list);
            break;}

            case 2:{
            Node *p6 = TaoNode();
            themCuoiDSLK(&list, p6);
            inDSLK(&list);
            break;}

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

            case 8:
            break;

            case 9:
            break;

            case 0:
            printf("\nThoat chuong trinh!");
            break;

            default:
                    printf("\nLựa chọn không hợp lệ!");
        }
    } while(luaChon != 0);

    return 0;
}