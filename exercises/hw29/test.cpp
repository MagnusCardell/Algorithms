#include <cstdlib>
#include <iostream>
using namespace std;
int Hirschberg_AlgC(char *stringA, char *stringB, int m, int n)
{
   int **arr, **arr2, i, j, max, arrmax, arr2max, up, down;

   if (m == 1 || n == 0){
      if (n == 0)
         return 0;
      for (j = 1; j <= n; j++){
         if (stringA[1] == stringB[j])
            return 1;
      }
      return 0;
   }


   arr = (int**)calloc(2, sizeof(int*));
   arr2 = (int**)calloc(2, sizeof(int*));

   arrmax = m / 2;
   arr2max = m - arrmax;
   up = 1;
   down = 0;


   for (i = 0; i < 2; i++){
      arr[i] = (int*)calloc((n + 1), sizeof(int));
      arr2[i] = (int*)calloc((n + 1), sizeof(int));
   }

   /*-----fill in arr by using algB -----*/
   for (i = 0; i <= arrmax; i++){
      for (j = 0; j <= n; j++){
         if (j == 0 || i == 0)
            arr[down][j] = 0;
         else{
            if (stringA[i] == stringB[j]){
               arr[down][j] = arr[up][j - 1] + 1;
            }
            else{
               arr[down][j] = arr[up][j];
               if (arr[down][j] < arr[down][j - 1])
                  arr[down][j] = arr[down][j - 1];
            }
         }
      }
      up ^= down;//swap up and down by using EXOR
      down ^= up;
      up ^= down;
   }

   arrmax = up;//remember the position of the last row


   /*-----fill in arr2 by using algB -----*/
   for (i = 0; i <= arr2max; i++){
      for (j = 0; j <= n; j++){
         if (j == 0 || i == 0)
            arr2[down][j] = 0;
         else{
            if (stringA[m - i + 1] == stringB[n - j + 1]){
               arr2[down][j] = arr2[up][j - 1] + 1;
            }
            else{
               arr2[down][j] = arr2[up][j];
               if (arr2[down][j] < arr2[down][j - 1])
                  arr2[down][j] = arr2[down][j - 1];
            }
         }
      }
      up ^= down;//swap up and down by using EXOR
      down ^= up;
      up ^= down;
   }

   arr2max = up;//remember the position of the last row

   /*-----find k and MAX-----*/
   max = 0;
   j = 0;//the k is the min j that makes MAX

   for (i = 0; i <= n; i++){
      if (arr[arrmax][i] + arr2[arr2max][n - i] > max){
         max = arr[arrmax][i] + arr2[arr2max][n - i];
         j = i;
      }
   }


   return Hirschberg_AlgC(stringA, stringB, m / 2, j) + Hirschberg_AlgC(&stringA[m / 2], &stringB[j], m - m / 2, n - j);


}

int main(){
    char a[] = "anagram";
    char b[] = "agram";
    int v = Hirschberg_AlgC(a, b, 6, 5);
    cout<<v<<endl;
}