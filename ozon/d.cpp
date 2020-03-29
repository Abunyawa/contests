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
    int n;
    cin>>n;
    int a,b;
    vi g(n);
    g[0] = 0;
    for(int i=1;i<=n-1;i++){
        cin>>a>>b;
        g[i] = i;
    }
    int ptr=0;
    while(true){
        if(ptr<n-1){
            cout<<"? "<<g[ptr]+1<<' '<<g[ptr+1]+1<<endl;
            cout.flush();
            int w;
            cin>>w;
            if(w==g[ptr]+1 || w==g[ptr+1]+1){
                cout<<"! "<<w<<endl;
                break;
            }else{
                ptr+=2;
            }
        }else{
            cout<<"! "<<g[n]+1<<endl;
            break;
        }
    }

}

int main(){
    abu;
    said;
    solve();
    

    return 0;
}