#include<bits/stdc++.h>
#include "../h/MatHang.h"
using namespace std;

// Hàm kiểm tra mã kiểm định viên có tồn tại trong file KiemDinhVien.txt không
bool MatHang::kiemTraMaKDVTonTai(const string& maKDV) {
    ifstream file("ThuMucDuLieu/KiemDinhVien.txt"); 
    
    if (!file.is_open()) {
        // Nếu không mở được file thì báo lỗi hoặc tạm cho qua để test
        cout << "[Loi]: Khong mo duoc file ThuMucDuLieu/KiemDinhVien.txt!\n";
        return false; 
    }

    string line;
    while (getline(file, line)) {
        // Kiểm tra xem dòng đó có chứa mã KDV không
        if (line.find(maKDV) != string::npos && !maKDV.empty()) {
            file.close();
            return true; // Tìm thấy mã hợp lệ
        }
    }
    file.close();
    return false; // Khong tim thay
}

// Hàm tạo mặc định
MatHang::MatHang() {
    this->maHang = "";
    this->tenHang = "";
    this->soLuongDongGoi = 0;
    this->donGiaCoBan = 0.0;
    this->maKiemDinhVien = "";
}

// Hàm tạo có tham số
MatHang::MatHang(string maHang, string tenHang, int soLuongDongGoi, double donGiaCoBan, string maKiemDinhVien) {
    this->maHang = maHang;
    this->tenHang = tenHang;
    this->soLuongDongGoi = soLuongDongGoi;
    this->donGiaCoBan = donGiaCoBan;
    this->maKiemDinhVien = maKiemDinhVien;
}

// Hàm hủy ảo
MatHang::~MatHang() {}

// Hàm nhập
void MatHang::nhap() {
    cout << "Nhap ma mat hang: "; getline(cin >> ws, maHang);
    cout << "Nhap ten mat hang: "; getline(cin, tenHang);

    do {
        cout << "Nhap so luong dong goi (> 0): "; cin >> soLuongDongGoi;
        if (soLuongDongGoi <= 0) cout << "Loi! So luong dong goi phai > 0. Nhap lai!\n";
    } while (soLuongDongGoi <= 0);

    do {
        cout << "Nhap don gia co ban (> 0): "; cin >> donGiaCoBan;
        if (donGiaCoBan <= 0) cout << "Loi! Don gia co ban phai > 0. Nhap lai!\n";
    } while (donGiaCoBan <= 0);

    // Nhập và kiểm tra mã kiểm định viên từ tệp
    do {
        cout << "Nhap ma kiem dinh vien phu trach: "; getline(cin >> ws, maKiemDinhVien);
        if (!kiemTraMaKDVTonTai(maKiemDinhVien)) {
            cout << "Loi! Ma KDV '" << maKiemDinhVien << "' khong ton tai trong danh sach. Nhap lai!\n";
        }
    } while (!kiemTraMaKDVTonTai(maKiemDinhVien));
}

// Hàm xuất
void MatHang::xuat() const {
    cout << "Ma hang: " << maHang
        << " | Ten hang: " << tenHang
        << " | SL dong goi: " << soLuongDongGoi
        << " | Don gia CB: " << donGiaCoBan
        << " | Ma KDV phu trach: " << maKiemDinhVien;
}

// Operator >>
istream& operator>>(istream& is, MatHang& mh) {
    mh.nhap();
    return is;
}

// Operator <<
ostream& operator<<(ostream& os, const MatHang& mh) {
    mh.xuat();
    return os;
}