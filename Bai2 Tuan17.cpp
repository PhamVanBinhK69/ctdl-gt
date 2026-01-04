#include <iostream>
#include <string>
using namespace std;

struct Node {
    int index;          
    string tenMuc;      
    Node* left;         
    Node* right;        

    Node(int i, string t) {
        index = i;
        tenMuc = t;
        left = NULL;
        right = NULL;
    }
};

Node* taoSach1() {
    Node* root = new Node(1, "Chuong 1");

    root->left = new Node(11, "Muc 1.1");
    root->right = new Node(12, "Muc 1.2");

    root->left->left = new Node(111, "Muc 1.1.1");
    root->left->right = new Node(112, "Muc 1.1.2");

    return root;
}

Node* taoSach2() {
    Node* root = new Node(1, "Chuong 1");

    root->left = new Node(11, "Muc 1.1");
    root->right = new Node(12, "Muc 1.2");

    root->left->left = new Node(111, "Muc 1.1.1");
    root->left->right = new Node(112, "Muc 1.1.2");

    return root;
}

bool laBanCopy(Node* s1, Node* s2) {
    if (s1 == NULL && s2 == NULL)
        return true;
    if (s1 == NULL || s2 == NULL)
        return false;

    if (s1->index != s2->index || s1->tenMuc != s2->tenMuc)
        return false;
    return laBanCopy(s1->left, s2->left) &&
           laBanCopy(s1->right, s2->right);
}


int main() {
    Node* sach1 = taoSach1();
    Node* sach2 = taoSach2();

    if (laBanCopy(sach1, sach2))
        cout << "Hai cuon sach la BAN COPY cua nhau" << endl;
    else
        cout << "Hai cuon sach KHONG phai ban copy" << endl;

    return 0;
}