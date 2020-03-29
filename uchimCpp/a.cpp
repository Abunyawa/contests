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
    vector<int> a(n+1);
    vector<int> pref(n+1);
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i] = pref[i-1] + a[i];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<(pref[r]-pref[l-1])/10<<endl;
    }


    return 0;
}