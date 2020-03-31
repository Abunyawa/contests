#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

void solve(){
    int n;
    cin>>n;
    vi a(n);
    int del[] = {1,2,3,5,7,11,13,17,19,23,29,31};
    vector<bool> used(12,false);
    vi ans;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int ind = 1;
        while(a[i]%del[ind]!=0){
            ind++;
        }
        used[ind] = true;
        ans.pb(ind);
    }

    int ctr = 0;
    int ind = 0;
    int mapp[11];
    for(int i=1;i<12;i++){
        if(used[i]){
            ctr++;
            mapp[i]=ind++;
        }
        
    }
    cout<<ctr<<'\n';
    for(auto e: ans){
        cout<<mapp[e]+1<<' ';
    }
    cout<<'\n';
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
