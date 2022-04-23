// BOJ 2751 수 정렬하기 2
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000001

typedef struct {
  int key;
} element;

typedef struct HeapType {
  element heap[MAX_SIZE];
  int heap_size;
} HeapType;

HeapType* create() {
  return (HeapType*)malloc(sizeof(HeapType));
}

void init_heap(HeapType *h) {
  h->heap_size = 0;
}

void insert_min_heap(HeapType *h, element item) {
  int i;
  i = ++(h->heap_size);
  while ((i != 1) && (item.key < h->heap[i / 2].key)) {
    h->heap[i] = h->heap[i / 2];
    i /= 2;
  }
  h->heap[i] = item;
}

element delete_min_heap(HeapType *h) {
  int parent, child;
  element item, temp;

  item = h->heap[1];
  temp = h->heap[h->heap_size--];
  parent = 1;
  child = 2;

  while (child <= h->heap_size) {
    if ((child < h->heap_size) && 
        (h->heap[child].key > h->heap[child + 1].key)) child++;
    if (temp.key < h->heap[child].key) break;
    h->heap[parent] = h->heap[child];
    parent = child;
    child *= 2;
  }
  h->heap[parent] = temp;
  return item;
}

int main() {
  HeapType *heap;
  heap = create();
  init_heap(heap);
  element e;

  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    e.key = x;
    insert_min_heap(heap, e);
  }

  for (int i = 0; i < n; i++) {
    e = delete_min_heap(heap);
    printf("%d\n", e.key);
  }
  return 0;
}