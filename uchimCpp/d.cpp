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
int k[10];

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            for(int j=0;j<10;j++){
                if(k[j]==0){
                    k[j] = 1;
                    break;
                }
            }
        }else if(s[i]=='R'){
            for(int j=9;j>=0;j--){
                if(k[j]==0){
                    k[j] = 1;
                    break;
                }
            }
        }else{
            k[(int)(s[i]-'0')]=0;
        }
    }
    for(int i=0;i<10;i++){
        cout<<k[i];
    }
    cout<<endl;
    return 0;
}