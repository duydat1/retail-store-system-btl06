#include<bits/stdc++.h>
#include "../h/KiemDinhVien.h"
using namespace std ; 

//Hàm mặc định 
KiemDinhVien::KiemDinhVien() : Nguoi(){
    this->maKiemDinhVien = "";
    this->chuyenMon = "" ; 
    this->soNamKinhNghiem = 0 ; 
    this->heSoLuong = 0.0 ; 
    this->hocVi = "" ;
    this->donViCongTac = "" ; 
    this->luongCoBan = 0.0 ; 
}
// Hàm tạo có tham số 
KiemDinhVien::KiemDinhVien(string maNguoi, string hoTen, string ngaySinh, string email,
                        string maKiemDinhVien, string chuyenMon , int soNamKinhNghiem, double heSoLuong, string hocVi,string donViCongTac, double luongCoBan)
    :Nguoi(maNguoi, hoTen, ngaySinh, email)
    {
        this->maKiemDinhVien = maKiemDinhVien ;
        this->chuyenMon = chuyenMon ; 
        this->soNamKinhNghiem = soNamKinhNghiem ; 
        this->heSoLuong = heSoLuong ; 
        this->hocVi = hocVi ; 
        this->donViCongTac = donViCongTac ; 
        this->luongCoBan = luongCoBan; 
    }

//Hàm hủy
KiemDinhVien::~KiemDinhVien(){}

//Hàm nhập 
void KiemDinhVien::nhap(){
    Nguoi::nhap();
    cout << "Nhap ma kiem dinh vien : " ; getline(cin>>ws , maKiemDinhVien);
    cout << "Nhap chuyen mon : " ; getline(cin,chuyenMon);

    do{
        cout << "Nhap so nam kinh nghiem : " ; cin >> soNamKinhNghiem;
        if(soNamKinhNghiem < 0 ) cout << "Loi! So nam kinh nghiem phai > 0 . Nhap lai!\n";
    }while(soNamKinhNghiem < 0);

    do{
        cout << "Nhap he so luong : " ; cin >> heSoLuong ; 
        if(heSoLuong <= 0 ) cout << "Loi! He so luong phai > 0 . Nhap lai!\n";
    }while(heSoLuong <= 0 );
    cin.ignore();
    cout << "Nhap hoc vi : " ; getline(cin,hocVi);
    cout << "Nhap don vi cong tac : " ; getline(cin,donViCongTac) ; 
    
    do{
        cout << "Nhap luong co ban : " ; cin >> luongCoBan;
        if(luongCoBan <= 0 ) cout << "Loi! So nam kinh nghiem phai >0 . Nhap lai!\n";
    }while(luongCoBan <= 0 );
}

//Hàm xuất 
void KiemDinhVien::xuat() const{
    Nguoi::xuat() ; 
    cout << " Ma kiem dinh vien : " << maKiemDinhVien
        << " | Chuyen mon : " << chuyenMon
        << " | So nam kinh nghiem : " << soNamKinhNghiem
        << " | He so luong : " << heSoLuong  
        << " | Hoc vi : " << hocVi
        << " | Don vi cong tac : " << donViCongTac
        << " | Luong co ban : " << luongCoBan
        << " | Luong duoc nhan : " << tinhLuong() << endl;
}

// Nạp chồng toán tử >>
istream& operator>>(istream& is, KiemDinhVien& kdv) {
    kdv.nhap();
    return is;
}

// Nạp chồng toán tử <<
ostream& operator<<(ostream& os, const KiemDinhVien& kdv) {
    kdv.xuat();
    return os;
}

double KiemDinhVien::tinhLuong() const {
    return luongCoBan*heSoLuong + soNamKinhNghiem*100000 ; 
}

string KiemDinhVien::danhGiaKinhNghiem() const{
    if(soNamKinhNghiem < 2 ) return "Moi";
    if(soNamKinhNghiem <= 5 ) return "Co Kinh Nghiem";
    return "Giau Kinh Nghiem";
}

//Hàm nhập riêng 
void KiemDinhVien::nhapkdv(){
    cout << "Nhap ma kiem dinh vien : " ; getline(cin>>ws , maKiemDinhVien);
    cout << "Nhap chuyen mon : " ; getline(cin,chuyenMon);

    do{
        cout << "Nhap so nam kinh nghiem : " ; cin >> soNamKinhNghiem;
        if(soNamKinhNghiem < 0 ) cout << "Loi! So nam kinh nghiem phai > 0 . Nhap lai!\n";
    }while(soNamKinhNghiem < 0);

    do{
        cout << "Nhap he so luong : " ; cin >> heSoLuong ; 
        if(heSoLuong <= 0 ) cout << "Loi! He so luong phai > 0 . Nhap lai!\n";
    }while(heSoLuong <= 0 );
    cin.ignore();
    cout << "Nhap hoc vi : " ; getline(cin,hocVi);
    cout << "Nhap don vi cong tac : " ; getline(cin,donViCongTac) ; 
    
    do{
        cout << "Nhap luong co ban : " ; cin >> luongCoBan;
        if(luongCoBan <= 0 ) cout << "Loi! So nam kinh nghiem phai >0 . Nhap lai!\n";
    }while(luongCoBan <= 0 );
}

//Hàm xuất riêng 
void KiemDinhVien::xuatkdv() const{
    cout << " | Ma kiem dinh vien : " << maKiemDinhVien
        << " | Chuyen mon : " << chuyenMon
        << " | So nam kinh nghiem : " << soNamKinhNghiem
        << " | He so luong : " << heSoLuong  
        << " | Hoc vi : " << hocVi
        << " | Don vi cong tac : " << donViCongTac
        << " | Luong co ban : " << luongCoBan
        << " | Luong duoc nhan : " << tinhLuong() ;
}




