#include<iostream>
using namespace std;
typedef int* pointer;

int  lowest(int* p1,size_t size)//必须在main函数里求得数组大小
                                // 数组传参到函数里会退化成指针
{
     int l=p1[0];
    for (int i=1;i<size;i++)
    {
        if (p1[i]<l)
            l=p1[i];
    }
    return l;
}
int BubbleSort(int* a,size_t size)//升序
{
    int flag=1;
    int i;
    for ( i=size-1;i>=0;i--) {
        for (int j=0;j<i;j++)
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag=0;
            }
        if (flag)
           break;
        flag=1;
    }
    return i;
}
 void show(int* a,size_t size)
{
    for (int i=0;i<size;i++)
        cout<<a[i]<<" ";
}
void  SelectionSort(int* a,size_t size)
{
    int min,flag;
    for (int i=0;i<size-1;i++) {
        min=a[i];
        flag=i;
        for (int j = i; j < size; ++j)
            if (min > a[j]) {
                min = a[j];
                flag=j;
            }
        swap(a[i],a[flag]);
    }
}
int main()
{
    int a[]={1,0,3,4,5,6,9,8};
    int size1=sizeof(a);//此处求的是数组a的内存大小
    int size=sizeof(a)/sizeof(a[0]);//求数组的大小
    //cout<<lowest(a,size);
    SelectionSort(a,size);
    show(a,size);
    return 0;
}