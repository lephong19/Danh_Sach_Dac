// Quản lý sinh viên với số phần tử lớn và biến động
#include <iostream>
#include <fstream>
#include <string>
using namespace std ;
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
struct ds {
    sinhVien *a;
    int n;
};
void init(ds &l) 
{
    l.a=NULL;
    l.n=0;
}
void nhapDSSV(ds &l) 
{
    do{
        cout << "Nhap So Luong SV can Them: ";
        cin >> l.n;
    }while(l.n <=0);
    l.a= new sinhVien[l.n] ;
    for(int i=0; i < l.n; i++) {
        nhapSinhVien(l.a[i]) ;
    }
}
void outputList(ds l ) 
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl ;
        return;
    }
    for(int i=0; i < l.n; i++) 
    {
        xuatSinhVien(l.a[i]) ;
    }
}
void pushBackArr(sinhVien *&a , int &n , sinhVien x ) 
{
    n=(a==NULL)?1:n+1;
    sinhVien *newArr=new sinhVien[n] ;
    for(int i=0; i < n-1; i++) 
    {
        newArr[i]=a[i] ;
    }
    newArr[n-1]=x;
    delete [] a;
    a=newArr;
}
void inputFromFile(ds &l) 
{
    ifstream fin ("sinhVien.txt") ;
    if(!fin){
        cout << "KHONG MO DUOC FILE" << endl;
        return;
    }
    sinhVien x ;
    while(fin >> x.mssv)
    {
        fin.ignore();
        getline(fin , x.hoTen,'#');
        fin.getline(x.ngaySinh,11,'#');
        fin.getline(x.queQuan,100,'#');
        fin >> x.diem;
        pushBackArr(l.a,l.n,x) ;
    } 
    fin.close() ;
}
void outputToFile(ds l)
{
    ofstream fout("sinhVien.txt");

    if(!fout)
    {
        cout << "KHONG MO DUOC FILE" << endl;
        return;
    }

    for(int i = 0; i < l.n; i++)
    {
        fout << l.a[i].mssv << "#";
        fout << l.a[i].hoTen << "#";
        fout << l.a[i].ngaySinh << "#";
        fout << l.a[i].queQuan << "#";
        fout << l.a[i].diem << endl;
    }

    fout.close();
}
bool cmp(sinhVien a, sinhVien b) 
{
    return a.diem < b.diem;
}
void sapXep(ds &l , bool (*func)(sinhVien,sinhVien)=cmp)
{
    for(int i=0; i < l.n-1;i++) 
    {
        for(int j=i+1;j < l.n;  j++) 
        {
            if(func(l.a[i],l.a[j]))
            swap(l.a[i],l.a[j]) ;
        }
    }
}
int timKiem(ds l , int id)
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl;
        return -1;
    }
    for(int i=0; i < l.n; i++) 
    {
        if(l.a[i].mssv==id)
        return i;
    }
    return -1;
}
int timKiemNhiPhan(ds l , int id)
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl;
        return -1;
    }
    int le=0; 
    int r=l.n-1;
    while(le <= r )
    {
        int m=(le+r)/2;
        if(l.a[m].mssv==id)
        {
            return m;
        }else if(l.a[m].mssv>id)
        {
            r=m-1;
        }else
        le=m+1;
    }
    return -1;
}
void sinhVienCoDiemCao(ds l) 
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl ;
        return;
    }
    sinhVien maxVal=l.a[0];
    for(int i=1;i <l.n; i++) 
    {
        if(l.a[i].diem>maxVal.diem)
        {
            maxVal=l.a[i];
        }
    }
    xuatSinhVien(maxVal);
}
void outputFromFile(ds l ) 

{
    ofstream fout("sinhVien.txt");

    if(!fout)
    {
        cout << "KHONG MO DUOC FILE" << endl;
        return;
    }

    for(int i = 0; i < l.n; i++)
    {
        fout << l.a[i].mssv << "#";
        fout << l.a[i].hoTen << "#";
        fout << l.a[i].ngaySinh << "#";
        fout << l.a[i].queQuan << "#";
        fout << l.a[i].diem << endl;
    }

    fout.close();
}

void giaiPhongVungNho(ds &l) 
{
    delete [] l.a;
    l.a=NULL;
    l.n=0;
}
int main() {
    ds l;
    init(l) ;
    inputFromFile(l) ;
    sapXep(l) ;
    outputList(l);
    outputFromFile(l) ;
    //sinhVienCoDiemCao(l);
    giaiPhongVungNho(l) ;
    return 0;
}

