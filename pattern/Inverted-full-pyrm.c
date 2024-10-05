#include <stdio.h>

int main(int argc, char const *argv[])
{

    int rows = 5;
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < rows + i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < rows - i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}


//extra 
// int main()
// {
//     int rows = 5;

    
//     for (int i = 0; i < rows; i++) {


//         for (int j = 0; j < 2 * i; j++) {
//             printf(" ");
//         }

//         for (int k = 0; k < 2 * (rows - i) - 1; k++) {
//             printf("* ");
//         }
//         printf("\n");
//     }
// }