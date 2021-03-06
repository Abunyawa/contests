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
    cin>>n;
    vi a(n);
    vector<bool> m(1025,0);
    int ans;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            ans = a[i];
        }else ans^=a[i];
        m[a[i]] = true; 
    }
    for(int k=1;k<=1024;k++){
        int locans = 0;
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(m[a[i]^k])
                locans^= (a[i]^k);
            else{
                flag = false;
                break;

            }
        }
        if(!flag) continue; 
        if(locans == ans){
            cout<<k<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';

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
