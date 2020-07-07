n_inputs = int(input())
for i in range(n_inputs):
    n, s = input().strip().split(" ")
    n = int(n)
    s = int(s)
    nums = [int(v) for v in input().strip().split(" ")]

    solution = -1
    for j in range(0, n):
        summ = 0
        for r in range(j, n):
            summ += nums[r]
            if summ == s:
                solution = "{} {}".format(j+1, r+1)
            if summ > s:
                break

        if solution != -1:
            break
    print(solution)
