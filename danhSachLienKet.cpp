#include <stdio.h>
#include <stdlib.h>
#include "danhSachLienKet.h"

Node *TaoNode(int x){
    Node *p = (Node*) malloc(sizeof(Node));
    p->Data = x;
    p->pNext = NULL;
    return p;
}

void KhoiTaoDanhSachLienKet(LinkedList &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

void LietKePhanTuDanhSachLienKet(LinkedList &l){
    for(Node *p = l.pHead; p != NULL; p = p->pNext){
        printf("%5d", p->Data);
    }
}

void ThemVaoDauDanhSach(LinkedList &l, Node *p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    } else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void ThemVaoCuoiDanhSach(LinkedList &l, Node *p){
    if(l.pHead == NULL){
        l.pHead = p;
        l.pTail = p;
    } else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void ThemVaoGiuaDanhSach(LinkedList &l, Node *q, Node *p){
    if(q != NULL){
        p->pNext = q->pNext;
        q->pNext = p;
        if(l.pTail == q){
            l.pHead = p;
        }
    }
}



int main(){
    LinkedList list;
    KhoiTaoDanhSachLienKet(list);

    Node *p1 = TaoNode(1);
    Node *p2 = TaoNode(2);
    Node *p3 = TaoNode(3);
    Node *p4 = TaoNode(4);

    // p1->pNext = p2;
    // p2->pNext = p3;
    // p3->pNext = p4;

    // list.pHead = p1;
    // list.pTail = p4;

    // ThemVaoDauDanhSach(list, p1);
    // ThemVaoDauDanhSach(list, p2);
    // ThemVaoDauDanhSach(list, p3);
    // ThemVaoDauDanhSach(list, p4);

    // LietKePhanTuDanhSachLienKet(list);

    ThemVaoCuoiDanhSach(list, p1);
    ThemVaoCuoiDanhSach(list, p2);
    ThemVaoCuoiDanhSach(list, p3);
    ThemVaoGiuaDanhSach(list, p2, p4);

    LietKePhanTuDanhSachLienKet(list);

    

    return 0;
}