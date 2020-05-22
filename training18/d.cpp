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
int poses[2000];

void solve(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        poses[min(a,b)]++;
        poses[max(a,b)+1]--;
    }
    int cur = 0;
    for(int i=0;i<=1000;i++){
        cur+=poses[i];
        poses[i] = cur;
    }
    int d = 2000;
    for(int i=0;i<=1000;i++){
        if(poses[i]==n){
            if(abs(x-i)<d){
                d = abs(x-i);
            }
        }
    }
    if(d==2000){
        cout<<-1<<'\n';
    }else{
        cout<<d<<'\n';
    }
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
