#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

class Phongtro {
	private:
		string maphong, ten, sdt, ngay;
        bool dongtien;
	public:
    //set
	void setMaphong(string a){maphong = a;}
    void setTen(string b){ten = b;}
    void setSdt(string c){sdt = c;}
    void setNgay(string d){ngay = d;}
    void setTien(bool e){dongtien = e;}
    //get
    string getMaphong(){return maphong;}
    string getTen(){return ten;}
    string getSdt(){return sdt;}
    string getNgay(){return ngay;}
    bool getTien(){return dongtien;}
};

//Khoi tao cac ham voi tham so counter
void add(int counter);
void deleteroom(int counter);
void paid(int counter);
void search(int counter);
void quit();

//Bien dem cho mang phongtro
int counter=0;

//Ham tang bien counter
void increment(int a){
	a++;
	counter=a;
}

//Ham giam bien counter
void decrement(int a){
	a--;
	counter=a;
}

//Cap phat bo nho
Phongtro phongtro[100];


int main(){
string choice;
//Man hinh chinh
system("cls");
cout<<"CHUONG TRINH QUAN LY NHA TRO\n\n";
cout<<"[1]Nguoi thue moi\n";	
cout<<"[2]Het hop dong\n";	
cout<<"[3]Dong tien\n";	
cout<<"[4]Kiem tra thong tin phong\n";		
cout<<"[5]Thoat\n\n";

cout<<"Nhap lua chon cua ban: ";
getline(cin,choice);
system("cls");

if(choice=="1"){
	add(counter);
}
else if(choice=="2"){
	deleteroom(counter);
}
else if(choice=="3"){
	paid(counter);
}
else if(choice=="4"){
	search(counter);
}
else if(choice=="5"){
	quit();
}
else{
	main();
}
	
getch();
return 0;
}


//Ham them nguoi thue moi
void add(int counter){
	string maphong, ten, sdt, ngay, thang, nam;
    cout << "Ma phong: ";
    cin >> maphong;
    cout << "Ten khach hang: ";
    cin.ignore(); getline(cin, ten);
    cout << "So dien thoai: ";
    cin >> sdt;
    cout << "Ngay vao chuyen vao: ";
    cin >> ngay;
    phongtro[counter].setMaphong(maphong);
    phongtro[counter].setTen(ten);
    phongtro[counter].setSdt(sdt);
    phongtro[counter].setNgay(ngay);	
		increment(counter);
		cout<<"\nThem nguoi thue moi thanh cong!!!\n\nNhan phim bat ky de tiep tuc!!!";
		getch();
		main();
}

//Ham ket thuc hop dong
void deleteroom(int counter){
	string maphong;
	int choice;
	if(counter==0){
		cout<<"Hien tai khong co khach thue phong!!!\n\nNhan phim bat ky de tiep tuc!!!";
		getch();
		main();
	}
	cout<<"Nhap ma phong khach chuyen di: ";
	getline(cin,maphong);

	for(int i=0;i<counter;i++){
		//Tim phong dua tren ma
		if(phongtro[i].getMaphong()==maphong){

				phongtro[i].setMaphong("");
                phongtro[i].setTen("");
                phongtro[i].setSdt("");
                phongtro[i].setNgay("");
                phongtro[i].setTien(false);
				for(int a=i;a<counter;a++){
					//chinh sua gia tri cua mang
					phongtro[a] = phongtro[a+1];
				}
				decrement(counter); //Loi goi ham giam bien counter
				cout<<"\nDa ket thuc hop dong thanh cong!!!\n\nNhan phim bat ky de tiep tuc!!!";
				getch();
				main();
			}
		}
	cout<<"\nHien khong co ai thue phong nay!!!\n\nNhan phim bat ky de tiep tuc!!!";
	getch();
	main();
	
}

//Ham chuyen doi trang thai da dong tien 
void paid(int counter){
    string maphong;
	int choice;
	cout<<"Dong tien nha\n\n";
	if(counter==0){
		cout<<"Hien tai khong co khach thue phong!!!\n\nNhan phim bat ky de tiep tuc!!!";
		getch();
		main();
	}
	cout<<"Nhap ma phong: ";
	cin >> maphong;
	for(int i=0;i<counter;i++){
		//Tim phong dua tren ma
		if(phongtro[i].getMaphong() == maphong){
            phongtro[i].setTien(true);
        }
    }
	cout<<"Chuyen trang thai phong thanh da dong tien!!!\n\nNhan phim bat ky de tiep tuc!!!";
    getch();
	main();
}

//Ham kiem tra thong tin phong
void search(int counter){
	string maphong;
	int choice;
	bool print = false; //Bien kieu bool de quyet dinh in ra cai gi
	cout<<"Kiem tra thong tin phong\n\n";
	if(counter==0){
		cout<<"Hien tai khong co khach thue phong!!!\n\nNhan phim bat ky de tiep tuc!!!";
		getch();
		main();
	}
	cout<<"Nhap ma phong: ";
	cin >> maphong;
	for(int i=0;i<counter;i++){
		//Tim phong dua tren ma, neu tim thay thi gan print = true
		if(phongtro[i].getMaphong() == maphong){ 
			cout<<"Ma phong: "<<phongtro[i].getMaphong()<<endl;
			cout<<"Ten khach hang: "<<phongtro[i].getTen()<<endl;
			cout<<"So dien thoai: "<<phongtro[i].getSdt()<<endl;
			cout<<"Ngay chuyen den: "<<phongtro[i].getNgay()<<endl;
            if(phongtro[i].getTien()) cout<<"Da dong tien";
            else cout<<"Chua dong tien";
			print = true;
		}
	}
	if(print){
		cout<<"\n\nNhan phim bat ky de tiep tuc!!!";
		getch();
		main();
	}
	//Neu khong ton tai phong theo ma da nhap
	else{
		cout<<"\nKhong co thong tin ve phong nay!!!\n\nNhan phim bat ky de tiep tuc!!!";
		getch();
		main();		
	}
}

//Ham thoat chuong trinh
void quit(){
	exit(1);
}

