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
int const INF  = 99999999;


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
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans = 0;
    for(int i=1;i<=30;i++){
        ll cur = 0;
        ll best = 0;
        for(int j = 0;j<n;j++){
            int val;
            if(a[j]>i){
                val = -INF;
            }else{
                val = a[j];
            }
            cur+=val;
            best = min(best,cur);
            ans = max(ans,(cur-best)-i);
        }
    }
    cout<<ans<<'\n';
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
