#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;
// curva de frecuencia at
int _at(double r){
    int at;
    if(r<=0.0916) at=1;
    else if(r<=0.2381) at=2;
    else if(r<=0.4335) at=3;
    else if(r<=0.6288) at=4;
    else if(r<=0.7851) at=5;
    else if(r<=0.8893) at=6;
    else if(r<=0.9487) at=7;
    else if(r<=0.9919) at=8;
    else at=9;
    return at;
}
// curva de frecuencia st
int _st(double r){
    float st;
    st=-4.0733*log(r);
    return st;
}

int main(){
    int simt,i=0,reloj=0,reloj1=0,at_,wt,n;
    float st_,sumwt=0;
    double r;
    srand(time(0)); // semilla
    cout<<"Ingrese tiempo de simulación (minutos): "; cin>>simt;
    do{
        n=rand();
        r=static_cast<double>(n)/RAND_MAX;
        at_=_at(r);
        n=rand();
        r=static_cast<double>(n)/RAND_MAX;
        st_=_st(r);
        reloj+=at_;
        if(reloj>=reloj1){
            reloj1=reloj+st_;
        }
        else{
            wt=reloj1-reloj;
            sumwt+=wt;
            reloj1=reloj+wt+st_;
        }
        i=i+1;
    }while(reloj<=simt);
    float awt=sumwt/i;
    cout<<"\nEl tiempo promedio de espera es: "<<awt;
    return 0;
}