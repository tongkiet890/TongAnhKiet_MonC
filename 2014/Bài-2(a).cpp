#include <iostream>
#include <string>

class IFace {
public:
    virtual void show() = 0;
    virtual IFace* clone() = 0;
    virtual ~IFace() {}
};

class Face : public IFace {
private:
    std::string shape;

protected:
    std::string getShape();

public:
    Face(std::string sh) : shape(sh) {}

    virtual void show() override {
        std::cout << "Shape: " << shape << std::endl;
    }
};

class EyedFace : public Face {
private:
    int eyes;

public:
    // Constructor
    EyedFace(std::string sh, int e) : Face(sh), eyes(e) {}

    // Override show method
    void show() override {
        Face::show();
        std::cout << "Eyes: " << eyes << std::endl;
    }

    // Override clone method
    IFace* clone() override {
        return new EyedFace(*this);
    }
};

int main() {
    EyedFace myEyedFace("Round", 2);

    // Show the EyedFace
    myEyedFace.show();

    // Clone the EyedFace
    IFace* clonedEyedFace = myEyedFace.clone();

    // Show the cloned EyedFace
    clonedEyedFace->show();

    // Clean up
    delete clonedEyedFace;

    return 0;
}
