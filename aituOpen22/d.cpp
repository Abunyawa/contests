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
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

void solve() {
    int n;
    cin>>n;
    map<string,int> m;
    vector<pair<pair<string,string>,pii>> arr;

    map<pair<string,string>,string> res;
    for(int i=0;i<n;i++){
        string t1;
        cin>>t1;
        string x;
        cin>>x;

        string t2;
        cin>>t2;
        
        int a,b;
        cin>>a>>x>>b;

        m[t1]++;
        m[t2]++;

        arr.pb({{t1,t2},{a,b}});

    }

    
    vector<pair<int,string>> teams;

    for(auto cur: m){
        teams.pb({cur.se, cur.fi});
    }

    sort(rall(teams));
    teams[0],teams[1];
    string win;


    for(int i=0;i<n;i++){
        if ((arr[i].fi.fi == teams[0].se && arr[i].fi.se == teams[1].se) || (arr[i].fi.fi == teams[1].se && arr[i].fi.se == teams[0].se)){
            if(arr[i].se.fi > arr[i].se.se){
                win = arr[i].fi.fi;
            }else{
                win = arr[i].fi.se;
            }
        }
        
    }

    vector<pair<pii,string>> ans;

    for(int i=0;i<n;i++){
        int g1 = m[arr[i].fi.fi];
        int g2 = m[arr[i].fi.se];
        string dec = arr[i].fi.fi + " - " +  arr[i].fi.se + " " + to_string(arr[i].se.fi) + " : " + to_string(arr[i].se.se);
        ans.pb({{min(g1,g2), i}, dec});
    }

    sort(all(ans));

    int cur = 0;
    for(int i=(n+1)/2;i>0;i/=2){
        if(i!=1){
            cout<<"1/"<<i<<" Finals\n";
        }else{
            cout<<"Final\n";
        }
        for(int j=0;j<i;j++){
            cout<<ans[cur++].se<<'\n';
        }
    }
    
    cout<<"Winner: "<<win<<'\n';
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

