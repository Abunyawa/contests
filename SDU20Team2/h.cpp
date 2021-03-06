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

int prefLet[26][5010];

void solve(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    int n = s.length();
    s = '0'+s;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<26;j++){
            prefLet[j][i] = prefLet[j][i-1];
        }
        prefLet[s[i]-'a'][i]++;
    }
    int l=1;
    int r = 1;
    for(int i=1;i<=n;i++){
        for(int j = i;j<=n;j++){
            int even = 0;
            int odd = 0;
            for(int let = 0;let<26;let++){
                if((prefLet[let][j]-prefLet[let][i-1])%2==0){
                    even++;
                }else{
                    odd++;
                }
            }
            if(odd-1<=k){
                if(j-i+1>r-l+1){
                    r = j;
                    l = i;
                }
            }

        }
    }
    cout<<l<<" "<<r<<'\n';

}

int main(){
    /*
    freopen("message.in", "r", stdin);
    freopen("message.out", "w", stdout);
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
