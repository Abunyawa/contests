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

bool need[200100];
queue<int> pos[200100];
int fre[200100];

void solve() {
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<=n;i++){
        need[i] = false;
        while(!pos[i].empty()){
            pos[i].pop();
        }
        fre[i]=-1;
    }
    vi a(n);
    vi b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        need[b[i]]=true;
        fre[b[i]] = i; 
        if(a[i]!=b[i]){
            pos[b[i]].push(i);
        }
    }
    vi c(m);
    for(int i=0;i<m;i++){
        cin>>c[i];
    }

    if(!need[c[m-1]]){
        no();
        return;
    }else{
        vi ans(m);
        for(int i=0;i<m;i++){
            if(!need[c[i]]){
                if(!pos[c[m-1]].empty()){
                    ans[i] = pos[c[m-1]].front();
                }else{
                    ans[i] = fre[c[m-1]];
                }
            }else{
                if(!pos[c[i]].empty()){
                    ans[i] = pos[c[i]].front();
                    a[ans[i]] = c[i];
                    pos[c[i]].pop();
                }else{
                    ans[i] = fre[c[i]];
                }
            }
        }

        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                no();
                return;
            }
        }
        yes();
        for(int i=0;i<m;i++){
            cout<<ans[i]+1<<' ';
        }
        cout<<'\n';
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

