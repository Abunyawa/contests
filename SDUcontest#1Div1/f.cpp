#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z,t1,t2,t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    int lf = t2*abs(z-x) + 2*t3 + t2*abs(x-y) + t3;
    int pew = abs(y-x)*t1;
    if(pew>=lf){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}