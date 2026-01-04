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


Nut* taoCay1() {
    Nut* goc = taoNut(1);
    goc->trai = taoNut(2);
    goc->phai = taoNut(3);
    goc->trai->trai = taoNut(4);
    goc->trai->phai = taoNut(5);
    return goc;
}

Nut* taoCay2() {
    Nut* goc = taoNut(1);
    goc->trai = taoNut(2);
    goc->phai = taoNut(3);
    goc->trai->trai = taoNut(4);
    goc->trai->phai = taoNut(5);
    return goc;
}



bool giongNhau(Nut* cay1, Nut* cay2) {
    if (cay1 == NULL && cay2 == NULL)
        return true;

    if (cay1 == NULL || cay2 == NULL)
        return false;

    if (cay1->giaTri != cay2->giaTri)
        return false;

    return giongNhau(cay1->trai, cay2->trai) &&
           giongNhau(cay1->phai, cay2->phai);
}



int main() {
    Nut* cay1 = taoCay1();
    Nut* cay2 = taoCay2();

    if (giongNhau(cay1, cay2))
        cout << "Hai cay nhi phan GIONG HET NHAU";
    else
        cout << "Hai cay nhi phan KHONG GIONG NHAU";

    return 0;
}