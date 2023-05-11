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



void solve() {
    int n,k;
    cin>>n>>k;

    vi a(n), b(n);
    vector<bool> used(n, false);

    used[0] = true;

    vector<pii> c;
    int mn = 0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        b[i]-=a[i];
        mn += a[i];
    }

    if(mn>k){
        cout<<-1<<'\n';
        return;
    }
    k-=mn;
    priority_queue<int> q;
    int free = 1;
    for(int i=1;i<n;i++){
        int cur = b[i];

        if(free>0){
            if(k>=cur){
                q.push(cur);
                k-=cur;
                free--;
            }else{
                if(!q.empty() && q.top()>cur){
                    k+=q.top();
                    k-=cur;
                    q.pop();
                    q.push(cur);
                }
                free++;
            }
        }else{
            if(q.empty()){
                free++;
                continue;
            }
            if(q.top()>cur){
                k+=q.top();
                k-=cur;
                q.pop();
                q.push(cur);
            }
            free++;
             
        }
    }
    cout<<q.size()<<'\n';
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

