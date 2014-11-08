#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item {
  char id;
  int price;
  char name[16];
};

void setitem(struct item *item, char id, int price, char *name){
  item->id = id;
  item->price = price;
  strncpy(item->name, name, sizeof(item->name));
}

int getprice(struct item item){
  return(item.price);
}

void dumpitem(struct item item){
  printf("ID: %d, Price: %d, Name: %s\n", item.id, item.price, item.name);
}

int main(int argc, char **argv){
  int i, total = 0;
  struct item item[3];

  if(argc != 4){
    printf("Usage: %s num_orange num_apple num_melon\n", argv[0]);
    exit(1);
  }

  setitem(&(item[0]), 1, 100, "orange");
  setitem(&(item[1]), 2, 300, "apple");
  setitem(&(item[2]), 3, 500, "melon");

  for(i = 0; i < 3; i++){
    dumpitem(item[i]);
    total += getprice(item[i]) * atoi(argv[i+1]);
  }

  printf("total price: %d\n", total);

  return(0);
}
