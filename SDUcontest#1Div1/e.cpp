#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<long long, long long> > a;
    for(int i =0;i<n;i++){
        long long l,r;
        cin>>l>>r;
        a.push_back(make_pair(l,r));
    }
    sort(a.begin(),a.end());
    vector<long long> t1,t2;
    bool flag = true;
    for(int i=0;i<n;i++){
        if(t1.empty()){
            t1.push_back(a[i].second);
        }else{
            if(t1[t1.size()-1]<a[i].first){
                t1.push_back(a[i].second);
            }else{
                if(t2.empty()){
                    t2.push_back(a[i].second);
                }else{
                    if(t2[t2.size()-1]<a[i].first){
                        t2.push_back(a[i].second);
                    }else{
                        flag = false;
                    }
                }
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}

