#include<bits/stdc++.h>
using namespace std;

#define f(x) (3*x - cos(x) - 2)
#define df(x) (3 + sin(x))  // Derivative of f(x)

int main() {
    double a, c, fa, fc;
    int i = 0;
    
    cout << "Enter initial guess a: ";
    cin >> a;
    fa = f(a);

    do {
        c = a - f(a)/df(a);
        fc = f(c);
        
        a = c;
        fa = fc;
        
        i++;
        
        if (fabs(df(c)) < 1e-10) {
            cout << "Warning: Derivative approaching zero." << endl;
            break;
        }
    }
    while(fabs(fc) > 0.00001);
    
    cout << "The root is: " << c << endl;
    return 0;
}