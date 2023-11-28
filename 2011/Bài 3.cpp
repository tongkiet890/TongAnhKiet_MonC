#include <iostream>
#include <vector>
#include <string>
using namespace std;


class MayLocNuoc {
protected:
    float donGiaThue; 
    float chiPhiSuDung;  
    float thoiGianHoatDong; 

public:
    MayLocNuoc(float gia, float chiPhi) : donGiaThue(gia), chiPhiSuDung(chiPhi), thoiGianHoatDong(0) {}

    virtual ~MayLocNuoc() {}

    virtual float tinhCongSuat() const = 0;
    virtual float tinhTongChiPhi() const = 0; 

    void datThoiGianHoatDong(float thoiGian) {
        thoiGianHoatDong = thoiGian;
    }
};


class MayLocLyTam : public MayLocNuoc {
private:
    float luongXangTieuThu; 

public:
    MayLocLyTam(float gia, float xang) : MayLocNuoc(gia, 0), luongXangTieuThu(xang) {}

   
    float tinhCongSuat() const override {
        return donGiaThue * thoiGianHoatDong;
    }

    float tinhTongChiPhi() const override {
        return (donGiaThue + chiPhiSuDung) * thoiGianHoatDong;
    }
};


class MayLocXucTac : public MayLocNuoc {
private:
    float luongHoaChat; 

public:
    MayLocXucTac(float gia, float hoaChat) : MayLocNuoc(gia, hoaChat), luongHoaChat(hoaChat) {}

    
    float tinhCongSuat() const override {
        return donGiaThue * thoiGianHoatDong * (luongHoaChat / 100);
    }

    float tinhTongChiPhi() const override {
        return (donGiaThue + chiPhiSuDung) * thoiGianHoatDong;
    }
};


class QuanLyMayLocNuoc {
private:
    vector<MayLocNuoc*> danhSachMayLoc; 

public:
    ~QuanLyMayLocNuoc() {
       
        for (MayLocNuoc* mayLoc : danhSachMayLoc) {
            delete mayLoc;
        }
    }

    void themMayLoc(MayLocNuoc* mayLoc) {
        danhSachMayLoc.push_back(mayLoc);
    }

    float tinhTongCongSuat() const {
        float tongCongSuat = 0;
        for (const MayLocNuoc* mayLoc : danhSachMayLoc) {
            tongCongSuat += mayLoc->tinhCongSuat();
        }
        return tongCongSuat;
    }

    float tinhTongChiPhi() const {
        float tongChiPhi = 0;
        for (const MayLocNuoc* mayLoc : danhSachMayLoc) {
            tongChiPhi += mayLoc->tinhTongChiPhi();
        }
        return tongChiPhi;
    }
};

int main() {
    QuanLyMayLocNuoc quanLy;

   
    MayLocLyTam* mayLocLyTam = new MayLocLyTam(50000, 5);
    mayLocLyTam->datThoiGianHoatDong(2);
    quanLy.themMayLoc(mayLocLyTam);

    MayLocXucTac* mayLocXucTac = new MayLocXucTac(80000, 2);
    mayLocXucTac->datThoiGianHoatDong(3);
    quanLy.themMayLoc(mayLocXucTac);

   
    cout << "Tong Cong Suat: " << quanLy.tinhTongCongSuat() << " m3" << endl;
    cout << "Tong Chi Phi: " << quanLy.tinhTongChiPhi() << " VND" << endl;

    return 0;
}
