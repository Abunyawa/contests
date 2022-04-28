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
    int n;
    cin>>n;
    vl a(n);
    map<ll,int> m;

    ll st = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
        st+=a[i];
    }

    priority_queue<ll> q;
    q.push(st);
    int pc = 0;;
    for(;pc+q.size()<n;){
        if(q.empty()){
            break;
        }

        ll cur = q.top();
        //cout<<cur<<'\n';
        q.pop();
        if(m[cur]>0){
            m[cur]--;
            pc++;
        }else{
            q.push(cur/2);
            q.push((cur+1)/2);
        }
    }
    while(!q.empty()){
        if(m[q.top()]>0){
            m[q.top()]--;
            q.pop();
        }else{
            //cout<<q.top()<<endl;
            no();
            return;
        }
    }

    for(auto x: m){
        if(x.second!=0){
            no();
            return;
        }
    }

    yes();


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

