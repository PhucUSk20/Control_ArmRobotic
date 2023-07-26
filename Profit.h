#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#ifndef Profit_h
#define Profit_h

class LoiNhuanCafe {
private:
    long long int doanhThu;
    long long int chiPhiNguyenLieu;
    long long int chiPhiMatBang;
    long long int chiPhiVanChuyen1MatHang;
    long long int chiPhiNhanVien;
    long long int chiPhiVanChuyen;
    int thang;

public:
    LoiNhuanCafe(long long int dt, long long int cpnl, long long int cpmb,long long int cpnv, long long int cpvc1, long long int cpvc, int month);
    void Thang();
    void ThayDoiChiPhiCoDinh();
    void ChiPhiCoDinh();
    void DoanhThuCacThangTruoc();
    void TinhChiPhiNguyenLieu();
    void TinhChiPhiNhanVien();
    void TinhChiPhiVanChuyen();
    void DoanhThuThangHienTai();
    void displayMenu();
};

LoiNhuanCafe::LoiNhuanCafe(long long int dt, long long int cpnl, long long int cpmb, long long int cpnv, long long int cpvc1, long long int cpvc, int month) {
    doanhThu = dt;
    chiPhiNguyenLieu = cpnl;
    chiPhiMatBang = cpmb;
    chiPhiNhanVien = cpnv;
    chiPhiVanChuyen1MatHang = cpvc1;
    chiPhiVanChuyen = cpvc;
    thang = month;
}

void LoiNhuanCafe::Thang()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    thang = 1 + ltm->tm_mon;
}

void LoiNhuanCafe::ChiPhiCoDinh()
{
    ifstream infile("Chiphicodinh.txt");
    string line;

    while (getline(infile, line)) {
        if (line.find("Chi phi mat bang:") != string::npos) {
            string cost = line.substr(line.find(":") + 1);
            chiPhiMatBang = stoi(cost);
        }
        else if (line.find("Chi phi van chuyen 1 mat hang:") != string::npos) {
            string cost = line.substr(line.find(":") + 1);
            chiPhiVanChuyen1MatHang = stoi(cost);
        }
    }
    infile.close();
}

void LoiNhuanCafe::ThayDoiChiPhiCoDinh()
{
    string file_path;
    string data;
    file_path = "Chiphicodinh.txt";
    ofstream output_file(file_path);
    if (!output_file.is_open())
    {
        cout << "Khong mo duoc file " << endl;
        return;
    }
    cout << "Nhap chi phi mat bang thang hien tai: " << endl;
    cin >> chiPhiMatBang;
    cout << "Nhap chi phi van chuyen 1 mat hang thang hien tai: " << endl;
    cin >> chiPhiVanChuyen1MatHang;
    output_file << "Chi phi mat bang: " << chiPhiMatBang << " dong" << endl;
    output_file << "Chi phi van chuyen 1 mat hang: " << chiPhiVanChuyen1MatHang << " dong" << endl;
    output_file.close();
}

void LoiNhuanCafe::DoanhThuCacThangTruoc()
{
    string file_path;
    string data;
    if (thang == 1) cout << "Khong co doanh thu cac thang truoc do hien tai dang la thang " << thang << "!";
    else {
            for (int i = 1; i < thang; i++) {
            file_path = "loinhuanthang" + to_string(i) + ".txt";
            ifstream input_file(file_path);
            if (input_file.is_open()) {
                while (getline(input_file, data)) {
                    cout << data << endl;
                }
                cout << "\n";
                input_file.close();
            }
            else {
                cout << "Khong mo duoc file " << file_path << endl;
            }
        }
    }
}

void LoiNhuanCafe::TinhChiPhiVanChuyen()
{
    ifstream infile("stock.txt");
    string line;
    int temp;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            istringstream iss(line);
            temp++;
            }
        }
    else
        {
            cout << "Khong mo duoc file " << endl;
            return;
        }
    infile.close();
    chiPhiVanChuyen = temp*chiPhiVanChuyen1MatHang;
}

void LoiNhuanCafe::TinhChiPhiNguyenLieu()
{
    ifstream infile("stock.txt");
    string line;
    string ten, loai;
    long long int gia = 0;
    long long int so_luong = 0;
    long long int TongGia = 0;
    long long int TongSoLuong = 0;

    if (infile.is_open()) {
        while (getline(infile, line)) {
            istringstream iss(line);
            if (getline(iss, ten, ',') && getline(iss, loai, ',') && (iss >> gia) && (iss.ignore() && iss >> so_luong)) {
                TongGia += gia;
                TongSoLuong += so_luong;
            }
        }
        infile.close();
        chiPhiNguyenLieu = TongGia*1000*TongSoLuong;
    }
}
void LoiNhuanCafe::DoanhThuThangHienTai()
{
    string file_path;
    string data;
    file_path = "loinhuanthang" + to_string(thang) + ".txt";
    ofstream output_file(file_path);
    if (!output_file.is_open())
    {
        cout << "Khong mo duoc file " << endl;
        return;
    }
    cout << "Nhap doanh thu quan cafe thang "<< thang << ": ";
    cin >> doanhThu;
    cout << "Chi phi nguyen lieu: " << chiPhiNguyenLieu << " dong" << endl;
    cout << "Chi phi mat bang: " << chiPhiMatBang << " dong" << endl;
    cout << "Chi phi nhan vien: ";
    cin >> chiPhiNhanVien;
    cout << "Chi phi van chuyen: " << chiPhiVanChuyen << " dong" << endl;
    long long int loiNhuan = doanhThu - chiPhiNguyenLieu - chiPhiMatBang - chiPhiNhanVien - chiPhiVanChuyen;
    cout << "Loi nhuan cua quan cafe thang " << thang << " la: " << loiNhuan << " dong" << endl;
    float tyLeLoiLo = (loiNhuan * 1.0) / doanhThu;
    cout << "\nTy le loi lo cua quan cafe thang " << thang << " la: " << fixed << setprecision(2) << tyLeLoiLo << endl;
    output_file << "Thang: " << thang << endl;
    output_file << "Doanh thu: " << doanhThu << " dong" << endl;
    output_file << "Chi phi nguyen lieu: " << chiPhiNguyenLieu << " dong" << endl;
    output_file << "Chi phi mat bang: " << chiPhiMatBang << " dong" << endl;
    output_file << "Chi phi nhan vien: " << chiPhiNhanVien << " dong" << endl;
    output_file << "Chi phi van chuyen: " << chiPhiVanChuyen << " dong" << endl;
    output_file << "Loi nhuan cua quan cafe thang " << thang << " la: " << loiNhuan << " dong\n" << endl;
    output_file.close();
}

void LoiNhuanCafe::displayMenu() {
    bool kt = true;
    string s1("| 1.Tra cuu doanh thu/chi tieu");
    string s2("| 2.Xem doanh thu chi tieu thang hien tai");
    string s3("| 3.Thay doi cac chi phi co dinh");
    string s4("| 4.Exit");
    while( kt ){
        system("cls");
        cout << "|"<<setfill('=')<<setw(21)<<right<<"MENU "<<setfill('=')<<setw(21)<<left<<"OPTION"<<"|"<<endl;
        cout << s1 <<setfill(' ')<<setw(44-s1.size())<<right<<"|"<< endl;
        cout << s2 <<setfill(' ')<<setw(44-s2.size())<<right<<"|"<< endl;
        cout << s3 <<setfill(' ')<<setw(44-s3.size())<<right<<"|"<< endl;
        cout << s4 <<setfill(' ')<<setw(44-s4.size())<<right<<"|"<< endl;
        cout << "|"<<setfill('=')<<setw(43)<<"|"<<endl;
        int choice;
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;
        switch (choice) {
            case 1:
                Thang();
                DoanhThuCacThangTruoc();
                system("pause");
                break;
            case 2:
                Thang();
                ChiPhiCoDinh();
                TinhChiPhiVanChuyen();
                TinhChiPhiNguyenLieu();
                DoanhThuThangHienTai();
                system("pause");
                break;
            case 3:
                Thang();
                ThayDoiChiPhiCoDinh();
                system("pause");
                break;
            case 4:
                kt = false;
                break;
            default:
                cout << "Lua chon khong hop le! Xin hay thu lai." << endl;
                break;
        } 
    }
}
#endif