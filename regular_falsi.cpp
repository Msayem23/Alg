#include<bits/stdc++.h>

using namespace std;
#define f(x) (3*x - cos(x) - 2)
int main(){

    float a,b,c,fa,fb,fc;
    int i=0;
    while (true){
        cout<<"Enter the real values for a and b";
        cin>>a>>b;
        fa = f(a);
        fb = f(b);
        if(fa*fb>0){
            cout<<"Incorrect guess. Make sure a and b has opposite sign"<<endl;
        }
        else{
            break;
        }

    }

    do{
        c=(a*fb - b*fa)/(fb - fa);
        fc = f(c);
        if(fa*fc>0){
            a=c;
            fa = fc;
        }
        else {
            b=c;
            fb = fc;
        }
        i++;
    }
    while(fabs(fc)>0.00001);
    cout<<"the root is:"<<c<<endl;
    return 0;
}