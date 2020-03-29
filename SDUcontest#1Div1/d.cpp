#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    string b;
    string c;
    cin>>a>>c;
    a = a + c[1]+c[0];
    cin>>b>>c;
    b = b + c[1]+c[0];
    string fina="";
    string finb="";

    for(int i = 0;i<4;i++){
        if(a[i]=='A'){
            fina += a[i];
            int p = i+1;
            while(p%4 != i){
                if(a[p%4]!='X'){
                    fina+=a[p%4];
                }
                p++;
            }
            break;
        }
    }
    for(int i = 0;i<4;i++){
        if(b[i]=='A'){
            finb += b[i];
            int p = i+1;
            while(p%4 != i){
                if(b[p%4]!='X'){
                    finb+=b[p%4];
                }
                p++;
            }
            break;
        }
    }

    if(fina == finb){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}