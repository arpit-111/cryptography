#include<iostream>
using namespace std;
int main(){
int q,a1,a,b,r,s1=1,s2=0,s,t1=0,t2=1,t;
cout<<"enter 1st no=";
cin>>a;
cout<<"enter 2nd no=";
cin>>b;
a1=a;
while(b!=0){
q=a/b;
r=a-(b*q);
a=b;
b=r;
s=s1-q*s2;
t=t1-q*t2;
s1=s2;
s2=s;
t1=t2;
t2=t;
}
int inv;
if(t1>0){
inv=t1%a1;
}
else if(t1==0){
inv=0;
}
else if(t1<0){
int i=-t1;
if(i%a1==0){
inv=0;
}
else{
inv=a1-((-t1)%a1);}
}
cout<<"gcd of "<<a<<" and "<<b<<" ="<<a;
cout<<"\n multiplicative inverse= "<<inv;
}