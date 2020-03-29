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
    string s;
    cin>>s;
    int zeroNum =0 ;
    int oneNum = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            oneNum++;
        }else{
            zeroNum++;
        }
    }
    if(oneNum!=zeroNum){
        cout<<1<<endl;
        cout<<s<<endl;
    }else{
        cout<<2<<endl;
        for(int i=0;i<n-1;i++){
            cout<<s[i];
        }
        cout<<' '<<s[n-1]<<endl;
    }

    return 0;
}