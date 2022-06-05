for _ in range(int(input())):
    A, B, C = [int(x) for x in input().split()]
    print(max(B,A+C))
