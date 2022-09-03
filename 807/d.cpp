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
    string t;
    cin>>t;

    if(s[0]!=t[0] || s[n-1]!=t[n-1]){
        cout<<-1<<'\n';
        return;
    }


    vector<pii> p1;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            int l =i;
            int r = i;
            while(r<n && s[r]=='1'){
                r++;
            }

            p1.pb({l,r-1});

            i = r-1;
        }
    }

    vector<pii> p2;
    for(int i=0;i<n;i++){
        if(t[i]=='1'){
            int l =i;
            int r = i;
            while(r<n && t[r]=='1'){
                r++;
            }

            p2.pb({l,r-1});

            i = r-1;
        }
    }

    if(p1.size()!=p2.size()){
        cout<<-1<<'\n';
        return;
    }
    ll ans =0;
    for(int i=0;i<p1.size();i++){
        ans+=abs(p1[i].fi-p2[i].fi)+abs(p1[i].se-p2[i].se); 
    }

    p1.clear();
    p2.clear();

    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            int l =i;
            int r = i;
            while(r<n && s[r]=='0'){
                r++;
            }

            p1.pb({l,r-1});

            i = r-1;
        }
    }

    for(int i=0;i<n;i++){
        if(t[i]=='0'){
            int l =i;
            int r = i;
            while(r<n && t[r]=='0'){
                r++;
            }

            p2.pb({l,r-1});

            i = r-1;
        }
    }

    ll ans1=0;
    for(int i=0;i<p1.size();i++){
        ans1+=abs(p1[i].fi-p2[i].fi)+abs(p1[i].se-p2[i].se); 
    }
    cout<<min(ans1,ans)<<'\n';
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

