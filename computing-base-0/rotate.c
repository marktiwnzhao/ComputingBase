//
// Created by 赵政杰 on 2021/10/27.
//
#include <stdio.h>
int main() {
    int n = 0;
    int k = 0;
    scanf("%d%d", &n, &k);
    long long int num[30000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
    }
    long long int anum[30000] = {0};
    //for (int i = 0; i < n; i++) {
        //printf("%lld ", num[i]);
    //}
    //printf("\n");

    /*int s = 0;
    for (int i = 0; i < n; i++) {
        s = i + k;
        while(s >= n) {
            s -= n;
        }
        anum[s] = num[i];
    }*/

    if (k % n != 0) {
        int ak = k % n;
        for (int i = 0; i < n; i++) {
            anum[i + ak] = num[i];
            //printf("%d ", anum[i + ak]);
        }
        //printf("\n");

        for (int j = 0; j < n; j++) {
            if (j < ak) {
                num[j] = anum[j + n];
                //printf("%d ", anum[j + n]);
            } else {
                num[j] = anum[j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", num[i]);
    }
    return 0;
}
