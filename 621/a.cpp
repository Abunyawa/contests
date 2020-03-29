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
        int n,d;
        cin>>n>>d;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int j = 1;
        while(j<n && d>=j){
            while(a[j]!=0 && d>=j){
                a[0]++;
                a[j]--;
                d-=j;
            }
            j++;
            cout<<d<<endl;
        }
        cout<<a[0]<<endl;
    }


    return 0;
}