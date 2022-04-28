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
    int n, x;
    cin>>n>>x;

    vi a(n);
    int mnInd = 0;
    int mxInd = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<a[mnInd]){
            mnInd = i;
        }
        if(a[i]<a[mxInd]){
            mxInd = i;
        }
    }
    ll ans = 0;
    for(int i=1;i<n;i++){
        int mn = min(a[i-1],a[i]);
        int mx = max(a[i-1],a[i]);
        ans+=mx-mn;
    }
    int cur = 0;
    

    
    if(x<=a[mxInd]){
        int bstAdd = 1e8;

        bstAdd = min(abs(a[0]-1), abs(a[n-1]-1));
        for(int i=1;i<n;i++){
            int add = abs(1-a[i-1]) + abs(1-a[i]) - abs(a[i]-a[i-1]);
            bstAdd = min(bstAdd, add);
        }

        ans+=bstAdd;
    }else{
        int bstAdd = 1e8;
        int ind = -1;
        bstAdd = min(abs(a[0]-1), abs(a[n-1]-1));

        if(abs(a[0]-1) < abs(a[n-1]-1)){
            ind = 0;
        }else{
            ind = n;
        }
        for(int i=1;i<n;i++){
            int add = abs(1-a[i-1]) + abs(1-a[i]) - abs(a[i]-a[i-1]);
            
            if(bstAdd>add){
                bstAdd = add;
                ind = i;
            }
        }

        a.insert(a.begin()+ind, 1);
        ans+=bstAdd;
        n++;
        
        bstAdd = min(abs(a[0]-x), abs(a[n-1]-x));

        for(int i=1;i<n;i++){
            int add = abs(x-a[i-1]) + abs(x-a[i]) - abs(a[i]-a[i-1]);
            
            if(bstAdd>add){
                bstAdd = add;
            }
        }

        ans+=bstAdd;
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

