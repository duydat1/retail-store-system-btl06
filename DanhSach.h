#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class DanhSach{
    private:
        T* ds;
        int soLuong;
        int sucChua;

        void moRong(){
            int sucChuaMoi =(sucChua == 0) ? 10 : sucChua * 2;
            T* temp = new T[sucChuaMoi];
            for(int i = 0; i < soLuong; i++){
                temp[i] = ds[i];
            }
            delete[] ds;
            ds = temp;
            sucChua = sucChuaMoi;
        }

    public:
        DanhSach(int cap = 10) : soLuong(0), sucChua(cap){
            ds = new T[sucChua];
        }

        ~DanhSach(){
            delete[] ds;
        }

        // Chặn sao chép nông để tránh lỗi double free(Mục 12.8)
        DanhSach(const DanhSach&) = delete;
        DanhSach& operator=(const DanhSach&) = delete;

        int laySoLuong() const{ return soLuong; }
        T* layMang(){ return ds; } // Hỗ trợ truyền mảng vào các hàm sắp xếp/tìm kiếm

        T& operator[](int index){
            if(index < 0 || index >= soLuong){
                throw out_of_range("Chi so khong hop le!");
            }
            return ds[index];
        }

        const T& operator[](int index) const{
            if(index < 0 || index >= soLuong){
                throw out_of_range("Chi so khong hop le!");
            }
            return ds[index];
        }

        // 1. Thêm cuối
        bool them(const T& obj){
            if(soLuong == sucChua) moRong();
            ds[soLuong++] = obj;
            return true;
        }

        // 2. Xóa tại vị trí
        bool xoa(int viTri){
            if(viTri < 0 || viTri >= soLuong) return false;
            for(int i = viTri; i < soLuong - 1; i++){
                ds[i] = ds[i + 1];
            }
            soLuong--;
            return true;
        }

        // 3. Sửa tại vị trí
        bool sua(int viTri, const T& obj){
            if(viTri < 0 || viTri >= soLuong) return false;
            ds[viTri] = obj;
            return true;
        }

        // 4. Chèn tại vị trí k
        bool chen(int k, const T& obj){
            if(k < 0 || k > soLuong) return false;
            if(soLuong == sucChua) moRong();
            for(int i = soLuong; i > k; i--){
                ds[i] = ds[i - 1];
            }
            ds[k] = obj;
            soLuong++;
            return true;
        }

        // 5. Xuất danh sách(Dùng cho đối tượng thường, con trỏ MatHang* duyệt ở menu)
        void xuatDanhSach() const{
            for(int i = 0; i < soLuong; i++){
                ds[i].xuat();
            }
        }

        // 6. Tìm kiếm theo điều kiện tùy chỉnh(Lambda/Hàm)
        template <typename Predicate>
        int timKiem(Predicate dieuKien) const{
            for(int i = 0; i < soLuong; i++){
                if(dieuKien(ds[i])) return i;
            }
            return -1;
        }

        // 7. Sắp xếp theo tiêu chí tùy chỉnh
        template <typename Compare>
        void sapXep(Compare cmp){
            for(int i = 0; i < soLuong - 1; i++){
                for(int j = 0; j < soLuong - i - 1; j++){
                    if(!cmp(ds[j], ds[j + 1])){
                        T temp = ds[j];
                        ds[j] = ds[j + 1];
                        ds[j + 1] = temp;
                    }
                }
            }
        }
};