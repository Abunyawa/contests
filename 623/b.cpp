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
        int a,b,p;
        cin>>a>>b>>p;
        string s;
        cin>>s;
        vector<int> pr(s.length());
        int n = s.length();
        int sm = 0;
        int m;
        for(int i=0;i<n-1;i++){
            if(s[i]=='A'){
                sm+=a;
            }else{
                sm+=b;
            }
            while(s[i]==s[i+1] && i<n-1){
                i++;
            }
        }
        pr[0] = sm;
        int ind = 1;
        while(ind<n){
            while(s[ind]==s[ind-1] && ind<n-1){
                pr[ind] = pr[ind-1];
                ind++;
            }
            int cur;
            if(s[ind-1] == 'A'){
                cur = a;
            }else{
                cur = b;
            }
            pr[ind]=pr[ind-1] - cur;
            ind++;
        }
        pr[n-1] = 0;
        for(int i=0;i<n;i++){
            
            if(pr[i]<=p){
                cout<<i+1<<endl;
                break;
            }
        }
    }

    return 0;
}