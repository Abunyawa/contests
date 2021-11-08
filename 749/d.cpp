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

int ask(string as){
    cout<<as<<endl;
    cout.flush();
    int k;
    cin>>k;
    return k;
}

void solve() {
    int n;
    cin>>n;
    int mx = 1;
    for(int i=2;i<=n;i++){
        string ques = "? ";
        for(int j=0;j<n;j++){
            if(j==n-1){
                ques+=to_string(i)+" ";
            }else{
                ques+="1 ";
            }
        }
        int k = ask(ques);
        if(k!=0){
            mx = i;
        }
    }

    int el = n+1 - mx;

    vi ans(n);

    ans[n-1] = el;
    for(int i=el+1;i<=n;i++){
        string ques = "? ";
        for(int j=0;j<n;j++){
            if(j==n-1){
                ques+=to_string(i)+" ";
            }else{
                ques+=to_string(el)+" ";
            }
        }

        int k = ask(ques);
        if(k!=0){
            ans[k-1] = i;
        }
    }

    for(int i=1;i<el;i++){
        string ques = "? ";
        for(int j=0;j<n;j++){
            if(j==n-1){
                ques+=to_string(i)+" ";
            }else{
                ques+=to_string(el)+" ";;
            }
        }


        int k = ask(ques);
        if(k!=0){
            ans[k-1] = i;
        }
    }


    string guess = "! ";
    for(int i=0;i<n;i++){
        guess+=to_string(ans[i])+" ";
    }

    cout<<guess<<endl;
    cout.flush();

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

