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

void solve(){
    int n;
    cin>>n;
    vector<string> a(n);
    vector<char> pref;
    vector<char> suf;
    bool flag = true;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i][0]!='*'){
            if(pref.empty()){
                int k = 0;
                while(k<a[i].length() && a[i][k]!='*'){
                    pref.pb(a[i][k++]);
                }
            }else{
                int ptr1 = 0;
                int ptr2 = 0;
                while(ptr1<a[i].length() && ptr2<pref.size() && a[i][ptr1]==pref[ptr2]){
                    ptr1++;
                    ptr2++;
                }
                if(ptr1!=a[i].length()){
                    if(ptr2!=pref.size() && a[i][ptr1]!='*'){
                        flag = false;
                    }else{
                        for(int p = ptr1;p<a[i].length();p++){
                            if(a[i][p]=='*'){
                                break;
                            }
                            pref.pb(a[i][p]);
                        }
                    }
                }
            }
        }
        if(a[i][a[i].length()-1]!='*'){
            if(suf.empty()){
                int k = a[i].length()-1;
                while(k>=0 && a[i][k]!='*'){
                    suf.pb(a[i][k--]);
                }
            }else{
                int ptr1 = a[i].length()-1;
                int ptr2 = 0;
                while(ptr1>=0 && ptr2<suf.size() && a[i][ptr1]==suf[ptr2]){
                    ptr1--;
                    ptr2++;
                }
                if(ptr1!=0){
                    if(ptr2!=suf.size() && a[i][ptr1]!='*'){
                        flag = false;
                    }else{
                        for(int p = ptr1;p>=0;p--){
                            if(a[i][p]=='*'){
                                break;
                            }
                            suf.pb(a[i][p]);
                        }
                    }
                }
            }
        }
    }
    vector<char> ans;
    for(auto e: pref){
        ans.pb(e);
    }
    for(auto e: a){
        for(auto c: e){
            if(c!='*'){
                ans.pb(c);
            }
        }
    }
    for(int i=suf.size()-1;i>=0;i--){
        ans.pb(suf[i]);
    }
    if(flag){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];            
        }
    }else{
        cout<<'*';
    }
    cout<<'\n';
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}
