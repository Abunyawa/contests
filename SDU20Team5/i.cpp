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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

double fact(double n){
    double ans = 1;
    for(double i=2;i<=n;i++){
        ans = (ans*i);
    }

    return ans;
}


double C(double n, double k){
    return fact(n) /(fact(k)*fact(n-k));
}



void add_self(int &a, int b){
    a += b;
    if(a>=MOD){
        a-=MOD;
    }
}

void sub_self(int &a, int b){
    a -= b;
    if(a<0){
        a+=MOD;
    }
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
            tree[x] = tree[2*x+1]+tree[2*x+2];
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
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }

    void set(int i, int v){
        set(i,v,0,0,size);
    }

    ll sum(int l, int r, int x, int lx, int rx){
        if(l>=rx || lx>=r){
            return 0;
        }
        if(lx>=l && rx<=r){
            return tree[x];
        }
        int m = (rx+lx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx);
        return s1+s2;
    }

    ll sum (int l,int r){
        return sum(l,r,0,0,size);
    }

};
bool used[26];
vector<char> let;
vi a;
bool was[10];
string s;
vector<string> ansG;
int m[26];


void ok(){
    ll nums[3];
    ll ptr = 0;
    ll cur = 0;
    string ans = "";
    for(int i=0;i<s.length();i++){
        if(s[i]=='+' || s[i]=='=' ){
            nums[ptr++] = cur;
            cur = 0;
        }else{
            cur*=10;
            cur+=m[s[i]-'A'];
        }
    }
    nums[ptr++] = cur;
    if(nums[0]+nums[1]==nums[2]){
        for(int i=0;i<s.length();i++){
            if(s[i]=='+' || s[i]=='=' ){
                ans+=s[i];
            }else{
                ans+=(char)(m[s[i]-'A']+'0');
            }
        }
        ansG.pb(ans);
    }
}


void dfs(int v){
    if(v==let.size()){

        ok();
        return;
    }

    for(int i=0;i<=9;i++){
        if(!was[i]){
            m[let[v]-'A'] = i;
            was[i] = true;
            dfs(v+1);
            was[i] = false;
        }
    }
}


void solve(){
    cin>>s;
    
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
            if(!used[s[i]-'A']){
                let.pb(s[i]);
                used[s[i]-'A'] = true;
            }
        }
    }


    a.resize(let.size());
    dfs(0);
    printf("%d\n",ansG.size());
    for(int i =0;i<ansG.size();i++){
        puts(ansG[i].c_str());
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}