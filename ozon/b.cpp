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
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

void solve(){
    string s;
    cin>>s;
    vi ans;
    int l = 0,r=s.length()-1;
    while(l<r){
        while(s[l]==')' && l<r){
            l++;
        }
        while(s[r]=='(' && l<r){
            r--;
        }
        if(l<r){
            ans.pb(l++);
            ans.pb(r--);
        }
    }
    sort(all(ans));
    if(ans.size()!=0){
        cout<<1<<endl;
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]+1<<' ';
        }
        cout<<endl;
    }else{
        cout<<0<<endl;
    }
}

int main(){
    abu;
    said;
    solve();
    

    return 0;
}