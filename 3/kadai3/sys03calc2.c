#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item {
  char id;
  int price;
  char name[16];
  char created_day[16];
};

void setitem(struct item *item, char id, int price, char *name, char *created_day){
  item->id = id;
  item->price = price;
  strncpy(item->name, name, sizeof(item->name));
  strncpy(item->created_day, created_day, sizeof(item->created_day));
}

int getprice(struct item item){
  return(item.price);
}

void dumpitem(struct item item){
  printf("ID: %d, Price: %d, Name: %s, CreatedDay: %s\n", item.id, item.price, item.name, item.created_day);
}

int main(int argc, char **argv){
  int i, total = 0;
  struct item item[3];

  if(argc != 4){
    printf("Usage: %s num_orange num_apple num_melon\n", argv[0]);
    exit(1);
  }

  setitem(&(item[0]), 1, 100, "orange", "2014/11/6");
  setitem(&(item[1]), 2, 300, "apple", "2014/11/7");
  setitem(&(item[2]), 3, 500, "melon", "2014/11/8");

  for(i = 0; i < 3; i++){
    dumpitem(item[i]);
    total += getprice(item[i]) * atoi(argv[i+1]);
  }

  printf("total price: %d\n", total);

  return(0);
}
