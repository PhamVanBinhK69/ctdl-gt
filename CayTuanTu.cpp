#include <iostream>
using namespace std;

#define MAX 100

struct CayTuanTu {
    int duLieu[MAX];
    int kichThuoc;
};

void khoiTaoCay(CayTuanTu &cay) {
    cay.kichThuoc = 0;
}

bool ktraRong(CayTuanTu cay) {
    return cay.kichThuoc == 0;
}

void themGoc(CayTuanTu &cay, int giaTri) {
    cay.duLieu[1] = giaTri;
    cay.kichThuoc = 1;
}

void themTrai(CayTuanTu &cay, int viTriCha, int giaTri) {
    int viTriTrai = 2 * viTriCha;
    cay.duLieu[viTriTrai] = giaTri;
    if (viTriTrai > cay.kichThuoc)
        cay.kichThuoc = viTriTrai;
}

void themPhai(CayTuanTu &cay, int viTriCha, int giaTri) {
    int viTriPhai = 2 * viTriCha + 1;
    cay.duLieu[viTriPhai] = giaTri;
    if (viTriPhai > cay.kichThuoc)
        cay.kichThuoc = viTriPhai;
}

void duyetTruoc(CayTuanTu cay, int viTri) {
    if (viTri > cay.kichThuoc) return;
    cout << cay.duLieu[viTri] << " ";
    duyetTruoc(cay, 2 * viTri);
    duyetTruoc(cay, 2 * viTri + 1);
}

void duyetGiua(CayTuanTu cay, int viTri) {
    if (viTri > cay.kichThuoc) return;
    duyetGiua(cay, 2 * viTri);
    cout << cay.duLieu[viTri] << " ";
    duyetGiua(cay, 2 * viTri + 1);
}

void duyetSau(CayTuanTu cay, int viTri) {
    if (viTri > cay.kichThuoc) return;
    duyetSau(cay, 2 * viTri);
    duyetSau(cay, 2 * viTri + 1);
    cout << cay.duLieu[viTri] << " ";
}

int main() {
    CayTuanTu cay;
    khoiTaoCay(cay);

    themGoc(cay, 1);
    themTrai(cay, 1, 2);
    themPhai(cay, 1, 3);
    themTrai(cay, 2, 4);
    themPhai(cay, 2, 5);

    cout << "Duyet truoc: ";
    duyetTruoc(cay, 1);
    cout << endl;
    cout << "Duyet giua: ";
    duyetGiua(cay, 1);
    cout << endl;
    cout << "Duyet sau: ";
    duyetSau(cay, 1);
    return 0;
}
