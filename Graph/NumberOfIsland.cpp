/*
Given a 2D grid grid where '1' represents land and '0' represents water, count and return the number of islands.

An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. You may assume water is surrounding the grid (i.e., all the edges are water).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ROW[] = { +1, -1, 0, 0 };
        int COL[] = { 0, 0, +1, -1 };
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == false)
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        auto front = q.front();
                        visited[front.first][front.second] = true;
                        q.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int x = front.first + ROW[k];
                            int y = front.second + COL[k];
                            if (x < 0 || y < 0 || x >= row || y >= col)
                                continue;
                            if (grid[x][y] == 1 && visited[x][y] == false)
                            {
                                q.push({x, y});
                                visited[x][y] = true;
                            }
                        }

                        if (q.empty())
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main()