#include <iostream>

// nPr = n * ( n-1) * .. * (n-r+1)
// nPr = n! / (n-r)!, r <= n, nP0 = 1
// if r == n : n!
// nPr = n * (n-1)P(r-1)

// 순열의 핵심 !! 
// 앞에서 선택한 것을 제외한 나머지가 다음 선택 대상!

using namespace std;

int data[] = { 1, 2, 3, 4 };

void Swap(int *n1, int *n2) {
 int tmp = *n1;
 *n1 = *n2;
 *n2 = tmp;
}

void printArray(int arr[], int n) {
 cout << "{ ";
 for (int i = 0; i < n; i++) {
  cout << arr[i] << " ";
 }
 cout << "}" << endl;
}

void perm_recursion(int k, int n) {
 if (k == n) {
  printArray(data, n);
 }
 else {
  for (int i = k; i < n; i++) {
   Swap(&data[k], &data[i]);
   perm_recursion(k + 1, n);
   Swap(&data[k], &data[i]);
  }
 }
}

// n : 전체 원소의 수
// r : 선택할 수 
// q : r의 복사본
void perm_formular(int a[], int n, int r, int q) {
 if (r == 0) {
  printArray(a, q);
 }
 else {
  for (int i = n - 1; i >= 0; i--) {
   Swap(&data[n-1], &data[i]);
   a[r - 1] = data[n - 1];
   perm_formular(a, n - 1, r - 1, q);
   Swap(&data[n - 1], &data[i]);
  }
 }
}
int main() {
 cout << "순열(재귀)" << endl;
 perm_recursion(0, 3);

 cout << "순열(점화식)" << endl;

 int a[6] = { 0, };
 perm_formular(a, 4, 4, 3);

 return 0;
}
