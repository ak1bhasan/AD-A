#include <bits/stdc++.h>

using namespace std;

struct student
{
    int age;
    string name;
    string dept;
    int id;
};

bool cmp(student a, student b)
{
    return a.age > b.age;
}

int main()
{
    int n = 3;

    student students[n];

    students[0].age = 18;
    students[0].name = "Donald Trump";
    students[0].dept = "CSE";
    students[0].id = 1;

    students[1].age = 28;
    students[1].name = "Joe Biden";
    students[1].dept = "EEE";
    students[1].id = 7;

    students[2].age = 40;
    students[2].name = "Dr. Yusuf";
    students[2].dept = "BBA";
    students[2].id = 4;

    sort(students, students + n, cmp);

    //printf("student %s bearing id %d from the dept. of %s is %d years old", s1.name, s1.dept, s1.id, s1.age);
    for (int i=0; i<n; i++)
    {
        cout << students[i].name << " bearing ID "
             << students[i].id << " from the dept. of "
             << students[i].dept << " is "
             << students[i].age
             << " years old." << endl;
    }



}
