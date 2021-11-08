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
    int ans = -1;
    for(char let = 'a';let<='z';let++){
        int ptr1 = 0;
        int ptr2 = n-1;
        bool flag = true;
        int loc = 0;
        while(ptr1<ptr2){
            if(s[ptr1] != s[ptr2]){
                if(s[ptr1]==let){
                    ptr1++;
                    loc++;
                    continue;
                }

                if(s[ptr2]==let){
                    ptr2--;
                    loc++;
                    continue;
                }

                flag = false;
                break;
            }else{
                ptr1++;
                ptr2--;
            }
        }

        if(!flag){
            continue;
        }else{
            if(ans==-1){
                ans = loc;
            }else{
                ans = min(ans,loc);
            }
        }
    }

    cout<<ans<<'\n';
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

