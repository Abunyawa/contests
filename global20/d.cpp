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
    vl b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> ctr(n+1,0);
    int ptr = n-1;

    for(int i=n-1;i>=0;i--){
        if(ptr>=0){
            if(a[i]==b[ptr]){
                ptr--;
                while(ptr>=0 && a[i]==b[ptr]){
                    ctr[a[i]]++;
                    ptr--;
                }
            }else{
                if(ctr[a[i]]>0){
                    ctr[a[i]]--;
                }else{
                    no();
                    return;
                }
            }
            
        }else{
            if(ctr[a[i]]>0){
                ctr[a[i]]--;
            }else{
                no();
                return;
            }
        }
    }

    yes();
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

