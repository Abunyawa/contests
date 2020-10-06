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
ll const MOD = 1e8;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

ll fact(int n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans = (ans*i)%MOD;
    }

    return ans;
}

ll powM(int n, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n%MOD;
    }

    if(x%2==0){
        ll a = powM(n,x/2);
        return (a*a)%MOD;
    }else{
        return (n*powM(n,x-1))%MOD;
    }
}

ll C(int n, int k){
    return (fact(n) * powM((fact(k)*fact(n-k))%MOD,MOD-2))%MOD;
}

ll A(int n, int k){
    return (fact(n) * powM(fact(n-k)%MOD,MOD-2))%MOD;
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

bool prime(ll n){
    for(ll i = 2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int prefix[26][1000100];
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s = '#'+s;
    for(int i=1;i<=n;i++){
        for(int j = 0;j<26;j++){
            prefix[j][i] = prefix[j][i-1];
        }
        prefix[s[i]-'a'][i]++;
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int g = 0;
        int isOdd = false;
        int oddctr = 0;
        for(int j = 0;j<26;j++){
            int cur = prefix[j][r] - prefix[j][l-1];
            if(cur%2==0){
                g+=cur;
            }else{
                oddctr++;
                if(!isOdd){
                    g+=cur;
                    isOdd = true;
                }else{
                    g+=cur-1;
                }
            }
        }
        vector<int> let(26,0);
        int nl = l;
        int nr = r;
        int ctrsav = oddctr;
        while((prefix[s[nl]-'a'][r] - prefix[s[nl]-'a'][l-1])%2==1 && nl<r && oddctr>1){
            if(let[s[nl]-'a']==0){
                oddctr--;
                let[s[nl]-'a']=1;
                nl++;
            }else{
                break;
            }
        }
        while((prefix[s[nr]-'a'][r] - prefix[s[nl]-'a'][nl-1])%2==1 && nl<nr && oddctr>1){
            if(let[s[nr]-'a']==0){
                oddctr--;
                let[s[nr]-'a']=1;
                nr--;
            }else{
                break;
            }
        }
        //cout<<nl<<' '<<nr<<'\n';
        double ans = (double)(g*g)/(double)(nr-nl+1);
        int l1 = nl;
        int r1 = nr;
        nl = l;
        nr = r;
        oddctr = ctrsav;
        for(int i=0;i<26;i++){
            let[i] = 0;
        }
        while((prefix[s[nr]-'a'][r] - prefix[s[nl]-'a'][nl-1])%2==1 && nl<nr && oddctr>1){
            if(let[s[nr]-'a']==0){
                oddctr--;
                let[s[nr]-'a']=1;
                nr--;
            }else{
                break;
            }
        }
        while((prefix[s[nl]-'a'][r] - prefix[s[nl]-'a'][l-1])%2==1 && nl<nr && oddctr>1){
            if(let[s[nl]-'a']==0){
                oddctr--;
                let[s[nl]-'a']=1;
                nl++;
            }else{
                break;
            }
        }

        //cout<<nl<<' '<<nr<<'\n';

        if((double)(g*g)/(double)(nr-nl+1)>ans){
            cout<<nl<<' '<<nr<<'\n';
        }else{
            cout<<l1<<' '<<r1<<'\n';            
        }
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

