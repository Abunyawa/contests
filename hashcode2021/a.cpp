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

map<string, int> mapping;
int D, n, m, cars, bonusPts;
array<int, 4> e[MAXM];
vi inEdge[MAXN], outEdge[MAXN];
string streetName[MAXM];
vi carRoute[MAXC];
bool used[MAXM];

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
    if(e[a][3]!=e[b][3]){
        return e[a][3]> e[b][3];
    }else{
        return e[a][2]<e[b][2];
    }
}


void solve() {
    cin >> D >> n >> m >> cars >> bonusPts;
    
    rep (i, 0, m) {
        int u, v, w;
        string sname;
        cin >> u >> v >> sname >> w;
        e[i] = {u, v, w, 0};
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
            used[x] = i;
            e[x][3]++;
        }
    }
    
    vi ver;
    
    rep (i, 0, n) {
        inEdge[i] = filterEdges(inEdge[i]);
        
        if (!inEdge[i].empty()) {
            ver.pb(i);
        }
    }
    
    cout << sz(ver) << '\n';
    
    for (int i : ver) {
        cout << i << '\n';
        
        vi len;
        vi len2;

        for(int j= 0;j<inEdge[i].size();j++){
            len.pb(e[inEdge[i][j]][3]);
            len2.pb(e[inEdge[i][j]][2]);
        }
        sort(all(len));
        sort(all(len2));
        ll mid1 = len[inEdge[i].size()/2];
        ll mid2 = len[2*inEdge[i].size()/3];
        ll mid3 = len[3*inEdge[i].size()/4];
        ll mid4 = len[4*inEdge[i].size()/5];
        ll mid5 = len[5*inEdge[i].size()/6];
        ll mid6 = len[6*inEdge[i].size()/7];
        ll mid7 = len[7*inEdge[i].size()/8];
        ll mid8 = len[8*inEdge[i].size()/9];
        ll mid9 = len[9*inEdge[i].size()/10];
        ll mid10 = len[10*inEdge[i].size()/11];
        ll mid11 = len[11*inEdge[i].size()/12];
        ll mid12 = len[12*inEdge[i].size()/13];
        ll mid13 = len[13*inEdge[i].size()/14];



        sort(all(inEdge[i]),cmp);
        //random_shuffle(all(inEdge[i]));
        cout << sz(inEdge[i]) << '\n';
        int ctr = 0;
        bool flag = false;
        for (int id : inEdge[i]) {
            ll loc = 1;
            cout << streetName[id] << ' ' << 1 << '\n';
            flag = true;
            
        
            /*
            if(e[id][3]<=mid1){
                cout << streetName[id] << ' ' << 1 << '\n';
            }else if(e[id][3]<=mid2){                
                cout << streetName[id] << ' ' << 2 << '\n';                
            }else if(e[id][3]<=mid3){                
                cout << streetName[id] << ' ' << 3 << '\n';
            }else if(e[id][3]<=mid4){                
                cout << streetName[id] << ' ' << 4 << '\n';
            }else if(e[id][3]<=mid5){                
                cout << streetName[id] << ' ' << 5 << '\n';
            }else if(e[id][3]<=mid6){                
                cout << streetName[id] << ' ' << 6 << '\n';
            }else if(e[id][3]<=mid7){                
                cout << streetName[id] << ' ' << 7 << '\n';
            }else if(e[id][3]<=mid8){                
                cout << streetName[id] << ' ' << 8 << '\n';
            }else if(e[id][3]<=mid9){                
                cout << streetName[id] << ' ' << 9 << '\n';
            }else if(e[id][3]<=mid10){                
                cout << streetName[id] << ' ' << 10 << '\n';
            }else if(e[id][3]<=mid11){                
                cout << streetName[id] << ' ' << 11 << '\n';
            }else if(e[id][3]<=mid12){                
                cout << streetName[id] << ' ' << 12 << '\n';
            }else if(e[id][3]<=mid13){                
                cout << streetName[id] << ' ' << 13 << '\n';
            }else{
                cout << streetName[id] << ' ' << 14 << '\n';
            }
            */
        }
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
