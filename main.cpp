#include <iostream>

typedef struct {
  int *nodes;
  int length;
  int heap_size;
} heap;

int parent(int i){
  return (i - 1) / 2;
}

int left(int i){
  return 2*i + 1;
}

int right(int i){
  return 2*i + 2;
}


void maxHeapify(heap& A, int i){
  int l = left(i);
  int r = right(i);
  int largest;
  if (l < A.heap_size && A.nodes[l] > A.nodes[i]){
    largest = l;
  } else {
    largest = i;
  }
  if (r < A.heap_size && A.nodes[r] > A.nodes[largest]){
    largest = r;
  }
  if (largest != i){
    int temp = A.nodes[i];
    A.nodes[i] = A.nodes[largest];
    A.nodes[largest] = temp;
    maxHeapify(A, largest);
  }
}

int main(){
  int arr[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  heap A = {arr, 10, 15};
  for (int i = 0; i < 10; ++i) {
    std::cout << A.nodes[i] << " ";
    
  }
  std::cout << std::endl;
  maxHeapify(A, 1);
  for (int i = 0; i < 10; ++i) {
    std::cout << A.nodes[i] << " ";

  }
  std::cout << std::endl;
  return 0;
}
