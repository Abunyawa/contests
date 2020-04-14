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
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
/*
abcccabc
*/
void solve(){
    int n;
    cin>>n;
    set<int> a;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
        a.insert(x);
    }
    int ans = 0;
    if(n>1){
        ans = 1;
    }
    for(auto e: mp){
        int mb =max(min(e.S,(int)a.size()-1),min(e.S-1,(int)a.size()));
        ans = max(ans,mb);
    }
    cout<<ans<<'\n';
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
