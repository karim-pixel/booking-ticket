#include <stdio.h>
void addArrays(int arr1[], int arr2[], int result[], int size) {
 for (int i = 0; i < size; i++) {
 result[i] = arr1[i] + arr2[i];
 }
}
int main() {
 int arr1[] = {1, 2, 3, 4, 5};
 int arr2[] = {6, 7, 8, 9, 10};
 int result[5];
 addArrays(arr1, arr2, result, 5);
 printf("Resultant array after addition: ");
 for (int i = 0; i < 5; i++) {
 printf("%d ", result[i]);
 }
 printf("\n");
 return 0;
}
