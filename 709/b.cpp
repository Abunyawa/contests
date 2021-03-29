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

const ll INF = 1e9+7;

void solve() {
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll dif = -1;
    ll m = -1;
    if(n==1){
        cout<<0<<'\n';
        return;
    }

    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            dif = a[i]-a[i-1];
            break;
        }
    }
    if(dif==-1){
        ll chd = -1;
        for(int i=1;i<n;i++){
            ll loc = a[i-1]-a[i];
            if(chd==-1){
                chd=loc;
            }
            if(loc!=chd){
                cout<<-1<<'\n';
                return;
            }
        } 

        cout<<0<<'\n';
        return;
    }
    for(int i=1;i<n;i++){
        if(a[i]>=m && m!=-1){
            cout<<-1<<'\n';
            return;
        }
        if(a[i]>a[i-1]){
            int loc = a[i]-a[i-1];
            if(dif!=loc){
                cout<<-1<<'\n';
                return;
            }
        }else{
            if(m==-1){
                m = (a[i-1]+dif) - a[i];
                
            }else{
                if(((a[i-1]+dif)%m)!=a[i]){
                    cout<<-1<<'\n';
                    return;
                }
            }
        }
    }

    if(m==-1){
        cout<<0<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]>=m){
            cout<<-1<<'\n';
            return;
        }
    }
    

    if(dif>m){
        cout<<-1<<'\n';
        return;
    }
    cout<<m<<' '<<dif<<'\n';
    

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

