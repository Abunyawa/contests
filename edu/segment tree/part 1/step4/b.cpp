#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;
ll const MOD = 998244353;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
int R;
struct mat{
    int a,b,c,d;
};

mat mult(mat a, mat b){
    return {a.a*b.a%R+a.b*b.c%R, a.a*b.b%R+a.b*b.d%R, a.c*b.a%R+a.d*b.c%R, a.c*b.b%R+a.d*b.d%R};
}

struct segtree {

    vector<mat> tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size-1,{1,0,0,1});
    }
    void build(vector<mat> &a,int x, int lx, int rx){
        if(rx-lx == 1){
            if(lx<a.size())
                tree[x] = a[lx];
        }else{
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            tree[x] = mult(tree[2*x+1],tree[2*x+2]);
        }
    }

    void build(vector<mat> &a){
        init(a.size());
        build(a,0,0,size);
    }

    
    mat sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return {1,0,0,1};
        }
        if(lx>=l && rx<=r){
            return tree[x];
        }
        int m = (rx+lx)/2;
        mat s1 = sum(l,r,2*x+1,lx,m);
        mat s2 = sum(l,r,2*x+2,m,rx);
        return mult(s1,s2);
    }

    mat sum (int l,int r){
        return sum(l,r,0,0,size);
    }

};

/*
1 2 3 4 5
1 1 1 1 1
*/

void solve(){
    int n,m;
    cin>>R>>n>>m;
    vector<mat> a;

    for(int i=0;i<n;i++){
        mat x;
        cin>>x.a>>x.b>>x.c>>x.d;
        a.pb(x);
    }
    segtree st;
    st.build(a);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        l--;
        mat ans = st.sum(l,r);
        cout<<ans.a%R<<' '<<ans.b%R<<'\n';
        cout<<ans.c%R<<' '<<ans.d%R<<'\n'<<'\n';

    }
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
