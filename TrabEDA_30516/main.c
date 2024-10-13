/** * * * * * * * * * * * * * * * * * * * * * * *
 * @file   main.c
 * @author Hugo Lopes_30516
 *
 * @brief Funcão main
 *
 * @date  March 2024
 * * * * * * * * * * * * * * * * * * * * * * * **/

#define _CRT_SECURE_NO_WARNINGS


#include <stdbool.h>
#include "header.h" 
#include<locale.h>

#pragma region Função main

/**
 * Função main.
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

    // Imprimir a matriz após a mudança
    printf("\nMatriz após mudar o valor:\n");
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

    // Imprimir a matriz após acrescentar a linha
    printf("\nMatriz após acrescentar uma linha:\n");
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

    // Imprimir a matriz após acrescentar a coluna
    printf("\nMatriz após acrescentar uma coluna:\n");
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

    // Imprimir a matriz após eliminar a coluna
    printf("\nMatriz após eliminar uma coluna:\n");
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

    // Imprimir a matriz após eliminar a linha
    printf("\nMatriz após eliminar uma linha:\n");
    imprMatriz(ini, lins, cols);

    // Guardar a matriz modificada em um arquivo
    if (!guardarMatriz("matriz2.txt", ini, &lins, &cols)) 
    {
        printf("Erro ao guardar a matriz em arquivo.\n");
        freeLista(ini);
        return 1;
    }

    // Liberar a memória alocada para a lista
    freeLista(ini);

    return 0;
}


 #pragma endregion          