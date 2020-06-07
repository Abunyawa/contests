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


void solve(){
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<'\n';
        return;
    }
    vector<int> bina;
    int f1 = -1;

    int l1 = -1;
    int p =0;
    while(a!=0){
        bina.pb(a%2);
        if(a%2==1){
            l1=p;
        }
        if(a%2==1 && f1 == -1){
            f1 = p;
        }
        p++;
        a/=2;
    }
    vector<int> binb;
    p=0;
    int l1b=-1;
    int f1b=-1;
    while(b!=0){
        binb.pb(b%2);
        if(b%2==1){
            l1b=p;
        }
        if(b%2==1 && f1b == -1){
            f1b = p;
        }
        p++;
        b/=2;
    }
    if(f1==-1 || f1b==-1){
        cout<<-1<<'\n';
        return;
    }
    while(f1<=l1 && f1b<=l1b && bina[f1]==binb[f1b]){
        f1++;
        f1b++;
    }
    if(f1b==l1b+1 && f1 == l1+1){
        int num = abs(l1b-l1);
        
        cout<<num/3 + num%3/2 + num%3%2<<'\n';
    }else{
        cout<<-1<<'\n';
    }
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
