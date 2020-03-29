#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%2==1){
        cout<<"NO"<<endl;
    }else{
        vector<pair<double,double> > a(n);
        for(int i=0;i<n;i++){
            double x,y;
            cin>>x>>y;
            a[i] = make_pair(x,y);
        }
        bool flag = true;
        long double xc = (a[0].first + a[n/2].first)/2;
        long double yc = (a[0].second + a[n/2].second)/2;
        for(int i = 1;i+n/2<n;i++){
            long double x1 = (a[i].first + a[i+n/2].first)/2;
            long double y1 = (a[i].second + a[i+n/2].second)/2;
            if(x1!=xc || y1 != yc){
                flag = false;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }



    return 0;
}