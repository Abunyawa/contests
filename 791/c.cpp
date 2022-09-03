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

vector<int> t1;
int n1;

void init1 (int nn)
{
	n1 = nn;
	t1.assign (n, 0);
}

int sum1 (int r)
{
	int result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t1[r];
	return result;
}

void inc1 (int i, int delta)
{
	for (; i < n1; i = (i | (i+1)))
		t1[i] += delta;
}

int sum1 (int l, int r)
{
	return sum1 (r) - sum1 (l-1);
}

void init1 (vector<int> a)
{
	init1 ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		inc (i, a[i]);
}


void solve() {
    int n,q;
    cin>>n>>q;
    
    init(n+10);
    init1(n+10);
    vi ctr(n+10,0);
    vi ctr1(n+10,0);


    for(int i=0;i<q;i++){
        int tt;
        cin>>tt;
        if(tt==1){
            int x,y;
            cin>>x>>y;

            ctr[x]++;
            ctr1[y]++;
            if(ctr[x]==1){
                inc(x,1);
            }

            if(ctr1[y]==1){
                inc1(y,1);
            }
        }else if(tt==2){
            int x,y;
            cin>>x>>y;

            ctr[x]--;
            ctr1[y]--;
            if(ctr[x]==0){
                inc(x,-1);
            }

            if(ctr1[y]==0){
                inc1(y,-1);
            }
        }else{
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;

            ll h = sum(x1,x2);
            ll v = sum1(y1,y2);

            if(h==x2-x1+1 || v==y2-y1+1){
                yes();
            }else{
                no();
            }
        }
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

