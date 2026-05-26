#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

void save_products(const char *filename, Product *arr, size_t count) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Cannot open file");
        exit(1);
    }
    fwrite(arr, sizeof(Product), count, fp);
    fclose(fp);
}

size_t load_products(const char *filename, Product *arr, size_t max_count) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Cannot open file");
        return 0;
    }
    size_t n = fread(arr, sizeof(Product), max_count, fp);
    fclose(fp);
    return n;
}

int main(void) {
    Product products[3] = {
        {1, "Notebook", 2.99},
        {2, "Pencil", 0.49},
        {3, "Backpack", 25.00}
    };

    save_products("store.bin", products, 3);
    printf("Products saved.\n");

    Product loaded[3];
    size_t n = load_products("store.bin", loaded, 3);
    printf("Loaded %zu products:\n", n);

    for (size_t i = 0; i < n; i++)
        printf("%d | %-10s | $%.2f\n", loaded[i].id, loaded[i].name, loaded[i].price);

    return 0;
}
