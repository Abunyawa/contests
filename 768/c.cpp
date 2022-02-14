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
    int n,k;
    cin>>n>>k;
    vector<pii> a(n/2);
    for(int i=0;i<n/2;i++){
        a[i] = {i, i+n/2};
    }

    if(k==n-1){
        if(n/2==2){
            cout<<-1<<'\n';
            return;
        }
        cout<<a[0].fi<<' '<<a[0].se<<'\n';
        cout<<a[n/2-1].fi<<' '<<a[n/2-1].se<<'\n';
        cout<<a[1].fi<<' '<<a[n/2-2].fi<<'\n';
        cout<<a[1].se<<' '<<a[n/2-2].se<<'\n';

        for(int i=2;i<n/2-2;i++){
            cout<<a[i].fi<<' '<<a[n/2-1-i].se<<'\n';
        }
    }else if(k==n-2){
        if(n/2==2){
            cout<<0<<' '<<1<<'\n';
            cout<<2<<' '<<3<<'\n';
            return;
        }
        cout<<a[0].fi<<' '<<a[0].se<<'\n';
        cout<<a[n/2-1].fi<<' '<<a[n/2-1].se<<'\n';
        cout<<a[1].fi<<' '<<a[1].se<<'\n';
        cout<<a[n/2-2].fi<<' '<<a[n/2-2].se<<'\n';

        for(int i=2;i<n/2-2;i++){
            cout<<a[i].fi<<' '<<a[n/2-1-i].se<<'\n';
        }
    }else if(k==n/2){
        cout<<a[0].fi<<' '<<a[n/2-1].fi<<'\n';
        cout<<a[0].se<<' '<<a[n/2-1].se<<'\n';

        for(int i=1;i<n/2-1;i++){
            cout<<a[i].fi<<' '<<a[n/2-1-i].se<<'\n';
        }
    }else if(k==n/2-1){
        cout<<a[0].fi<<' '<<a[0].se<<'\n';
        cout<<a[n/2-1].fi<<' '<<a[n/2-1].se<<'\n';

        for(int i=1;i<n/2-1;i++){
            cout<<a[i].fi<<' '<<a[n/2-1-i].se<<'\n';
        }
    }else if(k>n/2){
        int good = k-n/2+1;

        cout<<a[good].fi<<' '<<a[n/2-1].se<<'\n';
        cout<<a[n/2-1].fi<<' '<<a[good].se<<'\n';

        for(int i=0;i<n/2-1;i++){
            if(i!=good){
                if(i==n/2-1-good || i==0){
                    cout<<a[i].fi<<' '<<a[i].se<<'\n';
                }else{
                    cout<<a[i].fi<<' '<<a[n/2-1-i].se<<'\n';
                }
            }
        }

    }else if(k==0){
        for(int i=0;i<n/2;i++){
            cout<<a[i].fi<<' '<<a[n/2-1-i].se<<'\n';
        }
    }else{
        int good = k;

        cout<<a[good].fi<<' '<<a[n/2-1].se<<'\n';
        cout<<a[n/2-1].fi<<' '<<a[0].se<<'\n';
        cout<<a[n/2-1-good].fi<<' '<<a[good].se<<'\n';
        cout<<a[0].fi<<' '<<a[n/2-1-good].se<<'\n';


        for(int i=1;i<n/2-1;i++){
            if(i!=good && i!=n/2-1-good){
                cout<<a[i].fi<<' '<<a[n/2-1-i].se<<'\n';
                
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

