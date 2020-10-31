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
ll const MOD = 1000003;

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



void solve(){
    int n;
    cin>>n;
    vl a(n+1);
    vl pref(n+1);
    pref[0] = 1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i] = a[i]%MOD;
        pref[i] = (pref[i-1]*a[i])%MOD;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==0){
            int l,r;
            cin>>l>>r;
            for(int k = l;k<=r;k++){
                a[k]++;
                a[k] = a[k]%MOD;
            }
            pref[0] =1;
            for(int j=1;j<=n;j++){
                pref[j] = (pref[j-1]*a[j]%MOD)%MOD;
            }
        }else{
            int l,r;
            cin>>l>>r;
            cout<<((pref[r]+MOD) * powM((pref[l-1]+MOD),MOD-2))%MOD<<'\n';
        }
    }

}

int main(){
    /*
    freopen("army.in", "r", stdin);
    freopen("army.out", "w", stdout);
    */
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
