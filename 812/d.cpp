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

int ask(int a, int b){
    cout<<"? "<<a<<' '<<b<<endl;
    int x;
    cin>>x;

    return x;
}

void answer(int a){
    cout<<"! "<<a<<endl;
}

void solve() {
    int n;
    cin>>n;

    ll p = 1<<n;
    if(p==2){
        int ans = ask(1,2);
        if(ans==1){
            answer(1);
            return;
        }else{
            answer(2);
            return;
        }
        return;
    }else{
        queue<int> q;

        for(int i=1;i<=p;i++){
            q.push(i);
        }

        while(true){
            if(q.size()>=4){
                int a = q.front(); q.pop();
                int b = q.front(); q.pop();
                int c = q.front(); q.pop();
                int d = q.front(); q.pop();
                
                int ans = ask(a,c);
                if(ans==0){
                    ans = ask(b,d);
                    if(ans==1){
                        q.push(b);
                    }else{
                        q.push(d);
                    }
                }else if(ans==1){
                    ans = ask(a,d);
                    if(ans==1){
                        q.push(a);
                    }else{
                        q.push(d);
                    }
                }else{
                    ans = ask(b,c);
                    if(ans==1){
                        q.push(b);
                    }else{
                        q.push(c);
                    }
                }
            }else{
                if(q.size()==2){
                    int a = q.front();
                    q.pop();
                    int b = q.front();
                    q.pop();

                    int ans = ask(a,b);
                    if(ans==1){
                        answer(a);
                        return;
                    }else{
                        answer(b);
                        return;
                    }
                }else{
                    answer(q.front());
                    return;
                }
            }
        }
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

