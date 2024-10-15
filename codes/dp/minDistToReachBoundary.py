directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

n, m = list(map(int, input().split()))
grid = []
ans = [float('inf')]

def dfs(i, j, grid, visited, dist, ans):
    if (i == n-1 or i == 0 or j == 0 or j == m-1) and grid[i][j] != 1:
      ans[0] = min(dist, ans[0])
      return 
    if i> n or i< 0 or j > m or j<0 or grid[i][j] == 1 or visited[i][j]:
        return 
    for k in range(4):
        visited[i][j] = True
        deltaI= i + directions[k][0]
        deltaJ = j + directions[k][1]
        dfs(deltaI, deltaJ, grid, visited, dist + 1, ans)
        visited[i][j] = False
    return 


for i in range(n):
    ll = list(map(int, input().split()))
    grid.append(ll)

for i in range(n):
    for j in range(m):
        if(grid[i][j] == 2):
            visited = [[False for _ in range(m)] for _ in range(n)]
            dfs(i, j, grid, visited,0, ans)
            if(ans[0] != float('inf')):
              print(ans[0])
            else:
              print(-1)
            break



