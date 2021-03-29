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

const int MAXN = (int)1e5 + 5;
const int MAXM = (int)1e5 + 5;
const int MAXC = (int)1e3 + 5;

vector<pii> ans[MAXN];
map<string, int> mapping;
int D, n, m, cars, bonusPts;
array<int, 4> e[MAXM];
vi inEdge[MAXN], outEdge[MAXN];
string streetName[MAXM];
vi carRoute[MAXC];
ll used[MAXM];

vi filterEdges(vi v) {
    vi u;
    
    for (int x : v) {
        if (used[x]) {
            u.pb(x);
        }
    }
    
    return u;
}

bool cmp(int a, int b) {
    return used[a] > used[b];
}

void solve() {
    cin >> D >> n >> m >> cars >> bonusPts;
    
    rep (i, 0, m) {
        int u, v, w;
        string sname;
        cin >> u >> v >> sname >> w;
        e[i] = {u, v, w,0};
        mapping[sname] = i;
        streetName[i] = sname;
        outEdge[u].pb(i);
        inEdge[v].pb(i);
    }
    
    rep (i, 0, cars) {
        int sz;
        cin >> sz;
        
        while (sz--) {
            string s;
            cin >> s;
            int x = mapping[s];
            carRoute[i].pb(x);
            used[x] += (sz + 1) * (sz + 1);
            e[x][3]++;
        }
    }
    
    rep (i, 0, n) {
        inEdge[i] = filterEdges(inEdge[i]);
        outEdge[i] = filterEdges(outEdge[i]);
    }
    
    int R = -1;
    vi ver;
    
    rep (i, 0, n) {
        int curSize = sz(inEdge[i]);
        
        if (curSize == 0) {
           continue;
        }
        
        ver.pb(i);
        sort(all(inEdge[i]), cmp);
        
        if (curSize == 1) {
            ans[i].eb(inEdge[i][0], 1);
        }
        else if (curSize == 2) {
            int a = inEdge[i][0];
            int b = inEdge[i][1];
            ans[i].eb(a, 1);
            ans[i].eb(b, 1);
        }
        else {
            R = i;
            cerr << sz(inEdge[i]) << endl;
            int t = 225;
            
            for (int x : inEdge[i]) {
                ans[i].eb(x, (t + 74) / 75);
                t--;
            }
        }
    }
    
    cout << sz(ver) << '\n';
    
    for (int i : ver) {
        cout << i << '\n';
        cout << sz(ans[i]) << '\n';

        vi len;
        vi len2;

        for(int j= 0;j<inEdge[i].size();j++){
            len.pb(e[inEdge[i][j]][2]);
        }
        sort(all(len));
        ll mid1 = len[inEdge[i].size()/2];
        ll mid2 = len[2*inEdge[i].size()/3];
        

        for (auto it : ans[i]) {

            if(e[it.fi][2]<=mid1){
                cout << streetName[it.fi] << ' ' << 3 << '\n';
            }else if(e[it.fi][2]<=mid2){
                cout << streetName[it.fi] << ' ' << 2 << '\n';
            }else{
                cout << streetName[it.fi] << ' ' << 1 << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("e.txt", "r", stdin);
    freopen("maybe-e.txt", "w", stdout);
    
    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}