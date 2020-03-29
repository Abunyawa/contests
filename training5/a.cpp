#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
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
    vector<char> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<char> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]=='0' && b[i]=='1'){
            cout<<'1';
        }else{
            cout<<'0';
        }
    }
    cout<<endl;

    return 0;
}