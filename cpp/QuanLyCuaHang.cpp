#include<bits/stdc++.h>
#include "../h/QuanLyCuaHang.h"
using namespace std ; 

//Hàm mặc định 
QuanLyCuaHang::QuanLyCuaHang() : Nguoi() , NhanVienBanHang(), KiemDinhVien() {
    this->khuVucQuanLy = "" ; 
    this->soLuongNhanSu = 0 ; 
    this->heSoChucVu = 0.0 ; 
}

//Hàm tạo có tham số 
QuanLyCuaHang::QuanLyCuaHang(string maNguoi, string hoTen, string ngaySinh, string email,
                        string maNhanVien, string chucVu, double luongCoBan , double heSoLuong, string phongBan,
                        string maKiemDinhVien, string chuyenMon,int soNamKinhNghiem, string hocVi, string donViCongTac,
                        string khuVucQuanLy , int soLuongNhanSu , float heSoChucVu 
    ): Nguoi(maNguoi,hoTen,ngaySinh,email),
    NhanVienBanHang(maNguoi, hoTen, ngaySinh, email,maNhanVien,chucVu,luongCoBan,heSoLuong,phongBan),
    KiemDinhVien(maNguoi, hoTen, ngaySinh, email,maKiemDinhVien,chuyenMon,soNamKinhNghiem,heSoLuong,hocVi,donViCongTac,luongCoBan){
        this->khuVucQuanLy = khuVucQuanLy;
        this->soLuongNhanSu = soLuongNhanSu;
        this->heSoChucVu = heSoChucVu;
    }



//Hàm hủy 
QuanLyCuaHang::~QuanLyCuaHang(){}

//Hàm nhập 
void QuanLyCuaHang::nhap(){
    Nguoi::nhap();
    NhanVienBanHang::nhapnvbh();
    KiemDinhVien::nhapkdv();
    cout << "Nhap khu vuc quan ly : " ; getline(cin>>ws,khuVucQuanLy);
    do {
        cout << "Nhap so luong nhan su : " ; cin >> soLuongNhanSu;
        if (soLuongNhanSu < 0) cout << "Loi! So luong nhan su phai >= 0. Nhap lai!\n";
    } while (soLuongNhanSu < 0);

    do {
        cout << "Nhap he so chuc vu : " ; cin >> heSoChucVu;
        if (heSoChucVu <= 0) cout << "Loi! He so chuc vu phai > 0. Nhap lai!\n";
    } while (heSoChucVu <= 0);
}

//Hàm xuất 
void QuanLyCuaHang::xuat() const{
    Nguoi::xuat();
    NhanVienBanHang::xuatnvbh();
    KiemDinhVien::xuatkdv();
    cout << " | Khu vuc quan ly : " << khuVucQuanLy
        << " | So luong nhan su : " << soLuongNhanSu
        << " | He so chuc vu : " << heSoChucVu;
}

istream& operator>>(istream& is, QuanLyCuaHang& qlch) {
    qlch.nhap();
    return is;
}

ostream& operator<<(ostream& os, const QuanLyCuaHang& qlch) {
    qlch.xuat();
    return os;
}

//Hàm tính phụ cấp 
double QuanLyCuaHang::tinhPhuCap() const{
    return NhanVienBanHang::tinhLuong() + heSoChucVu*2000000;
}

//Hàm cập nhật số nhân sự 
void QuanLyCuaHang::capNhatSoNhanSu(int n){
    if (n >= 0) soLuongNhanSu = n;
    else cout << "Khong the cap nhat so nhan su am.\n";
}




