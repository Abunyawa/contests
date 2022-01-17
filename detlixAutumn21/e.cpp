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
int const INF = 100000000;
int masks[40][40];
vector<string> one, two;
vector<string> m = {"a", "b", "c", "ab", "bc"};


bool contains(string s, string sub) {
    int pos = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (pos < sub.size() && s[i] == sub[pos]) pos++;
    }
    return pos >= sub.size();
}

int count(){
    int ret = 0;

    for(auto f: one){
        for(auto s: two){
            string res = f+s;
            if(contains(res, "abc")) return -1;

            for(int k=0;k<5;k++){
                if(contains(res, m[k])){
                    ret |= (1<<k);
                }
            }
        }
    }

    return ret;
}

struct segtree {
    vector<array<int,40>> tree;
    int size;

    void init(int n){
        size = n;
        array<int,40> loc;
        for(int i=0;i<40;i++){
            loc[i] = INF;
        }
        tree.assign(4*n, loc);
    }

    void merge(int v){
        for(int i=0;i<40;i++) tree[v][i] = INF;

        for(int i = 0;i<32;i++){
            for(int j = 0; j<32;j++){
                int nw = masks[i][j];
                if(nw==-1)continue;

                tree[v][nw] = min(tree[v][nw], tree[2*v][i]+tree[2*v+1][j]);
            }
        }
    }
    void build(vi &a,int x, int lx, int rx){
        if(rx-lx == 0){
            //cout<<lx-1<<endl;
            tree[x][(1<<a[lx-1])] = 0;
            tree[x][0] = 1;
            
        }else{
            int m = (lx+rx)/2;
            build(a,2*x,lx,m);
            build(a,2*x+1,m+1,rx);
            merge(x);
            
        }
    }

    void build(vi &a){
        init(a.size());
        build(a,1,1,a.size());
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==0){
            for(int i=0;i<33;i++) tree[x][i] = INF;
            tree[x][(1<<v)] = 0;
            tree[x][0] = 1;
            return;
        }
        int m = (lx+rx)/2;
        if(i<=m){
            set(i,v,2*x,lx,m);
        }else{
            set(i,v,2*x+1,m+1,rx);
        }
        merge(x);
    }

    void set(int i, int v){
        set(i,v,1,1,size);
    }
   
    ll sum (){
        int mn = INF;
        for(int i=0;i<32;i++){
            mn = min(mn, tree[1][i]);
        }
        return mn;
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vi a;
    for(int i=0;i<n;i++){
        a.pb(s[i]-'a');
    }

    segtree st;
    st.build(a);
    /*
    for(int i=0;i<32;i++){
        cout<<st.tree[0][i]<<' ';
    }

    cout<<'\n';
    */
    for(int i=0;i<q;i++){
        int pos;
        char x;
        cin>>pos>>x;
        st.set(pos, x-'a');

        cout<<st.sum()<<'\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
            for(int k = 0; k<5;k++){
                if(i&(1<<k)) one.pb(m[k]);
                if(j&(1<<k)) two.pb(m[k]);
            }
            one.pb("");
            two.pb("");
            masks[i][j] = count();
            one.clear();
            two.clear();
        }
    }

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

