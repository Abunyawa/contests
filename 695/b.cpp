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
    for(int i =0 ;i<n;i++){
        cin>>a[i];
    }
    int ctr = 0;
    for(int i=1;i<n-1;i++){
        if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])){
            ctr++;
        }
    }
    int ans  = ctr;

    for(int i=1;i<n-1;i++){
        int was = 0;
        for(int j = i-1;j<=i+1;j++){
            if(j-1>=0 && j+1<n){
                if((a[j]>a[j-1] && a[j]>a[j+1]) || (a[j]<a[j-1] && a[j]<a[j+1])){
                    was++;
                }
            }
        }
        ll nw = a[i];
        a[i] = a[i-1];
        int now = 0;
        for(int j = i-1;j<=i+1;j++){
            if(j-1>=0 && j+1<n){
                if((a[j]>a[j-1] && a[j]>a[j+1]) || (a[j]<a[j-1] && a[j]<a[j+1])){
                    now++;
                }
            }
        }
        a[i] = nw;
        ans = min(ans,ctr-was+now);

        a[i] = a[i+1];
        now = 0;
        for(int j = i-1;j<=i+1;j++){
            if(j-1>=0 && j+1<n){
                if((a[j]>a[j-1] && a[j]>a[j+1]) || (a[j]<a[j-1] && a[j]<a[j+1])){
                    now++;
                }
            }
        }

        a[i] = nw;
        ans = min(ans,ctr-was+now);
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

