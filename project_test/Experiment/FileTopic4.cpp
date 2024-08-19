//
// Created by dwijd on 4/30/2024.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

//      Topic:- tellg();

    // ofstream ofs("data4.txt");
    // ofs<<"This is the example for tellg fution in file handing";
    // ofs.close();

    /*ifstream ifs("data4.txt");

    int curpos = ifs.tellg();
    cout<<endl<<"current cursor or byte postion[tellg()] = "<<curpos<<endl;

    curpos = curpos+10;

    cout<<"Updated cursor or byte postion[tellg()] = "<<curpos<<endl;

    ifs.close();

       Topic:- seekg();
    sintax :- sekkg(offset,direction)
              seek(offset) --> to fix the offset

    consecpt : beg | ios::beg
*/

    ofstream ofs("data4.txt");
    ofs<<"This is the example for tellg fution in file handing";
    ofs.close();

     ifstream ifs("data4.txt"); //--> this for refreance if you are using only seekg

    string s,s2;
    cout<<"This is orignal text"<<endl;
    while (getline(ifs , s)) {
        cout<<endl<<s;
    }

    int curpos = ifs.tellg();
    cout<<endl<<"current cursor or byte postion[seekg()] = "<<curpos<<endl;
        ifs.seekg(5,ios::cur);

        cout<<endl<<endl<<"This is Updated text"<<endl<<endl;
        while (getline(ifs , s2)) {
            cout<<s2;
        }


    // cout<<"Helloooo";

    return 0;

}
