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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

vector<int> g[200100];
map<pii,int> edges;
int deg[200100];
int ptr[200100];
bool used[200100];
vi ans;


void visit(int v){
    while(ptr[v]<g[v].size()){
        int to = g[v][ptr[v]];
        if(edges[{v,to}]==0){
            ptr[v]++;
            continue;
        }
        edges[{v,to}]--;
        edges[{to,v}]--;
        visit(to);
        ans.pb(to);
    }
}

void solve() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            g[i].pb(x);
            edges[{i,x}]++;
            deg[x]++;
        }
    }


    int v1 = -1; 
    int v2 = -1;
    bool flag = true;
    for(int i=1;i<=n;i++){
        if(deg[i]%2!=0){
            if(v1==-1){
                v1 = i;
            }else if(v2==-1){
                v2 = i;
            }else{
                flag = false;
            }
        }
    }

    if(!flag){
        printf("-1");
        return;
    }else{
        if(v1!=-1){
            used[v1]=true;
            visit(v1);
            ans.pb(v1);

        }else{
            used[1]=true;
            visit(1);
            ans.pb(1);

        }
        printf("%d\n",ans.size()-1);
        for(auto x: ans){
            printf("%d ",x);
        }
        printf("\n");
    }
    

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
/*
    freopen("euler.in","r",stdin);
    freopen("euler.out","w",stdout);
    */
    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

