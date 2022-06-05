N = int(input())
QALY = 0
for _ in range(N):
    q, y = [float(x) for x in input().split()]  
    QALY += q * y
print(QALY)