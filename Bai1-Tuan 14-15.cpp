#include <iostream>
using namespace std;

struct Nut {
    int giaTri;
    Nut* trai;
    Nut* phai;
};

Nut* taoNut(int x) {
    Nut* p = new Nut;
    p->giaTri = x;
    p->trai = NULL;
    p->phai = NULL;
    return p;
}

Nut* dungCay() {
    Nut* goc = taoNut(4);
    goc->trai = taoNut(1);
    goc->phai = taoNut(3);
    goc->trai->trai = taoNut(2);
    goc->trai->phai = taoNut(16);
    goc->phai->trai = taoNut(9);
    goc->phai->phai = taoNut(10);
    goc->trai->trai->trai = taoNut(14);
    goc->trai->trai->phai = taoNut(8);
    goc->trai->phai->trai = taoNut(7);
    return goc;
}

void duyetTruoc(Nut* goc) {
    if (goc == NULL) return;
    cout << goc->giaTri << " ";
    duyetTruoc(goc->trai);
    duyetTruoc(goc->phai);
}

void duyetGiua(Nut* goc) {
    if (goc == NULL) return;
    duyetGiua(goc->trai);
    cout << goc->giaTri << " ";
    duyetGiua(goc->phai);
}

void duyetSau(Nut* goc) {
    if (goc == NULL) return;
    duyetSau(goc->trai);
    duyetSau(goc->phai);
    cout << goc->giaTri << " ";
}

void hoanDoi(int &a, int &b) {
    int tam = a;
    a = b;
    b = tam;
}

void vunDong(Nut* goc) {
    if (goc == NULL) return;
    Nut* lonNhat = goc;
    if (goc->trai && goc->trai->giaTri > lonNhat->giaTri)
        lonNhat = goc->trai;
    if (goc->phai && goc->phai->giaTri > lonNhat->giaTri)
        lonNhat = goc->phai;
    if (lonNhat != goc) {
        hoanDoi(goc->giaTri, lonNhat->giaTri);
        vunDong(lonNhat);
    }
}

void taoHeap(Nut* goc) {
    if (goc == NULL) return;
    taoHeap(goc->trai);
    taoHeap(goc->phai);
    vunDong(goc);
}

int main() {
    Nut* goc = dungCay();
    cout << "Duyet truoc: ";
    duyetTruoc(goc);
    cout << "\nDuyet giua: ";
    duyetGiua(goc);
    cout << "\nDuyet sau: ";
    duyetSau(goc);
    taoHeap(goc);
    cout << "\n\nSau khi vun dong (duyet truoc): ";
    duyetTruoc(goc);
    return 0;
}