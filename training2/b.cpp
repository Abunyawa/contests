#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b,n,d;
    cin>>a>>b>>n>>d;
    long long curM = -1;
    int ind = -1;
    for(int i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        long long initialS = 4*d*d;
        long long lenX = 0;
        bool flagX = false;
        bool flagY = false;
        if(x+d>=0 && x+d<=a){
            flagX = true;
            if(x-d>=0 && x-d<=a){
                lenX = 2*d;
            }else{
                lenX = x+d;
            }
        }

        if(x-d>=0 && x-d<=a){
            flagX = true;
            if(x+d>=0 && x+d<=a){
                lenX = 2*d;
            }else{
                lenX = a-x+d;
            }
        }
        if(x-d<0 && x+d>a){
            flagX = true;
            lenX = a;
        }

        long long lenY = 0;
        if(y+d>=0 && y+d<=b){
            flagY = true;
            if(y-d>=0 && y-d<=a){
                lenY = 2*d;
            }else{
                lenY = y+d;
            }
        }
        if(y-d>=0 && y-d<=b){
            flagY = true;
            if(y+d>=0 && y+d<=b){
                lenY = 2*d;
            }else{
                lenY = b-y+d;
            }
        }

        if(y-d<0 && y+d>b){
            flagY = true;
            lenY = b;
        }
        if(flagX && flagY){
            if(initialS - lenX*lenY > curM){
                curM = initialS - lenX*lenY;
                ind = i;
            }
        }

    }

    cout<<ind+1<<' '<<curM<<endl;

    return 0;
}