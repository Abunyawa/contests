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

    string a,b;
    cin>>a>>b;

    int eq = 0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) eq++;
    }

    if(eq!=n && eq!=0){
        no();
        return;
    }
    vector<pii> ans;
    

    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            ans.pb({i+1,i+1});
        }  
    }

    if(ans.size()%2==0){
        if(eq==n){
            yes();
            cout<<ans.size()<<'\n';
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
            }
        }else{
            ans.pb({1,n});
            ans.pb({1,1});
            ans.pb({2,n});
            yes();
            cout<<ans.size()<<'\n';
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
            }
        }
    }else{
        if(eq==0){
            yes();
            cout<<ans.size()<<'\n';
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
            }
        }else{
            ans.pb({1,n});
            ans.pb({1,1});
            ans.pb({2,n});
            yes();
            cout<<ans.size()<<'\n';
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
            }
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

