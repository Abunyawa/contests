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
const ll MOD = 998244353;
void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}
int findPalLeft(string s,int l,int r){
    int locL = l;
    int ans = 0;
    for(int i=r;i>=l;i--){
        int tmp = i;
        while(s[locL]==s[tmp] && locL<tmp){
            locL++;
            tmp--;
        }

        if(locL>=tmp){
            ans+=i-l+1;
            break;
        }
        locL = l;
    }
    return ans;
}
int findPalRight(string s,int l,int r){
    int locR = r;
    int ans = 0;
    for(int i=l;i<=r;i++){
        int tmp = i;
        while(s[locR]==s[tmp] && locR>tmp){
            locR--;
            tmp++;
        }
        if(locR<=tmp){
            ans+=r-i+1;
            break;
        }
        locR = r;
    }
    return ans;
}

void solve(){
    string st;
    cin>>st;
    int n = st.length();
    int l1=0,r1=n-1;
    while(l1<r1 && st[l1]==st[r1]){
        l1++;
        r1--;
    }
    string s = st.substr(l1,r1-l1+1);
    vector<int> d1 (s.length());
    
    int l=0, r=-1;
    for (int i=0; i<s.length(); ++i) {
        int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
        while (i+k < s.length() && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = k;
        if (i+k-1 > r)
            l = i-k+1, r = i+k-1;
    }
    vector<int> d2 (s.length());
    l=0, r=-1;
    for (int i=0; i<s.length(); ++i) {
        int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
        while (i+k < s.length() && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
        d2[i] = k;
        if (i+k-1 > r)
            l = i-k,  r = i+k-1;
    }
    ll lp = 0;
    ll rp = s.length();
    for(int i=0;i<d1.size();i++){
        if(d1[i] == i+1){
            if(i*2>lp)
                lp = i*2;
        }
        if(d2[i]==i){
            if(2*i-1>lp)
                lp = i*2-1;
        }
        if(d1[i]==s.length()-i){
            if(i-(s.length()-i-1)<rp){
                rp = i-(s.length()-i);
            }
        }
        if(d2[i]==s.length()-i){
            if(s.length()-(s.length()-i)*2<rp)
                rp = s.length()-(s.length()-i)*2;
        }
    }
    /*
    cout<<s<<endl;
    for(int i=0;i<d1.size();i++){
        cout<<d1[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<d2.size();i++){
        cout<<d2[i]<<' ';
    }
    
    cout<<endl;
    cout<<lp<<rp<<endl;
    */
    if(lp+1>s.length()-rp){
        //cout<<lp<<endl;
        for(int i=0;i<l1;i++){
            cout<<st[i];
        }
        for(int i=0;i<=lp;i++){
            cout<<s[i];
        }
        for(int i=r1+1;i<n;i++){
            cout<<st[i];
        }
        cout<<endl;
    }else{
        //cout<<rp<<endl;

        for(int i=0;i<l1;i++){
            cout<<st[i];
        }
        for(int i=rp;i<s.length();i++){
            cout<<s[i];
        }
        for(int i=r1+1;i<n;i++){
            cout<<st[i];
        }
        cout<<endl;
    }

}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}