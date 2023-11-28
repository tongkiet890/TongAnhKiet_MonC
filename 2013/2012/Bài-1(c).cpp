// Tập tin PhanSo.cpp
#include "PhanSo.h"

PhanSo::PhanSo() : tu(0), mau(1) {}

PhanSo::PhanSo(int tu, int mau) : tu(tu), mau(mau) {}

PhanSo PhanSo::operator+(const PhanSo& other) const {
    PhanSo result;
    result.tu = this->tu * other.mau + other.tu * this->mau;
    result.mau = this->mau * other.mau;
    return result;
}

PhanSo PhanSo::operator++() {
    // Tăng giá trị của phân số lên 1
    this->tu += this->mau;
    return *this;
}

PhanSo PhanSo::operator++(int) {
    PhanSo temp = *this;
    ++(*this);
    return temp;
}

void PhanSo::operator+=(const PhanSo& other) {
    *this = *this + other;
}

PhanSo::operator int() const {
    // Chuyển đổi phân số thành phần nguyên (lấy phần nguyên của phân số)
    return tu / mau;
}

ostream& operator<<(ostream& os, const PhanSo& ps) {
    os << ps.tu << "/" << ps.mau;
    return os;
}
