#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std ;
#define MAX 100
struct sinhVien{
    int mssv;
    string hoTen;
    char queQuan[100];
    char ngaySinh[11];
    float diem;
};
void nhapSinhVien(sinhVien &sv)
{
    cout << "Nhap MSSV: " ;
    cin >> sv.mssv;
    cin.ignore() ;
    cout << "Nhap Ho Va Ten: " ;
    getline(cin , sv.hoTen);
    cout << "Nhap Que Quan: ";
    cin.getline(sv.queQuan,100);
    cout << "Nhap Ngay Sinh: ";
    cin.getline(sv.ngaySinh,11);
    cout << "Nhap Diem GPA: " ;
    cin >> sv.diem;
}
void xuatSinhVien(sinhVien sv) 
{
    cout << "===============" << endl;
    cout << "MSSV La: " << sv.mssv << endl ;
    cout << "Ho Ten SV: " << sv.hoTen << endl;
    cout << "Que Quan SV: " << sv.queQuan << endl ;
    cout << "Ngay Sinh SV: " << sv.ngaySinh << endl;
    cout << "GPA: " << sv.diem << endl ;
    cout << "===============" << endl;

} 

struct ds{
    sinhVien a[MAX];
    int n;
};
void init(ds &l) 
{
    l.n=0;
}
void themCuoi(ds &l,sinhVien x) 
{
   if(l.n==MAX)
   {
    cout << "DS DAY" << endl ;
    return;
   }
        l.a[l.n]=x;
        l.n++;

}
void themSinhVien(ds &l )  
{
  
    int soLuong;
    do{
        cout << "Nhap So Luong SV Can Them: " ;
        cin >> soLuong; 
        cin.ignore() ;
    }while(soLuong <= 0 || soLuong+l.n > MAX);
    for(int i=0; i < soLuong; i++) 
    {
        sinhVien x ;
        nhapSinhVien(x) ;
        themCuoi(l,x) ;
    }
}
void xuatDs(ds l ) 
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl ;
        return;
    }
    for(int i=0; i < l.n; i++) 
    {
        xuatSinhVien(l.a[i]);
    }
    cout << endl ;
}
int timSinhVien(ds l ,const int &id)
{
    if(l.n==0)
    {
        cout << "DS RONG " << endl;
        return -1;
    }
    for(int i=0; i <l.n; i++) 
    {
        if(l.a[i].mssv==id)
        return i;
    }
    return -1;
}
void xoaThongTinSinhVien(ds &l , const int &id) 
{
    int viTriSV=timSinhVien(l,id) ;
    if(viTriSV==-1)
    {
        cout << "Khong Tim Thay SV" << endl;
        return;
    }
    for(int i=viTriSV; i < l.n-1; i++)
    {
        l.a[i]=l.a[i+1];
    }
    l.n--;
} 
void suaThongTinSV(ds &l, int id)
{
    int timThay=timSinhVien(l,id);
    if(timThay==-1)
    {
        cout << "KHONG TIM THAY SV " << endl ;
        return;
    }
    cin.ignore();
     cout << "Nhap Ho Va Ten Moi: " ;
    getline(cin , l.a[timThay].hoTen);
    cout << "Nhap Que Quan Moi: ";
    cin.getline(l.a[timThay].queQuan,100);
    cout << "Nhap Ngay Sinh Moi: ";
    cin.getline(l.a[timThay].ngaySinh,11);
    cout << "Nhap Diem GPA Moi: " ;
    cin >> l.a[timThay].diem;    
}
void timSinhVienTheoQue(ds l , char que[])
{
    if(l.n==0){
        cout << "DS RONG" << endl;
        return;
    }
    bool found=false;
    for(int i=0; i < l.n; i++) 
    {
        if(strcmp(l.a[i].queQuan,que)==0)
        {
            found=true;
                    xuatSinhVien(l.a[i]);

        }
    }
    if(!found)
    cout << "KHONG TIM THAY SINH VIEN NAO" << endl ;    
}
void kiemTraSvCoHoCungNS(ds l ,char namSinh[])
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl;
        return;
    }
    bool found=false;
    for(int i=0; i < l.n; i++) 
    {
        // strstr : Chuỗi lớn chứa chuỗi con thì !=NULL
        if(strstr(l.a[i].ngaySinh , namSinh)!=NULL)
        {
            found=true;
            xuatSinhVien(l.a[i]);
        }
    }
    if(!found)
    cout << "KHONG TIM THAY SINH VIEN NAO SINH NAM" << namSinh << endl ;
}
bool cmp(sinhVien sv1 , sinhVien sv2 )
{
    return sv1.diem>sv2.diem>0;
}
void sapXepGpaTangDan(ds &l, bool (*func)(sinhVien,sinhVien)=cmp) 
{
    for(int i=0; i < l.n-1; i++) 
    {
        for(int j=i+1; j < l.n;j++)
        {
            if(cmp(l.a[i],l.a[j]))
            swap(l.a[i],l.a[j]);
        }
    }
}
void inputFromFile(ds &l)
{
    ifstream fin ("sinhVien.txt");
    if(!fin)
    {
        cout << "KHONG MO DUOC FILE" << endl;
        return;
    }
    sinhVien x ;
    while(fin >> x.mssv)
    {
        fin.ignore();
        getline(fin,x.hoTen,'#');
        fin.getline(x.ngaySinh,11,'#');
        fin.getline(x.queQuan,100,'#');
        fin >> x.diem;
        themCuoi(l,x);
    }
    fin.close() ;
}
int main() 
{
    ds l ;
    init(l) ;
   inputFromFile(l) ;
    sapXepGpaTangDan(l);
    xuatDs(l);
    return 0;
}