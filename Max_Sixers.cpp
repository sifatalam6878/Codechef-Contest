#include<iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int mx_sixe = 0;
    for (int s = 0; s <= 100; ++s)
    {
        int rem_runs = x - 6 * s;
        int rem_ball = 100 - s;
        if (rem_runs >= 0 && rem_runs <= 4 * rem_ball)
        {
            mx_sixe = s;
        }
    }
    cout << mx_sixe << endl;
    return 0;
}