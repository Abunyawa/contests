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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
int n, m;
vector<pll> g[100100];
ll d[100100];
ll mx[100100];
ll mn[100100];
ll mxP[100100];
ll mnP[100100];
ll used[100100];

ll d2[100100];
ll mx2[100100];
ll mn2[100100];
ll mxP2[100100];
ll mnP2[100100];
ll used2[100100];

void bfs1(int st){
    queue<ll> q;
    used[st] = true;

    q.push(st);
    while(!q.empty()){
        ll cur = q.front();

        q.pop();

        for(auto x: g[cur]){
            ll to = x.fi;
            ll dis = x.se;
            if(used[to]){
                if(d[to]==d[cur]+1){
                    if(mx[cur]>mx[to]){
                        mx[to] = mx[cur];
                        mxP[to] = cur;
                    }
                    if(dis>mx[to]){
                        mx[to] = dis;
                        mxP[to] = cur;
                    }

                    if(mn[cur]<mn[to]){
                        mn[to] = mn[cur];
                        mnP[to] = cur;
                    }
                    if(dis<mn[to]){
                        mn[to] = dis;
                        mnP[to] = cur;
                    }
                }
            }else{
                used[to] = true;
                d[to] = d[cur]+1;
                if(mx[cur]>mx[to]){
                    mx[to] = mx[cur];
                    mxP[to] = cur;
                }
                if(dis>mx[to]){
                    mx[to] = dis;
                    mxP[to] = cur;
                }

                if(mn[cur]<mn[to]){
                    mn[to] = mn[cur];
                    mnP[to] = cur;
                }
                if(dis<mn[to]){
                    mn[to] = dis;
                    mnP[to] = cur;
                }

                q.push(to);
            }
        }
    }
}

void bfs2(int st){
    queue<ll> q;
    used2[st] = true;

    q.push(st);
    while(!q.empty()){
        ll cur = q.front();

        q.pop();

        for(auto x: g[cur]){
            ll to = x.fi;
            ll dis = x.se;
            if(used2[to]){
                if(d2[to]==d2[cur]+1){
                    if(mx2[cur]>mx2[to]){
                        mx2[to] = mx2[cur];
                        mxP2[to] = cur;
                    }
                    if(dis>mx2[to]){
                        mx2[to] = dis;
                        mxP2[to] = cur;
                    }

                    if(mn2[cur]<mn2[to]){
                        mn2[to] = mn2[cur];
                        mnP2[to] = cur;
                    }
                    if(dis<mn[to]){
                        mn2[to] = dis;
                        mnP2[to] = cur;
                    }
                }
            }else{
                used2[to] = true;
                d2[to] = d2[cur]+1;
                if(mx2[cur]>mx2[to]){
                    mx2[to] = mx2[cur];
                    mxP2[to] = cur;
                }
                if(dis>mx2[to]){
                    mx2[to] = dis;
                    mxP2[to] = cur;
                }

                if(mn2[cur]<mn2[to]){
                    mn2[to] = mn2[cur];
                    mnP2[to] = cur;
                }
                if(dis<mn2[to]){
                    mn2[to] = dis;
                    mnP2[to] = cur;
                }

                q.push(to);
            }
        }
    }
}


void solve() {
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        mx[i] = -1;
        mn[i] = 1e10;
        mx2[i] = -1;
        mn2[i] = 1e10;
    }
    for(int i=0;i<m;i++){
        ll u,v,x;
        cin>>u>>v>>x;
        g[u].pb({v,x});
        g[v].pb({u,x});
    }

    bfs1(1);
    bfs2(n);

    if(d[n]==1){
        cout<<1<<'\n';
        cout<<1<<' '<<n<<'\n';
        return;
    }
    ll mxA = 0;
    ll md;
    bool dir;
    for(int i=2;i<n;i++){
        if(d[i]+d2[i]==d[n]){
            if(mx[i]-mn2[i] > mxA){
                mxA = mx[i]-mn2[i];
                md = i;
                dir = true;
            }

            if(mx2[i]-mn[i] > mxA){
                mxA = mx2[i]-mn[i];
                md = i;
                dir = false;
            }
        }
    }


    vl ans1;
    vl ans2;
    //cout<<md<<endl;

    ll st = md;
    while(st!=1){
        if(dir){
            st = mxP[st];
            //cout<<st<<' ';
            ans1.pb(st);
        }else{
            st = mnP[st];
            //cout<<st<<' ';
            ans1.pb(st);
        }
    }


    st = md;
    while(st!=n){
        if(dir){
            st = mnP2[st];
            ans2.pb(st);
        }else{
            st = mxP2[st];
            ans2.pb(st);
        }
    }

    cout<<ans1.size()+ans2.size()<<'\n';
    reverse(all(ans1));
    for(ll x: ans1){
        cout<<x<<' ';
    }
    cout<<md<<' ';
    
    for(ll x: ans2){
        cout<<x<<' ';
    }
    cout<<'\n';

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

