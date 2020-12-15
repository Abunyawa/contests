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


void solve() {
    int n;
    cin>>n;
    vector<bitset<500>> a(n);
    vector<bitset<500>> inv(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            a[i][j] = x;
        }        
        inv[i][i] = 1;
    }
    
    
    for (int col=0, row=0; col<n && row<n; ++col) {
		for (int i=row; i<n; ++i)
			if (a[i][col]) {
				swap (a[i], a[row]);
				swap (inv[i], inv[row]);
				break;
			}
		if (!a[row][col]){
            cout<<-1<<'\n';
            return;
        }
 
		for (int i=0; i<n; ++i)
			if (i != row && a[i][col]){
				a[i] ^= a[row];
                inv[i] ^= inv[row];
            }
		++row;
	}
    
    
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(inv[i][j]){
                cout<<j+1<<' ';
            }
        }
        cout<<'\n';
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

