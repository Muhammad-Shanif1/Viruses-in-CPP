// #include<winable.h>    //this is use in dev cpp without this you see error
#include<windows.h>
int main()
{
    FreeConsole();
    int a=0;
    while (a<10)
    {
        BlockInput(true);
        Sleep(1000);
        a++;
    }
}