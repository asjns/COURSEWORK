import re

n = input()

def subfinder(mylist, pattern):
    l = list(filter(lambda x: x in pattern, mylist))
    return len(l) != 0

def transpose(l1):
    l2 =[[row[i] for row in l1] for i in range(len(l1[0]))]
    return l2

def check_horizontal(grid):
    for i in grid:
        b_ct = i.count('B')
        w_ct = i.count('W')
        if b_ct != w_ct:
            print('0')
            exit()

        if re.search('\'B\', \'B\', \'B\'' , str(i).strip('[').strip(']')) or re.search('\'W\', \'W\', \'W\'' , str(i).strip('[').strip(']')):
            print('0')
            exit()

grid = []

for i in range(int(n)):
    inp = input()
    grid.append([char for char in inp])

check_horizontal(grid)

grid = transpose(grid,)

check_horizontal(grid)

print('1')
