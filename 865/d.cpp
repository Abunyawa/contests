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
    int p;
    cout<<"+ "<<n+1<<endl;
    cin>>p;
    if(p==-2){assert(0);}
    cout<<"+ "<<n<<endl;
    cin>>p;
    if(p==-2){assert(0);}
    vi g;
    int l = 1;
    int r = n;
    while(l<=r){
        g.pb(r--);
        
        if(l!=r) g.pb(l++);
    }
    
    vi res(n,0);
    int mx = 0;
    for(int i=2;i<=n;i++){
        cout<<"? 1 "<<i<<endl;
        cin>>res[i-1];
        if(res[mx]<=res[i-1]){
            mx = i-1;
        }
    }   

    vi ans1(n);
    vi ans2(n);

    ans1[mx] = g[0];
    ans2[mx] = g[n-1];

    for(int i=0;i<n;i++){
        if(i==mx) continue;
        cout<<"? "<<mx+1<<' '<<i+1<<endl;
        cin>>res[i];
        ans1[i] = g[res[i]];
        ans2[i] = g[n-1-res[i]];
    }

    string ans = "! ";
    for(int i=0;i<n;i++){
        ans+=to_string(ans1[i])+" ";
    }
    for(int i=0;i<n;i++){
        ans+=to_string(ans2[i])+" ";
    }

    cout<<ans<<endl;
    cin>>p;
    if(p==-2){assert(0);}
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

