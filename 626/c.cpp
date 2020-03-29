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
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<int> st;
    ll ans = 0;
    ll ct = 0;
    for(int i=0;i<n;i++){
        if(st.empty()){
            if(s[i]==')'){
                st.push(i);
            }else{
                st.push(i);
                ct++;
            }
        }else{
            if(s[st.top()]=='(' && s[i]==')'){
                st.pop();
                ct--;
                continue;
            }else{
                if(s[i]==')'){
                    st.push(i);
                }else{
                    st.push(i);
                    ct++;
                }
            }
            if(st.size()==2*ct){

                ll v = st.top();
                ll l;
                while(!st.empty()){
                    l = st.top();
                    st.pop();
                }
                ans+=v-l+1;
                ct = 0;
            }
        }
    }
    if(!st.empty()){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;;
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