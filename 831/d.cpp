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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vi a(k);

    vi ptr(k+1);

    for(int i=0;i<k;i++){
        cin>>a[i];

        ptr[a[i]] = i+1;
    }


    int free = n*m-4;
    int last = 0;
    for(int i=k;i>0;i--){
        int cur = ptr[i];

        if(cur>last){
            if(free>=(cur-last-1)){
                free-=(cur-last-1);
                last = cur;
            }else{
                cout<<"TIDAK\n";
                return;
            }
        }else{
            free++;
        }
    }


    cout<<"YA\n";
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

