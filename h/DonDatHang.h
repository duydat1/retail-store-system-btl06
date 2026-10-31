#pragma once
#include<bits/stdc++.h>
#include "./KhachHang.h"
#include "./MatHang.h"

class DonDatHang{
    private:
        std::string maGiaoDich , maKhachHang , maHang , ngayDangKy , trangThai ;
        double soTienDangKy ;
        bool daThanhToan ; 

        //Các hàm kiểm tra nghiệp vụ bổ sung 
        bool kiemTraMaKhachHang(const std::string& maKH);
        bool kiemTraMaHangVaLayChiPhi(const std::string& maH,double& chiPhi );
        bool kiemTraTrungGiaoDich(const std::string& maGD);
        std::string time_Dangky();

    public:
        DonDatHang() ; 

        DonDatHang(std::string maGiaoDich , std::string maKhachHang , std::string maHang , std::string ngayDangKy ,
                    std::string trangThai , double soTienDangKy , bool daThanhToan );
        
        ~DonDatHang();

        void nhap();
        bool taoGiaoDich();
        bool huyGiaoDich();
        void thanhToan();
        bool kiemTraThanhToan() const;
        void xuat() const;
        
        friend std::istream& operator>>(std::istream& is , DonDatHang& ddh);
        friend std::ostream& operator<<(std::ostream& os ,const DonDatHang& ddh);



};










