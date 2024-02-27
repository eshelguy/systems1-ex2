#include <stdio.h>

#define NUM_ITEMS 5
#define MAX_WEIGHT 20

int knapSack (const int weights[], const int values[], int selected_bool[]) {
    int values_by_weight[MAX_WEIGHT + 1] = {0}; // Array to store the maximum value for each weight
    int included[NUM_ITEMS][MAX_WEIGHT + 1] = {0}; // Array to track which items are included at each weight

    for (int i = 0; i < NUM_ITEMS; i++) {
        for (int w = MAX_WEIGHT; w >= weights[i]; w--) {
            if (values_by_weight[w] < values_by_weight[w - weights[i]] + values[i]) {
                values_by_weight[w] = values_by_weight[w - weights[i]] + values[i];
                included[i][w] = 1; // Item i is included at weight w
            }
        }
    }

    // Determine which items were selected
    int w = MAX_WEIGHT;
    for (int i = NUM_ITEMS - 1; i >= 0; i--) {
        if (included[i][w]) {
            selected_bool[i] = 1; // Item i was selected
            w -= weights[i];
        }
    }

    return values_by_weight[MAX_WEIGHT]; // Return the maximum value for the maximum weight
}

int main() {
    char names[NUM_ITEMS] = {0};
    int values[NUM_ITEMS] = {0};
    int weights[NUM_ITEMS] = {0};

    for (int i = 0; i < NUM_ITEMS; i++) {
        scanf(" %c %d %d", &names[i], &values[i], &weights[i]);
    }

    int selected[NUM_ITEMS] = {0};
    int maxValue = knapSack(weights, values, selected);

    printf("Maximum profit: %d\n", maxValue);
    printf("Selected items:");
    for (int i = 0; i < NUM_ITEMS; i++) {
        if (selected[i]) {
            printf(" %c", names[i]);
        }
    }

    return 0;
}
