def func(num):
    global numRuns
    if num % 2 == 0:
        num /= 2
    elif num % 2 == 1:
        num = 3 * num + 1
    if num != 1:
        numRuns += 1
        if numRuns > 1000:
            numRuns = 0
        func(num)

for a in range(1000000000000000000000000000000):
    numRuns = 0
    a += 1
    func(a)