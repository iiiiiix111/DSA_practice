#include <iostream>
using namespace std;
int count=1;
/*void fibonacci(int a,int b)
{
    int sum;
    sum=a+b;
    a=b,b=sum;
    cout<<" "<<sum;
    count++;
    if (count<19)
        fibonacci(a,b);
    else
        return;
}*/
int fibonacci(int n)
{
    if (n<=1)
        return n;
    else
        return fibonacci(n-1)+ fibonacci(n-2);
}
int main() {
    //Fibonacci
   /* int sum;
    int prev1=0,prev2=1;

    cout<<prev1<<" "<<prev2<<" ";
    for (int i=0;i<18;i++)
    {
        sum=prev1+prev2;
        prev1=prev2;
        prev2=sum;
        cout<<prev2<<" ";
    }*/
  /* cout<<"0 1";
    fibonacci(0,1);
   */
  cout<<fibonacci(19);
  return 0;
}