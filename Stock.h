#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <sstream>
#include <cmath>
#include <time.h>

#ifndef Stock_h
#define Stock_h

using namespace std;
#define MAX 100

class Stock {
    private:
        string name;  // tên nguyên liệu hàng
        int cost;     // chi phí mua vào
        int quantity; // số lượng
        string unit;
        int dotnhap;
        string expiryDate; // Hạn sử dụng
    public:
        Stock(string name ="" , string unit ="", int quantity =0, int cost=0, int dotnhap=0,string expiryDate ="") {
            this->name = name;
            this->cost = cost;
            this->quantity = quantity;
            this->unit = unit;
            this->dotnhap = dotnhap;
            this->expiryDate=expiryDate;
        }
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
        int get_dotnhap(){
            return  dotnhap;
        }
        void set_dotnhap(int dotnhap){
            this->dotnhap = dotnhap;
        }
        string get_expiryDate(){
            return expiryDate;
        }
        void set_expiryDate(string expiryDate){
            this->expiryDate=expiryDate;
        }
        void getInformation() {
            cout << "Nguyen lieu: ";
            getline(cin, name);
            cout << "So luong: ";
            cin >> quantity;
            while (quantity < 0) {
                cout << "Error: So luong nhap vao bi am, vui long nhap lai: ";
                cin >> quantity;
            }
            cout << "Price: $";
            cin >> cost;
            while (cost < 0) {
                cout << "Error: Gia nguyen lieu nhap vao bi am, vui long nhap lai: ";
                cin >> cost;
            }
            cout << "Don vi: ";
            cin >> unit;
            cout << "Dot nhap: ";
            cin >> dotnhap;
        }
        void printProduct(){
            cout<<left<<setw(18)<<name<<left<<setw(12)<<unit<<left<<setw(12)<<quantity<<left<<setw(12)<<cost<<left<<setw(12)<<expiryDate;cout<<setfill(' ');
        }
        //Friend class1
        int ExpiryDate();
        void KiemtraHansudung();
};
class Inventory{
    private:
        Stock products[MAX];
        int count;
    public:
        Inventory(){
            count = 0;
        }
        Stock& getProduct(int index) {
            return products[index];
        }
        int get_count(){
            return count;
        }
        void set_count(int count){
            this->count = count;
        }
        void addProduct(string name , string unit, int quantity , int cost, int dotnhap,string expiryDate){
            if (count < MAX) {
            if (quantity < 0) {
                cout << "Error: So luong nhap vao bi am. Vui long nhap lai\n";
                return;
            }
            if (cost < 0) {
                cout << "Error: Gia nguyen lieu nhap vao bi am. Vui long nhap lai\n";
                return;
            }
            products[count] = Stock(name, unit, quantity, cost, dotnhap,expiryDate);
            count++;
            } else {
                cout << "Error: Khong the them nguyen lieu vao kho, suc chua cua kho da dat toi da!!!\n";
            }
        }
        void deleteProduct(int index) {
            if (index >= count) {
                cout << "Error: Khong ton tai san pham tai vi tri nay trong kho\n";
                return;
            }
            for (int i = index; i < count - 1; i++) {
                products[i] = products[i+1];
            }
            count--;
        }
        void displayAllProducts(){
            for (int i = 0; i < count; i++){
                cout<<left<<setw(5)<<i+1;
                products[i].printProduct();products[i].KiemtraHansudung(); cout<<endl;
            }
        }
};
void load_file(Inventory &inventory){
    ifstream filein("stock.txt");
    if (!filein) {
        cout << "Error: Cannot open input file\n";
        return;
    }
    string line;
    while (getline(filein, line)) {
        stringstream ss(line);
        string name, unit,expiryDate;
        int quantity, cost, dotnhap;
        if (getline(ss, name, ',') &&
            getline(ss, unit, ',') &&
            (ss >> quantity) &&
            (ss.ignore() && ss >> cost) &&
            (ss.ignore() && ss >> dotnhap)&&
            (ss.ignore() && getline(ss, expiryDate))) {
            if (quantity < 0 || cost < 0) {
                cout << "Error: Invalid data in input file\n";
            } else {
                inventory.addProduct(name, unit, quantity, cost, dotnhap,expiryDate);
            }
        } else {
            cout << "Error: Invalid format in input file\n";
        }
    }
    filein.close();
}
void ghi_file(Inventory inventory) {
    ofstream fileout("stock.txt");
    if (!fileout) {
        cout << "Error: Cannot open output file\n";
        return;
    }
    for (int i = 0; i < inventory.get_count(); i++) {
        Stock product = inventory.getProduct(i);
        fileout << product.get_name() << "," << product.get_unit() << "," << product.get_quantity() << "," << product.get_cost() << "," << product.get_dotnhap() << "," << product.get_expiryDate() << endl;
    }
    fileout.close();
    cout << "Data saved successfully!\n";
}

//So sánh ngày
int days_between_dates(string date1, string date2) {
    struct tm timeinfo1 = {}, timeinfo2 = {};
    char delimiter = '/';
    size_t pos1 = date1.find(delimiter);
    size_t pos2 = date2.find(delimiter);
    timeinfo1.tm_mday = stoi(date1.substr(0, pos1));
    timeinfo1.tm_mon = stoi(date1.substr(pos1 + 1, pos1 + 2)) - 1;
    timeinfo1.tm_year = stoi(date1.substr(pos1 + 4)) - 1900;
    timeinfo2.tm_mday = stoi(date2.substr(0, pos2));
    timeinfo2.tm_mon = stoi(date2.substr(pos2 + 1, pos2 + 2)) - 1;
    timeinfo2.tm_year = stoi(date2.substr(pos2 + 4)) - 1900;
    time_t time1 = mktime(&timeinfo1);
    time_t time2 = mktime(&timeinfo2);
    return (int) difftime(time2, time1) / (60 * 60 * 24);
}

int Stock::ExpiryDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char today[11];
    strftime(today, 11, "%d/%m/%Y", ltm);
    string today1(today);
    int days = days_between_dates(today1, expiryDate); //(Hạn sử dụng:: ngày, today)
    return days;
}

void Stock::KiemtraHansudung() {
    int expiryDays = ExpiryDate();
    if((expiryDays <=20)&&(expiryDays>0)){
            cout << "\tNguyen lieu " << name << " se het han trong vong " << expiryDays << " ngay";
    }
    else if(expiryDays<=0){
            cout << "\tNguyen lieu da het han su dung. ";
    }
}

void InHangTrongKho(Inventory &inventory){   
    bool kt = true;
    char temp;
start:
    system("cls");
    cout << "===========Danh sach nguyen lieu trong kho===========" << endl;cout<<setfill(' ');
    cout<<left<<setw(5)<<"STT"<<left<<setw(18)<<"NGUYEN LIEU"<<left<<setw(12)<<"DON VI"<<left<<setw(12)<<"SO LUONG"<<left<<setw(12)<<"GIA NHAP"<<left<<setw(12)<<"HSD"<<endl;cout<<setfill(' ');
    inventory.displayAllProducts();
    cout<<"================================================================"<<endl;
    for(int i=0;i <inventory.get_count();i++){
        int check = inventory.getProduct(i).ExpiryDate();
        if (check <= 0){
            cout <<"Nguyen lieu "<<inventory.getProduct(i).get_name()<<" da het han su dung. Vui long nhap hang moi"<<endl;
mid:        int sl;      
            cout <<"Nhap so luong hang moi muon nhap: ";cin>>sl;
            if(sl<=1){
                cout <<"Nhap sai dinh dang, vui long nhap lai" <<endl;
                goto mid;
            }
            cout<<endl;
            time_t now = time(0);
            now += 24 * 24 * 3600;
            tm *ltm = localtime(&now);
            char date_string[50];
            strftime(date_string, 50, "%d/%m/%Y", ltm);
            string expiryDate = date_string;
            inventory.getProduct(i).set_quantity(sl);
            inventory.getProduct(i).set_expiryDate(expiryDate);
            goto start;
        }
    }
    for (int i = 0; i < inventory.get_count(); i++){
        if (inventory.getProduct(i).get_quantity()<10){
            cout<<"Canh bao nguyen lieu "<<inventory.getProduct(i).get_name()<<" sap het."<<endl<<"Ban co muon nhap them? (y,n,e) ";char c; cin>>c;
            switch(c){
                case 'y':{
                    cout<<"Nguyen lieu: "<<inventory.getProduct(i).get_name()<<endl;
                    cout<<"So luong ban muon nhap them: ";int input; cin>>input;inventory.getProduct(i).set_quantity(input+inventory.getProduct(i).get_quantity()) ;goto start;
                }
                case 'n':break;
                case 'e':goto end;
            }
        }
    }
end:
    ghi_file(inventory);
    system("pause");
}
void NhapTT(Inventory &inventory){   
    string name,unit;
    int quantity,cost,dotnhap;
    cout<<"Nhap so loai nguyen lieu moi muon them vao kho: "; int sl;cin>>sl;cin.ignore();
    int n; n = inventory.getProduct(inventory.get_count()-1).get_dotnhap();
    for(int i = 0; i < sl; i++){
        cout<<"\t\t---------- Nguyen lieu nhap them thu "<<i+1<<" -----------"<<endl;
        cout<<"Ten nguyen lieu: ";getline(cin,name);
        cout<<"Don vi: ";getline(cin,unit);
        cout<<"So luong: ";cin>>quantity;cin.ignore();
        cout<<"Gia nguyen lieu: ";cin>>cost;cin.ignore();
        // chuyển ngày thành chuỗi lưu và product
        time_t now = time(0);
        // Thêm 7 ngày (7x24x3600 giây) để lấy thời gian của 1 tuần sau
        now += 24 * 24 * 3600;
        // Chuyển đổi thành struct tm
        tm *ltm = localtime(&now);
        // Định dạng ngày tháng nam thành chuỗi
        char date_string[50];
        strftime(date_string, 50, "%d/%m/%Y", ltm);
        string expiryDate = date_string;
        dotnhap = n + 1;
        inventory.addProduct(name,unit,quantity,cost,dotnhap,expiryDate);
    }
    ghi_file(inventory);
}   
void CalculatorExpensi(Inventory inventory){
    int expensive = 0;
    for (int i = 0; i < inventory.get_count(); i ++){
        expensive += inventory.getProduct(i).get_cost()*inventory.getProduct(i).get_quantity();
    }
    cout<< " ========================Thong ke nhap hang======================="<<endl;cout<<setfill(' ');
    cout<<left<<setw(5)<<"STT"<<left<<setw(18)<<"Nguyen lieu"<<left<<setw(12)<<"Don vi"<<left<<setw(12)<<"So luong"<<left<<setw(12)<<"Gia nhap"<<left<<setw(12)<<"Chi phi"<<endl;cout<<setfill(' ');
    for (int i = 0; i < inventory.get_count(); i ++){
    if(inventory.getProduct(i).get_dotnhap()==0){
        int gia = inventory.getProduct(i).get_quantity()*inventory.getProduct(i).get_cost();
        cout<<setw(5)<<i+1<<setw(18)<<left<<inventory.getProduct(i).get_name()<<left<<setw(12)<<inventory.getProduct(i).get_unit()<<left<<setw(12)<<inventory.getProduct(i).get_quantity()<<left<<setw(12)<<inventory.getProduct(i).get_cost()<<setw(12)<<left<<gia<<endl;cout<<setfill(' ');
        }
    }
    for(int j=1;j<=inventory.getProduct(inventory.get_count()-1).get_dotnhap();j++){
        cout << "=========================Nhap them dot "<<j<<"========================="<<endl;
        cout<<left<<setw(5)<<"STT"<<left<<setw(18)<<"Nguyen lieu"<<left<<setw(12)<<"Don vi"<<left<<setw(12)<<"So luong"<<left<<setw(12)<<"Gia nhap"<<left<<setw(12)<<"Chi phi"<<endl;cout<<setfill(' ');
        for(int i = 0;i<inventory.get_count();i++){
            if(inventory.getProduct(i).get_dotnhap()==j){
                int gia = inventory.getProduct(i).get_quantity()*inventory.getProduct(i).get_cost();
                cout<<setw(5)<<i+1<<setw(18)<<left<<inventory.getProduct(i).get_name()<<left<<setw(12)<<inventory.getProduct(i).get_unit()<<left<<setw(12)<<inventory.getProduct(i).get_quantity()<<left<<setw(12)<<inventory.getProduct(i).get_cost()<<setw(12)<<left<<gia<<endl;cout<<setfill(' ');
            }
        }
    }
    cout<<"================================================================"<<endl;
    cout<<"Tong chi phi nhap hang: "<<right<<setw(39)<<expensive <<endl; 
    cout<<"............"<<endl;
    system("pause");
}
void Xoa(Inventory &inventory){
    bool flag = true;
    while(flag){
        system("cls");
        float priot =(float)(inventory.get_count()-1)/2; 
        int b = round(priot);
        cout<<left<<setw(5)<<"STT"<<left<<setw(18)<<"NGUYEN LIEU" <<"\t|\t"<<left<<setw(5)<<"STT"<<left<<setw(18)<<"NGUYEN LIEU" <<endl;
        int c =round(fmod(priot, 1.0));  //STT 14 -> nguyen lieu 13 (số nguyên liệu là số chẵn)->priot là số lẻ = 6.5 -> c = 0.5 làm tròn lên là 1
                                     // Ở TT14 một cột là 7 một cột là 14       i<round(priot)=7
                                     // 1-> 7 i:0...6   i+1    i        8->14  i:0:6   i+1+(7=round(priot))
                                     //STT 13 -> nguyên liệu 12 (số nguyên liệu là số lẻ)-> priot là số chẵn = 6 -> c = 0.5 làm tròn xuống là 0;
                                     // Ở TT13   một cột là 7 một cột là 13
                                     //  i<priot = 6+1
                                     // 1-> 7  i:0...6  i+1       8->13 i:0..6 i+2+priot   TT i=priot-1  1+1+priot
        switch(c){
            case 1:
                for(int i = 0; i< b; i++){ 
                    cout<<setfill(' ');
                    cout<<left<<setw(5)<<i+1<<left<<setw(18)<<inventory.getProduct(i).get_name()<<"\t|\t"<<left<<setw(5)<<i+1+b<<left<<setw(18)<<inventory.getProduct(i+b).get_name()<<endl;
                }
                break;
            case 0:
                for(int i = 0; i<priot+1;i++){
                    if(i == priot){
                        cout<<setfill(' ');
                        cout<<left<<setw(5)<<1+priot<<left<<setw(18)<<inventory.getProduct(priot).get_name()<<"\t|\t"<<endl;
                    }else{
                        cout<<setfill(' ');
                        cout<<left<<setw(5)<<i+1<<left<<setw(18)<<inventory.getProduct(i).get_name()<<"\t|\t"<<left<<setw(5)<<i+2+priot<<left<<setw(18)<<inventory.getProduct(i+1+priot).get_name()<<endl;
                    }

                }
                break;
        }
        cout<<"Nhap vao STT cua nguyen lieu ma ban muon xoa khoi kho: (STT| 0.exit)? "; int input;cin >> input;
        if (input == 0){
            flag = false;
            break;    
        }
        inventory.deleteProduct(input-1);
    }
    ghi_file(inventory);
}
void menu(Inventory inventory){
    load_file(inventory);
    bool kt = true;
    int count = 0; // số lần nhập hàng
    string s1("| 1.Kiem ke hang ton kho");
    string s2("| 2.Nhap nguyen lieu moi vao kho");
    string s3("| 3.Tinh tong chi phi cho viec nhap hang");
    string s4("| 4.Xoa nguyen lieu trong kho");
    string s0("| 0.Quay lai");
    while (kt==true){
        system("cls");
        cout << "|"<<setfill('=')<<setw(21)<<right<<"Quan ly "<<setfill('=')<<setw(21)<<left<<"kho"<<"|"<<endl;
        cout << s1 <<setfill(' ')<<setw(44-s1.size())<<right<<"|"<< endl;
        cout << s2 <<setfill(' ')<<setw(44-s2.size())<<right<<"|"<< endl;
        cout << s3 <<setfill(' ')<<setw(44-s3.size())<<right<<"|"<< endl;
        cout << s4 <<setfill(' ')<<setw(44-s4.size())<<right<<"|"<< endl;
        cout << s0 <<setfill(' ')<<setw(44-s0.size())<<right<<"|"<< endl;
        cout << "|"<<setfill('=')<<setw(43)<<"|"<<endl;
        int lc;
        cout<< "Nhap lc: ";cin>>lc;
        system("cls");
        switch(lc){    
            case 1:{InHangTrongKho(inventory);break;}
            case 0:{kt = false;break;}
            case 2:{NhapTT(inventory);break;}
            case 3:{CalculatorExpensi(inventory);break;}
            case 4:{Xoa(inventory);break;}  
        }
    }
}
#endif