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

int sqrs[1000];

void solve() {
    int n;
    cin>>n;

    vi a(n,-1);


    int ptr = 0;

    while(sqrs[ptr]<n-1){
        ptr++;
    }
    
    int cur = n-1;
    for(int i=ptr;i>=0;i--){ 
        while(i>=0 && sqrs[i]-cur>cur){
            i--;
        }
        if(i<0){
            cout<<-1<<'\n';
            return;
        }

        int st = sqrs[i]-cur;

        for(int j = st;j<=cur;j++){
            a[j] = sqrs[i]-j;
        }

        cur = st-1;

        if(st==0){
            break;
        }
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<1000;i++){
        sqrs[i] = i*i;
    }
    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

