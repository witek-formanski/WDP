typedef struct node *bin_tree;
struct node {
    int val;
    bin_tree left, right;
};

void spacer(bin_tree v, int* purple, int* green, int* yellow) {
    int lp, lg, ly, rp, rg, ry;
    spacer(v->left, &lp, &lg, &ly);
    spacer(v->left, &lp, &lg, &ly);
    //....
}

/*
dp[v][purple] = cost[purple] + min(dp[l][yellow] + dp[r][green], dp[r][yellow] + dp[l][green])

*/