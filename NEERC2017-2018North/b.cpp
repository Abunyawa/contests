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
#define watch(x) (#x)<<" : "<<(x)<<" ";
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;
ll const MOD = 998244353;

void yes() {
    cout<<"YES"<<'\n';
}

void no() {
    cout<<"NO"<<'\n';
}


ll powM(int n, int x) {
    if(x==0) {
        return 1;
    }
    if(x==1) {
        return n%MOD;
    }

    if(x%2==0) {
        ll a = powM(n,x/2);
        return (a*a)%MOD;
    } else {
        return (n*powM(n,x-1))%MOD;
    }
}

double fact[100010];

ll C(int n, int k) {
    return fact[n] /(fact[k]*fact[n-k]);
}


void add_self(int &a, int b) {
    a += b;
    if(a>=MOD) {
        a-=MOD;
    }
}

void sub_self(int &a, int b) {
    a -= b;
    if(a<0) {
        a+=MOD;
    }
}


struct segtree {

    vl tree;
    int size;

    void init(int n) {
        size = 1;
        while(size < n) size*=2;
        tree.assign(2*size-1,0);
    }
    void build(vi &a,int x, int lx, int rx) {
        if(rx-lx == 1) {
            if(lx<a.size())
                tree[x] = a[lx];
        } else {
            int m = (lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            tree[x] = tree[2*x+1]+tree[2*x+2];
        }
    }

    void build(vi &a) {
        init(a.size());
        build(a,0,0,size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if(rx-lx==1) {
            tree[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m) {
            set(i,v,2*x+1,lx,m);
        } else {
            set(i,v,2*x+2,m,rx);
        }
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }

    void set(int i, int v) {
        set(i,v,0,0,size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        if(l>=rx || lx>=r) {
            return 0;
        }
        if(lx>=l && rx<=r) {
            return tree[x];
        }
        int m = (rx+lx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }

    ll sum (int l,int r) {
        return sum(l,r,0,0,size);
    }

};
map<char,int> pos;
map<char,int> neg;


void solve() {

    string s;
    cin>>s;
    vector<char> st;
    bool flag = true;
    for(int i =0; i<s.length(); i++) {
        if(s[i]!='|' && s[i]!='~') {
            if(flag) {
                pos[s[i]]++;
                if(pos[s[i]]+neg[s[i]]==1) {
                    st.pb(s[i]);
                }

            } else {
                neg[s[i]]++;
                flag = true;
                if(pos[s[i]]+neg[s[i]]==1) {
                    st.pb(s[i]);
                }
            }

        } else {
            if(s[i]=='~') {
                flag = false;
            }
        }

    }

    for(int i=0; i<st.size(); i++) {
        if(pos[st[i]]>0 && neg[st[i]]>0) {
            cout<<(1LL<<st.size())<<'\n';
            return;
        }
    }

    cout<<(1LL<<st.size())-1<<'\n';

}
/*
2 2

*/
int main() {

    freopen("boolean.in", "r", stdin);
    freopen("boolean.out", "w", stdout);

    abu;
    said;

    int t = 1;
    //cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}
