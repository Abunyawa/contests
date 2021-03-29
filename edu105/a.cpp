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

char mb[] = {'(',')'};


void solve() {
    string s;
    cin>>s;
    
    for(int a=0;a<2;a++){
        for(int b = 0;b<2;b++){
            for(int c = 0;c<2;c++){
                string loc ="";
                stack<char> st;

                for(int i=0;i<s.length();i++){
                    if(s[i]=='A'){
                        loc+=mb[a];
                    }
                    if(s[i]=='B'){
                        loc+=mb[b];
                    }
                    if(s[i]=='C'){
                        loc+=mb[c];
                    }
                }
                for(int i=0;i<s.length();i++){
                    if(st.empty()){
                        st.push(loc[i]);
                    }else{
                        if(st.top()=='(' && loc[i]==')'){
                            st.pop();
                        }else{
                            st.push(loc[i]);
                        }
                    }
                }

                if(st.empty()){
                    //cout<<loc<<'\n';
                    yes();
                    return;
                }
            }
        }
    }
    no();
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

