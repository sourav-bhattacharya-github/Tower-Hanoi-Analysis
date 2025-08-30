#include <stdio.h>
#include <time.h>

void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) // Base case: only one disk to move
        return;

    // Move (n-1) disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, target);
    // Move the nth disk from source to target
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int disk_sizes;
    clock_t start, end;
    double cpu_time;

    FILE *fp = fopen("hanoi_times.csv", "w");
    if (fp == NULL){
        perror("Error opening file");
        return 1; // exit with error
    }

    fprintf(fp, "Disks,Time(seconds)\n"); // CSV header

    for (disk_sizes = 20; disk_sizes <= 25; disk_sizes++) {
        start = clock();
        towerOfHanoi(disk_sizes, 'A', 'C', 'B');
        end = clock();

        cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        fprintf(fp, "%d,%f\n", disk_sizes, cpu_time);
        printf("Disk Size: %d, Time taken: %f seconds\n", disk_sizes, cpu_time);
    }

    if (fclose(fp) != 0) {
        perror("Error closing file");
        return 1;
    }

    printf("Data successfully written to hanoi_times.csv\n");
    return 0;
}