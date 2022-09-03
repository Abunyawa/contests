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
    string s;
    cin>>s;

    int ctr = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') ctr++;
    }

    if(ctr<1){
        no();
        return;
    }


    vector<pii> c;
    ctr = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            int st = i;
            int cur = st+1;
            while(s[cur%n]!='1'){
                cur++;
            }

            c.pb({st,(cur-1)%n});
            if(st==(cur-1)%n){
                ctr++;
            }
        }
    }

    if(ctr%2!=(c.size()-ctr)%2){
        no();
        return;
    }
    yes();
    int ind = -1;
    for(int i=0;i<c.size();i++){
        if(c[i].fi!=c[i].se){
            ind = i;
        }else{
            continue;
        }
        for(int j = c[i].first; j%n!=c[i].second;j++){
            cout<<(j+1)%n+1<<' '<<j%n+1<<'\n';
        }
        
    }

    if(ind==-1){
        for(int i = 1;i<c.size();i++){
            cout<<c[i].fi+1<<' '<<c[0].fi+1<<'\n';
        }
    }else{
        for(int i = 0;i<c.size();i++){
            if(i==ind) continue;
            cout<<c[i].se+1<<' '<<c[ind].se+1<<'\n';
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

