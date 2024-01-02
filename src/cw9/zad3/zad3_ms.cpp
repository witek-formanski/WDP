#include <iostream>
#include <map>
#include <set>

#include "fu.cpp"

using namespace std;

enum GroupType
{
    Row = 0,
    Column = 1
};

typedef pair<GroupType, int> *Group;

Group create_row(int y)
{
    Group row = (Group)malloc(sizeof(pair<GroupType, int>));
    row->first = Row;
    row->second = y;
    return row;
}

Group create_column(int x)
{
    Group column = (Group)malloc(sizeof(pair<GroupType, int>));
    column->first = Column;
    column->second = x;
    return column;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> towers;
    set<int> rowsNums;
    set<int> columnsNums;

    for (int i = 0; i < n; i++)
    {
        int row, column;
        cin >> row;
        cin >> column;
        towers.push_back(pair<int, int>(row, column));

        if (rowsNums.find(row) == rowsNums.end())
        {
            rowsNums.insert(row);
        }

        if (columnsNums.find(column) == columnsNums.end())
        {
            columnsNums.insert(column);
        }
    }

    map<int, Group> rows;
    map<int, Group> columns;

    // init find union
    map<Group, find_union<Group>> fus;
    for (int rowNu : rowsNums)
    {
        Group row = create_row(rowNu);
        rows[rowNu] = row;
        fus[row] = create_fu<Group>(row);
    }
    for (int colNu : columnsNums)
    {
        Group col = create_column(colNu);
        columns[colNu] = col;
        fus[col] = create_fu<Group>(col);
    }

    // color the groups
    for (pair<int, int> tower : towers)
    {
        find_union<Group> row = fus[rows[tower.first]];
        find_union<Group> column = fus[columns[tower.second]];
        union_fu(row, column);
    }

    // count colors
    set<find_union<Group>> heads;
    for (auto value : fus)
    {
        find_union<Group> fu = go_up(value.second);
        if (heads.find(fu) == heads.end())
        {
            heads.insert(fu);
        }
    }

    int colorsCount = (int)heads.size();
    cout << colorsCount;

    rowsNums.clear();
    columnsNums.clear();
    heads.clear();
    towers.clear();
}