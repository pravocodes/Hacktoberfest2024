#include <stdio.h>

int main(int argc, char const *argv[])
{
    // static approach
    // int rows = 5;

    // for (int i = 0; i < rows; i++)
    // {
        
    //     for (int l = 0; l < rows - i; l++)
    //     {
    //         if (l == 0)
    //         {
    //             printf("    ");
    //         }
    //         printf(" ");
    //     }
    //     for (int m = 0; m <= i; m++)
    //     {
    //         printf("* ");
    //     }
    //     printf("\n");
    // }
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < rows + i; j++)
    //     {
    //         printf(" ");
    //     }
    //     for (int k = 0; k < rows - i; k++)
    //     {
    //         printf("* ");
    //     }
    //     printf("\n");
    // }
    // return 0;

    // dynamic one 
     int n = 5;

    
    for (int i = 0; i < 2 * n - 1; i++) {
        // the row number
        int comp;
        if (i < n) {
            comp = 2 * (n - i) - 1;
        }
        else {
            comp = 2 * (i - n + 1) + 1;
        }

        // space
        for (int j = 0; j < comp; j++) {
            printf(" ");
        }

        for (int k = 0; k < 2 * n - comp; k++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
