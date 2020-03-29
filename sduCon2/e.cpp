#include<bits/stdc++.h>
using namespace std;

long long powM(int x, int p){
    if(p==0){
        return 1;
    }else{
        if(p%2==0){
            return powM(x,p/2)*powM(x,p/2);
        }else{
            return x*powM(x,p-1);
        }
    }
}

bool check(long long x, int i){
    int sm = 0;
    //cout<<x<<endl;
    while(x!=0){
        sm+=x%10;
        x/=10;
    }

    return sm==i;
}


int main(){
    int a, b, c;
    cin>>a>>b>>c;   
    vector<long long> ans;

    for(int i = 1;i<=90;i++){
        long long x = b*powM(i,a)+c;
        if(x<1000000000 && x>0){
            if(check(x,i)){
                ans.push_back(x);
            }
        }
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(auto e: ans){
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}