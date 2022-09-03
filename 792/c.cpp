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
int n;

void init (int nn)
{
	n = nn;
	t.assign (n, 0);
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
	for (; i < n; i = (i | (i+1)))
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

    int ctr = 1;
    map<ll,int> com;
    vector<ll> vals;
    ll a[n][m];

    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            ll x;
            cin>>x;
            if(com[x]==0){
                com[x] = ctr++;
                vals.pb(x);
            }
            a[i][j] = x;
        }
    }

    sort(all(vals));

    for(int i=0;i<vals.size();i++){
        com[vals[i]] = i;
    }

    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = com[a[i][j]];
        }
    }

    init(ctr+10);

    int ind = -1;
    int ind2 = -1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(sum(a[i][j]+1,ctr+9)>0){
                ind2 = j;
            }
            
            inc(a[i][j],1);
            
        }
        if(ind2!=-1){
            for(int k=ind2-1;k>=0;k--){
                if(a[i][k]>a[i][ind2]){
                    ind = k;
                }
            }
        }
        if(ind!=-1){
            break;
        }

        for(int j=0;j<m;j++){
            inc(a[i][j],-1);
        }
        
    }
    
    if(ind==-1){
        cout<<1<<' '<<1<<'\n';
        return;
    }

    for(int i=0;i<n;i++){
        swap(a[i][ind],a[i][ind2]);
    }


    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]<a[i][j-1]){
                cout<<-1<<'\n';
                return;
            }
        }
    }


    cout<<ind+1<<' '<<ind2+1<<'\n';
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

