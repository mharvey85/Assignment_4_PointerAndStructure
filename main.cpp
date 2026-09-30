#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);


int main(){
    //Allocating memory space for 5 items
    Item *item_list = (Item*)malloc(sizeof(Item) * 5);

    //calling functions
    add_item(item_list, 5.00, "19282", "breakfast", "cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 7.35, "12345", "meat", "bacon", 2);

    print_items(item_list, 3);

    free_items(item_list, 3);
  
    return 0;
}


//add_item function adds 5 different items to the array created 
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){
    Item actual_struct = item_list[index];

    item_list[index].price = price;

    //allocating space and assigning given char array to given index in item_list
    item_list[index].sku = (char*)malloc(sizeof(strlen(sku)+1));
    strcpy(item_list[index].sku, sku);

    item_list[index].category = (char*)malloc(sizeof(strlen(category)+1));
    strcpy(item_list[index].category, category);

    item_list[index].name = (char*)malloc(sizeof(strlen(name)+1));
    strcpy(item_list[index].name, name);
}

//free_items function frees the memory you allocated throughout the entire program
void free_items(Item *item_list, int size){
    for(int i = 0; i < size; i++){
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
        item_list[i].price = 0;
    }  
    free(item_list);
    
}

//average_price function calculates the average price of all your items
double average_price(Item *item_list, int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum = sum + (item_list[i].price);
    }
    return sum/(double)size;
}

//print_items function to print all the items to the screen
void print_items(Item *item_list, int size){
    double avg = average_price(item_list, size);
    for(int i = 0; i < size; i++){
        printf("####################\n");
        printf("Item Name: %s\n", item_list[i].name);
        printf("Item sku: %s\n", item_list[i].sku);
        printf("Item category: %s\n", item_list[i].category);
        printf("Item price: %f\n", item_list[i].price);    
    }
    printf("####################\n");
    printf("Average Price: %f\n", avg);
}