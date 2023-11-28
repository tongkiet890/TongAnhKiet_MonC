// Tập tin PhanSo.h
#ifndef _PhanSo_h
#define _PhanSo_h
#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    // Constructor
    PhanSo();
    PhanSo(int tu, int mau);

    // Phép cộng
    PhanSo operator+(const PhanSo& other) const;

    // Phép ++ (tăng giá trị của phân số lên 1)
    PhanSo operator++();    // Tiền tố
    PhanSo operator++(int); // Hậu tố

    // Phép cộng và gán
    void operator+=(const PhanSo& other);

    // Chuyển đổi sang kiểu int (lấy phần nguyên của phân số)
    operator int() const;

    // Hàm in phân số
    friend ostream& operator<<(ostream& os, const PhanSo& ps);
};

#endif
