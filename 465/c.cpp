#include<bits/stdc++.h>
using namespace std;

double dist(double x1,double y1,double x2,double y2){
    return pow((pow(x1-x2,2)+pow(y1-y2,2)),0.5);
}

int main(){
    double r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    cout.precision(10);
    /*
    y - y1         x - x1  
    ------    =   --------
    y2 - y1        x2 - x1


    */



   if(pow(x1-x2,2) + pow(y1-y2,2) >= r*r){
        cout<<x1<<' '<<y1<<' '<<r<<endl;
   }else{
        if(x1==x2 && y1==y2){
            cout<<x1<<' '<<y1+r/2<<' '<<r/2<<endl;
        }else if(x1==x2){
            double x_1 = x1;
            double x_2 = x1;
            double y_1 = y1 + r;
            double y_2 = y1 - r;
            
            if(dist(x2,y2,x_1,y_1)>dist(x2,y2,x_2,y_2)){
                cout<<(x2+x_1)/2<<' '<<(y2+y_1)/2<<' '<<dist(x2,y2,x_1,y_1)/2<<endl;
            }else{
                cout<<(x2+x_2)/2<<' '<<(y2+y_2)/2<<' '<<dist(x2,y2,x_2,y_2)/2<<endl;
            }

        }else{
            double b = (y2-y1)/(x2-x1);
            double x_1 = pow(r*r/(1+b*b),0.5)+x1;
            double x_2 = -pow(r*r/(1+b*b),0.5)+x1;
            double y_1 = (x_1 - x1)*b + y1;
            double y_2 = (x_2 - x1)*b + y1;

            if(dist(x2,y2,x_1,y_1)>dist(x2,y2,x_2,y_2)){
                cout<<(x2+x_1)/2<<' '<<(y2+y_1)/2<<' '<<dist(x2,y2,x_1,y_1)/2<<endl;
            }else{
                cout<<(x2+x_2)/2<<' '<<(y2+y_2)/2<<' '<<dist(x2,y2,x_2,y_2)/2<<endl;
            }
        }
   }

    return 0;
}