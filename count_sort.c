#include <stdio.h>
int a[100];
int b[100];
int c[100];
void print()
{
 for (int i = 0; i < 8; i++)
 {
  printf("%d ", c[i]);
 }
}
int main()
{
 for (int i = 0; i < 8; i++){
  scanf("%d", &a[i]);
  b[a[i]]++;
 }
 for (int i = 1; i < 5; i++)
  b[i] += b[i - 1];
 
 for (int i = 0; i < 8; i++)
 {
  c[b[a[i]]-1] = a[i];
  b[a[i]] -= 1;
 }
 print();
 return 0;
}
