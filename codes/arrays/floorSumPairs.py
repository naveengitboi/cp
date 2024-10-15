import math

mod = 1000003

def solve(nums, n):
    final = 0
    for i in range(n):
        deno = nums[i]
        total = 0
        for j in range(n):
            val = math.floor(nums[j]/deno)
            total += (val%mod)

        final += (total%mod)

    return final%mod


t = int(input())
while(t):
    n = int(input())
    nums = list(map(int,input().split()))
    ans = solve(nums, n)
    print(ans)
    t -= 1

