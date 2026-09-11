#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
    int a=10;
    for(int i=1;i<=a;i++){
        for (int j = 1; j <= i; j++)
        {
            cout<<"🖕";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}