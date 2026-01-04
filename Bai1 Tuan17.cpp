#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Muc {
    string ten;             
    int soTrang;             
    vector<Muc*> con;       

    Muc(string t, int s) {
        ten = t;
        soTrang = s;
    }
};

Muc* taoSach() {
    Muc* sach = new Muc("Sach", 0);

    Muc* chuong1 = new Muc("Chuong 1", 30);
    Muc* chuong2 = new Muc("Chuong 2", 45);
    Muc* chuong3 = new Muc("Chuong 3", 25);

    Muc* muc11 = new Muc("Muc 1.1", 10);
    Muc* muc12 = new Muc("Muc 1.2", 20);

    Muc* muc21 = new Muc("Muc 2.1", 25);
    Muc* muc22 = new Muc("Muc 2.2", 20);

    chuong1->con.push_back(muc11);
    chuong1->con.push_back(muc12);

    chuong2->con.push_back(muc21);
    chuong2->con.push_back(muc22);

    sach->con.push_back(chuong1);
    sach->con.push_back(chuong2);
    sach->con.push_back(chuong3);

    return sach;
}

int demSoChuong(Muc* sach) {
    return sach->con.size();
}

Muc* chuongDaiNhat(Muc* sach) {
    if (sach->con.empty()) return NULL;

    Muc* max = sach->con[0];
    for (Muc* c : sach->con)
        if (c->soTrang > max->soTrang)
            max = c;

    return max;
}

int capNhatSoTrang(Muc* node) {
    if (node->con.empty())
        return node->soTrang;

    int tong = 0;
    for (Muc* c : node->con)
        tong += capNhatSoTrang(c);

    node->soTrang = tong;
    return tong;
}

bool xoaMuc(Muc* cha, string tenCanXoa) {
    for (int i = 0; i < cha->con.size(); i++) {
        if (cha->con[i]->ten == tenCanXoa) {
            delete cha->con[i];
            cha->con.erase(cha->con.begin() + i);
            capNhatSoTrang(cha);
            return true;
        }
        if (xoaMuc(cha->con[i], tenCanXoa))
            return true;
    }
    return false;
}

Muc* timChuong(Muc* sach, string tenChuong) {
    for (Muc* c : sach->con)
        if (c->ten == tenChuong)
            return c;
    return NULL;
}

void inDeMuc(Muc* node, int muc = 0) {
    for (int i = 0; i < muc; i++)
        cout << "  ";
    cout << "- " << node->ten << " (" << node->soTrang << " trang)" << endl;

    for (Muc* c : node->con)
        inDeMuc(c, muc + 1);
}

int main() {
    Muc* sach = taoSach();

    cout << "So chuong cua cuon sach: "
         << demSoChuong(sach) << endl;

    Muc* maxChuong = chuongDaiNhat(sach);
    cout << "Chuong dai nhat: "
         << maxChuong->ten << " ("
         << maxChuong->soTrang << " trang)" << endl;

    cout << "\nXoa 'Muc 2.1'\n";
    xoaMuc(sach, "Muc 2.1");

    Muc* chuong = timChuong(sach, "Chuong 2");
    if (chuong) {
        cout << "\nDe muc Chuong 2:\n";
        inDeMuc(chuong);
    }

    return 0;
}
