// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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



struct segtreeMN {

    vl tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size-1,0);
    }
    void build(vl &a,int x, int lx, int rx){
        if(rx-lx == 1){
            if(lx<a.size())
                tree[x] = a[lx];
        }else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            tree[x] = min(tree[2*x+1],tree[2*x+2]);
        }
    }

    void build(vl &a){
        init(a.size());
        build(a,0,0,size);
    }


    ll sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return 999999999999;
        }
        if(lx>=l && rx<=r){
            return tree[x];
        }
        int m = (rx+lx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        return min(s1,s2);
    }

    ll sum (int l,int r){
        return sum(l,r,0,0,size);
    }

};
struct segtreeMX {

    vl tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size-1,0);
    }
    void build(vl &a,int x, int lx, int rx){
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

    void build(vl &a){
        init(a.size());
        build(a,0,0,size);
    }

    

    ll sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return -999999999999;
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
    vl a(n);
    map<ll,vi> m;
    vl ks;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]].pb(i);
        if(m[a[i]].size()==1){
            ks.pb(a[i]);
        }
    }
    segtreeMN t2;
    segtreeMX t1;
    t2.build(a);
    t1.build(a);
    sort(rall(ks));
    for(auto x: ks){
        if(m[x].size()>=3){
            for(int i=1;i<m[x].size()-1;i++){
                int left;
                int right;
                int l = m[x][0];
                int r = m[x][i]-1;
                if(t1.sum(0,l+1)!=x) continue;
                while(l<r){
                    int mid = (l+r)/2;
                    if(t1.sum(0,mid+1)==x){
                        if(l == mid) break;
                        l = mid;
                    }else{
                        r = mid-1;
                    }
                }
                if(t1.sum(0,r+1)==x){
                    left = r;
                }else{
                    left = l;
                }

                l = m[x][i]+1;
                r = m[x][m[x].size()-1];
                if(t1.sum(r,n)!=x) continue;
                while(l<r){
                    int mid = (l+r)/2;
                    if(t1.sum(mid,n)==x){
                        if(r==mid) break;
                        r = mid;
                    }else{
                        l = mid+1;
                    }
                }
                if(t1.sum(l,n)==x){
                    right=l;
                }else{
                    right = r;
                }
                if(t2.sum(left+1,right)==x){
                    int x1 = left+1;
                    int y = right-left-1;
                    int z = n-right;
                    yes();
                    cout<<x1<<' '<<y<<' '<<z<<'\n';
                    return;
                }

            }
        }
    }

    no();

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

