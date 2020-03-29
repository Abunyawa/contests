#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b;
    cin>>a>>b;
    double s = a*b;
    double p1,p2,p3,p4;
    cin>>p1>>p2>>p3>>p4;
    if(p1+p2!=p3+p4 && p1+p3!=p2+p4 && p1+p4!=p3+p2){
        cout<<"NO"<<endl;
    }else{
        p1 = s/100*p1;
        p2 = s/100*p2;
        p3 = s/100*p3;
        p4 = s/100*p4;
        if(p1+p2==p3+p4){
            double x = 2*p1/b;
            double y = 2*p3/a;
            cout<<"YES"<<endl<<x<<endl<<y<<endl;
        }else if(p1+p3==p2+p4){
            double x = 2*p1/b;
            double y = 2*p2/a;
            cout<<"YES"<<endl<<x<<endl<<y<<endl;
        }else{
            double x = 2*p1/b;
            double y = 2*p2/a;           
            cout<<"YES"<<endl<<x<<endl<<y<<endl;
        }
    }
    return 0;
}