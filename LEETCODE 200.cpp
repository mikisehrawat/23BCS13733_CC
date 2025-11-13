class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0')continue;
                queue<pair<int,int>>q;
                q.push({i,j});
                count++;
                while(!q.empty()){
                    auto x=q.front();q.pop();
                    int r=x.first; 
                    int c=x.second; 
                    if(r+1<m and grid[r+1][c]=='1'){
                        q.push({r+1,c});
                        grid[r+1][c]='0';
                    }
                    if(r-1>=0 and grid[r-1][c]=='1'){
                        q.push({r-1,c});
                        grid[r-1][c]='0';
                    }
                    if(c+1<n and grid[r][c+1]=='1'){
                        q.push({r,c+1});
                        grid[r][c+1]='0';
                    }
                    if(c-1>=0 and grid[r][c-1]=='1'){
                        q.push({r,c-1});
                        grid[r][c-1]='0';
                    }
                }
            }
        }
        return count;
    }
};