#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ofstream ofs("Data5.txt");

    int pos;
    pos = ofs.tellp();

    cout<<"current cursor potion ="<<pos;

    ofs<<"Wellcome to ESFp-II";
    ofs.seekp(5,ios::cur);
    ofs.close();

    ofstream ifs("Data5.txt");
    string s;
    ifs.seekp(5,ios::cur);

    while (getline(ifs,s))
    {
        cout<<s;
    }

    return 0;
}
