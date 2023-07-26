#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <algorithm>

#ifndef _staff_h_
#define _staff_h_

using namespace std;
#define max 76
#define PATH_MAX 100
#define FOR(i,h) for(int i=0; i<=h-1;i++)
#define Quanly 5000000
#define Phache 4000000
#define Phucvu 3000000
#define Baove 2500000

int snv;
class Staff{
private:
    string name, add, sex, position, ca; // tên, địa chỉ, giới tính, chức vụ, ca
    int dd, mm, yy;                      // ngày tháng năm sinh
                         // mã nhân viên

    int coe, time, off, base, punish; // hệ số lương, số năm làm, lương cơ bản, tiền phạt
    int bonus, tip, over;             // thưởng
public:
    string id;   
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
class Salary: private Staff{
private:
    int luong;
public:
    void s_luong(int luong){
        this->luong=luong;
    }
    int g_luong(){
        return luong;
    }
    void s_id(string id){
        this->id=id;
    }
    string g_id(){
        return id;
    }
};

void Danhsach(string a[], Staff b[]);
void Tracuu(string a[], Staff b[], Salary c[]);
void doc( Staff nv[], string a[], int &snv);
void xuat(string a[], Staff b[], int snv);
void ThemNV( string a[], Staff b[]);
void XoaNV(string a[], Staff b[]);
void TLuong(string a[], Staff b[], Salary c[]);
bool cpTen(const Staff nv1, const Staff nv2);
bool cpHSL(const Staff nv1, const Staff nv2);
bool cpNg(const Staff nv1, const Staff nv2);
bool cpCV(const Staff nv1, const Staff nv2);
string layTenTuHoTen(string hoten);

string layTenTuHoTen(string hoten) {
    string ten;
    int i = hoten.find_last_of(" "); // Tìm vị trí cuối cùng của ký tự ' ' trong họ tên
    if (i != string::npos) {
        ten = hoten.substr(i + 1); // Lấy phần tên từ vị trí ký tự ' ' + 1 đến hết chuỗi
    }
    return ten;
}

bool cpTen(Staff nv1, Staff nv2){
    string ten1 = layTenTuHoTen(nv1.g_name());
    string ten2 = layTenTuHoTen(nv2.g_name());
    return ten1 < ten2;
}
bool cpHSL( Staff nv1,  Staff nv2){
    return nv1.g_coe() > nv2.g_coe();
}
bool cpMNV( Staff nv1,  Staff nv2){
    return nv1.g_id() > nv2.g_id();
}
bool cpNg( Staff nv1,  Staff nv2){
    if (nv1.g_yy() != nv2.g_yy()) {
        return nv1.g_yy() < nv2.g_yy();
    } else if (nv1.g_mm() != nv2.g_mm()) {
        return nv1.g_mm() < nv2.g_mm();
    } else {
        return nv1.g_dd() < nv2.g_dd();
    }
}


bool cpCV( Staff nv1,  Staff nv2){
    return nv1.g_position() < nv2.g_position();
}

void doc( Staff nv[], string a[],int &snv){// ham doc gia tri tu file
    ifstream data("danhsach.txt");
    data>>snv;// doc so luong nhan vien trong danh sach
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
    data.close();
}

int luachon ( string a[], Staff b[], Salary c[]){
    int x;
    string s1("| 1.Xem danh sach nhan vien");
    string s2("| 2.Them nhan vien");
    string s3("| 3.Xoa nhan vien");
    string s4("| 4.Tra cuu & thay doi thong tin/thuong, phat");
    string s5("| 5.Luong nhan vien");
    string s0("| 0.Thoat chuong trinh");
    while(true){
        system("cls");
        cout << "|"<<setfill('=')<<setw(23)<<right<<"Quan ly "<<setfill('=')<<setw(23)<<left<<"Nhan vien "<<"|"<<endl;
        cout << s1 <<setfill(' ')<<setw(48-s1.size())<<right<<"|"<< endl;
        cout << s2 <<setfill(' ')<<setw(48-s2.size())<<right<<"|"<< endl;
        cout << s3 <<setfill(' ')<<setw(48-s3.size())<<right<<"|"<< endl;
        cout << s4 <<setfill(' ')<<setw(48-s4.size())<<right<<"|"<< endl;
        cout << s5 <<setfill(' ')<<setw(48-s5.size())<<right<<"|"<< endl;
        cout << s0 <<setfill(' ')<<setw(48-s0.size())<<right<<"|"<< endl;
        cout << "|"<<setfill('=')<<setw(47)<<"|"<<endl;
        
    cout<<"NHAP LUA CHON: ";
    cin>>x;
    if (x>5 || x <0){
        cout<< "ban da nhap sai, vui long nhap lai";
        getch();}
    else{break;};     
    }
    cout<<setfill(' ');
    system("cls");
    switch(x){
    case 1:
        Danhsach(a,b);
        getch();
        break;
    case 2:
        ThemNV(a,b);
        break;
    case 3:
        XoaNV(a,b);
        break;
    case 4:
        Tracuu( a,  b, c);
        break;
    case 5:
        TLuong(a,b,c);
        break;
    case 0:
        break;
    }
return 0;
}

void Danhsach(string a[], Staff b[]){ // in danh sach nhan vien
    string t;
    int x;
    doc(b, a, snv);//doc du lieu tu file
    while(true){
        system("cls");
        cout<<"Ban muon sap xep danh sach theo: "<<"\n"
            <<"1. Khong sap xep"<<"\n"
            <<"2. Theo ten"<<"\n"
            <<"3. Theo Ma Nhan Vien"<<"\n"
            <<"4. Theo ngay sinh"<<"\n"
            <<"5. Theo he so luong"<<"\n"
            <<"6. Theo chuc vu"<<"\n";
         cin>>x;
        if(x>=1||x<=6){break;}
    }
    switch(x){
    case 1:
        break;
    case 2:
        sort(b, b + snv, cpTen);
        break;
    case 3:
        sort(b, b + snv, cpMNV);
        break;
    case 4:
        sort(b, b + snv, cpNg);
        break;
    case 5:
        sort(b, b + snv, cpHSL);
        break;
    case 6:
        sort(b, b + snv, cpCV);
        break;
    }
    cout<< setfill(' ');
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
void ThemNV( string a[], Staff b[]){ // them nhan vien
    string name, add, sex, position, ca, id;
    int dd, mm, yy;
    int m;
    int i = 0;
    int k = 1;
    doc(b, a, snv);//doc du lieu tu file
    fflush(stdin);
    cout << "ban muon them bao nhieu nhan vien: ";
    cin >> m;
    system("cls");
    while (i < max){if (a[i] == "y"){i++;}
        else{if (k > m){break;}
            cout << "Nhan vien " << k << "\n";
            cout << "nhap ten nhan vien: ";
            fflush(stdin);
            getline(cin, name);
            cout << "\n"<< "nhap ma nhan vien: ";
            cin >> id;
            cout << "\n"<< "nhap ngay sinh: ";
            cin >> dd;
            cout << "\n"<< "thang: ";
            cin >> mm;
            cout << "\n"<< "nam: ";
            cin >> yy;
            cout << "\n"<< "nhap gioi tinh: ";
            cin>>sex;
            cout << "\n"<< "nhap dia chi: ";
            cin.ignore();
            getline(cin, add);
            cout << "\n"<< "nhap chuc vu(Quan ly/Pha che/Phuc vu/Bao ve): ";
            
            getline(cin, position);
            cout << "\n"<< "nhap ca lam: ";
            
            getline(cin, ca);
            cout << "\n";
            
            system("cls");
            
            Staff c(name, add, sex, position, ca, dd, mm, yy, id);
            b[i] = c;
            if(position=="Quan ly"){b[i].s_base(Quanly);}
            else if(position=="Pha che"){b[i].s_base(Phache);}
            else if(position=="Phuc vu"){b[i].s_base(Phucvu);}
            else if(position=="Bao ve"){b[i].s_base(Baove);}
            a[i] = "y";
            i++;
            k++;
                }
        }
        snv+=m;
        xuat(a,b,snv);
}

void Tracuu(string a[], Staff b[], Salary c[]){
    system("cls");
    doc(b,a,snv);
    string sl,sl2,mnv;
    int k;

    cout<<"\n";
    while(true){
        system("cls");
        cout<<"Nhap MA NHAN VIEN ban muon tra cuu: ";cin>>mnv;
        FOR(i,max){
            if (b[i].g_id().find(mnv) != std::string::npos){
            k=i;
            sl2="y";
            break;}
            else{
                sl2="n";
            }}
        if(sl2=="n"){
        cout<<"\n"<<"KHONG CO NHAN VIEN NAY TRONG DANH SACH"<<"\n";
        cout<<"Ban co muon nhap lai khong?(y/n): ";cin>>sl;
        if(sl=="y"){continue;}
        else {return;}
        }
        else if(sl2=="y"){break;}
        }
    system("cls");
    cout << right << setw(50) << "      TRA CUU NHAN VIEN"<< "\n"<< "\n";
    cout << left << setw(20) << "MA NHAN VIEN" << left << setw(25) << "HO VA TEN" << left << setw(15) << "NGAY SINH"
         << left << setw(20) << "GIOI TINH" << left << setw(15) << "CHUC VU" << left << setw(15) << "CA LAM" << left << setw(15) << "HE SO LUONG" 
         <<left << setw(15) << "NGAY NGHI"<< left << setw(20) << "THUONG"<< left << setw(20) << "PHAT"<<left << setw(15) <<endl;
    string t; t = to_string(b[k].g_dd()) + "/" + to_string(b[k].g_mm()) + "/" + to_string(b[k].g_yy());
    cout << left << setw(20) << b[k].g_id()
     << left << setw(25) << b[k].g_name()
     << left << setw(15) << t
     << left << setw(20) << b[k].g_sex()
     << left << setw(15) << b[k].g_position()
     << left << setw(15) << b[k].g_ca()
     << left << setw(15) << b[k].g_coe()
     << left << setw(15) << b[k].g_off()
     << left << setw(20) << b[k].g_bonus()
     << left << setw(20) << b[k].g_punish()
     << endl;
     while(true){
        cout<<"\n"<<"Ban co muon thay doi thong so NGHI/THUONG/PHAT khong(y/n): ";cin>>sl;
        cout<<endl;
        if(sl=="n"){return;}
        else if(sl=="y"){break;}
     }
     int x;

    while(true){
        system("cls");
        cout<< "    THONG SO NHAN VIEN"<<"\n"
            <<"1. So ngay nghi"<<"\n"
            <<"2. Tien thuong"<<"\n"
            <<"3. Tien phat"<<"\n"
            <<"4. He so luong"<<"\n";
        while(true){
        cout<<"Nhap lua chon cua ban: ";
        cin>>x;
        if(x>=1 || x <=4){break;}}
    switch(x){
    case 1:
        system("cls");
        cout<<"Nhap so ngay nghi ban muon thay doi: ";
        int off;
        cin>>off;
        b[k].s_off(off);
        break;
    case 2:
        system("cls");
        cout<<"Nhap so tien thuong ban muon thay doi: ";
        int thuog;
        cin>>thuog;
        b[k].s_bonus(thuog);
        break;
    case 3:
        system("cls");
        cout<<"Nhap so tien phat ban muon thay doi: ";
        int pun;
        cin>>pun;
        b[k].s_punish(pun);
        break;
    case 4:
        system("cls");
        cout<<"Nhap he so luong ban muon thay doi: ";
        int coe;
        cin>>coe;
        b[k].s_coe(coe);
        break;
    }
    cout<<"Ban co muon tiep tuc cap nhat cho "<<b[k].g_name()<<" (y/n): ";cin>>sl2;
    if(sl2=="n"){
        system("cls");
        cout<<"BAN DA CAP NHAT THANH CONG";
        getch();
        xuat(a,b,snv);
        return;
        }
    }
    }
void XoaNV(string a[], Staff b[]){
    doc(b, a, snv);
    int sl,stt,snvv;
    int count=0;
    int luu[max];
    string Ten,select;
    while (true){
        system("cls");
        cout<<"Ban muon xoa bao nhieu NHAN VIEN: ";cin>>sl;
        if(sl<1 || sl>snv){
            system("cls");
            cout<<"BAN DA NHAP SAI VUI LONG NHAP LAI!";
            getch();
        }
        else{break;}
    }
    snvv=sl;
    system("cls");
    FOR(i,sl){
        system("cls");
        while (true){
            fflush(stdin);
            cout<<"Nhap ten nguoi thu "<<i+1<<": ";cin>>Ten;
            FOR(i,max){
                if (a[i]=="n"){break;}
                else{
                    if (b[i].g_name().find(Ten) != std::string::npos){
                        string fullName = b[i].g_name();
                        int d = fullName.rfind(Ten);
                        if(d+Ten.length() == fullName.length()){
                            luu[count]=i;
                            count++;
                        } 
   		            }
                }
            }
            if(count<1){
                cout<<"\n"<<"    TEN KHONG CO TRONG DANH SACH, vui long nhap lai!";
                getch();
            }else{break;}
        }
        system("cls");
        cout << left << setw(8) << "STT" << left << setw(20) << "MA NHAN VIEN" << left << setw(25) << "HO VA TEN" << left << setw(15) << "NGAY SINH"
             << left << setw(20) << "GIOI TINH" << left << setw(15) << "CHUC VU" << left << setw(15) << "CA LAM" << left << setw(15) << "HE SO LUONG" << endl;
        FOR(i,count){
            string t = to_string(b[luu[i]].g_dd()) + "/" + to_string(b[luu[i]].g_mm()) + "/" + to_string(b[luu[i]].g_yy());
            cout    << left << setw(8) <<i+1
                    << left << setw(20) << b[luu[i]].g_id()
                    << left << setw(25) << b[luu[i]].g_name()
                    << left << setw(15) << t
                    << left << setw(20) << b[luu[i]].g_sex()
                    << left << setw(15) << b[luu[i]].g_position()
                    << left << setw(15) << b[luu[i]].g_ca()
                    << left << setw(15) << b[luu[i]].g_coe()
                    << endl;
        }
        getch();
        cout<<"\n";
        if(count > 1){
            fflush(stdin);
            cout<<"Nhap STT NHAN VIEN can xoa: ";cin>>stt;
            stt--;
        }
        else{stt=0;}
        while(true){
            system("cls");
            cout<<"\n"<<"\n"<<"       XAC NHAN XOA NHAN VIEN "<<b[luu[stt]].g_name()<<" (y/n): ";cin>>select;
            if(select=="y" || select=="n"){break;}
            else{
                cout<<"\n"<<"       BAN DA NHAP SAI VUI LONG NHAP LAI!";
            }
        }
        stt=luu[stt];
        if(select=="n"){
            snvv--;
            continue;}
        else{
            for(int i=stt;i<=max-1;i++){
                b[i]=b[i+1];
                if(a[i]=="n"){
                    a[i-1]=="n";
                    break;
                }
            }
        }
    }
    xuat(a,b,snv-snvv);
}
void TLuong(string a[], Staff b[], Salary c[]){
    doc(b,a,snv);
    void xuatl(string a[], Staff b[], Salary c[]);
    void bangl(string a[], Staff b[], Salary c[]);
        int x;
    while (true){
    system("cls");
    cout<< "   LUONG NHAN VIEN"<<"\n"
        <<"1. Tinh luong nhan vien"<<"\n"
        <<"2. Xem bang luong"<<"\n"
        <<"\n"
        <<"NHAP LUA CHON: ";
    cin>>x;
    if (x>2 || x <1){
        cout<< "ban da nhap sai, vui long nhap lai";
        getch();}
    else{break;};     
    }
    system("cls");
    switch(x){
    case 1:
        xuatl(a, b, c);
        break;
    case 2:
        bangl(a, b, c);
        break;
    }
}
void xuatl(string a[], Staff b[], Salary c[]){
    void xuatl(string a[], Staff b[], Salary c[]);
    void checkdir(char* relative_path);
    void checkdirN(int &nam);
    int luong,thang;
    int nam=2023;
    string select,fn;
    while(true){
    system("cls");
    cout<<"Neu chua cap nhat thuong/phat nhan (n) de thoat. Neu da cap nhat, nhan (y) de tiep tuc: ";cin>>select;
    if(select=="n"){return;}
    else if(select=="y"){break;}
    }

    string filename = "1.txt";
    string t3="luong_thang_NV\\";
    string t5="\\";
    string t2;
    int i=1;
    while(true){
        checkdir("/Luong_thang_NV");
        char nam_str[260];
        sprintf(nam_str, "/Luong_thang_NV/%d", nam);
        checkdir(nam_str);
        string t4=to_string(nam);
        string t1=t3+t4+t5;
        t2=t1+filename;
        ifstream infile(t2);

        if (infile.good()) {
            // File exists
            infile.close();
            i++;
            
            
            filename = to_string(i) + ".txt";
            

        } else {
                // File doesn't exist
            infile.close();
            if (i>12){checkdirN(nam);
            i=1;
            filename = "1.txt";
            continue;}
            thang=i;
            while (true){
            system("cls");
            cout<<" xac nhan tinh luong thang "<<thang<<"/"<<nam<<" (y/n): ";cin>>select;
            if(select=="n"){return;}
            else if(select=="y"){break;}
            }
            ofstream outfile(t2);
            outfile.close();
            break;
        }
    }
    fn=t2;
    ofstream dataa(fn);
    FOR(i,max){
        if(a[i]=="n"){break;}
        else{
            c[i].s_id(b[i].g_id());
            luong=b[i].g_base()*b[i].g_coe()+b[i].g_bonus()-b[i].g_off()*200000-b[i].g_punish();
            c[i].s_luong(luong);
        }
    }
    FOR(i,max){
        if(a[i]=="n"){break;}
        else{
            dataa<<c[i].g_id()<<" ";
        }
    }
    dataa<<"\n";
    FOR(i,max){
        if(a[i]=="n"){break;}
        else{
            dataa<<c[i].g_luong()<<" ";
        }
    }
    dataa.close(); 

}
void checkdir( char* relative_path){
    
    char current_dir[FILENAME_MAX];
   getcwd(current_dir, FILENAME_MAX);
   char absolute_path[PATH_MAX];
   snprintf(absolute_path, PATH_MAX, "%s%s", current_dir, relative_path);
   DIR* dir = opendir(absolute_path);
   if (dir) {
       closedir(dir);
       return;
   } else {
       int result = mkdir(absolute_path);
   }

}
void checkdirN(int &nam){
    char nam_str[260];
    sprintf(nam_str, "/Luong_thang_NV/%d", nam);
    char current_dir[FILENAME_MAX];
   getcwd(current_dir, FILENAME_MAX);
   char absolute_path[PATH_MAX];
   snprintf(absolute_path, PATH_MAX, "%s%s", current_dir, nam_str);
   DIR* dir = opendir(absolute_path);
   if (dir) {
       closedir(dir);
       nam++;
       return;
    }
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
void bangl(string a[], Staff b[], Salary c[]){
    system("cls");
    int thang, nam;
    string fn;
    fflush(stdin);
    while(true){
    system("cls");
    cout<<"Nhap THANG bang muon xem bang luong: ";cin>>thang;
    cout<<"\n"<<"Nhap NAM: ";cin>>nam;
    system("cls");
    string t1="Luong_thang_NV\\";
    string t2=to_string(nam)+"\\";
     fn=t1+t2+to_string(thang)+".txt";
    ifstream cc(fn);
    char nam_str[260];
    sprintf(nam_str, "/Luong_thang_NV/%d", nam);
    char current_dir[FILENAME_MAX];
    getcwd(current_dir, FILENAME_MAX);
    char absolute_path[PATH_MAX];
    snprintf(absolute_path, PATH_MAX, "%s%s", current_dir, nam_str);
    DIR* dir = opendir(absolute_path);
    if (dir && cc.good()) {
        closedir(dir);
        cc.close();
        break;
    }else{
        cout<<thang<<"/"<<nam<<" khong ton tai bang luong nao"<<"\n";
        cout<<"Ban co muon THOAT khong(y/n): ";string sl; cin>>sl;
        cout<<endl;
        if(sl=="y"){return; }
    }
    }
    ifstream data(fn);
    string temp;
    int t;
    fflush(stdin);
    getline(data,temp);
    FOR(i,max){
                if (a[i]=="n"){break;}
                else{
                    data>>t;
                    c[i].s_luong(t);
                }
    }
    data.close();
    cout<<    "BANG LUONG THANG "<<thang<<"/"<<nam<<endl;
    cout << left << setw(8) << "STT" << left << setw(20) << "MA NHAN VIEN" << left << setw(30) << "HO VA TEN"<< left<<setw(30) <<"LUONG"<<endl; 
    FOR(i,max){
                if (a[i]=="n"){break;}
                else{ 
                    cout    << left << setw(8) <<i+1
                    << left << setw(20) << b[i].g_id()
                    << left << setw(30) << b[i].g_name()
                    << left<<  setw(30) << c[i].g_luong()<<endl;
                }
               
    }
         getch();
}
void menu3(string a[], Staff nv[], Salary lnv[]){
    string lc;
    while (true){
        system("cls");
        FOR(i,max){a[i]="n";};
        luachon (a, nv, lnv);//thuc hien hanh dong 
        while(true){
            system("cls");
            cout << "Ban co muon tuy chinh NHAN VIEN tiep khong? (y/n): "; cin>>lc;
            if (lc=="n"|| lc=="y"){break;}
            else{cout<< "ban da nhap sai, vui long nhap lai!"; getch();}
        }
        if (lc=="n"){
            break;}
    }
}
#endif