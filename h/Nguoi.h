#pragma once
#include<bits/stdc++.h>
class Nguoi {
protected:
    std::string maNguoi;
    std::string hoTen;
    std::string ngaySinh;
    std::string email;

public:
    // Hàm tạo mặc định
    Nguoi();

    // Hàm tạo có tham số
    Nguoi(std::string maNguoi, std::string hoTen, std::string ngaySinh, std::string email);

    // Virtual destructor để hủy an toàn qua con trỏ lớp cơ sở
    virtual ~Nguoi();

    // Hàm nhập/xuất cơ bản
    virtual void nhap();
    virtual void xuat() const;

    // Nạp chồng toán tử >> và <<
    friend std::istream& operator>>(std::istream& is, Nguoi& n);
    friend std::ostream& operator<<(std::ostream& os, const Nguoi& n);
};






