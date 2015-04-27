#include <stdio.h>
#include <stdlib.h>

int isValid(int x, int y, int rows, int cols)
{
	if(x<0 || y <0 || x >= rows || y >= cols)
		return 0;
	else
		return 1;
}

int dfs(int x, int y, char **grid,int rows,int cols,int **visited)
{
	if(grid[x][y] != '1')
		return;
	visited[x][y]=1;
	if(isValid(x,y-1,rows,cols)&&!visited[x][y-1])//up
		dfs(x,y-1,grid,rows,cols,visited);

	if(isValid(x,y+1,rows,cols)&&!visited[x][y+1])//down
		dfs(x,y+1,grid,rows,cols,visited);

	if(isValid(x-1,y,rows,cols)&&!visited[x-1][y])//left
		dfs(x-1,y,grid,rows,cols,visited);

	if(isValid(x+1,y,rows,cols)&&!visited[x+1][y])//right
		dfs(x+1,y,grid,rows,cols,visited);
}

int numIslands(char **grid, int numRows, int numColumns) {
	if(grid==NULL)    
		return;
	int count=0;
	int i,j;
	//importand,initlize a Two dimensional dynamic array
	int **visited=(int **)malloc(sizeof(int*)*numRows);
	for(i=0;i<numRows;i++)
		visited[i]=(int*)malloc(sizeof(int)*numColumns);
	for(i=0;i<numRows;i++)
		for(j=0;j<numColumns;j++)
			visited[i][j]=0;
	
	for(i=0;i<numRows;i++)
		for(j=0;j<numColumns;j++)
		{
			if('1'==grid[i][j]&&!visited[i][j])
			{
				++count;
				dfs(i,j,grid,numRows,numColumns,visited);
			}
		}
	
	return count;
}

int main()
{
	//char *grid[]={"11000","11000","00100","00011"};
	char *grid[]={"00000","00000","00000","00000"};
	printf("result:%d\n",numIslands(grid,4,5));
	return 0;
}
