#include <stdio.h>
#include <time.h>

void bfs(int a[10][10], int n, int source) {
    int s[10], q[10], f = 0, r = -1, t, v;
    for (v = 0; v < n; v++) {
        s[v] = 0;
    }
    q[++r] = source;
    s[source] = 1;
    while (f <= r) {
        t = q[f++];
        printf("%d ", t); // Print the visited node here for BFS traversal
        for (v = 0; v < n; v++) {
            if (a[t][v] == 1 && s[v] == 0) {
                q[++r] = v;
                s[v] = 1;
            }
        }
    }
}

int main() {
    int a[10][10], n, i, j, s;
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the matrix representation:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source city: ");
    scanf("%d", &s);

    starttime = clock();
    printf("The BFS traversal is: ");
    bfs(a, n, s);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
