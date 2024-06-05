#include <stdio.h>

void tower_of_hanoi(int n, int S, int T, int D) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", S, T);
        return;
    }
    tower_of_hanoi(n - 1, S, D, T);
    printf("Move disk %d from %d to %d\n", n, S, T);
    tower_of_hanoi(n - 1, D, T, S);
}

int main() {
    int num_disks;
    printf("enter number of disks:");
    scanf("%d",&num_disks);
    tower_of_hanoi(num_disks, 1, 2, 3);
    return 0;
}