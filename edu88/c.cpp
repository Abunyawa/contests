#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

double f(int h, int c, ll times,int t){
    return abs(t - (double)(h*((times-1)/2+1)+c*(times-1)/2)/(double)times);
}

void solve(){
    double h,c,t;
    cin>>h>>c>>t;
    if((h+c)/2.0>=t){
        cout<<2<<'\n';
        return;
    }
    if(t>=h){
        cout<<1<<'\n';
        return;
    }
    ll l = 0;
    ll r = 100000000;
    while(r-l>2){
        ll m1 = l+(r-l)/3;
        ll m2 = l+ 2*(r-l)/3;
        if(f(h,c,2*m1+1,t)<f(h,c,2*m2+1,t)){
            r = m2;
        }else{
            l = m1;
        }
    }
    ll ans= 0;

    for(ll i = max(0ll,l-100);i<=r+100;i++){
        if(f(h,c,2*i+1,t)<f(h,c,2*ans+1,t)){
            ans = i;
        }
    }
    cout<<2*ans+1<<'\n';
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
