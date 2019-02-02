#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    string Name;
    string Department;
    string ID;
    int Batch;
    int Students_scale;

    Student(){};
    Student(string name,string department,string id,int batch,int point)
    {
        Name=name;
        Department=department;
        ID=id;
        Batch=batch;
        Students_scale=point;
    }

    void ShowStudent();
};

void Student::ShowStudent()
{
    cout<<"Name : "<<Name<<endl;
    cout<<"Department of"<<" "<<Department<<endl;
    cout<<"Batch : "<<Batch<<endl;
    cout<<"ID : "<<ID<<endl;
    cout<<"He gives his opinion on the scale of point"<<":- "<<Students_scale<<endl<<endl;
}

class Teacher : public Student
{
public:
    string Teacher_name;
    string Title;
    int Mark;

    Teacher(){};
    Teacher(string t_name,string title,int mark,string name,string dept,string id,int batch,int point):
                                                             Student(name,dept,id,batch,point)
    {
        Teacher_name=t_name;
        Title=title;
        Mark=mark;
    }

    void ShowTeacher();
};


void Teacher::ShowTeacher()
{
    cout<<"Name :"<<Teacher_name<<endl;
    cout<<Title<<","<<"Department of CSE"<<endl;
    cout<<"Marks :"<<Mark<<endl<<endl;
}

class Score
{
public:
    int Total_Score();
};

int Score::Total_Score()
{
    int s[6]={0};
    Teacher *obj[6]=
    {
        new Teacher("Kamal Hossain Chowdhury","Chairman",5,"Showrov","CSE","11708008",9,5),
        new Teacher("Mahmudul Hasan Raju","Assistant Professor",4,"Atik","CSE","11708009",9,2),
        new Teacher("Hasan Hafizur Rahman","Assistant Professor",3,"Muhit","CSE","11708010",10,4),
        new Teacher("Partha Chakrobarthy","Assistant Professor",5,"Anik","CSE","11708011",11,4),
        new Teacher("Eva","Lecturer",4,"Ovi","CSE","11708012",8,4)
    };

    for(int i=0;i<5;i++)
        obj[i]->ShowTeacher();

    for(int i=0;i<5;i++)
    {
        s[i]=obj[i]->Students_scale+obj[i]->Mark;
        obj[i]->ShowStudent();
    }

    int max=s[0];
    int m=1;
    for(int i=1;i<5;i++)
    {
        if(max<s[i])
        {
            max=s[i];
            m=m+i;
        }
    }

    return m;

}

class Elected_members:public Score
{
    string Name;
    string Rank;
    string ID;
    int Batch;
public:
    Elected_members(){};
    Elected_members(string name,string Rank,int batch,string id)
    {
        this->Name=name;
        this->Rank=Rank;
        this->Batch=batch;
        this->ID=id;
    }

    void Show_Best_society_member();
};

void Elected_members::Show_Best_society_member()
{
    cout<<"Finally the Best CSE society member is........."<<endl;
    cout<<endl;
    cout<<"Name: "<<Name<<", "<<"Department of CSE"<<endl;
    cout<<"Rank: "<<Rank<<endl;
    cout<<"Batch: "<<Batch<<endl;
    cout<<"ID: "<<ID<<endl;
    cout<<"Total Score: 10"<<endl;
}

int main()
{
    Elected_members *Detail[6]=
    {
        new Elected_members("Dipto Brotho Das","General Secretary",7,"11408030"),
        new Elected_members("Jawad Shafi","Assistant General Secretary",8,"11408020"),
        new Elected_members("Kawser Ahmed","member",9,"11408031"),
        new Elected_members("Mahim Mossarrof","member",9,"11408032"),
        new Elected_members("Chadon","General Secretary",9,"11408035"),

    };

    Score obj;

    int x=obj.Total_Score();

    x--;
    cout<<endl<<endl;

    for(int i=0;i<5;i++)
    {
        if(x==i)
        {
            Detail[i]->Show_Best_society_member();
        }
    }

    return 0;
}
