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

vector<int> t;
int p;

void init (int nn)
{
	p = nn;
	t.assign (p, 0);
}

int sum (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (int i, int delta)
{
	for (; i < p; i = (i | (i+1)))
		t[i] += delta;
}

int sum (int l, int r)
{
	return sum (r) - sum (l-1);
}

void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> seg(n+1);
    vector<vector<pii>> segNw(n+1);
    for(int i=0;i<m;i++){
        int x, l, r;
        cin>>x>>l>>r;
        seg[x].pb({l,r});
    }
    /*
    for(int i=1;i<=n;i++){
        if(seg[i].size()==0){
            continue;
        }
        sort(all(seg[i]));
        int l = seg[i][0].fi;
        int r = seg[i][0].se;
        for(int j=1;j<seg[i].size();j++){
            if(seg[i][j].fi<=r+1){
                r = max(r,seg[i][j].se);
            }else{
                segNw[i].pb({l,r});
                l = seg[i][j].fi;
                r = seg[i][j].se;
            }
        }
        segNw[i].pb({l,r});

    }
    */

    vi a(n+10,1);
    vi cur(n+10,1);
    a[0] = 0;
    init(a);
    inc(0,-1);
    vector<vi> del(n+1);
    vector<vi> add(n+1);
    vi ans(n+1);
    for(int i=1;i<=n;i++){
        

        int l = 1;
        int r = n+1;
        //cout<<i<<endl;
        while(l<r-1){
            int m = (l+r)/2;
            //cout<<m<<' '<<sum(1,m)<<endl;
            if(sum(1,m)>0){
                r = m;
            }else{
                l = m+1;
            }
        }
        if(sum(l,l)==1){
            ans[i] = l;
        }else{
            ans[i] = r;
        }

        for(pii pr: seg[i]){
            del[pr.fi-1].pb(ans[i]);
            add[pr.se].pb(ans[i]);
        }

        
        for(int k: del[i]){
            cur[k]--;
            if(sum(k,k)!=0){
                inc(k,-1);
            }
        }

        for(int k: add[i]){
            cur[k]++;
            if(cur[k]==1){
                if(sum(k,k)==0){
                    inc(k,1);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
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

