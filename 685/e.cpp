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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
/*
abc

bcd


*/


void solve() {
    int n;
    cin>>n;
    map<int,vi> m;
    int xorVals[n+1];
    int mx = 1;
    int num = 0;
    xorVals[1] = 0;
    m[0].pb(1);
    for(int i=2;i<=n;i++){
        cout<<"XOR 1 "<<i<<endl;
        cin>>xorVals[i];
        m[xorVals[i]].pb(i);
        if(m[xorVals[i]].size()>mx){
            mx = m[xorVals[i]].size();
            num = xorVals[i];
        }
    }
    vi ans(n+1);
    if(mx>1){
        int f = m[num][0];
        int s = m[num][1];
        cout<<"AND "<<f<<' '<<s<<endl;
        int x;
        cin>>x;
        ans[f] = x;
        ans[s] = x;
        ans[1] = xorVals[f]^x;
        for(int i=2;i<=n;i++){
            ans[i] = ans[1]^xorVals[i];
        }
    }else{
        int a = 1, b = 2, c = -1;
        for(int i=2;i<=3;i++){
            for(int j=i+1;j<=n;j++){
                if((xorVals[i]^xorVals[j])==(n-1)){
                    b = i;
                    c = j;
                }
            }
        }

        int xorab = xorVals[b];
        int xorac = xorVals[c];
        int xorbc = xorVals[b]^xorVals[c];
        int andab;
        int andac;
        int andbc=0;
        cout<<"AND "<<a<<' '<<b<<endl;
        cin>>andab;
        cout<<"AND "<<a<<' '<<c<<endl;
        cin>>andac;
        ll x = xorab + 2 * andab;
        ll y = xorac + 2 * andac;
        ll z = xorbc + 2 * andbc;
        ans[a] = (x+y-z)/2;
        for(int i=2;i<=n;i++){
            ans[i] = ans[1]^xorVals[i];
        }
        
    }
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

