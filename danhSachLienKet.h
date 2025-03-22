#ifndef DANH_SACH_LIEN_KET_H
#define DANH_SACH_LIEN_KET_H

typedef struct Node {
    int Data;
    struct Node *pNext;
} Node;

typedef struct LinkedList {
    Node *pHead;
    Node *pTail;
} LinkedList;

Node *TaoNode(int x);
void KhoiTaoDanhSachLienKet(LinkedList &l);
void LietKePhanTuDanhSachLienKet(LinkedList &l);

#endif
