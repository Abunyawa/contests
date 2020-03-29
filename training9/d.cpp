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
    string str;
    int n = str.length();
    int s=0,f=0;
    for(int i=0;i<n;i++){
        if(str[i]!='7'&&str[i]!='4'){
            if(str[i]>'4'){
                str[i]='7';
            }else{
                str[i] = '4';
            }
        }
        if(str[i]=='7'){
            s++;
        }else{
            f++;
        }
    }
    if(f==s){
        cout<<str<<endl;
    }else{
        if(n%2==1){
            str = '4'+str;
        }
        if(s>f){

        }
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