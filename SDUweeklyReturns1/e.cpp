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
    int n,m;
    cin>>n>>m;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<pii> st;
    for(int i=0;i<m;i++){
        int t,r;
        cin>>t>>r;

        if(st.empty()){
            st.push({t,r});
        }else{
            while(!st.empty() && r>st.top().se){
                st.pop();
            }

            st.push({t,r});
        }
    }
    vector<pii> good;
    while(!st.empty()){
        good.pb(st.top());
        st.pop();
    }

    reverse(all(good));

    int maxPref = good[0].se;
    sort(a.begin(),a.begin()+maxPref);
    vl sorted;
    for(int i=0;i<maxPref;i++){
        sorted.pb(a[i]);
    }
    good.pb({0,0});
    int ptr1 = 0;
    int ptr2 = maxPref-1;
    for(int i=0;i<good.size()-1;i++){
        int t = good[i].fi;
        int r = good[i].se;
        int to = good[i+1].se;
        /*
        debug(t);
        debug(r);
        debug(to);*/
        if(t==1){
            for(int j = r-1;j>=to;j--){
                a[j] = sorted[ptr2--];
            }
        }else{
            for(int j = r-1;j>=to;j--){
                a[j] = sorted[ptr1++];
            }
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

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

