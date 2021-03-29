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

struct segtree {

    vl tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size-1,0);
    }
    void build(vi &a,int x, int lx, int rx){
        if(rx-lx == 1){
            if(lx<a.size())
                tree[x] = a[lx];
        }else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            tree[x] = max(tree[2*x+1],tree[2*x+2]);
        }
    }

    void build(vi &a){
        init(a.size());
        build(a,0,0,size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            tree[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }

    void set(int i, int v){
        set(i,v,0,0,size);
    }

    ll sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return -10000000;
        }
        if(lx>=l && rx<=r){
            return tree[x];
        }
        int m = (rx+lx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        return max(s1,s2);
    }

    ll sum (int l,int r){
        return sum(l,r,0,0,size);
    }

};

void solve() {
    int n;
    cin>>n;
    vector<array<int, 3>> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
        a[i][2] = i;
    }

    sort(all(a));
    vi f(n);
    for(int i=0;i<n;i++){
        f[i] = i;
    }

    segtree st;
    st.build(f);

    
    for(int i=n-2;i>=0;i--){
        int target = a[i][0]+a[i][1]-1;
        int l = i;
        int r = n-1;
        int ans = i;
        while(l<=r){
            int mid = (l+r)/2;
            if(a[mid][0]>target){
                r = mid-1;
            }else{
                ans = mid;
                l = mid+1;
            }
        }
        //cout<<i<<' '<<ans<<' '<<target<<'\n';
        st.set(i,st.sum(i,ans+1));
    }

    vi ans(n);
    for(int i=0;i<n;i++){
        ans[a[i][2]] = st.sum(i,i+1)-i+1;
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
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

