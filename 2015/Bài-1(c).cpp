class Singleton {
private:
    static Singleton* instance;

    // Constructor riêng tư để ngăn chặn việc tạo đối tượng từ bên ngoài.
    Singleton() {}

public:
    // Hàm static để truy cập đối tượng Singleton.
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Khởi tạo biến static.
Singleton* Singleton::instance = nullptr;

