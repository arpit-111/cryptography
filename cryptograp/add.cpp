#include<iostream>
using namespace std;
string encrypt(string pt,int key){
    string ct="";
    for(int i=0;i<pt.size();i++){
        if(isupper(pt[i])){
            ct+=char(((int(pt[i])+key-65)%26)+65);
        }
        else{
            ct+=char(((int(pt[i])+key-97)%26)+97);
        }
    }
    return ct;
}
string decrypt(string ct,int key){
    string pt;
    for(int i=0;i<ct.size();i++){
        if(isupper(ct[i])){
            pt+=char(((int (ct[i])-key-65)%26)+65);
        }
        else{
                pt+=char(((int (ct[i])-key-97)%26)+97);
            
        }
    }
    return pt;
}
int main(){
    string pt;
    cout<<"enter pt=";
    cin>>pt;
    int key;
    cout<<"enter key=";
    cin>>key;
    string ct=encrypt(pt,key);
    cout<<endl<<"ct="<<ct;
    cout<<endl<<"pt="<<decrypt(ct,key);
}