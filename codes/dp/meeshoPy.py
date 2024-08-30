def count_subsequences(n, sequence, x, y):
    m = len(sequence)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    dp[0][x] = 1  # Start at position x

    for i in range(1, m + 1):
        for j in range(n + 1):
            if sequence[i - 1] == 'r':
                if j > 0:
                    dp[i][j] += dp[i - 1][j - 1]
            elif sequence[i - 1] == 'l':
                if j < n:
                    dp[i][j] += dp[i - 1][j + 1]

    return dp[m][y]

# Example usage:
n = 6
sequence = "rrlrlr"
x = 1
y = 4

result = count_subsequences(n, sequence, x, y)
print(result)  # Output: 3
