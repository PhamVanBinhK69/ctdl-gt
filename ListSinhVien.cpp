#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    string hoTen;
    string mssv;
    int namSinh;
    float gpa;
};

struct Node {
    SinhVien sinhVien;
    Node* next;
};

Node* taoNode(SinhVien sv) {
    Node* nutMoi = new Node;
    nutMoi->sinhVien = sv;
    nutMoi->next = 0;
    return nutMoi;
}

void themCuoi(Node*& controFirst, SinhVien sv) {
    Node* nutMoi = taoNode(sv);
    if (controFirst == 0) {
        controFirst = nutMoi;
        return;
    }
    Node* tam = controFirst;
    while (tam->next != 0)
        tam = tam->next;
    tam->next = nutMoi;
}

void inDanhSach(Node* controFirst) {
    while (controFirst != 0) {
        cout << controFirst->sinhVien.hoTen << " " ;
        cout << controFirst->sinhVien.mssv << " " ; 
        cout << controFirst->sinhVien.namSinh << "  ";
        cout << controFirst->sinhVien.gpa << endl;
        controFirst = controFirst->next;
    }
}

int demSoLuong(Node* controFirst) {
    int dem = 0;
    while (controFirst != 0) {
        dem++;
        controFirst = controFirst->next;
    }
    return dem;
}

int demSoGPAHon32(Node* controFirst) {
    int dem = 0;
    while (controFirst != 0) {
        if (controFirst->sinhVien.gpa > 3.2)
            dem++;
        controFirst = controFirst->next;
    }
    return dem;
}
                                                                  
void sapxepChen(Node*& controFirst, SinhVien sv) {
    Node* nutMoi = taoNode(sv);

    if (controFirst == 0 || sv.gpa < controFirst->sinhVien.gpa) {
        nutMoi->next = controFirst;
        controFirst = nutMoi;
        return;
    }

    Node* tam = controFirst;
    while (tam->next != 0 && tam->next->sinhVien.gpa < sv.gpa)
        tam = tam->next;

    nutMoi->next = tam->next;
    tam->next = nutMoi;
}

int main() {
    Node* controFirst = 0;

    themCuoi(controFirst, {"Pham Van Binh", "202413997", 2006, 3.5});
    themCuoi(controFirst, {"Bui Quang Huy", "202498760", 2006, 2.7});
    themCuoi(controFirst, {"Tran Dang Khoa", "202456789", 2006, 3.8});

    cout << "Danh sach sinh vien:" << endl;
    inDanhSach(controFirst);

    cout << "So luong sinh vien: " << demSoLuong(controFirst) << endl;
    cout << "So sinh vien GPA > 3.2: " << demSoGPAHon32(controFirst) << endl;

    sapxepChen(controFirst, {"Sinh vien moi", "202512345", 2007, 2.4});

    cout << "Danh sach sau khi chen sinh vien GPA = 2.4:" << endl;
    inDanhSach(controFirst);

    return 0;
}
