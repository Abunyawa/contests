#include<bits/stdc++.h>
using namespace std;


void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"YES"<<endl;
}

string reverse(string s){
    string a = "";
    for(int i=s.length()-1;i>=0;i--){
        a = a+s[i];
    }
    return a;
}
int ctr[26];

int main(){
    int n, m;
    cin>>n>>m;
    set<string> st;
    vector<string> a1;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        st.insert(a);
        a1.push_back(a);
    }
    vector<string> ans;
    map<string,int> ctr;
    for(int i=0;i<n;i++){
        if(st.find(reverse(a1[i]))!=st.end()){
            ans.push_back(a1[i]);
            if(ctr.find(a1[i])==ctr.end()){
                ctr[a1[i]]=1;
            }else{
                ctr[a1[i]]++;
            }
        }
    }
    vector<string> s;
    vector<string> f;
    for(auto j = ctr.begin();j!=ctr.end();j++){
        if(j->first != reverse(j->first) && ctr[j->first]!=0){
            ctr[j->first]--;
            s.push_back(j->first);
            ctr[reverse(j->first)]--;
            f.push_back(reverse(j->first));
        }
    }
    for(auto j = ctr.begin();j!=ctr.end();j++){
        if(j->first == reverse(j->first)){
            s.push_back(j->first);
            break;
        }
    }
    cout<<(s.size()+f.size())*m<<endl;
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
    for(int i=f.size()-1;i>=0;i--){
        cout<<f[i];
    }
    cout<<endl;
    return 0;
}