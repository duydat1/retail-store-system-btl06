#include<bits/stdc++.h>
#include "../h/HangCaoCap.h"
using namespace std ;

//Hàm tạo ko tham số 
HangCaoCap::HangCaoCap() : MatHang(){
    this->yeuCauBaoQuan = "";
    this->heSoCaoCap = 0.0 ; 
    this->coBaoHanh = true ; 
}

// Hàm tạo có tham số 
HangCaoCap::HangCaoCap(string maHang, std::string tenHang, int soLuongDongGoi, double donGiaCoBan,string maKiemDinhVien,
                        string yeuCauBaoQuan , double heSoCaoCap , bool coBaoHanh
):MatHang(maHang , tenHang , soLuongDongGoi , donGiaCoBan , maKiemDinhVien ){
    this->yeuCauBaoQuan = yeuCauBaoQuan;
    this->heSoCaoCap = heSoCaoCap;
    this->coBaoHanh = coBaoHanh ; 
}

// Hàm hủy 
HangCaoCap::~HangCaoCap(){}

//Hàm nhập 
void HangCaoCap::nhap(){
    MatHang::nhap();
    cout <<"Nhap yeu cau bao quan : " ; getline(cin>>ws , yeuCauBaoQuan);
    do{
        cout << "Nhap he so cao cap : " ; cin >> heSoCaoCap ; 
        if(heSoCaoCap <= 0 ) cout << "Loi! He so cao cap phai > 0. Nhap lai!" << endl ;
    }while(heSoCaoCap <= 0 );
    int temp;
    cout << "Nhap co bao hanh khong (1 or 0): "; cin >> temp;
    coBaoHanh = (temp != 0);
}

//Hàm xuất 
void HangCaoCap::xuat() const{
    MatHang::xuat();
    cout <<" | Yeu cau bao quan : " << yeuCauBaoQuan 
        << " | He so cao cap : " << heSoCaoCap 
        << " | Bao hanh : " << coBaoHanh ; 
}

istream& operator>>(istream& is , HangCaoCap& hcc){
    hcc.nhap();
    return is ;
}


ostream& operator<<(ostream& os , const HangCaoCap& hcc){
    hcc.xuat() ; 
    return os ; 
}

//Hàm tính chi phí 
double HangCaoCap::tinhChiPhi() const{
    return donGiaCoBan*heSoCaoCap ; 
}

//Hàm kiểm tra điều kiện 
string HangCaoCap::kiemTraDieuKien() const{
    if(coBaoHanh) return "Co Bao Hanh";
    return "Khong bao hanh";
}


