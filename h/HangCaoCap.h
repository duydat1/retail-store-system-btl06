#pragma once
#include "MatHang.h"
#include<bits/stdc++.h> 

class HangCaoCap: public MatHang{
    private:
        std::string yeuCauBaoQuan;
        double heSoCaoCap;
        bool coBaoHanh ;
    public : 
        HangCaoCap();
        
        HangCaoCap(std::string maHang, std::string tenHang, int soLuongDongGoi, double donGiaCoBan, std::string maKiemDinhVien,
        std::string yeuCauBaoQuan , double heSoCaoCap , bool coBaoHanh);

        ~HangCaoCap();

        void nhap() override ; 
        void xuat() const override ; 

        friend std::istream& operator>>(std::istream& is , HangCaoCap& hcc);
        friend std::ostream& operator<<(std::ostream& is ,const HangCaoCap& hcc);

        double tinhChiPhi() const override ;

        std::string kiemTraDieuKien() const ; 


};




