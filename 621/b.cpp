#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        long long x;
        cin>>x;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(all(a));
        if(x>=a[n-1]){
            if(x%a[n-1]==0){
                cout<<x/a[n-1]<<endl;
            }else{
                cout<<x/a[n-1]+1<<endl;
            }   
        }else{
            int ans = 2;
            for(int i=0;i<n;i++){
                if(a[i]==x){
                    ans = 1;
                }
            }
            cout<<ans<<endl;
        }
        
    }


    return 0;
}