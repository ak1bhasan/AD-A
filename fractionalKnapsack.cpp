/// Time complexity O(n log n)
#include<bits/stdc++.h>
using namespace std;

struct item
{
    int weight;
    int profit;
    double ratioo;
};

bool comp(item item1, item item2)
{
    return item1.ratioo > item2.ratioo;
}

int main()
{
    int n,cap;
    cin >> n >> cap;
    item items[n];
    for(int i = 0; i < n; i++)
    {
        cin >> items[i].profit;
        cin >> items[i].weight;
        items[i].ratioo = (double) items[i].profit / (double) items[i].weight;
    }
    sort(items,items + n,comp);

    double totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        if(items[i].weight < cap)
        {
            totalProfit += items[i].profit;
            cap -= items[i].weight;
        }
        else
        {
            totalProfit += (cap * items[i].ratioo);
            break;
        }
    }
    cout << totalProfit << endl;
}





