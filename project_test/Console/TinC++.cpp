/* Created by dwijd on 4/22/2024    [start of the project to make] */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class  lsin {
private:
    string admin;
    string apassword;
    int i;
public:

    lsin() {}

    void registe() {

        cout<<"Enter the admin name:\t";
        cin>>admin;
        cout<<"Enter the password:\t";
        cin>>apassword;


    }

    void dataStore() {  //This data is sored in file
        ofstream ofs;
        ofs.open("lsinData.txt");

        if(ofs.good()) {
            cout<<"File working";
        }else {
            cout<<"Error found in file loading";
        }
    }

};

int main()
{
    cout<<"Hellooo T";
    return 0;
}

