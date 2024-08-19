#include <iostream>

using namespace std;

int main(){

int age;
    try{
        cout<<"Please enter age "<<endl;
        cin>>age;
        if(age>100 || age<0){
            throw(100);
        }
        
    }
    catch(exception e){

        cout<<"nag "<<e;

    }

    return 0;

}