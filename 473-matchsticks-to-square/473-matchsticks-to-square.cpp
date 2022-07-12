class Solution {
public:
    
    bool dfs(vector<int>&grid,int ind,int l,int r,int u,int d){
        if(ind==grid.size()){
            return l==0 and r==0 and u==0 and d==0;
        }
        if(grid[ind]<=l)if(dfs(grid,ind+1,l-grid[ind],r,u,d))return true;
        if(grid[ind]<=r)if(dfs(grid,ind+1,l,r-grid[ind],u,d))return true;
        if(grid[ind]<=u)if(dfs(grid,ind+1,l,r,u-grid[ind],d))return true;
        if(grid[ind]<=d)if(dfs(grid,ind+1,l,r,u,d-grid[ind]))return true;
        return false;
    }
    bool makesquare(vector<int>&grid){
        int sum = accumulate(grid.begin(),grid.end(),0);
        if((sum%4 != 0) or grid.size()<=3)return false;
        int len = sum/4;
        //decreasing order sorting for less function call
        sort(grid.begin(),grid.end(), greater<int>());
        return dfs(grid,0,len,len,len,len);
    }
};