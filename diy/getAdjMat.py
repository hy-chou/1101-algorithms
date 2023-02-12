from sys import argv


def getDec(row):
    x = 0
    for i in range(len(row)):
        x += row[i] * 2**i
    return x


def flip(x):
    if x:
        return 0
    else:
        return 1


def switch(row, i):
    if i < 0 or i >= len(row):
        print('ERROR at switch(): bad i')
        quit()
    else:
        row[i] = flip(row[i])
    if i-1 >= 0:
        row[i-1] = flip(row[i-1])
    if i+1 < len(row):
        row[i+1] = flip(row[i+1])


row = list()
if (len(argv) == 2):
    n = int(argv[1])
    if n == 0:
        row.append(0)
    while (n >= 1):
        r = n % 2
        n = n // 2
        row.append(r)
print(getDec(row))

adj = list()
for i in range(len(row)):
    switch(row, i)
    adj.append(getDec(row))
    switch(row, i)
adj.sort()
print(adj)
