# Lab Assignment 4
We will practice more pointers and structures to become more familiar with their usage.  We will create an array of structures.

# Item Header
Create a file called item.h which creates a structure for storing an item in a grocery store database.  
The members of the struct should be price, SKU, description, and name.  
```
struct _Item
{
  double price;
  char *sku;
  char *name;
  char *category;
};
typedef struct _Item Item;
```

# Functions 
1. Include this item.h file in your main.c file to access the struct.  
2. Create an array of Items by dynamically allocating space for 5 different items - don't fill up the space yet with real values.
3. Make 4 functions
  - void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
  - void free_items(Item *item_list, int size);
  - double average_price(Item *item_list, int size);
  - void print_items(Item *item_list, int size);

add_item: add 5 different items to the array created in step 2.
print_item: print all the items to the screen.
average_price: calculates the average price of all your items.
free_items: frees the memory you allocated throughout the entire program.

# SKU Search 
1. Modify the main function to take command line arguments
2. Assume the user will run the program like: ./main 14512
3. Use the argument given in the command line (14512 in above) as the SKU to search for
4. Find the item in your item list using a while loop and print the item to the screen. If not found, print item not found.  
