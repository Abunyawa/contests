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



void solve() {
    ll n;
    cin>>n;

    ll carry = n-1;
    vl a(1000000,0);
    if(carry==0){
        cout<<3<<'\n';
        return;
    }else if(carry==1){
        cout<<5<<'\n';
        return;
    }else if(carry==2){
        cout<<7<<'\n';
        return;
    }
    a[2] = carry/3LL*2LL;
    carry-=a[2];

    int ptr = 2;

    for(int i=3;;i++){
        if(carry<3){

            if(carry==1){
                cout<<(i*i)-1LL<<'\n';
                return;
            }else if(carry==2){
                a[i] = 1;
                ll mn = (i+1LL)*(i+1LL)-1LL;
                a[2]++;
                for(int j=2;j<=i;j++){
                    ll cur = (j*j)-1LL + (j-1LL)*2LL*(a[j]);

                    mn = min(mn,cur);
                }

                cout<<mn<<'\n';
                return;
            }
        }

        a[i+1] = a[i]/3LL*2LL;
        a[i] = carry/3LL*2LL;
        carry -= a[i];
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

