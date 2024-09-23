#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
void pageReplacementAlgo(queue<int> pages, int frame)
{
    cout << "pages\t";
    int Frames[frame];
    for (int i = 0; i < frame; i++)
    {
        cout << "frame " << i + 1 << "\t";
        Frames[i] = -1;
    }
    cout << "status" << endl;
    int index = -1;
    int hits = 0;
    int faults = 0;
    while (not pages.empty())
    {
        int current = pages.front();
        pages.pop();
        bool flag = false;
        for (int i = 0; i < frame; i++)
        {
            if (current == Frames[i])
            {
                hits++;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << current << "\t";
            for (int i = 0; i < frame; i++)
            {
                cout << Frames[i] << "\t";
            }
            cout << "Hits" << endl;
        }
        else
        {
            faults++;
            index = (index + 1) % frame;
            Frames[index] = current;
            cout << current << "\t";
            for (int i = 0; i < frame; i++)
            {
                cout << Frames[i] << "\t";
            }
            cout << "faults" << endl;
        }
    }
    cout << "\nTotal Hits: " << hits << endl;
    cout << "Total Faults: " << faults << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    queue<int> pages;
    while (1)
    {
        cout << "enter the page( negative for exitting) " << endl;
        int page;
        cin >> page;
        if (page < 0)
        {
            break;
        }
        pages.push(page);
    }
    cout << "How many frames do you want to give??" << endl;
    int frame;
    cin >> frame;
    pageReplacementAlgo(pages, frame);
    return EXIT_SUCCESS;
}