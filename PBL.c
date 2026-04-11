#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
    struct Item* next;
} Item;

Item *inventory = NULL, *cart = NULL;

Item* createItem(int id, const char* name, float price, int quantity) {
    Item* item = (Item*)malloc(sizeof(Item));
    item->id = id;
    strcpy(item->name, name);
    item->price = price;
    item->quantity = quantity;
    item->next = NULL;
    return item;
}

Item* findItem(Item* list, int id) {
    while (list && list->id != id) list = list->next;
    return list;
}

void addItem(Item** list, Item* newItem) {
    newItem->next = *list;
    *list = newItem;
}

void displayItems(Item* list, int showSubtotal) {
    if (!list) {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nID\tName\tPrice\tQuantity");
    if (showSubtotal) printf("\tSubtotal");
    printf("\n----------------------------------------\n");

    float total = 0;
    while (list) {
        printf("%d\t%s\t%.2f\t%d", list->id, list->name, list->price, list->quantity);
        if (showSubtotal) {
            float sub = list->price * list->quantity;
            printf("\t\t%.2f", sub);
            total += sub;
        }
        printf("\n");
        list = list->next;
    }

    if (showSubtotal) {
        printf("----------------------------------------\n");
        printf("Total: $%.2f\n", total);
    }
}

void addToInventory() {
    int id, quantity;
    float price;
    char name[50];

    printf("\nEnter item ID: "); scanf("%d", &id);
    if (findItem(inventory, id)) {
        printf("Item with this ID already exists!\n");
        return;
    }

    printf("Enter item name: "); scanf("%s", name);
    printf("Enter item price: "); scanf("%f", &price);
    printf("Enter item quantity: "); scanf("%d", &quantity);

    addItem(&inventory, createItem(id, name, price, quantity));
    printf("Item added to inventory successfully!\n");
}

void addToCart() {
    if (!inventory) {
        printf("\nInventory is empty!\n");
        return;
    }

    displayItems(inventory, 0);
    int id, qty;
    printf("\nEnter item ID to add to cart: "); scanf("%d", &id);
    Item* inv = findItem(inventory, id);

    if (!inv) {
        printf("Error: Item ID %d not found in inventory!\n", id);
        return;
    }

    if (inv->quantity <= 0) {
        printf("Error: Item '%s' is out of stock and not available for purchase!\n", inv->name);
        return;
    }

    printf("Enter quantity (Available: %d): ", inv->quantity); scanf("%d", &qty);
    if (qty <= 0 || qty > inv->quantity) {
        printf("Invalid quantity!\n");
        return;
    }

    Item* c = findItem(cart, id);
    if (c) c->quantity += qty;
    else addItem(&cart, createItem(id, inv->name, inv->price, qty));

    inv->quantity -= qty;
    printf("Item added to cart successfully!\n");
}

void removeFromCart() {
    if (!cart) {
        printf("\nCart is empty!\n");
        return;
    }

    displayItems(cart, 1);
    int id, qty;
    printf("\nEnter item ID to remove from cart: "); scanf("%d", &id);
    Item *prev = NULL, *curr = cart;

    while (curr && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        printf("Item not found in cart!\n");
        return;
    }

    printf("Enter quantity to remove (In cart: %d): ", curr->quantity); scanf("%d", &qty);
    if (qty <= 0 || qty > curr->quantity) {
        printf("Invalid quantity!\n");
        return;
    }

    if (qty == curr->quantity) {
        if (prev) prev->next = curr->next;
        else cart = curr->next;
        free(curr);
    } else {
        curr->quantity -= qty;
    }

    Item* inv = findItem(inventory, id);
    if (inv) inv->quantity += qty;

    printf("Item removed from cart successfully!\n");
}

void freeList(Item* list) {
    Item* temp;
    while (list) {
        temp = list;
        list = list->next;
        free(temp);
    }
}

int main() {
    addItem(&inventory, createItem(1, "Apple", 0.99, 50));
    addItem(&inventory, createItem(2, "Bread", 2.49, 30));
    addItem(&inventory, createItem(3, "Milk", 1.99, 20));

    // Display inventory as soon as program starts
    printf("\n===============================================\n");
    printf("         WELCOME TO SHOPPING STORE              \n");
    printf("===============================================\n");1
    
    printf("\nCurrent Available Inventory:\n");
    displayItems(inventory, 0);

    int choice;
    while (1) {
        printf("\n1. Add item to inventory");
        printf("\n2. Display inventory");
        printf("\n3. Add item to cart");
        printf("\n4. Remove item from cart");
        printf("\n5. View cart and total");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addToInventory(); break;
            case 2: displayItems(inventory, 0); break;
            case 3: addToCart(); break;
            case 4: removeFromCart(); break;
            case 5: displayItems(cart, 1); break;
            case 6:
                freeList(inventory);
                freeList(cart);
                printf("\nExiting program...\n");
                return 0;
            default: printf("Invalid choice!\n");
        }
    }
}