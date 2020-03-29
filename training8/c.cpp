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
    string s;
    cin>>s;
    int l,r,k;
    cin>>l>>r>>k;
    int tot = l-r;
    if(s.length()==1 && (l!=0 || r!=0)){
        cout<<"Impossible"<<endl;
        return;
    }
    if(tot==0){
        s[0] = ('a'+((int)(s[0]-'a')+26*100000-k)%26);
        cout<<s<<endl;
        cout<<1<<endl;
        return;
    }else if(tot<0){
        if(abs(tot)>s.length()-1){
            cout<<"Impossible"<<endl;
            return;
        }else{
            s[abs(tot)]=('a'+((int)(s[abs(tot)]-'a')+26*1000000-k)%26);
            cout<<s<<endl;
            cout<<1<<endl;
            return;
        }
    }else if(tot>0){
        if(abs(tot)>s.length()-1){
            cout<<"Impossible"<<endl;
            return;
        }else{
            s[s.length()-1-abs(tot)]=('a'+((int)(s[s.length()-1-abs(tot)]-'a')+26*1000000-k)%26);
            cout<<s<<endl;
            cout<<s.length()<<endl;
            return;
        }
    }
    
}

int main(){
    abu;
    said;
    int t = 1;
    while(t--){
        solve();
    }

    return 0;
}