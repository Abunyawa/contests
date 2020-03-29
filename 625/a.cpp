#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> r(n);
    vector<int> b(n);
    long long sm1(0), sm2(0);
    for(int i=0;i<n;i++){
        cin>>r[i];
        sm1+=r[i];

    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        b[i]-=i;
    }
    if(sm1>sm2){
        cout<<1<<endl;
    }else{
        int dif = sm2-sm1;
        int ct = 0;
        int ct2 = 0;
        for(int i=0;i<n;i++){
            if(r[i]!=b[i] && r[i]==1){
                ct++;
            }
            if(r[i]!=b[i] && b[i]==1){
                ct2++;
            }
        }
        int ans;
        
        if(ct!=0){
            if(ct<=ct2){
                ans = (ct2)/ct;
                ans++;
                cout<<ans<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}