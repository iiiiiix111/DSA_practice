#include<iostream>
#include <cstring>
using namespace std;
typedef int* pointer;
int  lowest(const int* p1,size_t size)//必须在main函数里求得数组大小
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
void  InsertionSort(int* a,size_t size)
{
    for (int i=1;i<size;i++)
        for (int j=i;j>0;j--)
        {
            if (a[j]<a[j-1])
                swap(a[j],a[j-1]);
            else
                break;
        }
}
int Partition(int array[],int low,int high)
{
    int pivot=array[high];
    int i=low-1;
    for (int j=low;j<high;j++)
        if (array[j]<pivot)
        {
            i++;
            swap(array[i],array[j]);
        }
    swap(array[i+1],array[high]);//i+1前面的都是修改好的
    return i+1;
}
void QuickSort(int array[],int low,int high)
{
    if (low<high)
    {
        int PivotIndex=Partition(array,low,high);
        QuickSort(array,low,PivotIndex-1);
        QuickSort(array,PivotIndex+1,high);
    }
}
void CountingSort(int* a,size_t size)
{
    int maxval= a[0];
    for (int i=1;i<size;i++)
        if (maxval<a[i])
            maxval=a[i];
    int count[maxval+1];
    for (int i=0;i<maxval+1;i++)
        count[i]=0;
    for (int i=0;i<size;i++)
        count[a[i]]++;
    int i=0;
    for (int j=0;j<maxval+1;j++)
        for (int k=0;k<count[j];k++)
        {
            a[i]=j;
            i++;
        }
}
void RadixSort(int* a,int size)
{
    int max_val=a[0];
    for (int i=1;i<size;i++)
        if(max_val<a[i])
            max_val=a[i];

    int RadixArray[10][size];
    int exp=1;
    int index;
    int in;
    int CountRadix[10]={0};
    while (max_val/exp!=0)
    {
        for (int i=0;i<size;i++)
        {

            index=(a[i]/exp)%10;//取余
            RadixArray[index][CountRadix[index]]=a[i];
            CountRadix[index]++;
        }

        in=0;
        for (int j=0;j<10;j++)
        {
            for (int i=0;i<CountRadix[j];i++)
            {
                a[in]=RadixArray[j][i];
                in++;
            }
            CountRadix[j]=0;
        }
        exp*=10;
    }

}

int main()
{
    int a[]={189,0,5,442,63,92,852,3214,264,263,264,332};
    int size1=sizeof(a);//此处求的是数组a的内存大小
    int size=sizeof(a)/sizeof(a[0]);//求数组的大小
    //cout<<lowest(a,size);
    //SelectionSort(a,size);
    //InsertionSort(a,size);
    //QuickSort(a,0,size-1);
    //CountingSort(a,size);
    RadixSort(a,size);
    show(a,size);
    return 0;
}