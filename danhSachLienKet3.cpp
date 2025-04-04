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

int demDSLK(LinkedList *l){
    int dem = 0;
    if(kiemTraDanhSachRong(l)) return 0;
    for(Node *p = l->pHead; p != NULL; p = p->pNext){
        dem++;
    }
    return dem;
}

void themGiuaDSLK(LinkedList *l, Node *p){
    int k;
    do{
        printf("\nNhập vị trí muốn thêm: ");scanf("%d",&k);
        if(k < 1 || k > demDSLK(l)+1){
            printf("\nNhập lại vị trí từ 1 đến %d: ", demDSLK(l)+1);
        }
    } while(k < 1 || k > demDSLK(l)+1);

    Node *temp = l->pHead;
    if(k == 1){
        p->pNext = l->pHead;
        l->pHead = p;
    } else {
        for(int i = 1; i < k - 1; i++){
            temp = temp->pNext;
        }
        p->pNext = temp->pNext;
        temp->pNext = p;
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

    int luaChon;
    

    do{
        printf("\n=== Chương trình ===");
        printf("\n1: Thêm vào đầu");
        printf("\n2: Thêm vào cuối");
        printf("\n3: Thêm vào giữa");
        printf("\n4: Xóa ở đầu");
        printf("\n5: Xóa ở cuối");
        printf("\n6: Xóa ở  giữa");
        printf("\n7: Thoát chương trình");
        printf("\nNhập lựa chọn: ");
        scanf("%d",&luaChon);

        switch(luaChon){
            //C++ cấm nhảy qua khai báo biến chưa được khởi tạo trong switch; dùng {} để tránh lỗi
            case 1: { 
                Node *p5 = TaoNode();
                themDauDSLK(&list, p5);
                inDanhSachLienKet(&list);
                break;
            }

            case 2: {
                Node *p6 = TaoNode();
                themCuoiDSLK(&list, p6);
                inDanhSachLienKet(&list);
                break;
            }

            case 3:{
                Node *p7 = TaoNode();
                themGiuaDSLK(&list, p7);
                inDanhSachLienKet(&list);
                break;
            }
            case 4:
            case 5:
            case 6:
            case 7:
                printf("\nThoát chương trình!");
            break;

            default:
                printf("\nLựa chọn không hợp lệ!");

        }
    } while(luaChon != 7);

    return 0;
}