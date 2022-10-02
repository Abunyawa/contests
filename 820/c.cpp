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
    string s;
    cin>>s;
    int n = s.length();
    vector<vi> a(26, vi());

    for(int i=0;i<n;i++){
        a[s[i]-'a'].pb(i);
    }


    if(s[0]>s[n-1]){
        int df = s[0]-s[n-1];
        vi ans;

        for(int i = s[0]-'a'; i>=s[n-1]-'a';i--){
            for(int j =0;j<a[i].size();j++){
                ans.pb(a[i][j]);
            }
        }

        cout<<df<<' '<<ans.size()<<'\n';

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]+1<<' ';
        }

        cout<<'\n';
    }else{
        int df = abs(s[0]-s[n-1]);
        vi ans;

        for(int i = s[0]-'a'; i<=s[n-1]-'a';i++){
            for(int j =0;j<a[i].size();j++){
                ans.pb(a[i][j]);
            }
        }

        cout<<df<<' '<<ans.size()<<'\n';

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]+1<<' ';
        }

        cout<<'\n';
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

