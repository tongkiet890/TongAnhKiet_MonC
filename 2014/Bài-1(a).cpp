#include <iostream>
#include <cstring>

class Bike {
private:
    char* brand; // hiệu xe
public:
    // Constructor
    Bike(const char* b) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
    }

    // Destructor
    ~Bike() {
        delete[] brand;
    }

    // Copy Constructor
    Bike(const Bike& other) {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
    }

    // Assignment Operator
    Bike& operator=(const Bike& other) {
        if (this != &other) {
            delete[] brand;
            brand = new char[strlen(other.brand) + 1];
            strcpy(brand, other.brand);
        }
        return *this;
    }

    virtual void move(int t1) {
        std::cout << brand << ":" << t1 * 12 << " ";
    }
};

class EBike : public Bike {
public:
    void move(int t2) override {
        Bike::move(t2 * 2);
    }
};
