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
int n1;

void init (int nn)
{
	n1 = nn;
	t.assign (n1, 0);
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
	for (; i < n1; i = (i | (i+1)))
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


int ctr1 = 0;
int ctr2 = 0;
char ask1(int i){
    if(ctr1>=26){
        assert(0);
    }
    ctr1++;
    fflush(stdout);
    cout<<"? 1 "<<i<<endl;
    char x;
    cin>>x;
    return x;
}

int ask2(int l, int r){
    if(ctr2>=6000){
        assert(0);
    }
    ctr2++;
    fflush(stdout);
    cout<<"? 2 "<<l<<' '<<r<<endl;
    int x;
    cin>>x;

    return x;
}

int was[1010][1010];
void solve() {
    fflush(stdout);
    int n;
    cin>>n;

    int l = 1;
    int r = 1;
    int last = 0;

    vi a(n+1,-1);
    a[0] = 1;
    init(n+10);
    
    for(int i=1;i<=n;i++){
        inc(i,1);
    }

    int ctr = 0;

    while(r<=n){
        while(r<=n && ask2(l,r)==last+1){
            was[l][r] = last+1;
            a[r] = ctr++;
            r++;
            last++;
        }
        if(r>n){
            break;
        }
        
        int left = 1;
        int right = r;

        while(left<right-1){
            int m = (left+right)/2;
            int uni;
            if(was[m][r]==0){
                uni = ask2(m,r);
                was[m][r] = uni;
            }else{
                uni = was[m][r];
            }
            int places = sum(r) - sum(m-1);
            if(uni==places){
                right = m;
            }else{
                left = m+1;
            }
        }

        int need;

        int uni = ask2(left,r);

        if(was[left][r]==0){
            uni = ask2(left,r);
            was[left][r] = uni;
        }else{
            uni = was[left][r];
        }
        int places = sum(r) - sum(left-1);

        if(uni==places){
            need = left;
        }else{
            need = right;
        }

        inc(need-1,-1);

        a[r]= a[need-1];


        r++;
    }

    vector<char> m(26,'X');

    string ans = "";

    for(int i=1;i<=n;i++){
        if(m[a[i]]=='X'){
            char let = ask1(i);
            m[a[i]] = let;
            ans+=let;
        }else{
            ans+=m[a[i]];
        }
    }

    cout<<"! "<<ans<<'\n';
    return;
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

