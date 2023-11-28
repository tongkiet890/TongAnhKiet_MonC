#include <iostream>

class CoSo {
public:
    CoSo() {
        std::cout << "Constructor cua CoSo" << std::endl;
    }

    ~CoSo() {
        std::cout << "Destructor cua CoSo" << std::endl;
    }
};

class KeThua : public CoSo {
public:
    KeThua() {
        std::cout << "Constructor cua KeThua" << std::endl;
    }

    // Không có hàm hủy ảo
};

int main() {
    CoSo* obj = new KeThua();
    delete obj; // Gọi chỉ hàm hủy của lớp cơ sở, không gọi hàm hủy của lớp kế thừa

    return 0;
}
