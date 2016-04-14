/*

*/
#include<iostream>
using namespace std;
typedef long long uii;
uii mul(uii x,uii y){
    cout<<x<<" "<<y<<endl;
    uii a,b;
    b = x%10;
    a = x/10;
    uii c,d;
    d = y%10;
    c = y/10;
    if(a==0 || c==0) return x*y;
    uii f,m,l;
    // cout<<"a ="<<a<<"c =  "<<c<<endl;
    f = mul(a,c);
   // cout<<"f = "<<f<<endl;
    m = mul(a+b,c+d);
   //cout<<"m="<<m<<endl;
    l = mul(b,d);
    m = m - f - l;
   // cout<<"f="<<f<<" m="<<m<<" l="<<l<<endl;
    return 100*f+m*10+l;

}

int main(){
    uii x,y;
    uii ans=1;
    cin>>x>>y;
    for(uii i=0;i<y/2;i++){
        ans*=mul(x,x);
    }
    cout<<ans;
    int f;
    cin>>f;




    return 0;
}
