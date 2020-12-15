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
    vl a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll cur = a[0];
    bool flag=  false;
    ll ans1 = 9999999999999;
    map<ll,int> m;
    for(int i=1;i<n-1;i++){
        if(cur>a[i]){
            ans1 = min(ans1,(ll)i-1);
            flag = true;
            int l = 0;
            for(int k = l;k<i-1;k++){
                cur^=a[k];
                if(k>0){
                    if(cur<a[k-1] || cur>a[i]) ans1 = min(ans1,(ll)i-1 - (k+1));
                }else{
                    if(cur>a[i]) ans1 = min(ans1,(ll)i-1 - (k+1));
                }
            }
            break;
        }else{
            cur^=a[i];
        }
    }
    cur = a[n-1];
    for(int i=n-2;i>0;i--){
        if(cur<a[i]){
            ans1 = min(ans1,(ll)(n-1-i)-1);
            flag = true;
            int r = n-1;
            for(int k = r;k>i+1;k--){
                cur^=a[k];
                if(k<n-1){
                    if(cur>a[k+1] || cur<a[i]) ans1 = min(ans1,(ll)(n-1-i)-1 - (n-k));
                }else{
                    if(cur<a[i]) ans1 = min(ans1,(ll)(n-1-i)-1 - (n-k));
                }
            }
            break;

        }else{
            cur^=a[i];
        }
    }
    if(!flag){
        cout<<-1<<'\n';

        return;
    }else{
        cout<<ans1<<'\n';
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

