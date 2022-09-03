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

vi g[200];
int in[200];
vector<string> a(200);
bool used[200];
string ans;
int p;
void dfs(int v){
    used[v] = true;
    ans+=a[v];
    p++;

    for(int to: g[v]){
        dfs(to);
    }
}

void solve() {
    int n,k;
    cin>>n>>k;
    

    vl a(n);
    ll left=0;
    ll right=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        right+=a[i]*a[i];
        left+=a[i];
    }

    right -= (left*left);
    left = left*2;
    if(left==0){
        if(right==0){
            cout<<0<<'\n';
            return;
        }else{
            cout<<"IMPOSSIBLE\n";
            return;
        }
        
    }
    if(right%left==0){
        cout<<right/left<<'\n';
    }else{
        if(k==1){
            cout<<"IMPOSSIBLE\n";
        }else{
            left = 0;
            right=0;
            for(int i=0;i<n;i++){
                right+=a[i]*a[i];
                left+=a[i];
            }

            right-=left*left;
            if(right%2!=0){
                cout<<"IMPOSSIBLE\n";
                return;
            }else{
                right/=2;

                cout<<-1<<' '<<right+2<<'\n';
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
    for(int i=1;i<=tt;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

