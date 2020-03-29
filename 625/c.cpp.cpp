#include<bits/stdc++.h>
using namespace std;
long long ctr[800200];

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        a[i] = (int)(c-'a');
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl
        
        ;
    }
    return 0;
}

/*
bacabcad
21312314


*/