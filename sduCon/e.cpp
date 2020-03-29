#include<bits/stdc++.h>
using namespace std;
bool isVis(int y){
    if(y%4!=0){
        return false;
    }else if(y%100!=0){
        return true;
    }else if(y%400==0){
        return true;
    }else{
        return false;
    }
}
int main(){
    int d,m,y;
    cin>>d>>m>>y;
    int k;
    int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(isVis(y)){
        month[2]=29;
    }
    cin>>k;
    d+=k;
    while(true){
        if(m>12){
            m=1;
            y++;
            if(isVis(y)){
                month[2]=29;
            }else{
                month[2]=28;
            }
        }
        if(d>month[m]){
            d-=month[m];
            m++;
        }else{
            break;
        }
    }

    cout<<d<<' '<<m<<' '<<y;
    return 0;
}