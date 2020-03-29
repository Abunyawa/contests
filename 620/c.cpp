#include<bits/stdc++.h>
using namespace std;


void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}


int main(){
    int q;
    cin>>q;
    while(q--){
        long long n,m;
        cin>>n>>m;
        long long curT = 0;
        vector<> c;
        for(int i=0;i<n;i++){
            long long t,l,r;
            cin>>t>>l>>r;
            c.push_back(make_pair(l-t,r-t));
        }
        long long l= c[0].first,r = c[0].second;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(c[i].first>r || c[i].second<l){
                flag = false;
                break;
            }else{
                l = max(l,c[i].first);
                r = min(r,c[i].second);
            }
        }
        if(flag){
            yes();
        }else{
            no();
        }
    }

    return 0;
}