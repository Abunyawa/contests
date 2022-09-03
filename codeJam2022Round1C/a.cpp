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
    int n;
    cin>>n;
    p =0;
    ans = "";
    for(int i=0;i<200;i++){
        g[i].clear();
        in[i]=0;
        used[i] = 0;
    }
    vi ctr(26,0);
    vector<vector<int>> cons(26);
    vector<vector<int>> st(26);
    vector<vector<int>> en(26);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        string nw = "";
        for(int j=0;j<a[i].length();j++){
            if(j==0){
                nw+=a[i][j];
                continue;
            }
            if(a[i][j]!=a[i][j-1]){
                nw+=a[i][j];
            }
        }

        for(int j=1;j<nw.length()-1;j++){
            if(nw[j]!=nw[j-1] && nw[j]!=nw[j+1]){
                ctr[nw[j]-'A']++;
            }
        }
        if(nw.length()==1){
            cons[nw[0]-'A'].pb(i);
        }else{
            st[nw[0]-'A'].pb(i);
            en[nw[nw.length()-1]-'A'].pb(i);
        }
    }

    for(int i=0;i<26;i++){
        if(ctr[i]>1){
            cout<<"IMPOSSIBLE\n";
            return;
        }else if(ctr[i]==1 && (en[i].size()>0 || st[i].size()>0 || cons[i].size()>0)){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }


    for(int i=0;i<26;i++){
        if(en[i].size()>1){
            cout<<"IMPOSSIBLE\n";
            return;
        }
        
        if(st[i].size()>1){
            cout<<"IMPOSSIBLE\n";
            return;
        }

        if(en[i].size()!=0){
            if(cons[i].size()!=0){
                g[en[i][0]].pb(cons[i][0]);
                in[cons[i][0]]++;

                for(int j=1;j<cons[i].size();j++){
                    g[cons[i][j-1]].pb(cons[i][j]);
                    in[cons[i][j]]++;
                }
                if(st[i].size()>0){
                    g[cons[i][cons[i].size()-1]].pb(st[i][0]);
                    in[st[i][0]]++;
                }
            }else{
                if(st[i].size()>0){
                    g[en[i][0]].pb(st[i][0]);
                    in[st[i][0]]++;
                }
            }
        }else if(cons[i].size()!=0){
            for(int j=1;j<cons[i].size();j++){
                g[cons[i][j-1]].pb(cons[i][j]);
                in[cons[i][j]]++;
            }
            if(st[i].size()>0){
                g[cons[i][cons[i].size()-1]].pb(st[i][0]);
                in[st[i][0]]++;
            }
        }
        
    }

    for(int i=0;i<n;i++){
        if(!used[i] && in[i]==0){
            dfs(i);
        }
    }

    if(p!=n){
        cout<<"IMPOSSIBLE\n";
        return;
    }else{
        cout<<ans<<'\n';
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

