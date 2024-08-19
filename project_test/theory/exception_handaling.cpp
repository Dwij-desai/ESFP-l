#include <iostream>

using namespace std;

int main(){

    int a,b,c,x;

    cout<<"Enter two number : ";
    cin>>a>>b;

    x=a-b;
    try{
        if (x!=0)
        {
            cout<<"Result (a/x)= "<<a/x<<endl;
        }else
        {
            throw(x);
        }
        
    }
    catch(int e){

        cout<<"nag "<<e;

    }

    return 0;

}