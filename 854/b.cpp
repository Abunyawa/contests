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
    vector<ll> a(n);
    
    set<ll> st;
    bool bad = false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            bad = true;
        }
        st.insert(a[i]);
    }

    if(n==1){
        cout<<0<<'\n';
        return;
    }

    if(st.size()==1){
        cout<<0<<'\n';
        return;
    }

    if(bad){
        cout<<-1<<'\n';
        return;
    }
    
    vector<pii> ans;
    int pos1=-1,pos2=-1;
    ll mn = 1e9;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll x = a[i];
            ll y = a[j];

            while(x!=y){
                if(x>y){
                    x=(x+y-1)/y;
                }else{
                    y=(y+x-1)/x;
                }
            }

            if(x<mn){
                pos1=i;pos2=j;mn=x;
            }
        }
    }
    

    ll x = a[pos1];
    ll y = a[pos2];

    while(x!=y){
        if(x>y){
            ans.pb({pos1,pos2});
            x=(x+y-1)/y;
        }else{
            ans.pb({pos2,pos1});
            y=(y+x-1)/x;
        }
    }
    a[pos1] = x;
    a[pos2] = y;


    for(int i=0;i<n;i++){
        if(i==pos1 ||i==pos2) continue;

        while(a[i]!=a[pos1]){
            ans.pb({i,pos1});
            a[i] = (a[i]+a[pos1]-1)/a[pos1];
        }
    }

    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].fi+1<<' '<<ans[i].se+1<<'\n';
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

