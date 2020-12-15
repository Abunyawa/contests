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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
/*
abc

bcd


*/


void solve() {
    int n,k;
    cin>>n>>k;
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    sort(all(s1));
    sort(all(s2));
    int ptr = 0;
    bool flag = true; 
    vector<int> m1(26,0);
    vector<int> m2(26,0);
    for(int i=0;i<n;i++){
        m1[s1[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        m2[s2[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(m1[i]!=m2[i]){
            if(m1[i]<m2[i]){
                flag = false;
                break;
            }else{
                int next = m1[i]-m2[i];
                if(next%k!=0){
                    flag = false;
                    break;
                }else{
                    m1[i+1]+=next;
                    m1[i]-=next;
                }
            }
        }
    }
    for(int i=0;i<26;i++){
        if(m2[i]!=m1[i]){
            flag = false;
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

