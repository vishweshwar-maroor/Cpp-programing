int row = v.size();
int col = v[0].size();
vector<vector<int>> tv(col, vector<int>(row));
for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
    {
        tv[j][i] = v[i][j];
    }
}
return tv;