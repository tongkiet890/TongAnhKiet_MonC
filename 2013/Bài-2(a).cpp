#include <iostream>

class CoSo {
public:
    CoSo() {
        std::cout << "Constructor cua CoSo" << std::endl;
    }

    virtual ~CoSo() {
        std::cout << "Destructor cua CoSo" << std::endl;
    }
};

class KeThua : public CoSo {
public:
    KeThua() {
        std::cout << "Constructor cua KeThua" << std::endl;
    }

    ~KeThua() override {
        std::cout << "Destructor cua KeThua" << std::endl;
    }
};

int main() {
    CoSo* obj = new KeThua();
    delete obj; // Gọi hàm hủy ảo và giải phóng bộ nhớ

    return 0;
}
