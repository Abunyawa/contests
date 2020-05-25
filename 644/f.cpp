#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
int n,m;


bool check(string fr, string *s){
    vi pos(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]!=fr[j]){
                pos[i]++;
                if(pos[i]>1){
                    return false;
                }
            }
        }
    }
    return true;

}

void solve(){
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    for(int i=0;i<m;i++){
        string cur = s[0];

        for(auto j = 'a';j<='z';j++){
            cur[i] = j;
            if(check(cur,s)){
                cout<<cur<<'\n';
                return;
            }
        }
    }

    cout<<-1<<'\n';
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
