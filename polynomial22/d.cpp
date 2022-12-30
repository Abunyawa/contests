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
    int n,m;
    cin>>n>>m;
    vector<vi> a(n, vi(m));
    int ctr = 0;

    vi cur(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]) ctr++;
            if(a[i][j]) cur[i]++;
        }
    }

    if(ctr%n!=0){
        cout<<-1<<'\n';
        return;
    }

    vector<queue<int>> q(m);
    for(int i=0;i<n;i++){
        if(cur[i]<ctr/n){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    q[j].push(i);
                }
            }
        }
    }

    vector<array<int,3>> ans;
    for(int i=0;i<n;i++){
        int ptr = 0;
        while(ptr<m && cur[i]>ctr/n){
            if(a[i][ptr]==1){
                if(q[ptr].empty()){
                    ptr++;
                }else{
                    while(!q[ptr].empty() && cur[q[ptr].front()]==ctr/n){
                        q[ptr].pop();
                    }

                    if(q[ptr].empty()){
                        ptr++;
                    }else{
                        ans.pb({i+1, q[ptr].front()+1, ptr+1});
                        cur[i]--;
                        cur[q[ptr].front()]++;
                        q[ptr].pop();
                        ptr++;
                    }
                }
            }else{
                ptr++;
            }
            
        }
    }

    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<'\n';
    }
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

