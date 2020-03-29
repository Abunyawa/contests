#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<long,string> a,pair<long,string> b){
    if(a.first>b.first){
        return true;
    }else if(a.first<b.first){
        return false;
    }else{
        return a.second>b.second;
    }
}


int main(){
    int n;
    cin>>n;
    int nl = 0;
    vector<pair<long,string> > s;
    for(int i=0;i<n;i++){
        string a;
        long p;
        cin>>a>>p;
        if(a.length()>nl){
            nl = a.length();
        }
        s.push_back(make_pair(p,a));
    }
    sort(s.begin(),s.end(),cmp);
    int pll = max((int)(log10(n)*2+1),5);
    int scl = (int)log10(s[0].first);

    for(int i=0;i<n;i++){
        
    }

    return 0;
}