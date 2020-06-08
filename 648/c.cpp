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
/*
1 2 3 4 5
0 0 0 0 0

2 3 4 5 1
1 1 1 1 -4
 

5 4 3 2 1
4 2 0 3 1

1 2 3 4 5
0 0 0 0 0


1 3 2 4
0 1 3 0

4 2 3 1
3 0 0 1

1 2
0 0

2 1
1 1 
*/


void solve(){
    int n;
    cin>>n;
    map<int,int> ctr1;
    int mx = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ctr1[x] = i;
    }
    map<int,int> ctr2;
    int mx2 = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int ch = ctr1[x] - i;
        if(ch<0) ch+=n;
        ctr2[ch]++;
        if(ctr2[ch]>mx2){
            mx2 = ctr2[ch];
        }
    }
    
    cout<<mx2<<'\n';
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
