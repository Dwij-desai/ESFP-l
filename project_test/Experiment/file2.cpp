//
// Created by dwijd on 4/26/2024.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    ofstream file("data3.bin",ios::binary);

    string p="Hello"; //nisarg wanted::fuck you
    string q="C++";

    file.write((char*)&p,sizeof(p));
    file.write((char*)&q,sizeof(q));
    file.close();

    ifstream ifs;
    ifs.open("data3.bin",ios::binary);

    string a;
    string b;

    ifs.read((char *)&a,sizeof(a));
    ifs.read((char *)&b,sizeof(b));

    cout<<a<<"\t"<<b;

    cout<<endl;

    ifs.close();


    cout<<"*** File exacuted ***";

    return 0;
}