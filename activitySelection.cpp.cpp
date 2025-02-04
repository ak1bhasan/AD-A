//
//#include <bits/stdc++.h>
//using namespace std;
//
//struct activity
//{
//    int start;
//    int finish;
//};
//
//bool comp(activity a, activity b)
//{
//    return a.finish < b.finish;
//}
//
//int main()
//{
//    int n = 6;
//    activity activities[n];
//
//    activities[0].start = 1;
//    activities[0].finish = 4;
//    activities[1].start = 1;
//    activities[1].finish = 2;
//    activities[2].start = 3;
//    activities[2].finish = 6;
//    activities[3].start = 2;
//    activities[3].finish = 3;
//    activities[4].start = 3;
//    activities[4].finish = 5;
//    activities[5].start = 5;
//    activities[5].finish = 6;
//
//    sort(activities, activities+n, comp);
//
//    cout << "{" << activities[0].start
//         << "," << activities[0].finish << "}" << endl;
//
//    int currentFinish = activities[0].finish;
//
//    for (int i=1; i<n; i++)
//    {
//        if (currentFinish <= activities[i].start)
//        {
//            cout << "{" << activities[i].start << "," << activities[i].finish << "}" << endl;
//            currentFinish = activities[i].finish;
//        }
//    }
//}

#include<bits/stdc++.h>
using namespace std;

struct activity
{
    int start,finish;
};

bool comp(activity a,activity b)
{
    return a.finish < b.finish;
}

int main()
{
    int n = 6;
    activity activities[n];

    activities[0].start = 1; activities[0].finish = 4;
    activities[1].start = 1; activities[1].finish = 2;
    activities[2].start = 3; activities[2].finish = 6;
    activities[3].start = 2; activities[3].finish = 3;
    activities[4].start = 3; activities[4].finish = 5;
    activities[5].start = 5; activities[5].finish = 6;

    sort(activities, activities+n, comp);
    cout << "{" << activities[0].start
         << "," << activities[0].finish << "}" << endl;

    int currentFinish = activities[0].finish;

    for(int i = 1; i < n; i++)
    {
        if(currentFinish <= activities[i].start)
        {
            cout << "{" << activities[i].start
            << "," << activities[i].finish << "}" << endl;
            currentFinish = activities[i].finish;
        }
    }
}
