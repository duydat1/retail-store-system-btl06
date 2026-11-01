
#include "./DanhGiaDonHang.h"
using namespace std ; 

bool DanhGiaDonHang::kiemTraMaKhachHang(const string& maKH){
    ifstream file("ThuMucDuLieu/KhachHang.txt");
    if(!file.is_open() || maKH.empty()) return false;

    string line;
    while(getline(file, line)){
        size_t pos = line.find('|');
        if(pos == string::npos) continue;

        string maTrongFile = line.substr(0, pos);
        if(maTrongFile == maKH) return true;
    }
    return false;
}

bool DanhGiaDonHang::kiemTraMaHang(const string& maH){
    ifstream file("ThuMucDuLieu/MatHang.txt");
    if(!file.is_open() || maH.empty()) return false ; 

    string line ; 
    while(getline(file , line)){
        size_t pos = line.find('|');
        if(pos == string::npos) continue ;

        string maTrongFile = line.substr(0,pos);
        if(maTrongFile == maH) return true ; 
    }
    return false ; 
}

DanhGiaDonHang::DanhGiaDonHang(){
    this->maKetQua = "" ; 
    this->maKhachHang = "" ; 
    this->maHang = "" ; 
    this->diemDongGoi = 0.0; 
    this->diemChatLuong = 0.0 ; 
    this->diemGiaoHang = 0.0 ; 
    this->diemTongKet = 0.0 ; 
    this->xepLoai = "";
}

DanhGiaDonHang::DanhGiaDonHang(string maKetQua , string maKhachHang ,string maHang ,double diemDongGoi , double diemChatLuong , double diemGiaoHang , double diemTongKet ,string xepLoai ){
    this->maKetQua = maKetQua ; 
    this->maKhachHang = maKhachHang; 
    this->maHang = maHang ; 
    this->diemDongGoi = diemDongGoi; 
    this->diemChatLuong = diemChatLuong ; 
    this->diemGiaoHang = diemGiaoHang ; 
    this->diemTongKet = diemTongKet ; 
    this->xepLoai = xepLoai ;
}

DanhGiaDonHang::~DanhGiaDonHang(){}

void DanhGiaDonHang::nhap(){
    bool check ; 
    cout << "Nhap ma ket qua : " ; getline(cin>>ws , maKetQua);

    do{
        cout << "1. Nhap ma khach hang : ";getline(cin>>ws , maKhachHang);
        check = kiemTraMaKhachHang(maKhachHang);
        if(!check) cout << "Loi! Ma khach hang khong ton tai. Nhap lai!\n";
    }while(!check);

    do {
        cout << "2. Nhap ma hang : " ; getline(cin>>ws , maHang);
        check = kiemTraMaHang(maHang);
        if(!check) cout << "Loi! Ma hang khong ton tai. Nhap lai!\n";
    } while(!check);

    do{
        cout << "3. Diem dong goi : " ; cin >> diemDongGoi;
        if(diemDongGoi > 10.0 || diemDongGoi < 0.0 ) cout << "Loi! Diem dong goi phai >0 or <10. Nhap lai!\n";
    }while(diemDongGoi > 10.0 || diemDongGoi < 0.0 );

    do{
        cout << "4. Diem chat luong : " ; cin >> diemChatLuong;
        if(diemChatLuong > 10.0 || diemChatLuong < 0.0 ) cout << "Loi! Diem chat luong phai >0 or <10. Nhap lai!\n";
    }while(diemChatLuong > 10.0 || diemChatLuong < 0.0 );

    do{
        cout << "5. Diem giao hang: " ; cin >> diemGiaoHang;
        if(diemGiaoHang > 10.0 || diemGiaoHang < 0.0 ) cout << "Loi! Diem giao hang phai >0 or <10. Nhap lai!\n";
    }while(diemGiaoHang > 10.0 || diemGiaoHang < 0.0 );

    this->diemTongKet = tinhDiemTongKet();
    this->xepLoai = xepLoaiKetQua();
}

double DanhGiaDonHang::getdiemTongKet() const{
    return diemTongKet;
}

double DanhGiaDonHang::tinhDiemTongKet() const{
    return 0.1*this->diemDongGoi + 0.3*this->diemChatLuong + 0.6*this->diemGiaoHang;
}

string DanhGiaDonHang::xepLoaiKetQua() const{
    double diemTongKet = tinhDiemTongKet() ; 
    if(diemTongKet >= 8.5 ) return "Gioi" ; 
    if(diemTongKet >=7) return "Kha" ; 
    if(diemTongKet >=5) return "Trung binh" ;
    return "Yeu" ;   
} 

void DanhGiaDonHang::xuat() const{
    cout << "1. Ma ket qua : " << maKetQua << endl;
    cout << "2. Ma khach hang : " << maKhachHang << endl;
    cout << "3. Ma Hang : " << maHang << endl;
    cout << "4. Diem dong goi : " << diemDongGoi << endl ; 
    cout << "5. Diem chat luong : " << diemChatLuong << endl ; 
    cout << "6. Diem giao hang : " << diemGiaoHang << endl;
    cout << "7. Diem tong ket : " << this->diemTongKet << endl ;
    cout << "8. Xep loai : " << this->xepLoai << endl ;
}

void DanhGiaDonHang::capNhatDiem(){
    do{
        cout << "1. Diem dong goi : " ; cin >> diemDongGoi;
        if(diemDongGoi > 10.0 || diemDongGoi < 0.0 ) cout << "Loi! Diem dong goi phai >0 or <10. Nhap lai!\n";
    }while(diemDongGoi > 10.0 || diemDongGoi < 0.0 );

    do{
        cout << "2. Diem chat luong : " ; cin >> diemChatLuong;
        if(diemChatLuong > 10.0 || diemChatLuong < 0.0 ) cout << "Loi! Diem chat luong phai >0 or <10. Nhap lai!\n";
    }while(diemChatLuong > 10.0 || diemChatLuong < 0.0 );

    do{
        cout << "3. Diem giao hang: " ; cin >> diemGiaoHang;
        if(diemGiaoHang > 10.0 || diemGiaoHang < 0.0 ) cout << "Loi! Diem giao hang phai >0 or <10. Nhap lai!\n";
    }while(diemGiaoHang > 10.0 || diemGiaoHang < 0.0 );

    this->diemTongKet = tinhDiemTongKet();
    this->xepLoai = xepLoaiKetQua();
    
    cout << "Da cap nhat thanh cong "<< endl ;
    cout << "Diem tong ket moi: " << this->diemTongKet << endl ;
    cout << "Xep loai: " << this->xepLoai << endl;
}

istream& operator>>(istream& is , DanhGiaDonHang& dgdh){
    dgdh.nhap();
    return is ; 
}    
ostream& operator<<(ostream& os ,const DanhGiaDonHang& dgdh){
    dgdh.xuat();
    return os ;
}
