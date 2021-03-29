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

vi find(string a, string b){
    vi ret;
    int n = a.length();
    for(int s=0;s<n;s++){
        bool flag = true;
        for(int i=0;i<n;i++){
            if(a[i]!=b[(s+i)%n]){
                flag = false;
                break;
            }
        }
        if(flag){
            ret.pb(s);
        }
    }

    return ret;
}

void solve() {
    int n;
    cin>>n;
    vector<vi> a(n);
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        vi res = find(s[0],s[i]);
        if(res.size()==0){
            cout<<-1<<'\n';
            return;
        }

        a[i] = res;
        
    }
    int ans = -1;
    for(int st=0;st<s[0].length();st++){
        int loc = 0;
        for(int i=0;i<n;i++){
            int toAdd = -1;
            for(int j =0;j<a[i].size();j++){
                if(toAdd==-1){
                    if(a[i][j]>=st){
                        toAdd = a[i][j]-st;
                    }else{
                        toAdd = a[i][j]-st+s[0].length();

                    }
                }else{
                    int cur;
                    if(a[i][j]>=st){
                        cur = a[i][j]-st;
                    }else{
                        cur = a[i][j]-st+s[0].length();

                    }
                    toAdd = min(toAdd,cur);
                }
            }

            loc+=toAdd;
            
        }
        if(ans==-1){
            ans = loc;
        }else{
            ans = min(ans,loc);
        }
    }


    cout<<ans<<'\n';
    
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

