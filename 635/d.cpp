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
int bp(vector<ll> &a,ll x){
    int l = 0,r = a.size()-1;
    int mid = (l+r)/2;
    while(l+1<r){
        mid = (l+r)/2;
        if(a[mid]>x){
            r = mid;
        }else{
            l = mid;
        }
    }
    if(abs(x-a[l])<abs(x-a[r])) return l;
    return r;
}
void solve(){
    int rr,gg,bb;
    cin>>rr>>gg>>bb;
    vector<ll> red(rr);
    vector<ll> green(gg);
    vector<ll> blue(bb);
    for(int i=0;i<rr;i++){
        cin>>red[i];
    }
    for(int i=0;i<gg;i++){
        cin>>green[i];
    }
    for(int i=0;i<bb;i++){
        cin>>blue[i];
    }
    sort(all(red));
    sort(all(green));
    sort(all(blue));
    vector<int> rbg(rr);
    vector<int> rbb(rr);
    for(int i=0;i<rr;i++){
        rbg[i] = bp(green,red[i]);
        rbb[i] = bp(blue,red[i]);        
    }
    vector<int> gbr(gg);
    vector<int> gbb(gg);
    for(int i=0;i<gg;i++){
        gbr[i] = bp(red,green[i]);
        gbb[i] = bp(blue,green[i]);        
    }
    vector<int> bbr(bb);
    vector<int> bbg(bb);
    for(int i=0;i<bb;i++){
        bbr[i] = bp(red,blue[i]);
        bbg[i] = bp(green,blue[i]);        
    }

    ll ans = 10e18;
    for(int i=0;i<rr;i++){
        ans = min(ans,(red[i]-green[rbg[i]])*(red[i]-green[rbg[i]])+(red[i]-blue[rbb[i]])*(red[i]-blue[rbb[i]])+(blue[rbb[i]]-green[rbg[i]])*(blue[rbb[i]]-green[rbg[i]]));       
    }
    for(int i=0;i<gg;i++){
        ans = min(ans,(green[i]-red[gbr[i]])*(green[i]-red[gbr[i]])+(green[i]-blue[gbb[i]])*(green[i]-blue[gbb[i]])+(red[gbr[i]]-blue[gbb[i]])*(red[gbr[i]]-blue[gbb[i]]));
    }
    for(int i=0;i<bb;i++){
        ans = min(ans,(blue[i]-green[bbg[i]])*(blue[i]-green[bbg[i]])+(blue[i]-red[bbr[i]])*(blue[i]-red[bbr[i]])+(green[bbg[i]]-red[bbr[i]])*(green[bbg[i]]-red[bbr[i]]));
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
