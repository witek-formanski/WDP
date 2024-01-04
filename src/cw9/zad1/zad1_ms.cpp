#include <iostream>

#include "fu.cpp"

using namespace std;

int main()
{
    int n;
    cin >> n;

    find_union<int> *fus = new find_union<int>[n];
    for (int i = 0; i < n; i++)
        fus[i] = create_fu(i);

    int cyclesCount = 0;

    for (int i = 0; i < n; i++)
    {
        int piggyId;
        cin >> piggyId;

        if (equivalent(fus[i], fus[piggyId]))
        {
            cyclesCount++;
        }
        else
            union_fu(fus[i], fus[piggyId]);
    }

    cout << cyclesCount << endl;
}