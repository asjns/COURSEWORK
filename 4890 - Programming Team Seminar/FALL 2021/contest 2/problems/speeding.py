n = int(input())

t1, d1 = [int(x) for x in input().split()]
t2, d2, v = 0, 0, 0

for _ in range(n-1):
    t2, d2 = t1, d1
    t1, d1 = [int(x) for x in input().split()]
    v = max(v, int((d2-d1)/(t2-t1)))
    
print(v)