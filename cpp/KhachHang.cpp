#include<bits/stdc++.h>
#include "../h/KhachHang.h"
using namespace std;


// Hàm tạo mặc định
KhachHang::KhachHang() : Nguoi() {
    this->maKhachHang = "";
    this->soDienThoai = "";
    this->diaChi = "";
}

// Hàm tạo có tham số (gọi lại constructor của lớp Nguoi)
KhachHang::KhachHang(string maNguoi, string hoTen, string ngaySinh, string email,string maKhachHang, 
                    string soDienThoai, string diaChi)
    : Nguoi(maNguoi, hoTen, ngaySinh, email) {
    this->maKhachHang = maKhachHang;
    this->soDienThoai = soDienThoai;
    this->diaChi = diaChi;
}

// Hàm hủy
KhachHang::~KhachHang() {}

// Hàm nhập
void KhachHang::nhap() {
    Nguoi::nhap(); 
    cout << "Nhap ma khach hang: ";
    getline(cin >> ws, maKhachHang);
    cout << "Nhap so dien thoai: ";
    getline(cin, soDienThoai);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

// Hàm xuất 
void KhachHang::xuat() const {
    Nguoi::xuat(); 
    cout << " | Ma Khach hang: " << maKhachHang 
        << " | SDT: " << soDienThoai 
        << " | Dia chi: " << diaChi;
}

// Nạp chồng toán tử >>
istream& operator>>(istream& is, KhachHang& kh) {
    kh.nhap();
    return is;
}

// Nạp chồng toán tử <<
ostream& operator<<(ostream& os, const KhachHang& kh) {
    kh.xuat();
    return os;
}



