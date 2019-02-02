#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    string Name;
    Person(){};
    Person(string name)
    {
        Name=name;
    }
    void Showdata();
};

void Person::Showdata()
{
    cout<<"Name: "<<Name<<endl;
}

class SubmittedProblems
{
    int count;
    public:
    SubmittedProblems(){}
    SubmittedProblems(int count)
    {
        this->count = count;
    }
};

class ContestantProfile : public Person
{
public:
    int Rating;
    int Solved = 0;
    string ID;
    SubmittedProblems count;
    bool Finalist = 0;
    ContestantProfile(){};
    ContestantProfile(string name,int rating,string id,int solved,bool finalist,SubmittedProblems pb):
                                                                             Person(name)
    {
        Rating=rating;
        ID=id;
        Solved=solved;
        count=pb;
        Finalist=finalist;
    }
    void ShowContestantProfile();
    friend int Solved(ContestantProfile student);
    friend bool Status(ContestantProfile student);
};
void ContestantProfile::ShowContestantProfile()
{
    Showdata();
    cout<<"Rating: "<<Rating<<endl;
    cout<<"ID: "<<ID<<endl;
    cout<<"Number Of Problem Solves: "<<Solved<<endl;
    if(Finalist)
        cout<<"ACM World Finalist"<<endl;
}

int Solved(ContestantProfile student)
{
    return student.Solved;
}
bool Status(ContestantProfile student)
{
    return student.Finalist;
};

int main()
{
    SubmittedProblems count1(4);
    SubmittedProblems count2(8);
    SubmittedProblems count3(9);
    SubmittedProblems count4(5);
    ContestantProfile *students[5]=
    {
       new ContestantProfile("Ashikur Rahman",1200,"11708008",110,false,count1),
       new ContestantProfile("Rajib",1100,"11708009",51,false,count2),
       new ContestantProfile("Dolar",1300,"11708010",210,true,count3),
       new ContestantProfile("Showrov",1400,"11708011",214,true,count3),
       new ContestantProfile("Sakib",1200,"11708012",70,false,count4)
    };

    for(int i=0;i<5;i++)
    {

        int x=Solved(*students[i]);

        if((x>=100 && x<=200) || Status(*students[i]))
        {
            students[i]->ShowContestantProfile();
            cout<<"Number of Selected Problems: 1"<<endl;

        }
        else if(x>200)
        {
            students[i]->ShowContestantProfile();
            cout<<"Number of Selected Problems: 2"<<endl;

        }
        else
        {
            students[i]->ShowContestantProfile();
            cout<<"Sorry,Your Problem is not Selected."<<endl;

        }
        cout<<endl;
    }
    cout<<"BPG are selected this profile & problems for their Programming Contest!!!!"<<endl;

    return 0;
}
