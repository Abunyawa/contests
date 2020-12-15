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
vi a;

bool f(int  k){
    vector<vi> s(k,vi(0));
    queue<int> two;
    queue<int> zer;
    for(int i = 0;i<a.size();i++){
        if(a[i]==2){
            two.push(i);
        }else{
            zer.push(i);
        }
    }
    int ptr = 0;
    for(int i = 0;i<k;i++){
        if(two.empty()) return false;
        s[i].pb(two.front());
        two.pop();
    }
    for(int i = 0;i<k;i++){
        if(zer.empty()) return false;
    
        while(!zer.empty() && s[i][0]>zer.front()){
            zer.pop();
        }
        if(zer.empty()) return false;
        
        s[i].pb(zer.front());
        zer.pop();
    }
    for(int i = 0;i<k;i++){
        if(two.empty()) return false;
    
        while(!two.empty() && s[i][1]>two.front()){
            two.pop();
        }
        if(two.empty()) return false;
        
        s[i].pb(two.front());
        two.pop();
    }

    for(int i = 0;i<k;i++){
        if(zer.empty()) return false;
    
        while(!zer.empty() && s[i][2]>zer.front()){
            zer.pop();
        }
        if(zer.empty()) return false;
        
        s[i].pb(zer.front());
        zer.pop();
    }


    return true;

}

void solve() {
    int n;

    while(cin>>n){
        a.clear();
        for(int i=0;i<n;i++){
            char x;
            cin>>x;
            if(x!='1'){
                a.pb(x-'0');
            }
        }

        int l = 0;
        int r = a.size();
        while(l<r){
            int mid = (l+r)/2;
            bool res = f(mid);
            if(res){
                if(l==mid) break;
                l = mid;
            }else{
                r = mid-1;
            }
        }
        if(f(r)){
            cout<<r<<'\n';
        }else{
            cout<<l<<'\n';
        }
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

