T = int(input())
for _ in range(T):
    N = int(input())
    hor = set()
    ver = set()
    for _ in range(N):
        x, y = input().split()
        hor.add(int(x))
        ver.add(int(y))
    print(len(hor) + len(ver))
    