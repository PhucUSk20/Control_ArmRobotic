#ifndef Source_h
#define Source_h

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
#define MAX 100
#define max 76
#define FOR(i,h) for(int i=0; i<=h-1;i++)
#define FOR(i,a) for(int i=0; i<=a-1;i++)
// Khai báo class Menu
class base_menu{
    private:
        string douong,mahang;
        int quantity = 0;
        int cost;
        string size;//vd size s cost = 10k -> size L = size S + 50% = 10k + 5 (chua update size)
    public:
    static int number ;
        string get_douong(){
            return douong;
        }
        void set_douong(string douong){
            this->douong = douong;
        }
        string get_id(){
            return mahang;// ma hang chua co them vao
        }
        void set_id(string mahang){
            this->mahang = mahang;
        }
        int get_quantity(){
            return quantity;
        }
        void set_quantity(int quantity){
            this->quantity = quantity;
        }
        int get_cost(){
            return cost;
        }
        void set_cost(int cost){
            this->cost = cost;
        }
        base_menu() = default;
};
struct table{
    int countttt  = 0;
    string douong;
    int quantity;
};
// Khai báo class Khách hàng
class khachhang{
    private:
        int lc;//lua chon
        string name;
        string code;
        string rank;
        int points;
        int discount;
    public:
        table ban[100];
    int get_lc(){
        return lc;
    }
    void set_lc(int lc){
        this->lc = lc;
    }
    string get_name(){
        return name;
    }
    void set_name(string name){
        this->name = name;
    }
    string get_code(){
        return code;
    }
    void set_code(string code){
        this->code = code;
    }
    string get_rank(){
        return rank;
    }
    void set_rank(string rank){
        this->rank = rank;
    }
    int get_points(){
        return points;
    }
    void set_points(int points){
        this->points = points;
    }
    int get_discount(){
        return discount;
    }
    void set_discount(int discount) {
        this->discount = discount;
    }
    khachhang() = default;
    void inbill(khachhang kh[],int k,base_menu bm[],int c);
    friend istream& operator>>(istream &is, khachhang &a);
    friend ostream& operator<<(ostream &os, khachhang a);
};
// Khai báo class Stock
class Stock 
{
private:
    string name;  // tên nguyên liệu hàng
    int cost;     // chi phí mua vào
    int quantity; // số lượng
    string unit;
public:
    string get_name(){
        return name;
    }
    void set_name(string name){
        this->name = name;
    }
    int get_quantity(){
        return quantity;
    }
    void set_quantity(int quantity){
        this->quantity = quantity;
    }
    int get_cost(){
        return cost;
    }
    void set_cost(int cost){
        this->cost = cost;
    }
    string get_unit(){
        return unit;
    }
    void set_unit(string unit){
        this->unit = unit;
    }
    void getInformation()
    {
        cout << "Nguyen lieu: ";
        getline(cin,name);
        cout << "So luong: ";
        cin >> quantity;
        cout << "Gia nguyen lieu: ";
        cin >> cost;
    }
    Stock() = default;
    //Friend class1
    friend void Hienthidanhsach(Stock ds[], int n);
    friend istream& operator>>(istream &is, Stock &a);
    friend ostream& operator<<(ostream &os, Stock a);
};

class Staff{
private:
    string name, add, sex, position, ca; // tên, địa chỉ, giới tính, chức vụ, ca
    int dd, mm, yy;                      // ngày tháng năm sinh
    string id;                           // mã nhân viên

    int coe, time, off, base, punish; // hệ số lương, số năm làm, lương cơ bản, tiền phạt
    int bonus, tip, over;             // thưởng
public:
        Staff()
        {
                this->name = "";
                this->add = "";
                this->sex = "";
                this->position = "";
                this->ca = "";
                this->dd = 0;
                this->mm = 0;
                this->yy = 0;
                this->id = "";
                this->coe = 0;
                this->time = 0;
                this->off = 0;
                this->base = 0;
                this->punish = 0;
                this->bonus = 0;
                this->tip = 0;
                this->over = 0;
        }

        Staff(string name, string add, string sex, string position, string ca,
              int dd, int mm, int yy, string id)
        {
                this->name = name;
                this->add = add;
                this->sex = sex;
                this->position = position;
                this->ca = ca;
                this->dd = dd;
                this->mm = mm;
                this->yy = yy;
                this->id = id;
                this->coe = 0;
                this->time = 0;
                this->off = 0;
                this->base = 0;
                this->punish = 0;
                this->bonus = 0;
                this->tip = 0;
                this->over = 0;
        }
    void s_name(string name){
        this->name=name;
    }
    string g_name(){
        return name;
    }
    void s_sex(string sex){
        this->sex=sex;
    }
    string g_sex(){
        return sex;
    }
    void s_add(string add){
        this->add=add;
    }
    string g_add(){
        return add;
    }
    void s_position(string position){
        this->position=position;
    }
    string g_position(){
        return position;
    }
    void s_ca(string ca){
        this->ca=ca;
    }
    string g_ca(){
        return ca;
    }
    void s_id(string id){
        this->id=id;
    }
    string g_id(){
        return id;
    }
    void s_dd(int dd){
        this->dd=dd;
    }
    int g_dd(){
        return dd ;
    }
    void s_mm(int mm){
        this->mm=mm;
    }
    int g_mm(){
        return mm;
    }
    void s_yy(int yy){
        this->yy=yy;
    }
    int g_yy(){
        return yy;
    }
    void s_coe(int coe){
        this->coe=coe;
    }
    int g_coe(){
        return coe;
    }
    void s_time(int time){
        this->time=time;
    }
    int g_time(){
        return time ;
    }
    void s_off(int off){
        this->off=off;
    }
    int g_off(){
        return off;
    }
    void s_base(int base){
        this->base=base;
    }
    int g_base(){
        return base;
    }
    void s_bonus(int bonus){
        this->bonus=bonus;
    }
    int g_bonus(){
        return bonus;
    }
    void s_tip(int tip){
        this->tip=tip;
    }
    int g_tip(){
        return tip;
    }
    void s_punish(int punish){
        this->punish=punish;
    }
    int g_punish(){
        return punish;
    }
    void s_over(int over){
        this->over=over;
    }
    int g_over(){
        return over;
    }
};
Staff nv[76];

void Danhsach(string a[], Staff b[]);
void doc(ifstream &data, Staff nv[], string a[], int snv);
void xuat(string a[], Staff b[], int snv);
void ThemNV( string a[], Staff b[], int snv);
void XoaNV(string a[], Staff b[], int snv);


void doc(ifstream &data, Staff nv[], string a[], int snv){// ham doc gia tri tu file
    string temp; //bien tam
    string name, add, sex, position, ca; // tên, địa chỉ, giới tính, chức vụ, ca
    int dd, mm, yy;                      // ngày tháng năm sinh
    string id;                           // mã nhân viên
    int coe, time, off, base, punish; // hệ số lương, số năm làm, lương cơ bản, tiền phạt
    int bonus, tip, over;
    
    int i=0;int k=0;//bien kiem tra
    getline(data,temp);
    while (i < max){
        if (a[i] == "y"){i++;}
        else{if (k == snv){break;}
            getline(data, name);
            nv[i].s_name(name); 
            getline(data, add);
            nv[i].s_add(add);
            getline(data, sex);
            nv[i].s_sex(sex);
            getline(data, position);
            nv[i].s_position(position);
            getline(data, ca);
            nv[i].s_ca(ca);
            data >>dd >>mm >>yy; getline(data, temp);
            nv[i].s_dd(dd); nv[i].s_mm(mm); nv[i].s_yy(yy);
            getline(data, id);
            nv[i].s_id(id);
            data >>base>>coe>>time>>off
                 >>punish>>bonus>>tip>>over;
            nv[i].s_base(base);
            nv[i].s_coe(coe);
            nv[i].s_time(time);
            nv[i].s_off(off);
            nv[i].s_punish(punish);
            nv[i].s_bonus(bonus);
            nv[i].s_tip(tip);
            nv[i].s_over(over);
            getline(data, temp);
            fflush(stdin);
            a[i] = "y";
            i++;k++;

        }
    }
}

int luachon ( string a[], Staff b[], int snv){
    int x;
    while (true){
    system("cls");
    cout<< "    NHAN VIEN"<<"\n";
    cout<<"1. Xem danh sach nhan vien"<<"\n";
    cout<<"2. Them nhan vien"<<"\n";
    cout<<"3. Xoa nhan vien"<<"\n";
    cout<<"4. THOAT"<<"\n";
    cout<<"\n";
    cout<<"NHAP LUA CHON: ";
    cin>>x;
    if (x>4 || x <1){
        cout<< "ban da nhap sai, vui long nhap lai";
        getch();}
    else{break;};     
    }
    system("cls");
    switch(x){
    case 1:
        Danhsach(a,b);
        getch();
        break;
    case 2:
        ThemNV(a,b,snv);
        break;
    case 3:
        XoaNV(a,b,snv);
        break;
    case 4:
        exit(0);
    }
return 0;
}

void Danhsach(string a[], Staff b[]){ // in danh sach nhan vien
    string t;
    cout<<setfill(' ');
    cout << right << setw(50) << "      DANH SACH NHAN VIEN"<< "\n"<< "\n";
        cout << left << setw(20) << "MA NHAN VIEN" << left << setw(25) << "HO VA TEN" << left << setw(15) << "NGAY SINH"
             << left << setw(20) << "GIOI TINH" << left << setw(15) << "CHUC VU" << left << setw(15) << "CA LAM" << left << setw(15) << "HE SO LUONG" << endl;
          FOR(i,max)
        {
                if (a[i] == "y")
                {
                        t = to_string(b[i].g_dd()) + "/" + to_string(b[i].g_mm()) + "/" + to_string(b[i].g_yy());
                        cout << left << setw(20) << b[i].g_id()
                             << left << setw(25) << b[i].g_name()
                             << left << setw(15) << t
                             << left << setw(20) << b[i].g_sex()
                             << left << setw(15) << b[i].g_position()
                             << left << setw(15) << b[i].g_ca()
                             << left << setw(15) << b[i].g_coe()
                             << endl;
                }
                else{break;}
        
        cout << endl; 
        }
}
void ThemNV( string a[], Staff b[], int snv){ // them nhan vien
    string name, add, sex, position, ca, id;
    int dd, mm, yy;
    int m;
    int i = 0;
    int k = 1;
    fflush(stdin);
    cout << "ban muon them bao nhieu nhan vien: ";
    cin >> m;
    system("cls");
    while (i < max){if (a[i] == "y"){i++;}
        else{if (k > m){break;}
            cout << "Nhan vien " << k << "\n";
            cout << "nhap ten nhan vien: ";
            cin.ignore();
            getline(cin, name);
            cout << "\n";
            cout << "nhap ma nhan vien: ";
            cin >> id;
            cout << "\n";
            cout << "nhap ngay sinh: ";
            cin >> dd;
            cout << "\n";
            cout << "thang: ";
            cin >> mm;
            cout << "\n";
            cout << "nam: ";
            cin >> yy;
            cout << "\n";
            cout << "nhap gioi tinh: ";
            cin >> sex;
            cout << "\n";
            cout << "nhap dia chi: ";
            cin.ignore();
            getline(cin, add);
            cout << "\n";
            cout << "nhap chuc vu: ";
            cin.ignore();
            getline(cin, position);
            cout << "\n";
            cout << "nhap ca lam: ";
            cin >> ca;
            cout << "\n";
            system("cls");
            Staff c(name, add, sex, position, ca, dd, mm, yy, id);
            b[i] = c;
            a[i] = "y";
            i++;
            k++;
                }
        }
        snv+=m;
        xuat(a,b,snv);
}

void XoaNV(string a[], Staff b[], int snv){
    Staff xoa;
    string ten_x,t,id_x,lc;
    int k,sl;
    int count=0;
    system("cls");
    cout<<"ban can xoa bao nhieu NV: ";cin>>sl;
    snv-=sl;
    FOR(i,sl){
    cout<<"nhap ten nhan vien can xoa: ";
    cin.ignore();getline(cin,ten_x);cout<<"\n";
    cout << left << setw(20) << "MA NHAN VIEN" << left << setw(25) << "HO VA TEN" << left << setw(15) << "NGAY SINH"
         << left << setw(20) << "GIOI TINH" << left << setw(15) << "CHUC VU" << left << setw(15) << "CA LAM" << left << setw(15) << "HE SO LUONG" << endl;   
        FOR(i,max){
            if (a[i]=="n"){break;}
            else{
            if(b[i].g_name().find(ten_x)!=string::npos){
                count++;
                k=i;
                t = to_string(b[i].g_dd()) + "/" + to_string(b[i].g_mm()) + "/" + to_string(b[i].g_yy());
                cout << left << setw(20) << b[i].g_id()
                     << left << setw(25) << b[i].g_name()
                     << left << setw(15) << t
                     << left << setw(20) << b[i].g_sex()
                     << left << setw(15) << b[i].g_position()
                     << left << setw(15) << b[i].g_ca()
                     << left << setw(15) << b[i].g_coe()
                     << endl;
                }
            }
            }
        cout<<"Neu nhieu hon 1 nhan vien duoc tim thay, HAY NHO MA NHAN VIEN, Nhan phim bat ky de tiep tuc";
        getch();
        if (count==1){
        while(true){
             system("cls");
             cout<<" XAC NHAN XOA NHAN VIEN "<<b[k].g_name()<<" (y/n): ";cin>>lc;
             if (lc=="n"|| lc=="y"){break;}
             else{cout<< "ban da nhap sai, vui long nhap lai!"; getch();}
        }
        if(lc=="n"){break;}
        else{
            FOR(i,max){
                if (a[i]=="n"){break;}
                else{
                    if(i==k){
                        b[i]=b[i+1];
                        k++;
                    }
                }
            }
        }
        } 
        else if (count>1){
        cout<<"\n"<<"NHAP MA NHAN VIEN CAN XOA: ";cin>>id_x;
        FOR(i,max){
          if (a[i]=="n"){break;}
          else{
            if (b[i].g_id().find(id_x)!=string::npos){k=i; break;}
            }
        }
        FOR(i,max){
                if (a[i]=="n"){break;}
                else{
                    if(i==k){
                        b[i]=b[i+1];
                        k++;
                    }
                }
            }
        }
     
    system("cls");
    cout<<"DA XOA NHAN VIEN RA KHOI DANH SACH!"<<"\n";
    getch();
    }
    xuat(a, b, snv);
}

void xuat(string a[], Staff b[], int snv){
    ofstream data("danhsach.txt", ios::out | ios::trunc);
    data<<snv;
    FOR(i,max){
        if (a[i]=="n"){break;}
        else{
            data<<"\n"<<b[i].g_name()<<"\n"<<b[i].g_add()<<"\n"<<b[i].g_sex()<<"\n"<<b[i].g_position()<<"\n"
            <<b[i].g_ca()<<"\n"<<b[i].g_dd()<<" "<<b[i].g_mm()<<" "<<b[i].g_yy()<<"\n"<<b[i].g_id()<<"\n"
            <<b[i].g_base()<<" "<<b[i].g_coe()<<" "<<b[i].g_time()<<" "<<b[i].g_off()
            <<" "<<b[i].g_punish()<<" "<<b[i].g_bonus()<<" "<<b[i].g_tip()<<" "<<b[i].g_over();
        }
    }
    data.close();
}
void menu3(){
    int snv;
    string lc;
    while (true){
        ifstream data("danhsach.txt");
        string a[max];
        system("cls");
        FOR(i,max){a[i]="n";};
        data>>snv;// doc so luong nhan vien trong danh sach
        doc(data, nv, a, snv);//doc du lieu tu file
        luachon (a, nv, snv);//thuc hien hanh dong 
        data.close();
        while(true){
            system("cls");
            cout << "Ban co muon tuy chinh NHAN VIEN tiep khong? (y/n): "; cin>>lc;
            if (lc=="n"|| lc=="y"){break;}
            else{cout<< "ban da nhap sai, vui long nhap lai!"; getch();}
        }
        if (lc=="n"){break;}
    }
}
#endif