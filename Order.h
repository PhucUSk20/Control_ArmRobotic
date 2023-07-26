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
#ifndef Order_h
#define Order_h
class base_menu{
    private:
        string douong,mahang;
        int quantity = 0;
        int cost;
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
    int xy = 0;
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
// Hàm cho Order
void loadmenu(base_menu bm[],int &c);//c la so thu tu mon
void load_Info_Client(khachhang kh[],int &skh);
void menu(base_menu bm[],int c);
void menu2(khachhang kh[], int k, int skh,base_menu bm[], int c);
void douong(base_menu bm[],int c);
void Check_Client(khachhang kh[], int &skh, base_menu bm[], int &c);
void inban(khachhang kh[], int i);
void xepban(khachhang kh[],int k);
void SaveOrder(khachhang kh[], int k, base_menu bm[], int c, int count);
istream& operator>>(istream &is, khachhang &a){
    cout<<"Ho va ten: ";fflush(stdin);getline(is,a.name);
    cout<<"So dien thoai: ";fflush(stdin);getline(is,a.code);
    string rank = "Sliver Member";
    a.set_rank(rank);
    a.set_points(0);
    a.set_lc(0);
    a.set_discount(5); 
    return is;
}
ostream& operator<<(ostream &os, khachhang a){
    os<<"Ho va ten: "<<a.name<<endl;
    os<<"So dien thoai: "<<a.code<<endl;
    os<<"Hang thanh vien: "<<a.rank<<endl;
    os<<"Diem tich luy: "<<a.points<<endl;
    return os;
}
void loadmenu(base_menu bm[],int &c){
    ifstream filein;
    filein.open("menu.txt",ios_base::in);
    while(filein.eof()!=true){
        base_menu a;
        string b;
        int input,input1;
        getline(filein,b,',');a.set_douong(b);
        filein>>input;a.set_quantity(input);filein.ignore();
        filein>>input1;a.set_cost(input1);filein.ignore();
        bm[c++] = a;
    }
    filein.close();
}
/*
void ghi_file(khachhang kh[],int skh){
    ofstream outfile;
    outfile.open("client.txt", ios_base::out);
    for(int i=0;i<skh;i++){
    outfile<<kh[i].get_name()<<","<<kh[i].get_code()<<","<<kh[i].get_rank()<<","<<kh[i].get_points()<<","<<kh[i].get_lc()<<","<<kh[i].get_discount()<<endl;
    if(i=skh-1){
        cout<<endl;
        }
    }
    outfile.close();
}
void CheckPoint(khachhang kh[],int skh){
    for(int i = 0;i< skh ; i++){
        if(kh[i].get_points() == 0){
            kh[i].set_rank("Brozen Member"); 
        }else if ((kh[i].get_points()>= 100)&&(kh[i].get_points()<200)){
            kh[i].set_rank("Sliver Member");
        }else if((kh[i].get_points() >= 200)&&(kh[i].get_points()<500)){
            kh[i].set_rank("Golden Member");
        }else if ((kh[i].get_points() >=500)&&(kh[i].get_points()<1000)){
            kh[i].set_rank("Diamond Member");
        }else if (kh[i].get_points() >=1000){
            kh[i].set_rank("VIP Member");
        }
    }
    ghi_file(kh,skh);
}*/
void menu(khachhang kh[], int k ,int skh,base_menu bm[],int c){
    int lc = 1;
    while(lc != 0){
        int count = 0;   // đếm số món mà khách đã chọn
        cout<<left;
        cout<<"Moi chon mon:"<<endl;
        douong(bm,c);
        cout<<"0.Exit"<<endl;
        int cnt = 0;
        cout<<"Chon: ";cin>>lc;
        switch(lc){
            case 0:{
                SaveOrder(kh,k,bm,c,count);
                break;
            }
            case 1:{
                int sl;
                cout<<"Nhap so luong: ";cin>>sl;
                bm[lc-1].set_quantity(bm[lc-1].get_quantity()+sl);
                cnt = cnt + sl*bm[lc-1].get_cost();break;
            }
            case 2:{
                int sl;
                cout<<"Nhap so luong: ";cin>>sl;
                bm[lc-1].set_quantity(bm[lc-1].get_quantity()+sl);
                cnt = cnt + sl*bm[lc-1].get_cost();break;
            }
            case 3:{
                int sl;
                cout<<"Nhap so luong: ";cin>>sl;
                bm[lc-1].set_quantity(bm[lc-1].get_quantity()+sl);
                cnt = cnt + sl*bm[lc-1].get_cost();break;
            }
            case 4:{
                int sl;
                cout<<"Nhap so luong: ";cin>>sl;
                bm[lc-1].set_quantity(bm[lc-1].get_quantity()+sl);
                cnt = cnt + sl*bm[lc-1].get_cost();break;
            }
            case 5:{
                int sl;
                cout<<"Nhap so luong: ";cin>>sl;
                bm[lc-1].set_quantity(bm[lc-1].get_quantity()+sl);
                cnt = cnt + sl*bm[lc-1].get_cost();break; 
            }
            case 6:{
                int sl;
                cout<<"Nhap so luong: ";cin>>sl;
                bm[lc-1].set_quantity(bm[lc-1].get_quantity()+sl);
                cnt = cnt + sl*bm[lc-1].get_cost();break; 
            }
            count ++;
        }
    }
}
void khachhang::inbill(khachhang kh[], int k,base_menu bm[],int c){
    //set up time
    time_t now = time(0);
    tm *lcd = localtime(&now);
    int total = 0;
    cout<<setfill(' ')<<right;
    cout<<setw(30)<<"24H COFFEE "<<endl;
    cout<<setw(35)<<"HOA DON THANH TOAN"<<endl;
    cout<<left;
    cout<<"Ban: "<<kh[k].get_lc()<<"\t\t"<<"Ngay: "<<lcd->tm_mday<<"/"<<1+lcd->tm_mon<<"/"<<1900+lcd->tm_year<<"\t\t"<<"Gio: "<<1+lcd->tm_hour<<":"<<1+lcd->tm_min<<endl;
        cout<<"----------------------------------------------------------------------"<<endl;cout<<left;
    cout<<" TT "<<setfill(' ')<<setw(30)<<"Ten mon"<<"SL   "<<setw(20)<<"Don gia"<<setw(30)<<"Thanh tien"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    for(int i = 0;i<c;i++){
        int j  = 0;
        if(bm[i].get_quantity()>0){
            int T = 0;
            T = bm[i].get_quantity()*bm[i].get_cost();total += T;
            cout<<left;
            cout<<j+1<<"    "<<setfill(' ')<<setw(29)<<bm[i].get_douong()<<setw(5)<<bm[i].get_quantity()<<setw(20)<<bm[i].get_cost()<<" "<<T<<endl;
        }
    }
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Thanh tien:"<<setfill(' ')<<setw(52)<<right<<total<<endl;
    cout<<"\t\t"<<"Discount: "<<kh[k].get_discount()<<setw(35)<<right<<"-"<<(total*kh[k].get_discount())/100<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Tong cong:"<<setfill(' ')<<setw(53)<<right<<(total*(100-kh[k].get_discount())/100)<<endl;
    cout<<setfill(' ')<<setw(60)<<right<<"CASH:VND"<<endl;
    cout<<left;
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"\t" <<setfill(' ')<<setw(30)<<"Cam on Quy khach va hen gap lai!"<<endl;
    cout<<"\t\t"<<setfill(' ')<<setw(30)<<"PassWifi:khachhanglaso1"<<endl;
    cout<<endl;
    cout<<setw(60)<<right<<kh[k].get_name()<<endl;
    cout<<setw(60)<<right<<kh[k].get_rank()<<endl;
    cout<<setw(60)<<right<<kh[k].get_code()<<endl;
    cout<<"Diem dau:"<<setw(65-9)<<right<<kh[k].get_points()<<endl;
    kh[k].set_points(kh[k].get_points()+total/10);
    cout<<"Diem cong:"<<setw(65-10)<<total/10<<endl;
    cout<<"Diem cuoi:"<<setw(65-10)<<right<<kh[k].get_points()<<endl;
}

void douong(base_menu bm[],int c){
    for(int i = 0;i<c;i++){
        cout<<i+1<<"."<<setfill('-')<<setw(47)<<bm[i].get_douong()<<bm[i].get_cost()<<"k";
        if(bm[i].get_quantity()>0) {
            cout<<" Da chon: "<<bm[i].get_quantity()<<endl;
        }
        else {
            cout<<endl;
        }
    }
}
void SaveOrder(khachhang kh[], int k, base_menu bm[], int c, int count){
    for (int i=0; i<count; i){
        for(int j=0;j<c;j++){
            if(bm[j].get_quantity()>0){
                kh->ban[i].douong = bm[j].get_douong();
                kh->ban[i].quantity = bm[j].get_quantity();
            }
        } 
    }
}
void load_Info_Client(khachhang kh[], int& skh) { //skh số danh sách khách hàng đã có thẻ thành viên
ifstream filein("client.txt"); //mở file input
while (!filein.eof()) { //kiểm tra kết thúc tệp tin
khachhang c;
string input, input1, input2;
int input3, input4, input5;
getline(filein, input, ',');
c.set_name(input);
getline(filein, input1, ',');
c.set_code(input1);
getline(filein, input2, ',');
c.set_rank(input2);
filein >> input3;
c.set_points(input3);
filein.ignore();
filein >> input4;
c.set_lc(input4);
filein.ignore();
filein >> input5;
c.set_discount(input5);
kh[skh++] = c; //lưu thông tin khách hàng vào mảng
}
filein.close(); //đóng file input
}
/*
void ghi_file_Client(khachhang kh[],int skh){
    ofstream outfile;
    outfile.open("client.txt", ios_base::app);
    int i =skh-1;
    outfile<<kh[i].get_name()<<","<<kh[i].get_code()<<","<<kh[i].get_rank()<<","<<kh[i].get_points()<<","<<kh[i].get_lc()<<","<<kh[i].get_discount()<<endl;
    outfile.close();
}
*/
void ghi_file_Client(khachhang kh[],int skh){
    ofstream outfile;
    outfile.open("client.txt", ios_base::out);
    for(int i=0;i<skh;i++){
    outfile<<kh[i].get_name()<<","<<kh[i].get_code()<<","<<kh[i].get_rank()<<","<<kh[i].get_points()<<","<<kh[i].get_lc()<<","<<kh[i].get_discount()<<endl;
    }
    outfile.close();
}
void Check_Client(khachhang kh[], int &skh, base_menu bm[], int &c){
    cout << "Ban da chon vao order mon!"<<endl<<" "<<endl;
    cout << "Ban da co the thanh vien chua ? (y/n):  ";
    // lua chon
    char input;
    cin>>input;
    switch(input){
        case 'y':{
            string input2;
            cout<<"Vui long nhap vao so the thanh vien cua ban: ";cin>>input2;
            for(int i=0; i< skh; i++){
                if (input2 == kh[i].get_code()){
                    cout<<"Chao mung "<<kh[i].get_name()<<" da quay tro lai quan coffee cua chung toi"<<endl;
                    system("pause");system("cls");
                    menu2(kh,i,skh,bm, c);
                }
            }
            break;
        }
        case 'n':{
            cout<<"Vui long nhap vao thong tin de tao the thanh vien"<<endl;
            cin >> kh[skh];skh++;
            ghi_file_Client(kh,skh);
            menu2(kh,skh-1,skh,bm, c);
            break;
        }
    }
}
/*
void inban(khachhang kh[], int i){// i là khách hàng thứ i trong database client
    cout <<" Vui long chon ban (X the hien cho ban da co nguoi)"<<endl;
    xepban(kh);
    int choice;
    cout<<"Nhap: ";cin>>choice;kh[i].set_lc(choice);system("pause");
    if(choice>0&&choice<=20){
        kh->ban[choice-1].countttt=1;
        xepban(kh);
    }
}*/
void inban(khachhang kh[], int i){// i là khách hàng thứ i trong database client
    cout <<" Vui long chon ban (X the hien cho ban da co nguoi)"<<endl;
    xepban(kh,i);
    int a = kh[i].get_lc();
    int choice;
    cout<<"Nhap: ";cin>>choice;system("pause");
    if(choice>0&&choice<=20){
        if(a!=choice){
            kh->ban[a-1].countttt = 0;
            kh->ban[choice-1].countttt=1;
            kh[i].set_lc(choice);
        }
       // kh->ban->xy = choice - 1;
        //cout<<kh[i].ban->xy;
        //system("pause");
    }
    xepban(kh,i);
}
/*
void xepban(khachhang kh[]){
    int i = 0;int a1 = 20/5;
    cout<<"------So do ban------"<<endl<<setfill(' ');
    while(i<=a1){
        if(i==a1){
            for(int j=5*i;j<20;j++){
                cout<<right;
                if(kh->ban[j].countttt==1) cout<<"X"<<setw(5);
                else cout<<j+1<<setw(5);
            }
        }
        else{
            for(int j = i*5;j<5*i+5;j++){
                cout<<right;
                if(j==(5*i+4)&&kh->ban[j].countttt==1) cout<<"X";
                else if(j==(5*i+4)) cout<<j+1;
                else if(kh->ban[j].countttt==1) cout<<"X"<<setw(5);
                else cout<<j+1<<setw(5);
            }
            cout<<endl;
        }
        i++;
    }
}*/
void xepban(khachhang kh[],int k){
    int a1,i,b1;
    a1 = 20;i = 0;
    int key = kh[k].get_lc()-1;
    cout<<"------So do ban------"<<endl<<setfill(' ');
    for(;i<a1;i++){
        cout<<left;
        b1 = (i+1)%5;
        if(kh->ban[i].countttt==1&&key==i){
            if(b1==0) cout<<"(X)"<<endl;
            else cout<<setw(5)<<"(X)";
        }
        else if(kh->ban[i].countttt==1&&key!=i){
            if(b1==0) cout<<"X"<<endl;
            else cout<<setw(5)<<"X";
        }
        else {
            if(b1==0) cout<<i+1<<endl;
            else cout<<setw(5)<<i+1;
        }
    }
}
void menu2(khachhang kh[], int k, int skh,base_menu bm[], int c){
 bool kt  = true;
    string s1("| 1.Dat ban");
    string s2("| 2.Dat mon");
    string s3("| 3.Thanh toan");
    string s4("| 0.Quay lai");
    while(kt == true){
        system("cls");
        cout << "|"<<setfill('=')<<setw(16)<<right<<"MENU "<<setfill('=')<<setw(16)<<left<<"OPTION"<<"|"<<endl;
        cout << s1 <<setfill(' ')<<setw(34-s1.size())<<right<<"|"<< endl;
        cout << s2 <<setfill(' ')<<setw(34-s2.size())<<right<<"|"<< endl;
        cout << s3 <<setfill(' ')<<setw(34-s3.size())<<right<<"|"<< endl;
        cout << s4 <<setfill(' ')<<setw(34-s4.size())<<right<<"|"<< endl;
        cout << "|"<<setfill('=')<<setw(33)<<"|"<<endl;
        //Nhập lựa chọn
        int choise;
        cout<<"Chon??: ";cin>>choise;
        switch (choise){            // pape = choise, c =n
            case 1:{inban(kh, k);system("pause");break;}
            case 2:{menu(kh,k,skh,bm, c);system("pause");break;}
            case 0:{
                kt = false;
                for(int i=0; i<c; i++){
                    bm[i].set_quantity(0);
                }
                break;
            }
            case 3:{
                kh->inbill(kh,k,bm,c);
                ghi_file_Client(kh, skh);
                system("pause");
                break;
            }
        }
    }
}
#endif