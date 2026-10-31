#include<bits/stdc++.h>
#include "../h/HangPhoThong.h"
using namespace std ; 

//Hàm ko tham số 
HangPhoThong::HangPhoThong() : MatHang(){
        this->nhomHang = "" ; 
        this->heSoGia = 0.0 ;
}

// Hàm có tham số 
HangPhoThong::HangPhoThong(string maHang, string tenHang, int soLuongDongGoi, double donGiaCoBan, string maKiemDinhVien,
                            string nhomHang , double heSoGia
    ): MatHang(maHang , tenHang , soLuongDongGoi , donGiaCoBan , maKiemDinhVien) {
        this->nhomHang = nhomHang ; 
        this->heSoGia = heSoGia ; 
}

// Hàm hủy 
HangPhoThong::~HangPhoThong(){}

// Hàm nhập 
void HangPhoThong::nhap(){
    MatHang::nhap();
    cout << "Nhap nhom hang : " ; getline(cin>>ws,nhomHang);
    do{
        cout<<"He so gia : " ; cin >> heSoGia ; 
        if(heSoGia <= 0 ) cout << "Loi! He so gia phai > 0 . Nhap lai!" <<endl;
    }while(heSoGia <= 0 );
}

//Hàm xuất 
void HangPhoThong::xuat() const {
    MatHang::xuat();
    cout << " | Nhom hang : " << nhomHang 
        << " | He so gia : " << heSoGia ; 
}

istream& operator>>(istream& is , HangPhoThong& hpt){
    hpt.nhap(); 
    return is ;
}

ostream& operator<<(ostream& os , const HangPhoThong& hpt){
    hpt.xuat() ; 
    return os ; 
}

//Hàm tính chi phí 
double HangPhoThong::tinhChiPhi() const{
    return donGiaCoBan*heSoGia ; 
}

void HangPhoThong::docTuFile(ifstream& in) {
    // 1. Đọc 5 thuộc tính chung của MatHang
    in >> ws; getline(in, maHang, '|');
    in >> ws; getline(in, tenHang, '|');
    in >> soLuongDongGoi;
    in.ignore(1, '|'); // Bỏ qua dấu ngăn cách
    in >> donGiaCoBan;
    in.ignore(1, '|');
    in >> ws; getline(in, maKiemDinhVien, '|');

    // 2. Đọc 2 thuộc tính riêng của HangPhoThong
    in >> ws; getline(in, nhomHang, '|');
    in >> heSoGia;
    in.ignore(); // Bỏ qua ký tự xuống dòng
}


