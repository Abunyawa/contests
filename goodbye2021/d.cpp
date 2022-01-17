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
    vector<bool> took(n,false);

    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    ll x;
    cin>>x;


    for(int i=0;i<n;i++){
        if(a[i]>=x){
            took[i] = true;
        }

        a[i]-=x;
    }

    vector<array<ll,3>> bl;
    ll last = 0;

    for(int i=0;i<n;i++){
        if(a[i]<0){
            int l = max(0,i-1);
            int r = min(n-1,i+1);

            if(a[l]>0 && a[r]>0){
                if(a[l]+a[i]>=0 && a[r]+a[i]>=0){
                    took[i] = true;
                    a[l] += a[i];
                    a[r] += a[i];
                }
            }else if(a[l]>0 && a[r]<0){
                if(a[l]+a[i]>=0){
                    took[i] = true;
                    a[l] += a[i];
                }
            }else if(a[r]>0 && a[l]<0){
                if(a[r]+a[i]>=0){
                    took[i] = true;
                    a[r] += a[i];
                }
            }

            if(took[i]){
                a[i] = 0;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        if(took[i]) ans++;
    }

    cout<<max(ans,max(n/2,(n+1)/2))<<'\n';
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

