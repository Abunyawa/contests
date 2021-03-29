// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n, m;
    cin>>n>>m;
    vl a(n);

    vi ctr(m,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        ctr[a[i]%m]++;
    }
    int ans = 0;
    if(ctr[0]>0){
        ans++;
        ctr[0] = 0;
    }
    for(int i=1;i<=m/2;i++){
        if(m%2==0 && m/2==i){
            break;
        }
        int del = min(ctr[i], ctr[(m-i)%m]);
        ctr[i] -=del;
        ctr[m-i] -= del;
        if(del>0){
            ans++;
        }
        if(ctr[i]>0 && del>0){
            ctr[i]--;
        }
        if(ctr[m-i]>0 && del>0){
            ctr[m-i]--;
        }
        ans+=max(ctr[i], ctr[(m-i)%m]);
    }
    if(m%2==0){
        if(ctr[m/2]>0){
            ans++;
        }
    }

    cout<<ans<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

