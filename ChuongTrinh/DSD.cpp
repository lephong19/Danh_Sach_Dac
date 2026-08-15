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
int timViTriPhanTu(ds l, cosnt int &key)
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
int main() {
    ds l;
    init(l);
    inputList(l);
    outputList(l);
    themVaoIndex(l,100,2);
    outputList(l);
    return 0;
}