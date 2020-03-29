#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        int a,b;
        cin>>a>>b;
        int dif = abs(a-b);
        int bes = dif/5;
        dif%=5;
        int two = dif/2;
        dif %=2;
        cout<<bes+two+dif<<endl;
    }


    return 0;
}