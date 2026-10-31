#pragma once
#include "MatHang.h"
#include<bits/stdc++.h>

class HangPhoThong:public MatHang{
    private : 
        std::string nhomHang ; 
        double heSoGia ; 
    public :
        HangPhoThong();

        HangPhoThong(std::string maHang, std::string tenHang, int soLuongDongGoi, double donGiaCoBan, std::string maKiemDinhVien,
                    std::string nhomHang , double heSoGia);

        ~HangPhoThong();

        void nhap() override;
        void xuat() const override ; 

        friend std::istream& operator>>(std::istream& is , HangPhoThong& hpt);
        friend std::ostream& operator<<(std::ostream& os , const HangPhoThong& hpt) ;

        double tinhChiPhi() const override ; 

        void docTuFile(std::ifstream& in) override;


};




