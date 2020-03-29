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
int num[26];
int main(){
    string s;
    cin>>s;
    int n = s.length();
    for(int i = 0;i<n;i++){
        num[(int)(s[i]-'a')]++;
    }
    vector<pair<int,char> > ans;
    for(int i=0;i<26;i++){
        if(num[i]!=0){
            ans.pb(mp(num[i],(char)i+'a'));
        }
    }
    sort(all(ans));
    

    return 0;
}