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
    int n;
    int x;

    cin>>n>>x;
    int odd= 0 ;
    int even = 0;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            even++;
        }else{
            odd++;
        }
    }

    bool is = false;
    if(odd==0){
        no();
        return;
    }
    odd--;
    x--;
    if(x<=even){
        yes();
    }else{
        if((x-even)%2==0){
            yes();
            return;
        }else if(x%2==0){
            if(x-min(x,odd/2*2)<=even){
                yes();
                return;
            }else{
                no();
            }
        }else if(x%2==1){
            if(x-min(x-1,odd/2*2)<=even){
                yes();
                return;
            }else{
                no();
            }
        }else{
            no();
            return;
        }
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
