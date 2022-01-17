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
    unordered_multiset<ll> s;
    ll x;
    ll ans;
    int ctr = 0;
    for(int i=0;i<91000;i++){
        cout<<"next"<<endl;
        cout<<flush;

        cin>>x;
        if(x==-1){
            //find ans;
            int cur = 0;
            ll last = -1;
            for(auto it = s.begin();it!=s.end();it++){
                //debug(*it);
                if((*it)!=last){
                    if(cur>ctr){
                        ans = last;
                        ctr = cur;
                    }
                    cur = 1;
                    last = (*it);
                }else{
                    cur++;
                }
            }

            if(cur>ctr){
                ans = last;
            ctr = cur;
            }

            cout<<ans<<endl;
            return;
        }else{
            s.insert(x);
        }
    }


    //cout<<"asdasd"<<'\n';
    //return;
    while(true){
        cout<<"next"<<endl;
        cout<<flush;

        cin>>x;
        //debug(sizeof(s));
        if(x==-1){
            //find ans;
            int cur = 0;
            ll last = -1;
            for(auto it = s.begin();it!=s.end();it++){
                if((*it)!=last){
                    if(cur>ctr){
                        ans = last;
                        ctr = cur;
                    }
                    cur = 1;
                    last = (*it);
                }else{
                    cur++;
                }
            }

            if(cur>ctr){
                ans = last;
            ctr = cur;
            }

            cout<<ans<<endl;
            return;
        }else{
            auto it = s.begin();
            while(it!=s.end()){
                ll cur = (*it);
                s.erase(it);
                it = s.upper_bound(cur);
            }
            s.insert(x);

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

