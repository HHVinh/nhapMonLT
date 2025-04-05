#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Data;
    struct Node *pNext;
} Node;

typedef struct LinkedList {
    Node *pHead;
    Node *pTail;
} LinkedList;

Node* TaoNode(int x) {
    Node *p = (Node*) malloc(sizeof(Node));
    p->Data = x;
    p->pNext = NULL;
    return p;
}

void khoiTaoDanhSachLienKet(LinkedList *l) {
    l->pHead = NULL;
    l->pTail = NULL;
}

void inDanhSachLienKet(LinkedList *l) {
    for (Node *p = l->pHead; p != NULL; p = p->pNext) {
        printf("%5d", p->Data);
    }
}

int kiemTraDSLKRong(LinkedList *l) {
    if (l->pHead != NULL) {
        return 0;  // Danh sách không rỗng
    }
    return 1;  // Danh sách rỗng
}

void themVaoDauDSLK(LinkedList *l) {
    int x;
    printf("\nNhập giá trị muốn thêm đầu DSLK: "); scanf("%d", &x);

    Node *p = TaoNode(x);

    if (kiemTraDSLKRong(l)) {
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
    
    if (kiemTraDSLKRong(l)) {  // Nếu danh sách rỗng
        l->pHead = p;
        l->pTail = p;
    } else {  // Nếu danh sách không rỗng
        l->pTail->pNext = p;  // Cập nhật pNext của node cuối hiện tại trỏ tới node mới
        l->pTail = p;  // Cập nhật pTail trỏ tới node mới
    }
    p->pNext = NULL;  // Đảm bảo node mới là node cuối nên pNext của nó phải là NULL
}

int demNode(LinkedList *l) {
    int dem = 0;
    Node *p = l->pHead;  // Con trỏ p trỏ đến node đầu tiên của danh sách

    while (p != NULL) {
        dem++;
        p = p->pNext;  // Duyệt đến node tiếp theo
    }

    return dem;  // Trả về số lượng node
}

void themVaoGiuaDSLK(LinkedList *l) {
    int k; 
    int dem = demNode(l);

    do {
        printf("\nNhập vị trí muốn thêm vào giữa DSLK: ");
        scanf("%d", &k);
        if (k < 1 || k > dem + 1) { 
            printf("Vị trí bạn nhập không hợp lệ. Nhập lại từ 1 đến %d: ", dem + 1);
        }
    } while (k < 1 || k > dem + 1);

    if (k == 1) {
        themVaoDauDSLK(l);
    } else if (k == dem + 1) {
        themVaoCuoiDSLK(l);
    } else {
        int x;
        printf("\nNhập giá trị muốn thêm vào DSLK: ");
        scanf("%d", &x);
        Node *p = TaoNode(x);

        Node *temp = l->pHead;
        for (int i = 1; i < k - 1; i++) {  // Duyệt đến node trước vị trí k
            temp = temp->pNext;
        }

        p->pNext = temp->pNext;
        temp->pNext = p;
    }
}

void xoaDauDSLK(LinkedList *l) {
    if (l->pHead == NULL) return;

    Node *temp = l->pHead;
    l->pHead = l->pHead->pNext;

    free(temp);
}

void xoaCuoiDSLK(LinkedList *l) {
    if (l->pHead == NULL) return;

    if (l->pHead->pNext == NULL) {
        free(l->pHead);
        l->pHead = NULL;
        return;
    }

    Node *temp = l->pHead;
    Node *temp2 = NULL;

    while (temp->pNext != NULL) {
        temp2 = temp;
        temp = temp->pNext;
    }

    temp2->pNext = NULL;
    l->pTail = temp2;
    free(temp);
}

void xoaGiuaDSLK(LinkedList *l) {
    int dem = demNode(l);

    int k;
    do {
        printf("\nNhập vị trí cần xóa: ");
        scanf("%d", &k);
        if(k < 1 || k > dem){
            printf("Vị trí không hợp lệ. Nhập lại từ 1 đến %d: ", dem);
        }
    } while(k < 1 || k > dem);

    if(k == 1){
        xoaDauDSLK(l);
    } else if(k == dem){
        xoaCuoiDSLK(l);
    } else {
        Node *temp1 = l->pHead;
        Node *temp2 = NULL;

        for(int i = 1; i < k; i++){
            temp2 = temp1;
            temp1 = temp1->pNext;
        }

        temp2->pNext = temp1->pNext;
        free(temp1);
    }
}

int main() {
    LinkedList list;
    khoiTaoDanhSachLienKet(&list);

    Node *p1 = TaoNode(1);
    Node *p2 = TaoNode(2);
    Node *p3 = TaoNode(3);
    Node *p4 = TaoNode(4);
    Node *p5 = TaoNode(5);

    p1->pNext = p2;
    p2->pNext = p3;
    p3->pNext = p4;

    list.pHead = p1;
    list.pTail = p4;

    printf("\nDSLK hiện tại: ");
    inDanhSachLienKet(&list);

    int luaChon;
    do {
        printf("\n===Nhập lựa chọn của bạn===");
        printf("\n1: Thêm vào đầu DSLK");
        printf("\n2: Thêm vào cuối DSLK");
        printf("\n3: Thêm vào giữa DSLK");
        printf("\n4: Xóa ở đầu DSLK");
        printf("\n5: Xóa ở cuối DSLK");
        printf("\n6: Xóa ở giữa DSLK");
        printf("\n7: Thoát chương trình");
        printf("\n\nNhập lựa chọn: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                themVaoDauDSLK(&list);
                printf("\nDSLK đã thêm phần tử vào đầu: ");
                inDanhSachLienKet(&list);
                break;

            case 2:
                themVaoCuoiDSLK(&list);
                printf("\nDSLK đã thêm phần tử vào cuối: ");
                inDanhSachLienKet(&list);
                break;

            case 3:
                themVaoGiuaDSLK(&list);
                printf("\nDSLK đã thêm phần tử vào giữa: ");
                inDanhSachLienKet(&list);
                break;

            case 4:
                xoaDauDSLK(&list);
                printf("\nDSLK sau khi xóa ở đầu: ");
                inDanhSachLienKet(&list);
                break;

            case 5:
                xoaCuoiDSLK(&list);
                printf("\nDSLK sau khi xóa ở cuối: ");
                inDanhSachLienKet(&list);
                break;

            case 6:
                xoaGiuaDSLK(&list);
                printf("\nDSLK sau khi xóa ở giữa: ");
                inDanhSachLienKet(&list);
                break;

            case 7:
                printf("\nThoát chương trình!\n");
                break;

            default:
                printf("\nLựa chọn không hợp lệ!\n");
        }
    } while (luaChon != 7);

    return 0;
}
