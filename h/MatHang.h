#pragma once
#include<bits/stdc++.h>

class MatHang {
protected:
    std::string maHang;
    std::string tenHang;
    int soLuongDongGoi;
    double donGiaCoBan;
    std::string maKiemDinhVien;

    // Hàm phụ kiểm tra mã KDV tồn tại trong tệp
    bool kiemTraMaKDVTonTai(const std::string& maKDV);

public:
    MatHang();
    MatHang(std::string maHang, std::string tenHang, int soLuongDongGoi, double donGiaCoBan, std::string maKiemDinhVien);
    
    virtual ~MatHang();

    virtual void nhap();
    virtual void xuat() const;

    friend std::istream& operator>>(std::istream& is, MatHang& mh);
    friend std::ostream& operator<<(std::ostream& os, const MatHang& mh);

    // Hàm thuần ảo
    virtual double tinhChiPhi() const = 0;
};