#include <iostream>
#include <string>
#include  <fstream>

using namespace  std;

class employee{
    public:
        int id;
        string name,Address,salary;
};

int main() {

    employee obj[3];

    ofstream ofs;
    
    ofs.open("data2.txt",ios::out);

    for(int i=0; i<3;i++){

        cout<<"Enter employee id name address & salary for object"<<i<<":\t";
        cin>>obj[i].id>>obj[i].name>>obj[i].Address>>obj[i].salary;

        ofs<<"\n Here employee id name address & salary for object"<<i<<":\t"<<endl;
        ofs<<obj[i].id<<"\t"<<obj[i].name<<"\t"<<obj[i].Address<<"\t"<<obj[i].salary;
        
    }

    ofs.close();

    ifstream ifs;
    ifs.open("data2.txt",ios::in);

    string as;
    while (ifs>>as) {
        getline(ifs, as);
        cout<<as;
    }

    ifs.close();

    return 0;


}