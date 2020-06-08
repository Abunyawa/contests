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

int bin[510][65];
bool use[510];
int mb[510];

void solve(){
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    ll totA = 0;
    if(n==1){
        cout<<a[0]<<endl;
        return;
    }else if(n==2){
        int ans = a[0]|a[1];
        cout<<ans<<'\n';    
        return;    
    }else if(n>=3){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k = 0;k<n;k++){
                    ll ans = 0;
                    if(k!=i && k!=j && i!=j){
                        ans = a[i]|a[j]|a[k];
                        if(ans>totA){
                            totA = ans;
                        }
                    }

                }
            }
        }
    }
    cout<<totA<<'\n';

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
