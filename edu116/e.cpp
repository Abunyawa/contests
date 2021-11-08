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

int n,m;

void build_y (vector<vi> &a, vector<vi> &t, int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			t[vx][vy] = a[lx][ly];
		else
			t[vx][vy] = max(t[vx*2][vy], t[vx*2+1][vy]);
	else {
		int my = (ly + ry) / 2;
		build_y(a, t, vx, lx, rx, vy*2, ly, my);
		build_y (a, t, vx, lx, rx, vy*2+1, my+1, ry);
		t[vx][vy] = max(t[vx][vy*2], t[vx][vy*2+1]);
	}
}
 
void build_x (vector<vi> &a, vector<vi> &t, int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		build_x (a, t, vx*2, lx, mx);
		build_x (a, t, vx*2+1, mx+1, rx);
	}
	build_y (a, t, vx, lx, rx, 1, 0, m-1);
}

int max_y (vector<vi> &t, int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_) / 2;
	return max(max_y (t, vx, vy*2, tly, tmy, ly, min(ry,tmy)), max_y (t, vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry));
}
 
int max_x (vector<vi> &t, int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return max_y (t, vx, 1, 0, m-1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return max(max_x (t, vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry), max_x (t, vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry));
}


void build_y2 (vector<vi> &a, vector<vi> &t, int vx, int lx, int rx, int vy, int ly, int ry) {
	if (ly == ry)
		if (lx == rx)
			t[vx][vy] = a[lx][ly];
		else
			t[vx][vy] = min(t[vx*2][vy], t[vx*2+1][vy]);
	else {
		int my = (ly + ry) / 2;
		build_y2(a, t, vx, lx, rx, vy*2, ly, my);
		build_y2 (a, t, vx, lx, rx, vy*2+1, my+1, ry);
		t[vx][vy] = min(t[vx][vy*2], t[vx][vy*2+1]);
	}
}
 
void build_x2 (vector<vi> &a, vector<vi> &t, int vx, int lx, int rx) {
	if (lx != rx) {
		int mx = (lx + rx) / 2;
		build_x2 (a, t, vx*2, lx, mx);
		build_x2 (a, t, vx*2+1, mx+1, rx);
	}
	build_y2 (a, t, vx, lx, rx, 1, 0, m-1);
}

int min_y (vector<vi> &t, int vx, int vy, int tly, int try_, int ly, int ry) {
	if (ly > ry)
		return 100000000;
	if (ly == tly && try_ == ry)
		return t[vx][vy];
	int tmy = (tly + try_) / 2;
	return min(min_y (t, vx, vy*2, tly, tmy, ly, min(ry,tmy)), min_y (t, vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry));
}
 
int min_x (vector<vi> &t, int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
	if (lx > rx)
		return 100000000;
	if (lx == tlx && trx == rx)
		return min_y (t, vx, 1, 0, m-1, ly, ry);
	int tmx = (tlx + trx) / 2;
	return min(min_x (t, vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry), min_x (t, vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry));
}



void solve() {
    cin>>n>>m;
    vector<vi> a(n, vi (m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
        a[i][m] = i;
    }

    sort(all(a));
    
    vector<vi> t(4*n, vi (4*m));
    vector<vi> t2(4*n, vi (4*m));
    build_x(a, t, 1, 0, n-1);
    build_x2(a,t2,1,0,n-1);

	
    int ansX;
    int ansY;
    bool flag = false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            
            int mxLU = max_x(t,1,0,n-1,0,i,0,j);

            int mnLD = min_x(t2,1,0,n-1,i+1,n-1,0,j);
            int mnRU = min_x(t2,1,0,n-1,0, i, j+1,m-1);
            int mxRD = max_x(t,1,0,n-1,i+1,n-1,j+1,m-1);   

			if(i==0 && j == 1){
				debug(mxLU);
				debug(mnLD);
				debug(mxRD);
				debug(mnRU);
			}

            if(mnLD>mxLU && mnRU>mxRD){
                flag = true;
                ansX = i;
                ansY = j;
            }
        }
    }


    if(!flag){
        no();
    }else{
        vi ans(n,0);
        for(int i=0;i<=ansX;i++){
            ans[a[i][m]] = 1;
        }


        yes();

        for(int i=0;i<n;i++){
            if(ans[i]==1){
                cout<<'B';
            }else{
                cout<<'R';
            }
        }

        cout<<' '<<ansY+1<<'\n';
    }

    
}

/*
15887
16975
17998
52143
93332
153
757
898
111444
333222

*/

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

