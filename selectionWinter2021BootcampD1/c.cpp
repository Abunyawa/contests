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
    string s;
    cin>>s;
    int ctr[3];
    ctr[0] = 0;
    ctr[1] = 0;
    ctr[2] = 0;
    for(int i=0;i<n;i++){
        ctr[s[i]-'0']++;
    }

    if(ctr[0]<n/3){
        for(int i=0;i<n;i++){
            if(ctr[0]==n/3){
                break;
            }
            if(ctr[s[i]-'0']>n/3){
                ctr[s[i]-'0']--;
                ctr[0]++;
                s[i]='0';
            }
        }
    }

    if(ctr[1]<n/3){
        for(int i=0;i<n;i++){
            if(ctr[1]==n/3){
                break;
            }
            if(s[i]=='2' && ctr[s[i]-'0']>n/3){
                ctr[s[i]-'0']--;
                ctr[1]++;
                s[i]='1';
            }
        }

        
    }

    if(ctr[2]<n/3){
        

        for(int i=n-1;i>=0;i--){
            if(ctr[2]==n/3){
                break;
            }
            if(ctr[s[i]-'0']>n/3){
                ctr[s[i]-'0']--;
                ctr[2]++;
                s[i]='2';
            }
        }
    }

    if(ctr[1]<n/3){
        
        for(int i=n-1;i>=0;i--){
            if(ctr[1]==n/3){
                break;
            }
            if(s[i]=='0' && ctr[s[i]-'0']>n/3){
                ctr[s[i]-'0']--;
                ctr[1]++;
                s[i]='1';
            }
        }
    }


    cout<<s<<'\n';
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

