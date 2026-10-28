#pragma once
#include "Nguoi.h"

class NhanVienBanHang : virtual public Nguoi{
    private : 
        std :: string maNhanVien , chucVu , phongBan ; 
        double luongCoBan , heSoLuong ; 
    public : 
        NhanVienBanHang();

        NhanVienBanHang(std::string maNguoi, std::string hoTen, std::string ngaySinh, std::string email,
                    std::string maNhanVien, std::string chucVu, double luongCoBan , double heSoLuong, std::string phongBan);
        
        ~NhanVienBanHang() override;
        
        void nhap() override ; 
        void xuat() const override ; 

        friend std::istream& operator>>(std::istream& is , NhanVienBanHang& nvbh);
        friend std::ostream& operator<<(std::ostream& os , const NhanVienBanHang& nvbh);

        double tinhLuong() const ;

};










