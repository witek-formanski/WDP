#include <iostream>

#include "fu.cpp"

using namespace std;

vector<vector<int>> groups(const vector<vector<bool>> phoneNumbers)
{
    int n = (int)phoneNumbers.size();
    vector<find_union<int>> fus(n);
    for (int i = 0; i < n; i++)
        fus[i] = create_fu(i);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (!phoneNumbers[i][j])
            {
                if (!equivalent(fus[i], fus[j]))
                {
                    union_fu(fus[i], fus[j]);
                }
            }
        }
    }

    vector<bool> wasPrinted(n, false);
    vector<vector<int>> groups;
    for (int i = 0; i < n; i++)
    {
        if (wasPrinted[i])
            continue;
        find_union<int> current = fus[i];
        vector<int> group;
        for (int worker : elements(current))
        {
            wasPrinted[worker] = true;
            int workerNo = worker+1;
            group.push_back(workerNo);
        }
        groups.push_back(group);
    }

    for (int i = 0; i < n; i++)
    {
        free(fus[i]);
    }
    fus.clear();

    return groups;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<bool>> phoneNumbers(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int b;
            cin >> b;
            phoneNumbers[i][j] = (bool)b;
        }
    }

    vector<vector<int>> gr = groups(phoneNumbers);
    for (vector<int> group : gr)
    {
        for (int c : group)
        {
            cout << c << " ";
        }
        cout << endl;
        group.clear();
    }
    gr.clear();

    for (vector<bool> row : phoneNumbers)
    {
        row.clear();
    }
    phoneNumbers.clear();
    return 0;
}