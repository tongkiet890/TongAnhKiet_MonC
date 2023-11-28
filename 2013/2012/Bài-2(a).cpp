#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Vẽ một hình." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Vẽ một hình tròn." << std::endl;
    }
};

int main() {
    Shape* hinh1 = new Shape();
    Shape* hinh2 = new Circle();

    hinh1->draw(); // Vẽ một hình.
    hinh2->draw(); // Vẽ một hình tròn.

    delete hinh1;
    delete hinh2;

    return 0;
}
