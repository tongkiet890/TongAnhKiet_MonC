class EyedFace : public Face {
private:
    static int objectCount;  // Thêm một biến tĩnh để đếm số đối tượng

public:
    // Constructor
    EyedFace(std::string sh, int e) : Face(sh) {
        eyes = e;
        objectCount++;  // Tăng số đối tượng khi tạo mới
    }

    // Destructor
    ~EyedFace() {
        objectCount--;  // Giảm số đối tượng khi huỷ
    }

    // Static method để lấy số đối tượng
    static int getObjectCount() {
        return objectCount;
    }

    
    IFace* clone() override {
        return new EyedFace(*this);
    }
};

int EyedFace::objectCount = 0;  // Khởi tạo giá trị cho biến tĩnh

void testFace(IFace* fc) {
    IFace* a[3] = {fc, fc->clone(), fc->clone()};
    for (int i = 0; i < 3; i++) {
        a[i]->show();
    }
    std::cout << "The same 3 lines?" << std::endl;
}

int main() {
    EyedFace fc1("Rectangle", 2);
    testFace(&fc1);

    // Kiểm tra số đối tượng EyedFace sau khi chạy hàm testFace
    std::cout << "Number of EyedFace objects: " << EyedFace::getObjectCount() << std::endl;

    return 0;
}
