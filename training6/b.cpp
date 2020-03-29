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
double smAll(vector<int> &a,int l, int r){
    double sm = 0;
    for(int i=l;i<=r;i++){
        sm+=a[i];
    }
    return sm;
}

int main(){
    string nm;
    cin>>nm;
    string f;
    cin>>f;
    string s;
    cin>>s;
    string t;
    cin>>t;
    string nm1="";
    string f1="";
    string s1="";
    string t1=""; 
    for(int i=0;i<nm.length();i++){
        if(nm[i]!='(' && nm[i]!=')' && nm[i]!='-' && nm[i]!='+'){
            nm1+=nm[i];
        }
    }
    for(int i=0;i<f.length();i++){
        if(f[i]!='(' && f[i]!=')' && f[i]!='-'&& f[i]!='+'){
            f1+=f[i];
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]!='(' && s[i]!=')' && s[i]!='-' && s[i]!='+'){
            s1+=s[i];
        }
    }
    for(int i=0;i<t.length();i++){
        if(t[i]!='(' && t[i]!=')' && t[i]!='-' && t[i]!='+'){
            t1+=t[i];
        }
    }
    if(nm1.length()==11){
        nm1 = nm1.substr(1);
    }else{
        nm1 = "495" + nm1;
    }
    if(f1.length()==11){
        f1 = f1.substr(1);
    }else{
        f1 = "495" + f1;
    }
    if(s1.length()==11){
        s1 = s1.substr(1);
    }else{
        s1 = "495" + s1;
    }
    if(t1.length()==11){
        t1 = t1.substr(1);
    }else{
        t1 = "495" + t1;
    }
    if(nm1==f1){
        yes();
    }else{
        no();
    }
    if(nm1==s1){
        yes();
    }else{
        no();
    }if(nm1==t1){
        yes();
    }else{
        no();
    }
    return 0;
}