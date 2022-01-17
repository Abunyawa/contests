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

int parent[2010];
int rank1[2010];
int size1[2010];

void make_set (int v) {
	parent[v] = v;
	rank1[v] = 0;
    size1[v] = 1;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rank1[a] < rank1[b])
			swap (a, b);
		parent[b] = a;
        size1[a] += size1[b];
		if (rank1[a] == rank1[b])
			++rank1[a];
	}
}


void solve() {
    int n,d;
    cin>>n>>d;

    for(int i=1;i<=n;i++){
        make_set(i);
    }

    int ans = 0;
    int free = 0;
    for(int i=0;i<d;i++){
        int x,y;
        cin>>x>>y;
        if(find_set(x) != find_set(y)){
            union_sets(x,y);
            vi szs;
            vi used(n+1, false);
            for(int j=1;j<=n;j++){
                if(!used[find_set(j)]){
                    szs.pb(-size1[find_set(j)]);
                    used[find_set(j)] = true;
                }
            }


            sort(all(szs));
            int sz = 0;

            for(int k=0;k<szs.size() && k<=free;k++){
                sz -= szs[k];
            }

            ans = max(ans,sz-1);
        }else{
            int big = 0;
            int st = 0;
            free++;
            vi szs;
            vi used(n+1, false);
            for(int j=1;j<=n;j++){
                if(!used[find_set(j)]){
                    szs.pb(-size1[find_set(j)]);
                    used[find_set(j)] = true;
                }
            }

            sort(all(szs));
            int sz = 0;

            for(int k=0;k<szs.size() && k<=free;k++){
                sz -= szs[k];
            }

            ans = max(ans,sz-1);
        }

        cout<<ans<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

