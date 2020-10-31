#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define watch(x) (#x)<<" : "<<(x)<<" ";
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;



void solve(){
    string s;
    getline(cin,s);
    bool curS = false;
    int n = s.length();
    vi a;
    int ans = 0;
    int ctrF = 0;
    int ctrS = 0;
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            ans++;
        }else{
            if(s[i]<='z' && s[i]>='a'){
                a.pb(1);
                ctrF++;
            }else{
                a.pb(2);
                ctrS++;
            }
        }
    }
    vi comp;
    vector<bool> is;
    int cur = 1;
    if(a.size()>0){
        for(int i=1;i<a.size();i++){
            if(a[i]!=a[i-1]){
                if(a[i-1]==1){
                    is.pb(false);
                    comp.pb(cur);
                }else{
                    is.pb(true);
                    comp.pb(cur);
                }
                cur = 1;
            }else{
                cur++;
            }
        }
        if(a[a.size()-1]==1){
            is.pb(false);
            comp.pb(cur);
        }else{
            is.pb(true);
            comp.pb(cur);
        }
        int ans1 = ans;
        int ans2 = ans+2;
        vi ansLeft[comp.size();
        
        for(int i=0;i<comp.size();i++){
            if(is[i]==curS){
                ans1+=comp[i];
            }else{
                if(i!=comp.size()-1){
                    if(comp[i]*2<4+comp[i]){
                        ans1+=comp[i]*2;
                    }else{
                        ans1+=2+comp[i]+2;
                    }
                }else{
                    if(comp[i]*2<2+comp[i]){
                        ans1+=comp[i]*2;
                    }else{
                        ans1+=2+comp[i];
                    }
                }
            }
        }
        
        curS = !curS;
        for(int i=0;i<comp.size();i++){
            if(is[i]==curS){
                ans2+=comp[i];
            }else{
                if(i!=comp.size()-1){
                    if(comp[i]*2<4+comp[i]){
                        ans2+=comp[i]*2;
                    }else{
                        ans2+=2+comp[i]+2;
                    }
                }else{
                    if(comp[i]*2<2+comp[i]){
                        ans2+=comp[i]*2;
                    }else{
                        ans2+=comp[i]+2;
                    }
                }
            }
        }
        
        cout<<min(ans1,ans2)<<'\n';
        return;
    }
    cout<<ans<<'\n';


}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
