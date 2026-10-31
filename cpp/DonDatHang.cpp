#include<bits/stdc++.h>
#include "../h/DonDatHang.h"
#include "../h/HangPhoThong.h"
#include "../h/HangCaoCap.h"
using namespace std ; 


// Kiểm tra mã khách hàng tồn tại trong KhachHang.txt
bool DonDatHang::kiemTraMaKhachHang(const string& maKH) {
    ifstream file("ThuMucDuLieu/KhachHang.txt");
    if(!file.is_open() || maKH.empty()) return false;

    string line;
    while(getline(file, line)) {
        size_t pos = line.find('|');
        if(pos == string::npos) continue;

        string maTrongFile = line.substr(0, pos);
        if(maTrongFile == maKH) return true;
    }
    return false;
}

// Kiểm tra mã hàng tồn tại trong MatHang.txt sau đó tính chi phí 
bool DonDatHang::kiemTraMaHangVaLayChiPhi(const string& maH, double &chiPhi) {
    ifstream file("ThuMucDuLieu/MatHang.txt");
    if(!file.is_open() || maH.empty()) return false;

    int loaiHang;
    // Gắn 1 (Phổ thông) hoặc 2 (Cao cấp) ở đầu mỗi dòng
    while(file >> loaiHang) {
        MatHang* mh = nullptr;
        if(loaiHang == 1) mh = new HangPhoThong();
        else if(loaiHang == 2) mh = new HangCaoCap();
        else {
            // Không hợp lệ thì bỏ qua dòng này luôn 
            string temp; getline(file, temp);
            continue;
        }
        // Gọi hàm ảo đọc nốt phần dữ liệu còn lại của dòng (Bạn cần viết hàm này ở 2 class con)
        mh->docTuFile(file);

        if(mh->getMaHang() == maH) {
            chiPhi = mh->tinhChiPhi(); // Tính chi phí đa hình
            delete mh;
            file.close();
            return true;
        }
        delete mh;
    }
    file.close();
    return false;
}

//Kiểm tra trùng lặp mã giao hàng trong DonDatHang.txt
bool DonDatHang::kiemTraTrungGiaoDich(const string& maGD) {
    ifstream file("ThuMucDuLieu/DonDatHang.txt");
    if(!file.is_open() || maGD.empty()) return false;

    string line;
    while(getline(file, line)){
        size_t pos = line.find('|');
        if(pos == string::npos) continue;

        string maTrongFile = line.substr(0, pos);
        if(maTrongFile == maGD) return true;// Trùng mã
    }
    return false;// Không trùng
}

//Ngày đăng ký 
string DonDatHang::time_Dangky() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    stringstream ss;
    ss << setw(2) << setfill('0') << ltm->tm_mday << "/"
        << setw(2) << setfill('0') << ltm->tm_mon + 1 << "/"
        << ltm->tm_year + 1900;

    return ss.str();
}

DonDatHang::DonDatHang(){
    this->maGiaoDich = "" ; 
    this->maKhachHang = "" ; 
    this->maHang = "" ; 
    this->ngayDangKy = "" ; 
    this->trangThai = "" ; 
    this->soTienDangKy = 0.0 ; 
    this->daThanhToan = 0 ;
}

DonDatHang::DonDatHang(std::string maGiaoDich , std::string maKhachHang , std::string maHang , std::string ngayDangKy ,
                    std::string trangThai , double soTienDangKy , bool daThanhToan ){
        this->maGiaoDich = maGiaoDich ; 
        this->maKhachHang = maKhachHang ; 
        this->maHang = maHang ; 
        this->ngayDangKy = ngayDangKy ; 
        this->trangThai = trangThai ; 
        this->soTienDangKy = soTienDangKy ; 
        this->daThanhToan = daThanhToan ;
        }

DonDatHang::~DonDatHang(){}

void DonDatHang::nhap() {
    cout << "Nhap ma giao dich: "; getline(cin >> ws, maGiaoDich);
    cout << "Nhap ma khach hang: "; getline(cin, maKhachHang);
    cout << "Nhap ma hang: "; getline(cin, maHang);
    this->ngayDangKy = time_Dangky();
    cout << "Nhap so tien thanh toan: "; cin >> soTienDangKy;
    this->trangThai = "Da dang ky";
    this->daThanhToan = false;
}

bool DonDatHang::taoGiaoDich(){
    bool check ; 
    do{
        cout << "1. Nhap ma khach hang : ";getline(cin>>ws , maKhachHang);
        check = kiemTraMaKhachHang(maKhachHang);
        if(!check) cout << "Loi! Ma khach hang khong ton tai. Nhap lai!\n";
    }while(!check);

    do {
        cout << "2. Nhap ma hang : " ; getline(cin>>ws , maHang);
        check = kiemTraMaHangVaLayChiPhi(maHang, this->soTienDangKy);
        if(!check) cout << "Loi! Ma hang khong ton tai. Nhap lai!\n";
    } while(!check);

    do{
        cout << "3. Nhap ma giao dich : "; getline(cin >> ws, maGiaoDich);
        check = kiemTraTrungGiaoDich(maGiaoDich);
        if(check) cout << "Loi! Ma giao dich da ton tai. Nhap lai!\n";
    }while(check);
    
    this->ngayDangKy = time_Dangky();
    cout << "4. Ngay dang ky giao dich: " << this->ngayDangKy << "\n";
    
    this->trangThai = "Da dang ky";
    this->daThanhToan = false;
    
    cout << "=> So tien phai thanh toan: " << fixed << setprecision(0) << this->soTienDangKy << " VND\n";
    cout << "=> Tao giao dich thanh cong!\n";
    
    return true;
}

bool DonDatHang::huyGiaoDich() {
    if (trangThai == "Da huy") {
        cout << "Loi! Don hang nay da bi huy tu truoc do!\n";
        return false;
    }
    // Cập nhật trạng thái
    trangThai = "Da huy";
    cout << "=> Da huy giao dich thanh cong!\n";
    return true;
}

void DonDatHang::thanhToan() {
    if (daThanhToan) {
        cout << "Thong bao: Don hang da duoc thanh toan truoc do, khong ghi lap!\n";
    } else {
        daThanhToan = true;
        cout << "=> Thanh toan thanh cong so tien: " << fixed << setprecision(0) << soTienDangKy << " VND\n";
    }
}

bool DonDatHang::kiemTraThanhToan() const {
    return daThanhToan; // Trả true nếu đã thanh toán 
}

void DonDatHang::xuat() const {
    cout << "\n--- THONG TIN DON DAT HANG ---\n";
    cout << "Ma GD: " << maGiaoDich << endl;
    cout << "Ma KH: " << maKhachHang << endl;
    cout << "Ma Hang: " << maHang << endl;
    cout << "Ngay dang ky: " << ngayDangKy << endl;
    cout << "Trang thai GD: " << trangThai << endl;
    cout << "So tien phai TT: " << fixed << setprecision(0) << soTienDangKy << " VND\n";
    cout << "Thanh toan: " << (daThanhToan ? "Da thanh toan" : "Chua thanh toan") << endl;
}










