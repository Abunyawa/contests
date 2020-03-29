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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=n-1;
    vector<char> ans;
    int lastNum = 0;

    while(l<=r){
        if(!ans.empty()){
            if(a[l]<lastNum && a[r]<lastNum){
                break;
            }
        }
        if(a[l]>lastNum && a[r]>lastNum)
            if(a[l]<=a[r]){
                ans.pb('L');
                lastNum = a[l++];
            }else{
                ans.pb('R');
                lastNum = a[r--];
            }
        else{
            if(a[l]>=a[r]){
                ans.pb('L');
                lastNum = a[l++];
            }else{
                ans.pb('R');
                lastNum = a[r--];
            }
        }
        
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}