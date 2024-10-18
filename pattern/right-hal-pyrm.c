#include <stdio.h>

int main()
{

    for (int i = 5; i < 0; i--){
             printf(" ");
        for (int j = i; j < i; j--)
        {
        printf("%d", j+1);
        }
   
    }
}