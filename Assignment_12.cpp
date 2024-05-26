#include<bits/stdc++.h>
using namespace std;
#define SIZE 10
class Student
{
    int roll;
    char name[20];
public:
    Student()
    {
        strcpy(name, "");
        roll = 0;
    }
    void getDetails()
    {
        cout<<"Enter roll no.: ";
        cin>>roll;
        cout<<"Enter name: ";
        cin>>name;
    }
    void showDetails()
    {
        cout<<"===================================="<<endl;
        cout<<"Roll no.: "<<roll<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"===================================="<<endl;
    }
    friend class DAF;
};
class DAF
{
    Student s;
public:
    void init()
    {
        ifstream obj1;
        obj1.read("datafile1.dat", ios::in | ios::binary);
        if(!obj1)
        {
            cout<<"Creating file..."<<endl;
            ofstream obj2;
            Student dummy;
            obj2.open("datafile1.dat", ios::binary);
            for(int i=0 ; i<SIZE ; i++)
                obj2.write((char *)&dummy, sizeof(Student));
            obj2.close();
        }
        else
        {
            obj1.close();
        }
    }
    int getHash(int roll)
    {
        return roll%10;
    }
    void read()
    {
        int roll = 0;
        cout<<"Enter roll no.: ";
        cin>>roll;
        int hash = getHash(roll);
        ifstream obj;
        obj.open("datafile1.dat", ios::in | ios::binary);
        obj.seekg(sizeof(Student) * hash, ios::beg);
        obj.read((char *)&s, sizeof(Student));
        if(s.roll == roll)
            s.showDetails();
        else
            cout<<"Not found!";
        obj.close();
    }
    void write()
    {
        s.getDetails();
        fstream obj;
        obj.open("datafile1.dat", ios::in | ios::out | ios::binary);
        obj.seekp(sizeof(Student) * getHash(s.roll), ios::beg);
        obj.write((char *)&s, sizeof(Student));
        obj.close();
    }
    void delet()
    {
        cout<<"Enter roll no.: ";
        int roll = 0;
        cin>>roll;
        Student dummy;
        int hash = getHash(roll);
        ofstream obj;
        obj.open("datafile1.dat", ios::app | ios::binary);
        obj.seekp(sizeof(Student) * hash, ios::beg);
        obj.write((char *)&s, sizeof(Student));
        cout<<"Deleted!"<<endl;
        obj.close();
    }
};
int main()
{
    DAF d;
    d.init();
    d.write();
    d.write();
    d.read();
    d.delet();
    return 0;
}
