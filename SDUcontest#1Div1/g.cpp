#include<bits/stdc++.h>
using namespace std;
bool used[10000];
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    long long sm = 0;
    map<int,vector<int> > mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
        if(mp.find(a[i])==mp.end()){
            vector<int> k;
            k.push_back(i);
            mp[a[i]] = k;
        }else{
            mp[a[i]].push_back(i);
        }
    }
    long long perP = sm/(n/2);
    for(int i = 0;i<n;i++){
        if(!used[i]){
            cout<<i+1<<' '<<mp[perP - a[i]].back()+1<<endl;
            used[i] = true;
            used[mp[perP - a[i]].back()] = true;
            mp[perP - a[i]].pop_back();
        }

    }
    return 0;
}