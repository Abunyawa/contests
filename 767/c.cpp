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
    map<int,queue<int>> m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        m[x].push(i);
    }

    vi b;
    int mn = 0;
    while(mn!=n){
        int mx = -1;
        for(int i=0;i<1e6;i++){
            while(!m[i].empty() && m[i].front()<mn){
                m[i].pop();
            }

            if(!m[i].empty()){
                int ind = m[i].front();
                mx = max(mx,ind);
                m[i].pop();
            }else{
                if(i!=0){
                    b.pb(i);
                    mn = mx+1;
                }
                break;
            }
        }

        if(m[0].empty()){
            if(mn!=n){
                for(int j = 0; j < n-mn;j++){
                    b.pb(0);
                }
            }
            break;
        }
    }

    cout<<b.size()<<'\n';

    for(int i=0;i<b.size();i++){
        cout<<b[i]<<' ';
    }

    cout<<'\n';
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

