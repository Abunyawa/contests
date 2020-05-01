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
    vector<int> pos(n+1);
    vector<bool> used(n+1,false);
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]] = i;

    }
    bool flag = true;
    int lim = n;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            int num = i;
            int cur = pos[i];
            while(cur<lim-1 && a[cur+1] == num+1){
                used[num] = true;
                num = a[cur+1];
                cur++;
            }
            if(cur!=lim-1){
                flag = false;
                break;
            }else{
                used[num] = true;
                lim = pos[i];
            }
        }
    }
    if(flag){
        yes();
    }else{
        no();
    }
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
