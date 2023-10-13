//
// Created by 赵政杰 on 2021/10/26.
//
#include <stdio.h>
int main(){
  int n = 0;
  int target = 0;
  scanf("%d%d", &n, &target);
  int number[105] = {0};
  for (int i = 1; i <= n; i++) {
    scanf("%d", &number[i]);
  }
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (number[i] + number[j] == target) {
          printf("%d %d", number[i], number[j]);
          break;
      }
    }
  }
    return 0;

}
