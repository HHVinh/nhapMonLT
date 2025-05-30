// Khai báo struct Node và danh sách liên kết đơn chứa thông tin sinh viên gồm:
// Mã sinh viên (chuỗi 10 ký tự),
// Tên sinh viên (chuỗi 30 ký tự),
// Điểm trung bình (float)
// Viết các hàm:
// Thêm sinh viên vào cuối danh sách
// Tìm và in ra sinh viên có điểm trung bình cao nhất

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sinhvien{
    char MaSV[10];
    char TenSV[30];
    float DTB;
} Sinhvien;

typedef struct Node{
    Sinhvien Data;
    struct Node* pNext;
} Node;

typedef struct LinkedList{
    Node* pHead;
    Node* pTail;
} LinkedList;


void khoiTaoDSLK(LinkedList *l){
    l->pHead = NULL;
    l->pTail = NULL;
}

Node* taoNode(Sinhvien sv){
    Node* p = (Node*)malloc(sizeof(Node));
    if(p == NULL){
        printf("Lỗi cấp phát");
        return NULL;
    }

    p->Data = sv;
    p->pNext = NULL;

    return p;
}

void themCuoiDSLK(LinkedList *l, Sinhvien sv){
    Node* p = taoNode(sv);
    if(p == NULL) return;
    if(l->pHead == NULL){
        l->pHead = l->pTail = p;
    } else{
        l->pTail->pNext = p;
        l->pTail = p;
    }
}

void inSinhVienDiemCaoNhat(LinkedList l){
    if(l.pHead == NULL){
        printf("DSLK rỗng");
        return;
    }

    Node* p = l.pHead;
    Node* caoNhat = p;

    while(p != NULL){
        if(p->Data.DTB > caoNhat->Data.DTB){
            caoNhat = p;
        }
        p = p->pNext;
    }

    Sinhvien sv = caoNhat->Data;
    printf("Sinh viên có ĐTB cao nhất: \n");
    printf("Mã SV: %s", sv.MaSV);
    printf("Tên SV: %s", sv.TenSV);
    printf("ĐTB: %.2f", sv.DTB);
}

int main(){
    LinkedList ds;
    khoiTaoDSLK(&ds);

    int n;
    printf("Nhập số lượng sinh viên: ");
    scanf("%d", &n);
    getchar(); // loại bỏ ký tự '\n' còn dư

    for (int i = 0; i < n; i++){
        Sinhvien sv;
        printf("Nhập mã sinh viên: ");
        fgets(sv.MaSV, sizeof(sv.MaSV), stdin);
        sv.MaSV[strcspn(sv.MaSV, "\n")] = '\0';  // loại bỏ '\n'

        printf("Nhập tên sinh viên: ");
        fgets(sv.TenSV, sizeof(sv.TenSV), stdin);
        sv.TenSV[strcspn(sv.TenSV, "\n")] = '\0';

        printf("Nhập điểm trung bình: ");
        scanf("%f", &sv.DTB);
        getchar(); // loại bỏ '\n' sau khi nhập float

        themCuoiDSLK(&ds, sv);
    }

    inSinhVienDiemCaoNhat(ds);

    return 0;
}
