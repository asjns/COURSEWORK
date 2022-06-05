N,M = [int(x) for x in input().split()]

# read in array (sellers)
A = [int(x) for x in input().split()]

E = set() 
# read in edges (neighbors)
for _ in range(M):
    edge = tuple(int(x) for x in input().split())
    E.add(edge); E.add(edge[::-1])

for _ in range(int(input())):
    Q = [s for s in input().split()]
    if Q[0] == "+":
        edge = tuple(int(x) for x in Q[-2:])
        E.add(edge); E.add(edge[::-1])
    elif Q[0] == "-":
        edge = tuple(int(x) for x in Q[-2:])
        E.remove(edge); E.remove(edge[::-1])
    else:
        cost = 0
        G = {v: [edge[1] for edge in E if edge[0] == v] 
            for v in range(1,N+1)}
        while(len(G)>0):
            buy = max(G, key= lambda x: len(set(G[x])))
            cost += A[buy-1]
            nbrs = G.pop(buy)
            cost += len(nbrs) - (len(G) - len(nbrs))
            for n in nbrs:
                G[n].remove(buy)
        print(cost)


