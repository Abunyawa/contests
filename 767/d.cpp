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
    map<string, int> m;
    bool flag = false;
    vector<string> ss;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ss.pb(s);
        if(s.length()==1){
            if(m[s]){
                flag = true;
            }
        }else if(s.length()==2){
            string s1 = string(1,s[1]);
            string s0 = string(1,s[0]);
            
            if(m[s1] || m[s1+s0]){
                flag = true;
            }
        }else{
            string s2 = string(1,s[2]);
            string s1 = string(1,s[1]);
            string s0 = string(1,s[0]);
            if(s[0]==s[1]){
                if(m[s2]){
                    flag = true;
                }
            }

            if(m[s2+s1] || m[s2+s1+s0]){
                flag = true;
            }
        }

        m[s]++;

        for(char ch='a';ch<='z';ch++){
            string lt = string(1,ch);
            if(m[lt]){
                m[ch+s]++;
            }
        }
    }

    if(flag){
        yes();
        return;
    }

    m.clear();
    for(int i=n-1;i>=0;i--){
        string s = ss[i];
        reverse(all(s));
        if(s.length()==1){
            flag = true;
            
        }else if(s.length()==2){
            string s1 = string(1,s[1]);
            string s0 = string(1,s[0]);
            if(s1==s0){
                flag=true;
            }
            if(m[s1] || m[s1+s0]){
                flag = true;
            }
        }else{
            string s2 = string(1,s[2]);
            string s1 = string(1,s[1]);
            string s0 = string(1,s[0]);

            if(s2==s0){
                flag=true;
            }
            if(s[0]==s[1]){
                if(m[s2]){
                    flag = true;
                }
            }

            if(m[s2+s1] || m[s2+s1+s0]){
                flag = true;
            }
        }

        m[s]++;

        for(char ch='a';ch<='z';ch++){
            string lt = string(1,ch);
            if(m[lt]){
                m[ch+s]++;
            }
        }
    }


    if(flag){
        yes();
    }else{
        no();
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

