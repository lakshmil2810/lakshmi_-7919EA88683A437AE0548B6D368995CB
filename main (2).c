#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
struct Product {
    char name[50];
    float price;
};

// Function to perform a linear search for a target product
int* linear_search_product(struct Product products[], int numProducts, const char* targetProduct) {
    int* indices = NULL;
    int count = 0;

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, targetProduct) == 0) {
            // Found a match, allocate or expand the array of indices
            indices = (int*)realloc(indices, (count + 1) * sizeof(int));
            indices[count] = i;
            count++;
        }
    }

    // If no matches were found, return an empty list
    if (count == 0) {
        free(indices);  // Deallocate memory
        indices = NULL;
    }

    return indices;
}

int main() {
    // Sample list of products
    struct Product products[] = {
        {"Product1", 10.0},
        {"Product2", 15.0},
        {"Product1", 12.0},
        {"Product3", 20.0},
        {"Product4", 25.0}
    };

    int numProducts = sizeof(products) / sizeof(products[0]);

    // Input: Target product name
    const char* targetProduct = "Product1";

    // Perform linear search
    int* indices = linear_search_product(products, numProducts, targetProduct);

    // Output the indices of the target product
    if (indices != NULL) {
        printf("Indices of '%s' in the list: ", targetProduct);
        for (int i = 0; i < numProducts; i++) {
            if (indices[i] != -1) {
                printf("%d ", indices[i]);
            }
        }
        printf("\n");
        free(indices); // Deallocate memory
    } else {
        printf("'%s' not found in the list.\n", targetProduct);
    }

    return 0;
}
