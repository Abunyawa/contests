#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int f0 = -1,l0=-1;
        int ctr1 = 0;
        int l = s.size();
        for(int i=0;i<l;i++){
            if(s[i]=='1'){
                ctr1++;
                if(f0 == -1){
                    f0 = i;
                }
                l0 = i;
            }
        }
        if(ctr1==0 || ctr1 == 1){
            cout<<0<<endl;
        }else{
            cout<<l0 - f0 +1 - ctr1<<endl;
        }
    }

    return 0;
}