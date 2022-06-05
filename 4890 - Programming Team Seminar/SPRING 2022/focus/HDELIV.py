from collections import deque

for _ in range(int(input())):
    n, m = [int(x) for x in input().split()]
    
    graph = {i: set() for i in range(n)}
    
    for _ in range(m):
        x, y = [int(x) for x in input().split()]
        graph[x].add(y)
        graph[y].add(x)
                
    Q = int(input())
    for _ in range(Q):
  
        queue = deque()
        visited = [False for x in range(n)]
        
        A,B = [int(x) for x in input().split()]
        
        if A == B:
            print("YO")
        else:
            def dijkstra(A,B):
        
                visited[A] = True
                queue.append(A)
                
                while len(queue):
                    X = queue.popleft()
                    for Y in graph[X]:
                        if Y == B:
                            return("YO")
                        elif not visited[Y]:
                            visited[Y] = True
                            queue.append(Y)
                
                return("NO")
            
            print(dijkstra(A,B))
                
        