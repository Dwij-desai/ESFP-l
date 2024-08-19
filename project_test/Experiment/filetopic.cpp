

#include <iostream>
#include <string>
#include  <fstream>

using namespace  std;

int main() {
    int id;
    string name,Address,salary;

    ofstream ofs;

    ofs.open("data2.txt",ios::out);
    cout<<"Enter employee id name address & salary";
    cin>>id>>name>>Address>>salary;

    ofs<<"Enter employee id name address & salary:"<<endl;
    ofs<<id<<"\t"<<name<<"\t"<<Address<<"\t"<<salary;

    ofs.close();

    ifstream ifs;
    ifs.open("data2.txt",ios::in);

    ifs>>id>>name>>Address>>salary;

    cout<<id<<"\t"<<name<<"\t"<<Address<<"\t"<<salary;

    // string as;
    // while (getline(ifs,as)) {
    //     cout<<as;
    // }

    ifs.close();

    return 0;


}


// int main() {
//
//     ofstream ofs; //output stream
//
//     ofs.open("data.txt",ios::out);
//
//     ofs<<"Hellooo"<<endl;                // This the way to store
//     ofs<<"krisha is gay XD";            // Data in the file(input form)
//
//     ofs.close();
//
//     //Now just to read the file
//
//     ifstream ifs; //input stream
//
//     ifs.open("data.txt",ios::in);     //here we can use same file
//
//     string as;
//     while (getline(ifs,as)) {
//         cout<<as;
//     }
//     ifs.close();
//
//     return 0;
//
// }