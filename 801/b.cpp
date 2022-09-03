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
    bool flag = false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0){
            if(a[i]!=a[i-1]){
                flag = true;
            }
        }
    }


    
    if(n%2==0){
        if(!flag){
            cout<<"Joe\n";
            return;
        }

        ll m = 1e10;
        int ind = 0;
        for(int i=0;i<n;i++){
            if(a[i]<m){
                m = a[i];
                ind = i;
            }
        }



        if(ind%2==0){
            cout<<"Joe\n";
        }else{
            cout<<"Mike\n";
        }
        
    }else{
        cout<<"Mike\n";
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

