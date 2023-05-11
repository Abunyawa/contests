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
    int n;
    cin>>n;
    vl a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n-1;i++){
        if(i+2<n){
            ll dif = a[i]-a[i+1];

            a[i+1]+=dif;
            a[i+2] += dif; 
        }
    }
    int unsrt = false;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            
            unsrt++;
        }
    }

    if(unsrt == 0){
        yes();
    }else{
        if(unsrt==1){
            if(a[n-2]>a[n-1]){
                if((n-1)%2==0){
                    yes();
                }else{
                    no();
                }
            }
        }else{
            no
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

