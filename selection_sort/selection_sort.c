/* Il programma ordinera' gli elementi interi di
 * un vettore con una funzione selection_sort() 
 */


#include <stdio.h>
#include "myvect.h"

#define SIZE 4

void selection_sort(int v[], int size);
void selection_sort_helper(int v[], int size, int index_min);

int main()
{
  int v[SIZE];

  myvect_init();

  myvect_init_in_range(v, SIZE, 0, 100);

  printf("Vettore prima dell'ordinamento:\n");
  myvect_print(v, SIZE);

  selection_sort(v, SIZE);

  printf("Vettore dopo l'ordinamento:\n");
  myvect_print(v, SIZE);

  return 0;
}

void selection_sort(int v[], int size)
{
  selection_sort_helper(v, size, 0 );
}

void selection_sort_helper(int v[], int size, int index_min)
{
  int i, temp;
  
  if (size - index_min <= 1) return;

  for (i=1; i<size; i++) {
    if (v[i] < v[index_min]) {
      index_min = i;
    }
  }
  temp = v[0];
  v[0] = v[index_min];
  v[index_min] = temp;
  
  selection_sort_helper(v, size, index_min+1);
}
