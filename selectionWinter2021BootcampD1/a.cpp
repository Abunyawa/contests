// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}


int f[1000100];

void fill(int i, int j, int k){
    int num = i*j*k;
    for(int del = 1;del<=sqrt(num);del++){
        if(num%del==0){
            if(del==num/del){
                f[num]++;
            }else{
                f[num]+=2;
            }
        }
    }
}

void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    ll mod = (1<<30);
    ll ans = 0;

    
    for(int i=1;i<=a;i++){
        for(int j = 1;j<=b;j++){
            for(int k = 1;k<=c;k++){
                if(f[i*j*k]==0){
                    fill(i,j,k);
                }
                ans+=f[i*j*k];
            }
        }
    }
    cout<<ans%mod<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

