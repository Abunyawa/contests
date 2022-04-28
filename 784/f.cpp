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
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int smL = 0;
    int smR = 0;
    int l = 0;
    int r = n-1;
    int ans =0;
    while(l<=r){
        
        while(l<=r && smL<smR){
            smL+=a[l++];
        }
        if(smL==smR){
            ans = l + n-1 - r;
        }

        while(l<=r && smL>smR){
            smR+=a[r--];
        }

        if(smL==smR){
            ans = l + n-1 - r;
            smL+=a[l++];
        }
        //cout<<smL<<' '<<smR<<'\n';

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

