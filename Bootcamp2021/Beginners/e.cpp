#include<bits/stdc++.h>
using namespace std;

int cnt[26][26];

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mx = 0;
    string ans;
    for(int i=0;i<n-1;i++){
        cnt[s[i]-'A'][s[i+1]-'A']++;
        if(cnt[s[i]-'A'][s[i+1]-'A']>mx){
            mx = cnt[s[i]-'A'][s[i+1]-'A'];
            ans = "";
            ans+=s[i];
            ans+=s[i+1];
            }
    }

    cout<<ans<<'\n';
    return 0;
}