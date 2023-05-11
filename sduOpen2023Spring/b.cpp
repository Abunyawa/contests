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

/*
n n-1 n-2 ...... 3 2 1

n/2 n/2+1 m/2+2 ....3 2 1 n n-1 n-2 ... n/2-3 n/2-2 n/2-1 

3 2 1
3 1 2
1 3 2
1 2 3

4 3 2 1
2 1 4 3
1 2 4 3
1 2 3 4

6 5 4 3 2 1
5 6 4 3 2 1
3 2 1 5 6 4


n%4 = n/2%2
n/2 
10 9 8 7 6 5 4 3 2 1
5 4 3 2 1
5 2 1 4 3
1 4 5 2 3

7 6 5 4 3 2 1
7 3 2 1 6 5 4
1 6 5 7 3 2 4
1 3 2 4 6 5 7
1 2 3 4 5 6 7

9 8 7 6 5 4 3 2 1 n 
9 4 3 2 1 8 7 6 5 n - 1 
1 8 7 6 9 4 3 2 5 n - 2

2 + n - 3 + 1
2 + 6 + 1

6 5 4 3 2 1
6 5 2 1 4 3
2 1 6 5 4 3
2 1 4 3 6 5


1 2 5 6 3 4

10 9 8 7 6 5 4 3 2 1

2 1 4 3 6 5 8 7 10 9
1 2 3 4 5 6 7 8 9 10

n%2=1 ok 2:n 1 to fp
n%2%2=0 ok
n%2%2=1


3 2 1
3 1 2
1 3 2
1 2 3


8 7 6 5 4 3 2 1
4 3 2 1 8 7 5 6


7 6 5 4 3 2 1
7 3 2 1 6 5 4
1 6 5 7 3 2 4
1 5 6 7 2 3 4
1 2 3 4 5 6 7


*/

vector<pii> ans;
void calc(int n, int pref){
    if(n==0){
        return;
    }
    if(n==1){
        return;
    }
    if(n%2==1){
        ans.pb({2+pref,n/2});
        ans.pb({1+pref,n/2});
        calc((n-3)/2, pref+1);
        calc((n-3)/2, pref+1+n/2);
        ans.pb({2+pref, n/2});
    }else if(__builtin_popcount(n)==1){
        ans.pb({1+pref, n/2});
        calc(n/2, pref);
        calc(n/2, pref+n/2);
    }else{
        int ind = ans.size();

        calc(n/2, 0);

        for(int i=ind;i<ans.size();i++){
            ans[i] = {ans[i].fi*2-1+pref, ans[i].se*2};
        }

        for(int i=1;i<=n;i+=2){
            ans.pb({i+pref,1});
        }
    }
}

void solve() {
    int n;
    cin>>n;

    calc(n,0);
    //if(ans.size()>n) assert(0);
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].fi<<' '<<ans[i].se<<'\n';
    }
}

void test(){
    for(int kk=2;kk<=1000;kk++){
        ans.clear();
        calc(kk,0);

        vi a;
        a.pb(0);
        for(int j=kk;j>0;j--){
            a.pb(j);
        }

        for(int i=0;i<ans.size();i++){
            for(int st=ans[i].fi;st<ans[i].fi+ans[i].se;st++){
                swap(a[st],a[st+ans[i].se]);

            }
        }
        bool good = true;
        for(int i=1;i<a.size();i++){
            if(a[i]!=i){
                good = false;
            }
        }

        if(ans.size()>kk) good=false;
        if(!good) cout<<kk<<' '<<good<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
        //test();
    }

    return 0;
}

