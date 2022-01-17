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
    cout<<"yes"<<'\n';
}

void no(){
    cout<<"no"<<'\n';
}


void solve() {
    ll n,k;
    cin>>n>>k;
    ll fix = sqrt(k);

    if(n==1){
        no();
        return;
    }

    if(k==1){
        no();
        return;
    }
    map<int,int> hs;
    for(int i=2;i<=fix;i++){
        while(k%i==0){
            hs[i] = true;
            k/=i;
        }
    }

    if(k!=1){
        hs[k] = true;
    }

    bool flag = true;
    fix = sqrt(n);
    for(int i=2;i<=fix;i++){
        while(n%i==0){
            if(hs[i]==0){
                flag = false;
            }
            n/=i;
        }
    }

    if(n!=1){
        if(hs[n]==0){
            flag = false;
        }
    }

    if(flag){
        no();
    }else{
        yes();
    }
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

