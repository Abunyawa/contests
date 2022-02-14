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
    int n;
    cin>>n;
    vl a(n);

    for(int i=0;i<n;i++){

        cin>>a[i];
    }
    ll ans = 0;
    vector<bool> used(n,0);
    ll ctr = 0;
    for(int i=1;i<n-1;i++){
        if(a[i]>=1){
            if(a[i]>1){
                used[i] = true;
            }
            ans += a[i]/2;
            ctr += a[i]%2;
            a[i] = a[i]%2;
        }
    }

    //cout<<ans<<'\n';
    bool flag = false;
    for(int i=1;i<n-1;i++){
        if(used[i] && a[i]==0){
            flag = true;
            ans += ctr;
            break;
        }
    }

    if(flag){
        cout<<ans<<'\n';
        return;
    }
    
    for(int i=1;i<n-1;i++){
        if(used[i] && a[i]==1){
            if(ctr>1){
                flag = true;
                ans += ctr;
                break;
            }
        }
    }

    if(flag){
        cout<<ans<<'\n';
        return;
    }else{
        cout<<-1<<'\n';
    }
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

