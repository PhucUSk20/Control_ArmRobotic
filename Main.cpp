#include "Order.h"
#include "Staff.h"
#include "Stock.h"
#include "Profit.h"
using namespace std;
// Nguyên mẫu hàm   
void create_menu(khachhang kh[], int &skh, base_menu bm[], int &c, Inventory &inventory, int &n,LoiNhuanCafe cafe,Staff nv[],string a[], Salary lnv[]);
// Hàm Main 
int main(){
    khachhang kh[100];
    base_menu bm[100];
    Staff nv[76];
    Salary lnv[100];
    Inventory inventory;
    LoiNhuanCafe cafe(0, 0, 0, 0, 0, 0, 0);
    string a[max];
    int c = 0;// ban
    int skh = 0;// khach hang
    int n = 0; // nguyen lieu
    create_menu(kh,skh,bm,c,inventory,n,cafe,nv,a,lnv);
    return 0;
}
// Định nghĩa hàm 
void create_menu(khachhang kh[], int &skh, base_menu bm[], int &c, Inventory &inventory, int &n,LoiNhuanCafe cafe,Staff nv[],string a[], Salary lnv[]){
    loadmenu(bm,c);
    load_Info_Client(kh,skh);
    ghi_file_Client(kh,skh);
    bool kt  = true;
    string s1("| 1.Order-Thanh toan");
    string s2("| 2.Quan ly nhan vien");
    string s3("| 3.Quan ly kho");
    string s4("| 4.Quan ly loi nhuan");
    string s0("| 0.Thoat chuong trinh");
    while(kt == true){
        system("cls");
        cout << "|"<<setfill('=')<<setw(21)<<right<<"Quan ly "<<setfill('=')<<setw(21)<<left<<"quan Coffee "<<"|"<<endl;
        cout << s1 <<setfill(' ')<<setw(44-s1.size())<<right<<"|"<< endl;
        cout << s2 <<setfill(' ')<<setw(44-s2.size())<<right<<"|"<< endl;
        cout << s3 <<setfill(' ')<<setw(44-s3.size())<<right<<"|"<< endl;
        cout << s4 <<setfill(' ')<<setw(44-s4.size())<<right<<"|"<< endl;
        cout << s0 <<setfill(' ')<<setw(44-s0.size())<<right<<"|"<< endl;
        cout << "|"<<setfill('=')<<setw(43)<<"|"<<endl;
        //Nhập lựa chọn
        int choise;
        cout<<"Chon??: ";cin>>choise;
        switch (choise){         
            case 1:{Check_Client(kh,skh,bm,c);break;}
            case 2:{menu3(a,nv,lnv);break;}
            case 3:{menu(inventory);break;}
            case 4:{cafe.displayMenu();break;}
            case 0:{kt = false;break;}
        }
    }
}