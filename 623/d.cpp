#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<pair<ll,ll> > ar(n);
    vector<ll> check;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        cin>>ar[i].F;
    }
    for(int i=0;i<n;i++){
        cin>>ar[i].S;
    }
    sort(all(ar));
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(mp.find(ar[i].F)==mp.end()){
            mp[ar[i].F] = ar[i].S;
        }else{
            mp[ar[i].F+1] = min(ar[i].S,mp[ar[i].F]);
            ans+=min(ar[i].S,mp[ar[i].F]);
            mp[ar[i].F] = max(ar[i].S,mp[ar[i].F]);
        }
    }
    cout<<ans<<endl;
    return 0;
}