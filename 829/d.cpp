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

ll ctr[500100];

void solve() {
    int n, x;
    cin>>n>>x;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ctr[a]++;
    }


    for(int i=1;i<500100;i++){
        if(ctr[i]>i){
            ctr[i+1]+=ctr[i]/(i+1);
            ctr[i]=ctr[i]%(i+1);
        }

        //cout<<ctr[i]<<'\n';
    }

    
    for(int j=x-1;j>0;j--){
        if(ctr[j]>0){
            //cout<<j<<'\n';
            no();
            return;
        }
    }
    yes();
    return;

    no();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

