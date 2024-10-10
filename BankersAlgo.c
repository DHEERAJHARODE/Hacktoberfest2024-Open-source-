#include <stdio.h>

#define n 10
#define m 10

int p, r;
int available[m];
int max[n][m];
int allocation[n][m];
int need[n][m];

int Safety_Algorithm() {
    int Work[m], Finish[n];
    
    for (int i = 0; i < r; i++) {
        Work[i] = available[i];
    }

    for (int i = 0; i < p; i++) {
        Finish[i] = 0;
    }

    int safeSequence[n], count = 0;

    while (count < p) {
        int found = 0;
        for (int i = 0; i < p; i++) {
            if (Finish[i] == 0) {
                int j;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > Work[j])
                        break;
                }
                if (j == r) {
                    for (int k = 0; k < r; k++) {
                        Work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    Finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return -1;
        }
    }

    printf("System is in a safe state.");
    printf("\nSafe sequence: ");
    for (int i = 0; i < p - 1; i++) {
        printf("P%d -> ", safeSequence[i]);
    }
    printf("P%d\n", safeSequence[p - 1]);
    return 0;
}

void Resource_Request() {
    int x, request[m];
    
    printf("Enter the process number (index is starting at 0) making request: ");
    scanf("%d", &x);

    printf("Enter the request for each resource:\n");
    for (int i = 0; i < r; i++) {
        scanf("%d", &request[i]);
    }

    for (int i = 0; i < r; i++) {
        if (request[i] > need[x][i] || request[i] > available[i]) {
            printf("Invalid request.\n");
            return;
        }
    }

    for (int i = 0; i < r; i++) {
        available[i] -= request[i];
        allocation[x][i] += request[i];
        need[x][i] -= request[i];
    }

    if (Safety_Algorithm() == -1) {
        for (int i = 0; i < r; i++) {
            available[i] += request[i];
            allocation[x][i] -= request[i];
            need[x][i] += request[i];
        }
        printf("Request denied. System would be in unsafe state.\n");
    }
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    printf("Enter the maximum resource allocation for each x:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the current resource allocation for each x:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("Enter the available instances of each resource:\n");
    for (int i = 0; i < r; i++) {
        scanf("%d", &available[i]);
    }
    Safety_Algorithm();
    Resource_Request();
    return 0;
}
