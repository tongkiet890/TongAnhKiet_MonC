class HosoBenhAn {
private:
    int msbn;
    std::vector<HoatDong*> hoatDongHistory;

public:
    HosoBenhAn(int msbn) : msbn(msbn) {}

    void ThemHoatDong(HoatDong* hoatDong) {
        hoatDongHistory.push_back(hoatDong);
    }

    void InLichSuHoatDong() {
        // In lịch sử hoạt động của bệnh nhân từ hồ sơ bệnh án
    }
};

class BenhNhan {
protected:
    int msbn;
    std::string hoTen;
    std::string diaChi;
    LoaiBenhNhan loaiBenhNhan;
    std::vector<HoatDong*> history;
    HosoBenhAn* hosoBenhAn;

public:
    BenhNhan(int msbn, const std::string& hoTen, const std::string& diaChi, LoaiBenhNhan loaiBenhNhan)
        : msbn(msbn), hoTen(hoTen), diaChi(diaChi), loaiBenhNhan(loaiBenhNhan) {
        hosoBenhAn = new HosoBenhAn(msbn);
    }

    ~BenhNhan() {
        delete hosoBenhAn;
    }

    void ThemHoatDong(HoatDong* hoatDong) {
        history.push_back(hoatDong);
        hosoBenhAn->ThemHoatDong(hoatDong);
    }

    void InThongTin() {
        // In thông tin cơ bản của bệnh nhân
    }

    void InLichSuHoatDong() {
        hosoBenhAn->InLichSuHoatDong();
    }
};
