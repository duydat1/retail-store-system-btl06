#pragma once
#include "Nguoi.h"

class KhachHang : public Nguoi {
    private:
        std::string maKhachHang;
        std::string soDienThoai;
        std::string diaChi;

    public:
        KhachHang();

        KhachHang(std::string maNguoi, std::string hoTen, std::string ngaySinh, std::string email,
                std::string maKhachHang, std::string soDienThoai, std::string diaChi);

        ~KhachHang() override;

        // Ghi đè hàm nhap() và xuat() từ lớp Nguoi
        void nhap() override; 
        void xuat() const override;


        friend std::istream& operator>>(std::istream& is, KhachHang& kh);
        friend std::ostream& operator<<(std::ostream& os, const KhachHang& kh);
}; 














