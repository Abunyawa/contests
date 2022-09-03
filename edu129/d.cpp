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

typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

int len(ll x){
    int ctr = 0;
    for(ll i=1;;i*=10){
        if(x/i==0){
            return ctr;
        }
        ctr++;
    }
}

ll mx(ll x){
    ll cp  =x;

    ll mx = 0;
    
    while(cp!=0){
        ll cur = cp%10;

        mx = max(mx,cur);
        cp/=10;
    }

    return mx;
}
int n;
map<ll,bool> m;
void bfs(ll x){
    queue<pair<ll,int>> q;
    q.push({x,0});

    while(!q.empty()){
        ll cur = q.front().fi;
        int step = q.front().se;
        q.pop();

        if(len(cur)==n){
            cout<<step<<'\n';
            return;
        }

        ll cp = cur;

        vector<bool> used(10,0);
        used[0] = true;
        used[1] = true;
        while(cp!=0){
            ll nw = cp%10;
            if(!used[nw]){
                used[nw] = true;
                if(len(cur*nw)<=n && m[cur*nw]==false){
                    m[cur*nw] = true;
                    q.push({cur*nw, step+1});
                }
            }
            cp/=10;
        }
    }

    cout<<-1<<'\n';
}

void solve() {
    ll x;
    cin>>n>>x;
    if(n<len(x)){
        cout<<-1<<'\n';
        return;
    }

    bfs(x);

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

