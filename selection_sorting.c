#include <stdio.h>

void print_array(int arr[], int n);

int main(int argc, int *argv[])
{
    int arr[] = {64, 25, 12, 22, 11};

    size_t tamanho_arr = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < tamanho_arr - 1; i++)
    {
        int indice_menor = i;

        for (int j = i + 1; j < tamanho_arr; j++)
        {
            if (arr[j] < arr[indice_menor])
                indice_menor = j;
        }

        int aux = arr[i];
        arr[i] = arr[indice_menor];
        arr[indice_menor] = aux;
        
    }

    print_array(arr, tamanho_arr);

    return 0;

}

void print_array(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}