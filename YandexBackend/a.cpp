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
ll const N = 1000100;
string s[N],ans[N];

void yes(){
    cout<<"Yes"<<endl;
}

void no(){
    cout<<"No"<<endl;
}

void solve(){
    int ind = 0;
    while(cin>>s[ind]){
        if(s[ind][0]-48 >= 0 && s[ind][0]-48<=9){
            break;
        }
        ind++;
    }
    int m = ind-1;
    int n = stoi(s[ind]);
    unordered_map<ll,int> a;
    hash<string> hs;
    for(int i=0;i<=m;i++){
        ans[i] = s[i];
        int k = 'z' - s[i][0];
        for(int j=0;j<s[i].length();j++){
            s[i][j] = (s[i][j]-'a'+k)%26+'a';
        }
        a[hs(s[i])] = i;
    }
    for(int i=0;i<n;i++){
        string st;
        cin>>st;
        int k = 'z' - st[0];
        for(int j=0;j<st.length();j++){
            st[j] = (st[j]-'a'+k)%26+'a';
        }
        cout<<ans[a[hs(st)]]<<'\n';
    }
}

int main(){
    abu;
    said;
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
