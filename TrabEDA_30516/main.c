/** * * * * * * * * * * * * * * * * * * * * * * *
 * @file   main.c
 * @author Hugo Lopes_30516
 *
 * @brief Func�o main
 *
 * @date  March 2024
 * * * * * * * * * * * * * * * * * * * * * * * **/

#define _CRT_SECURE_NO_WARNINGS


#include <stdbool.h>
#include "header.h" 
#include<locale.h>

#pragma region Fun��o main

/**
 * Fun��o main.
 * 
 * \return Retorna 0 se tudo se processou corretamente.
 */


int main() 
{
    setlocale(LC_ALL, "Portuguese");

    int lins, cols;
    bool OK, res;

    // Ler a matriz do ficheiro
    Node* ini = lerMatriz("Matriz.txt", &lins, &cols, &OK);
    if (!OK) 
    {
        printf("Erro ao ler a matriz.\n");
        return 1;
    }

    // Imprimir a matriz lida
    printf("Matriz lida:\n");
    imprMatriz(ini, lins, cols);

    // Mudar um valor na matriz
    ini = mudarVal(ini, &lins, &cols, 100, 5, 6, &res);
    if (!res) 
    {
        printf("Erro ao mudar o valor na matriz.\n");
        freeLista(ini);
        return 1;
    }

    // Imprimir a matriz ap�s a mudan�a
    printf("\nMatriz ap�s mudar o valor:\n");
    imprMatriz(ini, lins, cols);

    // Acrescentar uma linha na matriz
    int lin_valores[] = { 101, 202, 303, 404, 505, 606, 707, 808, 909 };
    ini = acrescentarLinha(ini, lin_valores, &lins, &cols, 3, &res);
    if (!res) 
    {
        printf("Erro ao acrescentar uma linha na matriz.\n");
        freeLista(ini);
        return 1;
    }

    // Imprimir a matriz ap�s acrescentar a linha
    printf("\nMatriz ap�s acrescentar uma linha:\n");
    imprMatriz(ini, lins, cols);

    // Acrescentar uma coluna na matriz
    int col_valores[] = { 101, 202, 303, 404, 505, 606, 707, 808, 909 };
    ini = acrescentarColuna(ini, col_valores, &lins, &cols, 2, &res);
    if (!res) 
    {
        printf("Erro ao acrescentar uma coluna na matriz.\n");
        freeLista(ini);
        return 1;
    }

    // Imprimir a matriz ap�s acrescentar a coluna
    printf("\nMatriz ap�s acrescentar uma coluna:\n");
    imprMatriz(ini, lins, cols);

    // Eliminar uma coluna na matriz
    int col_valores_1[] = { 101, 202, 303, 404, 505, 606, 707, 808, 909 };
    ini = eliminaColuna(ini, col_valores_1, &lins, &cols, 2, &res);
    if (!res) 
    {
        printf("Erro ao eliminar uma coluna na matriz.\n");
        freeLista(ini);
        return 1;
    }

    // Imprimir a matriz ap�s eliminar a coluna
    printf("\nMatriz ap�s eliminar uma coluna:\n");
    imprMatriz(ini, lins, cols);

    // Eliminar uma linha na matriz
    int lin_valores_1[] = { 101, 202, 303, 404, 505, 606, 707, 808, 909 };
    ini = eliminarLinha(ini, lin_valores_1, &lins, &cols, 3, &res);
    if (!res) 
    {
        printf("Erro ao eliminar uma linha na matriz.\n");
        freeLista(ini);
        return 1;
    }

    // Imprimir a matriz ap�s eliminar a linha
    printf("\nMatriz ap�s eliminar uma linha:\n");
    imprMatriz(ini, lins, cols);

    // Guardar a matriz modificada em um arquivo
    if (!guardarMatriz("matriz2.txt", ini, &lins, &cols)) 
    {
        printf("Erro ao guardar a matriz em arquivo.\n");
        freeLista(ini);
        return 1;
    }

    // Liberar a mem�ria alocada para a lista
    freeLista(ini);

    return 0;
}


 #pragma endregion          