#include<iostream>
using namespace std;
int main(){
int p,x,y,r1,r2,g,k1,k2;
cout<<"enter value of p(prime)=";
cin>>p;
cout<<"\nenter a random no x(private of 1st)=";
cin>>x;
if(0<=x<=p-1){
}
else {
cout<<"invalid value of x";
}
cout<<"\nenter a random no y(private of 2nd)=";
cin>>y;
if(0<=y<=p-1){
}
else{
cout<<"invalid value of y";
}
cout<<"\nenter no g(alpha)=";
cin>>g;
int rr1=1;
int rr2=1;
for(int i=1;i<=x;i++){
rr1=rr1*g;
}
for(int i=1;i<=y;i++){
rr2=rr2*g;
}
r1=rr1%p;
r2=rr2%p;
cout<<"R1="<<r1<<"\n"<<"R2="<<r2;
int kk1=1,kk2=1;
for(int i=1;i<=x;i++){
kk1=kk1*r2;
}
for(int i=1;i<=y;i++){
kk2=kk2*r1;
}
k1=kk1%p;
k2=kk2%p;
cout<<"\nkey for a="<<k1;
cout<<"\nkey for b="<<k2;
if(k1==k2){
cout<<"\nsucceeded!";
}
else{
cout<<"\nfailed!";
}
}