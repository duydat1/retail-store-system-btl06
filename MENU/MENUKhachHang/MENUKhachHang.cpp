
#include "MENUKhachHang.h"

// 7. Tính điểm trung bình của 1 khách hàng từ danh sách đánh giá 
double tinhDiemTBKhachHang(const string& maKH, const DanhSach<DanhGiaDonHang>& dsDG){
    double tongDiem = 0;
    int dem = 0;
    for(int i = 0; i < dsDG.laySoLuong(); i++){
        if(dsDG[i].getmaKhachHang() == maKH){
            tongDiem += dsDG[i].getdiemTongKet();
            dem++;
        }
    }
    return(dem == 0) ? -1.0 :(tongDiem / dem); // Chưa có đánh giá trả về -1
}

void menuKhachHang(DanhSach<KhachHang>& dsKH, const DanhSach<DanhGiaDonHang>& dsDG){
    int chon;
    do{
        cout << "\n================ MENU QUAN LY KHACH MUA HANG ================" << endl;
        cout << "1. Them khach mua hang" << endl;
        cout << "2. Hien thi danh sach khach mua hang" << endl;
        cout << "3. Tim khach mua hang theo ma" << endl;
        cout << "4. Tim khach mua hang theo ho ten" << endl;
        cout << "5. Sua thong tin khach mua hang" << endl;
        cout << "6. Xoa khach mua hang" << endl;
        cout << "7. Sap xep khach mua hang theo diem TB ket qua danh gia" << endl;
        cout << "8. Chen khach mua hang vao danh sach tai vi tri k" << endl;
        cout << "9. Luu danh sach KhachHang vao tep" << endl;
        cout << "10. Doc danh sach KhachHang tu tep" << endl;
        cout << "0. Quay lai menu chinh" << endl;
        cout << "Nhap lua chon : ";
        cin >> chon;

        switch(chon){
            case 1:{ // Thêm khách mua hàng 
                KhachHang kh ; 
                kh.nhap();
                int idx = sequentialSearch(dsKH.layMang(), dsKH.laySoLuong(), [&](const KhachHang& k){
                    return k.getmaKhachHang() == kh.getmaKhachHang();
                });
                if(idx != -1){
                    cout << "Loi : Ma khach hang da ton tai!" << endl;
                } else{
                    dsKH.them(kh);
                    cout << "Them khach hang thanh cong!" << endl;
                }
                break;
            }
            
            case 2:{ // Hiện thị danh sách khách mua hàng 
                if(dsKH.laySoLuong() == 0 ) cout << "Danh sach trong" << endl ;
                else dsKH.xuatDanhSach(); 
                break ;
            }

            case 3:{ // Tìm khách mua hàng theo mã 
                string ma;
                cout << "Nhap ma khach hang can tim : ";
                cin >> ws; getline(cin, ma);

                quickSort(dsKH.layMang(), 0, dsKH.laySoLuong() - 1, [](const KhachHang& a, const KhachHang& b){
                    return a.getmaKhachHang() < b.getmaKhachHang();
                });

                int idx = binarySearch(dsKH.layMang(), dsKH.laySoLuong(), ma, [](const KhachHang& k){
                    return k.getmaKhachHang();
                });

                if(idx != -1) dsKH[idx].xuat();
                else cout << "Khong tim thay khach hang co ma : " << ma << endl;
                break;
            }

            case 4:{ // Tìm khách mua theo họ tên 
                string ten;
                cout << "Nhap ho ten can tim : ";
                cin >> ws; getline(cin, ten);
                bool timThay = false;
                for(int i = 0; i < dsKH.laySoLuong(); i++){
                    if(dsKH[i].gethoTen().find(ten) != string::npos){
                        dsKH[i].xuat();
                        timThay = true;
                    }
                }
                if(!timThay) cout << "Khong tim thay khach hang ten : " << ten << endl;
                break;
            }

            case 5:{ // Sửa thông tin
                string ma;
                cout << "Nhap ma khach hang can sua : ";
                cin >> ws; getline(cin, ma);
                int idx = sequentialSearch(dsKH.layMang(), dsKH.laySoLuong(), [&](const KhachHang& k){
                    return k.getmaKhachHang() == ma;
                });
                if(idx == -1){
                    cout << "Khong tim thay ma khach hang!" << endl;
                } else{
                    cout << "Nhap thong tin moi:" << endl;
                    KhachHang khMoi;
                    khMoi.nhap();
                    dsKH.sua(idx, khMoi);
                    cout << "Cap nhat thanh cong!" << endl;
                }
                break;
            }
            case 6:{ // Xóa khách hàng
                string ma;
                cout << "Nhap ma khach hang can xoa : ";
                cin >> ws; getline(cin, ma);
                int idx = sequentialSearch(dsKH.layMang(), dsKH.laySoLuong(), [&](const KhachHang& k){
                    return k.getmaKhachHang() == ma;
                });
                if(idx != -1 && dsKH.xoa(idx)){
                    cout << "Da xoa khach hang!" << endl;
                } else{
                    cout << "Khong tim thay ma khach hang!" << endl;
                }
                break;
            }
            case 7:{ // Sắp xếp giảm dần theo điểm TB kết quả đánh giá
                if(dsKH.laySoLuong() == 0){
                    cout << "Danh sach trong!" << endl;
                    break;
                }
                bubbleSort(dsKH.layMang(), dsKH.laySoLuong(), [&](const KhachHang& a, const KhachHang& b){
                    return tinhDiemTBKhachHang(a.getmaKhachHang(), dsDG) > tinhDiemTBKhachHang(b.getmaKhachHang(), dsDG);
                });
                cout << "Da sap xep danh sach theo diem danh gia trung binh giam dan!" << endl;
                dsKH.xuatDanhSach();
                break;
            }
            case 8:{ // Chèn tại vị trí k
                int k;
                cout << "Nhap vi tri k muon chen(0 -> " << dsKH.laySoLuong() << ") : ";
                cin >> k;
                if(k < 0 || k > dsKH.laySoLuong()){
                    cout << "Vi tri khong hop le!" << endl;
                } else{
                    KhachHang kh;
                    kh.nhap();
                    dsKH.chen(k, kh);
                    cout << "Chen thanh cong!" << endl;
                }
                break;
            }
            case 9:{ // Lưu vào tệp
                ofstream fOut("ThuMucDuLieu/KhachHang.txt");
                if(!fOut.is_open()){
                    cout << "Loi mo file ThuMucDuLieu/KhachHang.txt!" << endl;
                    break;
                }
                for(int i = 0; i < dsKH.laySoLuong(); i++){
                    fOut << dsKH[i].getmaNguoi() << "|"
                        << dsKH[i].gethoTen() << "|"
                        << dsKH[i].getngaySinh() << "|"
                        << dsKH[i].getemail() << "|"
                        << dsKH[i].getmaKhachHang() << "|"
                        << dsKH[i].getsoDienThoai() << "|"
                        << dsKH[i].getdiaChi() << "\n";
                }
                fOut.close();
                cout << "Da luu " << dsKH.laySoLuong() << " khach hang vao tep!" << endl;
                break;
            }
            case 10:{ // Đọc từ tệp
                ifstream fIn("ThuMucDuLieu/KhachHang.txt");
                if(!fIn.is_open()){
                    cout << "Khong tim thay file ThuMucDuLieu/KhachHang.txt!" << endl;
                    break;
                }
                while(dsKH.laySoLuong() > 0) dsKH.xoa(0); // Làm sạch danh sách cũ

                string line;
                while(getline(fIn, line)){
                    if(line.empty()) continue;
                    stringstream ss(line);
                    string maN, ten, ns, mail, maKH, sdt, dc;
                    getline(ss, maN, '|');
                    getline(ss, ten, '|');
                    getline(ss, ns, '|');
                    getline(ss, mail, '|');
                    getline(ss, maKH, '|');
                    getline(ss, sdt, '|');
                    getline(ss, dc, '|');

                    KhachHang kh(maN, ten, ns, mail, maKH, sdt, dc);
                    dsKH.them(kh);
                }
                fIn.close();
                cout << "Da doc " << dsKH.laySoLuong() << " khach hang tu tep!" << endl;
                break;
            }
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
            
        }
    }while(chon!=0);
}




