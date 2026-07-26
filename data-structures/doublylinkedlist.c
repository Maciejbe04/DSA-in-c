#include<stdio.h>
#include<stdlib.h>


struct Node{

  int value;
  struct Node *next;
  struct Node *prev;

};

struct Node* mymalloc(){
  

  return (struct Node*)malloc(sizeof(struct Node));
}


void delete(struct Node *deleted){

  struct Node *before_deleted = deleted->prev;
  struct Node *after_deleted = deleted->next;


  if(before_deleted == NULL){
    after_deleted->prev = NULL;
  }
  else if(after_deleted == NULL){
    before_deleted->next = NULL;
  }else{
    before_deleted->next = after_deleted;
    after_deleted->prev = before_deleted;
  }

  free(deleted);

}

struct Node* insert(int value, struct Node* previous, struct Node* nexter){
    
    struct Node *append = mymalloc();
    
    append->value = value;

    if(nexter == NULL){
      append->next = previous;
      append->prev = NULL;
      previous->prev = append;
    }
    else if(previous == NULL){
      append->next = NULL;
      append->prev = nexter;
      nexter->next = append;
    }
    else{
      append->next = nexter;
      append->prev = previous;
      previous->next = append;
      nexter->prev = append;
      
    }

    return append;
}

void freeEverything(struct Node *first){

    struct Node *current = first;

    while(current != NULL){
      struct Node *tmp = current->next;
  
      free(current);

      current = tmp;
    }

}


int main(){


  struct Node *first = NULL;
  struct Node *second = NULL;
  struct Node *third = NULL;


  first = mymalloc();
  second = mymalloc();
  third = mymalloc();

  first->value = 5;
  first->next = second;
  first->prev = NULL;

  
  second->value = 3;
  second->next = third;
  second->prev = first;
  
  third->value = 8;
  third->prev = second;
  third->next = NULL;

  struct Node *fourth = insert(120, first, second);

  //struct Node *insertFirst = insert(-9, first, NULL);

  //struct Node *insertLast = insert(-548, NULL, third);

  struct Node *temp = first;

  while (temp != NULL) {
    printf("%d -> ", temp->value);
    temp = temp->next;
  }

  printf("STOP\n");

  printf("backwards\n");

  delete(third);

  temp = third;

  while(temp != NULL){
    printf("%d -> ", temp->value);
    temp = temp->prev;
  }




  freeEverything(first);

  


  return 0;
}
