#include <stdio.h>


int binary_search(int tab[], int begin, int end, int searched){


  printf("%d begin, %d end\n", begin, end);

  
  if (begin > end || end < begin) {
    
    perror("error");
    return -1;
  }

  int split = begin + (end - begin)/2;

  if(tab[split] == searched)
    return split;


  if(tab[split] > searched){
      return binary_search(tab, begin, split-1, searched);
  }else if (tab[split] < searched) {
      return binary_search(tab, split+1, end, searched);
  }


}

#define SIZE 8


int main(){
  
  int tab[SIZE] = {1,2,3,5,7,8,20,25};

  int index = binary_search(tab, 0, SIZE, 8);

  printf("%d\n", index);


  return 0;

  

}
