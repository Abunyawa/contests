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
    typedef complex<double> base;


    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;

const double PI = 3.1415926;

    void yes(){
        cout<<"YES"<<'\n';
    }

    void no(){
        cout<<"NO"<<'\n';
    }

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void multiply (const vector<ll> & a, const vector<ll> & b, vector<ll> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
 
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}


void solve() {
    
    ll n;

    while(cin>>n){
        if(n==0) return;
        vector<ll> a(10000,1);
        vector<ll> b(10000,1);
        vector<ll> c(10000,1);
        vector<ll> d(10000,1);
        for(int i=0;i<10000;i++){
            a[i] = i;
            b[i] = i;
            c[i] = i;
            
        }
        multiply(a,b,d);
        ll ans = n+2;
        for(int i=1;i<10000;i++){
            if(n%c[i]==0){
                ans = min(ans,d[n/c[i]]*c[i]);
            }
        }
        cout<<ans<<'\n';
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

