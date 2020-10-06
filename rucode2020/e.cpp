#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf pop_front
#define yes cout << "YES" << '\n';
#define no cout << "NO" << '\n';
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
ll dif = 0.0000001;
ll a,b,c,d;

bool f(double m){
    if((a*m*m*m + b*m*m + c*m + d) > 0) return true;
    return false;
}

void solve(){
    int n,w; cin >> n >> w;
    vector<pair<int,int>> a(w);
    for(int i = 0; i < w; i++){
        int z,x; cin>>z>>x;
        a[i] = {min(z,x),max(z,x)};
    }
    sort(all(a));
    bool flag = true;
    int iter = 0;
    for(int i = 0; i < w; i++){
        if(a[i].ff < iter) continue;
        iter = a[i].ss;
        for(int j = i+1; j < w; j++){
            if(a[i].ss > a[j].ff and a[j].ss > a[i].ss and a[i].ff != a[j].ff and a[i].ss != a[j].ss){
                // cout << a[i].ff << ' ' << a[i].ss << endl;
                // cout << a[j].ff << ' ' << a[j].ss << endl;
                cout << "Unsafe";
                return;
            }
        }
    }
    cout << "Safe";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    // freopen("cubroot.in", "r", stdin);
    // freopen("cubroot.out", "w", stdout);
    while(t--){
        solve();
    }
 
    return 0;
} 