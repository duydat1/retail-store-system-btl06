#include<bits/stdc++.h>
#include "../h/NhanVienBanHang.h"
using namespace std ; 


// Hàm tạo mặc định 
NhanVienBanHang::NhanVienBanHang() : Nguoi(){
    this->maNhanVien = "";
    this->chucVu = "";
    this->luongCoBan = 0.0 ; 
    this->heSoLuong = 0.0 ; 
    this->phongBan = "";
}

//hàm tạo có tham số 
NhanVienBanHang::NhanVienBanHang(string maNguoi, string hoTen, string ngaySinh, string email,
                                string maNhanVien, string chucVu,double luongCoBan, double heSoLuong, string phongBan )
    : Nguoi(maNguoi, hoTen, ngaySinh, email) {
        this->maNhanVien = maNhanVien;
        this->chucVu = chucVu;
        this->luongCoBan = luongCoBan; 
        this->heSoLuong = heSoLuong; 
        this->phongBan = phongBan;
}

//Hàm hủy 
NhanVienBanHang::~NhanVienBanHang(){} 

//Hàm nhập
void NhanVienBanHang::nhap(){
    Nguoi::nhap() ; 
    cout << "Nhap ma nhan vien : " ; getline(cin>>ws , maNhanVien);
    cout << "Nhap chuc vu : " ; getline(cin , chucVu);
    do {
        cout << "Nhap luong co ban (> 0) : "; cin >> luongCoBan;
        if (luongCoBan <= 0) cout << "Loi! Luong co ban phai > 0. Nhap lai!\n";
    } while (luongCoBan <= 0);
    do {
        cout << "Nhap he so luong (> 0) : ";
        cin >> heSoLuong;
        if (heSoLuong <= 0) cout << "Loi! He so luong phai > 0. Nhap lai!\n";
    } while (heSoLuong <= 0);
    cout << "Nhap phong ban : " ; getline(cin>>ws , phongBan);
}

//Hàm xuất 
void NhanVienBanHang::xuat() const {
    Nguoi::xuat() ; 
    cout << "Ma nhan vien : " << maNhanVien 
        << " | Chuc vu : " << chucVu 
        << " | Luong co ban : " << luongCoBan 
        << " | He so luong : " << heSoLuong 
        << " | Phong ban : " << phongBan 
        << " | Tien luong : " << tinhLuong() << endl ; 
}

// >> 
istream& operator>>(istream& is , NhanVienBanHang& nvbh){
    nvbh.nhap() ; 
    return is ; 
}

// << 
ostream& operator<<(ostream& os , const NhanVienBanHang& nvbh){
    nvbh.xuat() ; 
    return os ; 
}

//Hàm tính tiền lương 
double NhanVienBanHang::tinhLuong() const {
    return this->luongCoBan * this->heSoLuong;
}






