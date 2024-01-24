/*
O(n^2k)
dp[p][1] - sumy prefiksowe
dp[p][k] = min[0 <= i <= p](max(dp[i][k - 1], dp[su[j = i -> p - 1]tab[j]]))

O(n log(sum(tab)))
binsearch po wyniku
*/