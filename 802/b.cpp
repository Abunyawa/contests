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
    
    vi num(n);

    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        num[i] = x-'0';
    }

    vi ans(n,0);
    if(num[0]==9){
        ans[0] = 1;
        num[0] = 0;
        int add = (11-num[n-1])%10;
        ans[n-1] = add;
        for(int i=n-1;i>=0;i--){
            num[i] += add;
            add = num[i]/10;
            num[i]%=10;
        }


        for(int l=0, r = n-2;l<r;l++,r--){
            if(l==0){
                if(num[r] == 9 && num[l]==0){
                    ans[r] = 1;
                    int add = 1;
                    for(int i=r;i>=0;i--){
                        num[i] += add;
                        add = num[i]/10;
                        num[i]%=10;
                    }
                }
            }
            ans[l]+=max(num[l],num[r])-num[l];
            ans[r]+=max(num[l],num[r])-num[r];

            
        }

        for(int i=0;i<n;i++){
            cout<<ans[i];
        }

        cout<<'\n';
    }else{

        for(int l=0, r = n-1;l<r;l++,r--){
            ans[l]+=max(num[l],num[r])-num[l];
            ans[r]+=max(num[l],num[r])-num[r];
            if(l==0){
                if(ans[l]==0){
                    ans[l]++;
                    ans[r]++;
                }
            }
        }

        for(int i=0;i<n;i++){
            cout<<ans[i];
        }

        cout<<'\n';
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

