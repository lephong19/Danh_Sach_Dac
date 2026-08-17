#include <iostream>
using namespace std ;
#define MAX 100
struct ds{
    int n;
    int a[MAX];
};
void init(ds &l)
{
    l.n=0;
}
void inputList(ds &l) 
{
    do{
        cout << "Nhap So Luong: ";
        cin >> l.n;
    }while(l.n <=0|| l.n>MAX);
    for(int i=0; i < l.n; i++)
    {
        cin >> l.a[i];
    }
}
void outputList(ds l) 
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl;
        return;
    }
    for(int i=0; i < l.n; i++) 
    {
        cout << "PT Thu " << i << " la:" << l.a[i] << endl; 
    }
    cout << endl ;
}
int timViTriPhanTu(ds l, const int &key)
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl;
        return -1;
    }
    for(int i=0; i < l.n; i++) 
    {
        if(l.a[i] == key )
        return i;
    }
    return -1;
}
void themCuoi(ds &l, const int &key)
{
    if(l.n==MAX)
    {
        cout << "DS DAY" << endl ;
        return;
    }
    l.a[l.n]=key;
    l.n++;
}
void xoaCuoi(ds &l)
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl;
        return;
    }
    l.n--;
}
void xoaTaiIndex(ds &l , const int &pos)
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl;
        return;
    }
    if(pos < 0 || pos >= l.n)
    {
        cout << "Vi Tri Xoa Khong Phu Hop" << endl;
        return;
    }
    for(int i=pos; i < l.n-1; i++) 
    {
        l.a[i]=l.a[i+1];
    }
    l.n--;
}
void themVaoIndex(ds &l , const int &val, const int &pos)
{
    if(l.n==MAX)
    {
        cout << "DS DAY" << endl ;
        return;
    }
    if(pos < 0 || pos > l.n)
    {
        cout << "Vi Tri Them Khong Hop Le" << endl;
        return;
    }
    for(int i=l.n-1 ; i >= pos; i--) {
        l.a[i+1]=l.a[i];
    }
    l.a[pos]=val;
    l.n++;
}
int timMax(ds l )
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl;
        return -1;
    }
    int maxVal=l.a[0] ;
    for(int i=1;i < l.n; i++) 
    {
        if(l.a[i] > maxVal){
            maxVal=l.a[i];
        }
    }
    return maxVal;
}
int timGtLonT2(ds l)
{
    if(l.n==0)
    {
        cout << "DS RONG" << endl ;
        return -1;
    }
    int max=l.a[0];
    int max2=INT_MIN;
    for(int i=1; i < l.n; i++) 
    {
        if(l.a[i]>max)
        {
            max2=max;
            max=l.a[i] ;
        }else if(l.a[i]>max2)
        {
            max2=l.a[i];
        }
    }
    return max2;
}
void giamDanSel(ds &l){
    for(int i=0; i < l.n-1; i++) 
    {
        int max_pos=i;
        for(int j=i+1; j < l.n; j++) 
        {
            if(l.a[max_pos]<l.a[j])
            max_pos=j;
        }
        int temp=l.a[i] ;
        l.a[i]=l.a[max_pos];
        l.a[max_pos]=temp;
    }
}
void giamDanIns(ds &l) 
{
    for(int i=1; i < l.n;i++)
    {
        int key=l.a[i] ;
        int pos=i-1;
        while(pos >=0 && l.a[pos]<key) 
        {
            l.a[pos+1]=l.a[pos];
            pos--;
        }
        l.a[pos+1]=key;
    }
}
void giamDanBub(ds &l) 
{
    for(int i=0; i < l.n-1; i++) 
    {
        for(int j=0; j < l.n-1-i; j++) 
        {
            if(l.a[j] < l.a[j+1])
            swap(l.a[j],l.a[j+1]); 
        }
    }
}
void giamDanInt(ds &l)
{
    for(int i=0; i < l.n-1; i++) 
    {
        for(int j=i+1; j < l.n; j++) 
        {
            if(l.a[i]< l.a[j])
            swap(l.a[i],l.a[j]);
        }
    }
}
// Yêu cầu: quicksort , heapsort, mergesort
int main() {
    ds l;
    init(l);
    inputList(l);
    outputList(l);
    //themVaoIndex(l,100,2);
    cout << "Sau Khi SX Giam Dan: " << endl ;
    //giamDanSel(l);
    //giamDanIns(l) ;
    //giamDanBub(l) ;
    giamDanInt(l) ;
    outputList(l);
    return 0;
}