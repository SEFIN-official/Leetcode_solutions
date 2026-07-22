class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

        int tm = 0;
        int fresh = 0;
        int rotten = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){

            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;

            q.pop();

            tm=max(tm,time);

            for(int i=0;i<4;i++){

                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n &&
                   nc>=0 && nc<m &&
                   grid[nr][nc]==1 &&
                   visited[nr][nc]==0){

                    visited[nr][nc]=2;
                    rotten++;

                    q.push({{nr,nc},time+1});
                }
            }
        }

        if(rotten!=fresh)
            return -1;

        return tm;
    }
};
