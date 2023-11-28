#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

enum LoaiPhong {
    A,
    B,
    C
};

enum LoaiHoatDong {
    KhamBenh,
    NhapVien,
    XuatVien,
    TongKet
};

class BenhNhan {
public:
    int msbn;
    int vienPhi;

    BenhNhan(int msbn) : msbn(msbn), vienPhi(0) {}
};

class HoatDong {
public:
    int ngay;
    int msbn;
    LoaiHoatDong loai;
    int phi;

    HoatDong(int ngay, int msbn, LoaiHoatDong loai, int phi)
        : ngay(ngay), msbn(msbn), loai(loai), phi(phi) {}
};

class NhapVien : public HoatDong {
public:
    LoaiPhong loaiPhong;

    NhapVien(int ngay, int msbn, LoaiPhong loaiPhong, int phi)
        : HoatDong(ngay, msbn, LoaiHoatDong::NhapVien, phi), loaiPhong(loaiPhong) {}
};

class TongKet : public HoatDong {
public:
    TongKet() : HoatDong(0, -1, LoaiHoatDong::TongKet, 0) {}
};

class QuanLyBenhVien {
private:
    std::vector<BenhNhan> danhSachBenhNhan;
    std::vector<HoatDong*> lichSuHoatDong;

public:
    void DocDuLieuTuTepTin(const std::string& tenTepTin) {
        std::ifstream file(tenTepTin);
        if (!file.is_open()) {
            std::cerr << "Khong the mo tep tin.\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int ngay, msbn, phi;
            std::string loai;

            iss >> ngay;
            iss >> msbn;
            iss >> loai;

            if (loai == "KB") {
                iss >> phi;
                lichSuHoatDong.push_back(new HoatDong(ngay, msbn, LoaiHoatDong::KhamBenh, phi));
            } else if (loai == "NV") {
                char loaiPhong;
                iss >> phi >> loaiPhong;
                LoaiPhong phong;
                if (loaiPhong == 'A') {
                    phong = LoaiPhong::A;
                } else if (loaiPhong == 'B') {
                    phong = LoaiPhong::B;
                } else if (loaiPhong == 'C') {
                    phong = LoaiPhong::C;
                }
                lichSuHoatDong.push_back(new NhapVien(ngay, msbn, phong, phi));
            } else if (loai == "XV") {
                lichSuHoatDong.push_back(new HoatDong(ngay, msbn, LoaiHoatDong::XuatVien, 0));
            } else if (loai == "TKVP") {
                lichSuHoatDong.push_back(new TongKet());
            }
        }

        file.close();
    }

    void LapDanhSachBenhNhan() {
        for (const auto& hoatDong : lichSuHoatDong) {
            if (hoatDong->loai != LoaiHoatDong::TongKet) {
                auto it = std::find_if(danhSachBenhNhan.begin(), danhSachBenhNhan.end(),
                                       [hoatDong](const BenhNhan& bn) { return bn.msbn == hoatDong->msbn; });

                if (it == danhSachBenhNhan.end()) {
                    danhSachBenhNhan.push_back(BenhNhan(hoatDong->msbn));
                }
            }
        }
    }

    void ThucHienHoatDong() {
        for (const auto& hoatDong : lichSuHoatDong) {
            if (hoatDong->loai != LoaiHoatDong::TongKet) {
                auto it = std::find_if(danhSachBenhNhan.begin(), danhSachBenhNhan.end(),
                                       [hoatDong](const BenhNhan& bn) { return bn.msbn == hoatDong->msbn; });

                if (it != danhSachBenhNhan.end()) {
                    switch (hoatDong->loai) {
                        case LoaiHoatDong::KhamBenh:
                            it->vienPhi += hoatDong->phi;
                            break;
                        case LoaiHoatDong::NhapVien:
                            it->vienPhi += hoatDong->phi;
                            break;
                        case LoaiHoatDong::XuatVien:
                            // Thực hiện hoạt động xuất viện
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }

    void InBangThongKeVienPhi() {
        std::cout << "+----------------------+-------------------+\n";
        std::cout << "| MSBN                 | Vien Phi          |\n";
        std::cout << "+----------------------+-------------------+\n";

        for (const auto& bn : danhSachBenhNhan) {
            std::cout << "| " << bn.msbn << "                    | " << bn.vienPhi << "               |\n";
        }

        std::cout << "+----------------------+-------------------+\n";
    }
};

int main() {
    QuanLyBenhVien quanLyBenhVien;
    quanLyBenhVien.DocDuLieuTuTepTin(THoongtin.txt);
    quanLyBenhVien.LapDanhSachBenhNhan();
    quanLyBenhVien.ThucHienHoatDong();
    quanLyBenhVien.InBangThongKeVienPhi();

    return 0;
}
