#pragma once
#include "Nguoi.h"

class KiemDinhVien:virtual public Nguoi{
    private:
        std::string maKiemDinhVien , chuyenMon , hocVi , donViCongTac ;
        double heSoLuong , luongCoBan ;
        int soNamKinhNghiem ; 
    public : 
        KiemDinhVien();

        KiemDinhVien(std::string maNguoi, std::string hoTen, std::string ngaySinh, std::string email,
                    std::string maKiemDinhVien, std::string chuyenMon,int soNamKinhNghiem,double heSoLuong, std::string hocVi, std::string donViCongTac , double luongCoBan);
        
        ~KiemDinhVien() override;

        void nhap() override ; 
        void xuat() const override ; 

        friend std::istream& operator>>(std::istream& is , KiemDinhVien& kdv);
        friend std::ostream& operator<<(std::ostream& os , const KiemDinhVien& kdv );

        double tinhLuong() const ; 

        std::string danhGiaKinhNghiem() const ;    

        void nhapkdv() ; 
        void xuatkdv() const ; 
};






