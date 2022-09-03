// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}

void solve() {
    ll n,m;
    int k;
    cin>>n>>m>>k;

    vl a(k);

    for(int i=0;i<k;i++){
        cin>>a[i];
    }

    vector<pair<ll,int>> good;
    for(int i=0;i<k;i++){
        

        if(a[i]>=2*n){
            good.pb({a[i], i});
        }
    }
    
    ll need = n*m - good.size()*2*n;
    int p = 0;
    for(int i=0;i<=good.size();i++){
        if(n*m>=i*2*n){
            need = n*m - i*2*n;
            p = i;
        }
    }
    sort(rall(good));
    for(int i=0;i<p;i++){
        ll have = (a[good[i].second]-2*n)/n*n;

        if(need>have){
            need-=have;
        }else{
            need = 0;
            break;
        }
    }

    if(need == 0){
        yes();
        return;
    }

    good.clear();
    for(int i =0;i<k;i++){
        

        if(a[i]>=2*m){
            good.pb({a[i], i});
        }
    }

    p = 0;
    for(int i=0;i<=good.size();i++){
        if(n*m>=i*2*m){
            need = n*m - i*2*m;
            p = i;
        }
    }

    sort(rall(good));
    for(int i=0;i<p;i++){
        ll have = (a[good[i].second]-2*m)/m*m;

        if(need>have){
            need-=have;
        }else{
            need = 0;
            break;
        }
    }

    if(need == 0){
        yes();
        return;
    }


    no();
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

