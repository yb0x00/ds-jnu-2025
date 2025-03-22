//작성일 : 2025.03.22
//작성자 : 최영빈

//조건
// 배열 A의 9개의 숫자(주어짐)를 증가순으로 Merge sorting하는
// 순환함수 MS(low, high), Merge(low, m, high)작성
// MS(0, 8) 호출을 통해  sorting된 결과를 출력

#include <stdio.h>

#define SIZE 9
int A[SIZE] = { 3, 2, 5, 7, 4, 8, 6, 9, 1 };
int temp[SIZE];

void Merge(int low, int m, int high) {
    int i = low;
    int j = m + 1;
    int k = low;

    while (i <= m && j <= high) {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while (i <= m)
        temp[k++] = A[i++];

    while (j <= high)
        temp[k++] = A[j++];

    for (int t = low; t <= high; t++)
        A[t] = temp[t];
}

void MS(int low, int high) {
    if (low >= high) return;
    int m = (low + high) / 2;
    MS(low, m);
    MS(m + 1, high);
    Merge(low, m, high);
}

int main() {
    MS(0, 8);

    printf("sorting된 결과: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}