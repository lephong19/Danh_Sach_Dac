#include <iostream>
using namespace std ;
#define M 100
struct ds{
    int a[M];
    int n;
};
void init(ds &ds)
{
    ds.n=0;
} 
void nhapMang(ds &ds){
    
    do{
        cout << "Nhap so luong ";
        cin >> ds.n;
    }while(ds.n <=0);

    for(int i=0; i < ds.n; i++) 
    {
        cin >> ds.a[i] ;
    }
}
void xuatMang(ds ds)
{
    if(ds.n==0)
    {
        cout << "DS rong";
        return;
    }
    for(int i=0; i < ds.n; i++)
    {
        cout << ds.a[i] << " " ; 
    }
    cout << endl ;
}
void mangKetQua(ds &ds,const int &x){
    ds.a[ds.n++]=x;
}
void timViTriX(ds dsm , const int &x,ds &res){
    res.n=0;
    for(int i=0; i <dsm.n; i++) 
    {
        if(dsm.a[i]==x)
        {
            res.a[res.n++]=i;
        }
    }
    if(res.n==0)
    {
        cout << "Khong tim thay" << x << endl;
        return;
    }

    for(int l=0; l<res.n;l++)
    {
        cout << res.a[l] << " " ;
    }
    cout << endl ;
}
int demSoLanXuatHien(ds dsm,const int &x)
{
    if(dsm.n==0){
        return -1;
    }
    int dem=0;
    for(int i=0; i < dsm.n;i++) 
    {
        if(dsm.a[i]==x)
        dem++;
    }
    if(dem==0)
    {
        cout << "Khong xuat hien" << endl;
        return -1;
    }
    return dem;
}
int timPTLonThu2(ds dsm)
{
    int max=dsm.a[0];
    int ans=dsm.a[0];
    bool timThay=false;
    for(int i=1; i < dsm.n;i++)
    {
        if(dsm.a[i]>max)
        {
            ans=max;
            max=dsm.a[i];
            timThay=true;
        }else if((dsm.a[i]>ans||!timThay)&&dsm.a[i]<max)
        {
            ans=dsm.a[i];
            timThay=true;
        }
    }
    if(!timThay)
    {
        cout << "Khong tim Thay";
        return -1;
    }
    return ans;
}
int timViTriDauChuaX(ds dsm, const int &x)
{
    // da sap xep
    int ans=-1;
    int l=0;
    int r=dsm.n-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(dsm.a[m]>=x)
        {
            ans=m;
            r=m-1;
        }else {
            l=m+1;
        }
    }
    return ans ;
}
 int timViTriCuoiChuaX(ds dsm,const int x ){
    int ans =-1;
    int l=0; 
    int r =dsm.n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(dsm.a[m]<=x)
        {
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return ans;
 }
 int demSoLanXuatHienBinary(ds dsm,const int &x){
    return (timViTriCuoiChuaX(dsm ,x)-timViTriDauChuaX(dsm,x))+1;
 }
 void selectionSort(ds &dsm){
    // Code
    for(int i= 0; i < dsm.n-1;i++)
    {
        int min_pos=i;
        for(int j=i+1;j < dsm.n; j++)
        {
            if(dsm.a[min_pos]>dsm.a[j])
            {
                min_pos=j;
            }
        }
        swap(dsm.a[i],dsm.a[min_pos]);
    }
 }

 void insertSort(ds &dsm){
    for(int i=1; i <dsm.n; i++)
    {
        int key=dsm.a[i];
        int pos =i-1;
        while(pos>=0 && dsm.a[pos]>key)
        {
            dsm.a[pos+1]=dsm.a[pos];
            pos--;
        }
        dsm.a[pos+1]=key;
    }
 }
 void bubleSort(ds &dsm)
 {
    for(int i=0; i < dsm.n-1;i++)
    {
        for(int j=0; j <dsm.n-1-i;j++)
        {
            if(dsm.a[j]>dsm.a[j+1]){
                swap(dsm.a[j],dsm.a[j+1]);
            }
        }
    }
 }
 void interChang(ds &dsm)
 {
    for(int i=0; i < dsm.n-1;i++)
    {
        for(int j=i+1; j<dsm.n; j++)
        {
            if(dsm.a[i]>dsm.a[j])
            swap(dsm.a[i],dsm.a[j])
        }
    }
 }
 void quickSort(int a[], int left, int right)
{
    int pivot = a[(left + right) / 2];

    int i = left;
    int j = right;
    // 40 60 15 "50" 90 20 10 70, l=0 r=7
    // 40 10 15i 50 90 20j 60 70
    // 40 10 15 50i 90 20j 60 70
    // 40 10 15 20 90i,j 50 60 70
    do
    {
        while(a[i] < pivot)
            i++;//i=1

        while(a[j] > pivot)
            j--;// j=6

        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }

    } while(i <= j);

    if(left < j)
        quickSort(a, left, j);

    if(i < right)
        quickSort(a, i, right);
}
 int main() 
{
    ds a;
    ds res;
    init(a);
    init(res);
    nhapMang(a);
    //4
    //timViTriX(a,5,res);
    //cout << demSoLanXuatHien(a,5);
    //cout << timPTLonThu2(a);
    // int kq=timViTriDauChuaX(a,5);
    // if(kq==-1)
    // {
    //     cout << "Khong tim thay" << endl;
    // }else
    // {
    //     cout << "Tim thay tai " << kq << endl ;
    // }

    // cout << demSoLanXuatHienBinary(a,5);
    //selectionSort(a);
    insertSort(a);
    xuatMang(a);
    return 0;
}