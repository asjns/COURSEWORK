rows = []
columns = []
new = []

R, C = [int(x) for x in input().split()]
for _ in range(R):
    rows.append(input())

for i in range(C):
    col = ""
    for j in rows:
        col += j[i]
    columns.append(col)
    
def check_cols():
    global new
    return len(set(new)) == len(new) and len(new[0]) > 0
    
def remove_top():
    global columns, new
    new = [c[1:] for c in columns]

while True:
    remove_top()
    if check_cols():
        columns = new
    else:
        break
    
print(R - len(columns[0]))