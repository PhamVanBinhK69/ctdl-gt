#include <iostream>
using namespace std;

struct Node {
    int duLieu;
    Node* Trai;
    Node* Phai;
};

Node* khoiTaoCay() {
    return NULL;
}

bool cayRong(Node* goc) {
    return goc == NULL;
}

Node* taoNode(int giaTri) {
    Node* nutMoi = new Node;
    nutMoi->duLieu = giaTri;
    nutMoi->Trai = NULL;
    nutMoi->Phai = NULL;
    return nutMoi;
}

void themTrai(Node* nutCha, int giaTri) {
    nutCha->Trai = taoNode(giaTri);
}

void themPhai(Node* nutCha, int giaTri) {
    nutCha->Phai = taoNode(giaTri);
}

void duyetTruoc(Node* goc) {
    if (goc == NULL) return;
    cout << goc->duLieu << " ";
    duyetTruoc(goc->Trai);
    duyetTruoc(goc->Phai);
}

void duyetGiua(Node* goc) {
    if (goc == NULL) return;
    duyetGiua(goc->Trai);
    cout << goc->duLieu << " ";
    duyetGiua(goc->Phai);
}

void duyetSau(Node* goc) {
    if (goc == NULL) return;
    duyetSau(goc->Trai);
    duyetSau(goc->Phai);
    cout << goc->duLieu << " ";
}

int main() {
    Node* goc = taoNode(1);

    themTrai(goc, 2);
    themPhai(goc, 3);
    themTrai(goc->Trai, 4);
    themPhai(goc->Trai, 5);

    cout << "Duyet truoc: ";
    duyetTruoc(goc);
    cout << endl;
    cout << "Duyet giua: ";
    duyetGiua(goc);
    cout << endl;
    cout << "Duyet sau: ";
    duyetSau(goc);

    return 0;
}
