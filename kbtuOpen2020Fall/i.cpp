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
    cout<<"Yes"<<'\n';
}

void no(){
    cout<<"No"<<'\n';
}



void solve() {
    int n;
    cin>>n;
    vi a(n);
    vi a2(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
        a2[i] = a[i];
    }
    vi d;
    vi d2;
    for(int i=0;i<n-1;i++){
        d.pb(a[i+1]-a[i]);
        d2.pb(a[i+1]-a[i]);
    }
    int ans1 = 0;
    for(int i=0;i<n-1;i++){
        for(int j = 0;j<n-2;j++){
            if(d[j+1]<d[j]){
                int dif = d[j] - d[j+1];
                dif = (dif+1)/2;
                ans1+=dif;
                a[j+1]-=dif;
                d[j]-=dif;
                d[j+1]+=dif;
            }
        }
    }
    int ans2 = 0;
    for(int i=0;i<n-1;i++){
        for(int j = n-1;j>=1;j--){
            if(d2[j-1]>d2[j]){
                int dif = d2[j-1] - d2[j];
                dif = (dif+1)/2;
                ans2+=dif;
                a2[j]-=dif;
                d2[j-1]-=dif;
                d2[j]+=dif;
            }
        }
    }

    if(ans1<ans2){
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }else{

        for(int i=0;i<n;i++){
            cout<<a2[i]<<' ';
        }
        cout<<'\n';
    }
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

