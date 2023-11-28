#include <iostream>

// Tập tin AbstractClass.h
#ifndef _AbstractClass_h
#define _AbstractClass_h

class LopTruuTuong {
public:
    // Phương thức thuần ảo
    virtual void phuongThucTuanAo() = 0;

    // Phương thức có triển khai
    void phuongThucCoTrienKhai() {
        std::cout << "Cac cong viec cu the cua phuong thuc co trien khai." << std::endl;
    }
};

#endif

// Tập tin ConcreteClass.cpp
#include "AbstractClass.h"

class LopCon : public LopTruuTuong {
public:
    // Triển khai phương thức thuần ảo
    void phuongThucTuanAo() override {
        std::cout << "Trien khai cua phuong thuc tuan ao." << std::endl;
    }
};

// Tập tin main.cpp
#include "AbstractClass.h"

int main() {
    LopCon doiTuong;
    doiTuong.phuongThucTuanAo();    // Trien khai cua phuong thuc tuan ao.
    doiTuong.phuongThucCoTrienKhai(); // Cac cong viec cu the cua phuong thuc co trien khai.

    return 0;
}
