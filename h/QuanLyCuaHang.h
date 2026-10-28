#pragma once
#include "NhanVienBanHang.h"
#include "KiemDinhVien.h"

class QuanLyCuaHang : public NhanVienBanHang, public KiemDinhVien {
    private:
        std::string khuVucQuanLy ; 
        int soLuongNhanSu ; 
        float heSoChucVu ; 
    public:
        QuanLyCuaHang();

        QuanLyCuaHang(std::string maNguoi, std::string hoTen, std::string ngaySinh, std::string email,
                        std::string maNhanVien, std::string chucVu, double luongCoBan , double heSoLuong, std::string phongBan,
                        std::string maKiemDinhVien, std::string chuyenMon,int soNamKinhNghiem, std::string hocVi, std::string donViCongTac,
                        std::string khuVucQuanLy , int soLuongNhanSu , float heSoChucVu );

        ~QuanLyCuaHang() override;

        void nhap() override ; 
        void xuat() const override; 

        friend std::istream& operator>>(std::istream& is , QuanLyCuaHang& qlch);
        friend std::ostream& operator<<(std::ostream& os , const QuanLyCuaHang& qlch);

        double tinhPhuCap() const ; 

        void capNhatSoNhanSu(int n) ; 

};





