#pragma once

#include <iostream>
#include <string>

class Nguoi {
protected: 
    std::string maNguoi;
    std::string hoTen;
    std::string ngaySinh;
    std::string email;

public:
    Nguoi();
    Nguoi(std::string maNguoi, std::string hoTen, std::string ngaySinh, std::string email);
    virtual ~Nguoi();

    virtual void nhap();
    virtual void xuat() const;

    friend std::istream& operator>>(std::istream& is, Nguoi& n);
    friend std::ostream& operator<<(std::ostream& os, const Nguoi& n);
};