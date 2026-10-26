
#include "../h/Nguoi.h"
using namespace std ; 

// Hàm tạo mặc định
Nguoi::Nguoi() {
    this->maNguoi = "";
    this->hoTen = "";
    this->ngaySinh = "";
    this->email = "";
}

// Hàm tạo có tham số
Nguoi::Nguoi(string maNguoi, string hoTen, string ngaySinh, string email) {
    this->maNguoi = maNguoi;
    this->hoTen = hoTen;
    this->ngaySinh = ngaySinh;
    this->email = email;
}

// Virtual Destructor
Nguoi::~Nguoi() {}

// Hàm nhập
void Nguoi::nhap() {
    cout << "Nhap ma nguoi: "; getline(cin >> ws, maNguoi);
    cout << "Nhap ho ten: "; getline(cin, hoTen);
    cout << "Nhap ngay sinh: "; getline(cin, ngaySinh);
    cout << "Nhap email: "; getline(cin, email);
}

// Hàm xuất
void Nguoi::xuat() const {
    cout << endl <<  "Ma: " << maNguoi << endl ;
    cout << "Ho ten: " << hoTen << endl ;
    cout << "Ngay sinh: " << ngaySinh << endl ;
    cout << "Email: " << email << endl << endl ;
}

// Nạp chồng toán tử >>
istream& operator>>(istream& is, Nguoi& n) {
    n.nhap();
    return is;
}

// Nạp chồng toán tử <<
ostream& operator<<(ostream& os, const Nguoi& n) {
    n.xuat();
    return os;
}