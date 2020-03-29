#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

int n,m;
vi g[100100];
int col[100100];
bool used[100100];

void solve(){
    int n;
    cin>>n;
    vector<char> prime (n+1, true);
    prime[0] = prime[1] = false;
    for (int i=2; i<=n; ++i)
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j=i*i; j<=n; j+=i)
                    prime[j] = false;
    vi a(n+1);
    vi b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]] = i;
    }
    vector<pii> ans;
    for(int i=1;i<=n;i++){
        if(prime[b[i] - i + 1]){
            ans.pb({i,b[i]});
            b[a[i]] = b[i];
        }else{

        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].F<<' '<<ans[i].S<<endl;
    }
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
