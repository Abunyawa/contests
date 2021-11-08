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
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}



void solve() {
    int n;
    cin>>n;
    vi a(n);
    int sm = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sm+=a[i];
    }

    vi b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    int mn = 1000000;
    for(int i=0;i<n;i++){
        if(b[i]!=0){
            mn = min(mn, a[i]/b[i]);
        }
    }

    int ans = 1;
    for(int i=1;i<=sqrt(sm);i++){
        if(sm%i==0){
            if(sm/i != i){
                if(i<=mn) ans = max(i, ans);
                if(sm/i <= mn)ans = max(ans, sm/i);
            }else{
                if(i<=mn) ans = max(i, ans);
            }
        }
    }

    vi ret;
    for(int j=0;j<n;j++){
        for(int k = 0;k<b[j];k++){
            ret.pb(j+1);
        }
        a[j] = a[j]-b[j]*ans;
    }
    int ptr = 0;

    cout<<ans<<' '<<sm/ans<<'\n';

    for(int i=0;i<ans;i++){
        for(int x: ret){
            cout<<x<<' ';
        }
        int ctr = ret.size();
        while(ctr!=sm/ans){
            while(ptr<n && a[ptr]<=0){
                ptr++;
            }
            if(ptr>=n){
                break;
            }
            
            cout<<ptr+1<<' ';
            a[ptr]--;
            ctr++;
        }
        cout<<'\n';
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}
