#pragma once
#include<bits/stdc++.h>
#include "../KhachHang/KhachHang.h"
#include "../MatHang/MatHang.h"

class DanhGiaDonHang{
    private:
        std::string maKetQua , maKhachHang , maHang ;
        double diemDongGoi , diemChatLuong , diemGiaoHang , diemTongKet ; 
        std::string xepLoai ; 

        bool kiemTraMaKhachHang(const std::string& maKH)  ; 
        bool kiemTraMaHang(const std::string& maH) ; 
    public : 
        DanhGiaDonHang();

        DanhGiaDonHang(std::string maKetQua , std::string maKhachHang ,std::string maHang ,double diemDongGoi , double diemChatLuong , double diemGiaoHang , double diemTongKet ,std::string xepLoai );

        ~DanhGiaDonHang();

        void nhap() ; 
        double tinhDiemTongKet() const ; 
        std::string xepLoaiKetQua() const ; 
        void xuat() const ; 
        void capNhatDiem() ; 

        friend std::istream& operator>>(std::istream& is , DanhGiaDonHang& dgdh);
        friend std::ostream& operator<<(std::ostream& os ,const DanhGiaDonHang& dgdh);

        // Các hàm get và set 
        string getmaKhachHang() const { return maKhachHang; }
        double getdiemTongKet() const { return diemTongKet; }
}; 








