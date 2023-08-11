#include<iostream>
using namespace std;
string encrypt(string pt,string key){
    string ct="";
    char ke;
    for(int i=0;i<pt.size();i++){
        ke=key[i%(key.size())];
        //cout<<endl<<ke;
        if(isupper(ke)){
            ke=int (ke)-65;
        }
        else{
            ke=(int (ke)-97);
        }
        if(isupper(pt[i])){
            ct+=char((((int (pt[i]))+(int(ke))-65)%26)+65);
           
        }
        else{
            ct+=char((((int (pt[i]))+(int(ke))-97)%26)+97);    
          
        }
    }
   // cout<<"ct="<<ct;
   return ct;
}
int main(){
    string pt;
    string key;
    cout<<"enter pt=";
    cin>>pt;
    cout<<"enter key=";
    cin>>key;
    string ct;
    ct=encrypt(pt,key);
    cout<<"ct="<<ct;
}