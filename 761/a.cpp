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
    string s;
    cin>>s;
    string t;
    cin>>t;
    int a=0;
    int b=0;
    int c=0;

    sort(all(s));
    for(int i=0;i<s.length();i++){
        if(s[i]=='b') b++;
        if(s[i]=='c') c++;
        if(s[i]=='a') a++;
    }

    if(t=="abc" && a!=0 && b!=0 && c!=0){
        b =0;
        c =0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b') b++;
            if(s[i]=='c') c++;
        }
        int ctr  =0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='a'){
                break;
            }else{
                cout<<s[i];
                ctr++;
            }
        }

        for(int i=0;i<c;i++){
            cout<<'c';
        }
        for(int i=0;i<b;i++){
            cout<<'b';
        }

        for(int i=0;i<s.length();i++){
            if(s[i]!='a' &&s[i]!='b' && s[i]!='c'){
                cout<<s[i];
            }
        }


        cout<<'\n';
    }else{
        for(int i=0;i<s.length();i++){
            cout<<s[i];
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

