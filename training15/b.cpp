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

int binp(vl &a,int n,ll x){
    int l = n,r = a.size()-1;
    while(l+1<r){
        int mid = (l+r)/2;
        if(a[mid]>=x){
            r = mid;
        }else{
            l = mid;
        }
    }

    if(a[r]<=x)
        return r;
    if(a[l]<=x)
        return l;
    return l;
}

void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> s(200100,0);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        s[l]++;
        s[r+1]--;
    }
    ll ans = 0;
    ll cur = 0;
    vector<int> pref(200100,0);
    for(int i=1;i<=200000;i++){
        pref[i]=pref[i-1];
        cur+=s[i];
        if(cur>=k){
            pref[i]++;
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        cout<<pref[b]-pref[a-1]<<'\n';
    }
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
