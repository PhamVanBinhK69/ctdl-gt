#include <iostream>
#include <string>

using namespace std;

struct Node {
    string duLieu;
    Node* Trai;
    Node* Phai;
};

Node* khoiTaoCay() {
    return NULL;
}

bool cayRong(Node* goc) {
    return goc == NULL;
}

Node* taoNode(string giaTri) {
    Node* nutMoi = new Node;
    nutMoi->duLieu = giaTri;
    nutMoi->Trai = NULL;
    nutMoi->Phai = NULL;
    return nutMoi;
}

void themTrai(Node* nutCha, string giaTri) {
    nutCha->Trai = taoNode(giaTri);
}

void themPhai(Node* nutCha, string giaTri) {
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
    Node* goc = taoNode("A");

    themTrai(goc, "A.1");
    themPhai(goc, "A.2");
    themTrai(goc->Trai, "A.1.1");
    themPhai(goc->Trai, "A.1.2");
    themTrai(goc->Phai, "A.2.1");
    themPhai(goc->Phai, "A.2.2");


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
