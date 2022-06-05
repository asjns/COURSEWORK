T = int(input())
for _ in range(T):
    N, K = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    P = []
    for a in A:
        L = [i+1 for i in range(len(P),a)]
        L.append(L.pop(0))
        P.extend(L)
    print(*P)
