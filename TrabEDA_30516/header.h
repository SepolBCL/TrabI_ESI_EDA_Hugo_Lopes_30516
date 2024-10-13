/** * * * * * * * * * * * * * * * * * * * * * * *
 * @file   header.h
 * @author Hugo Lopes_30516
 *
 * @brief Library 
 *
 * @date  March 2024
 * * * * * * * * * * * * * * * * * * * * * * * **/
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>



#pragma region estrutura
// Definição da estrutura de um nó da lista ligada
typedef struct Node {
    int num;
    struct Node* prox;
}Node;
#pragma endregion


#pragma region funções
Node* novoNo(int num);
Node* InsereFim(Node* ini, Node* novonum);
bool imprnumero(Node* numInt);
bool imprMatriz(Node* ini, int lins, int cols);
Node* lerMatriz(const char* ficheiro, int* lins, int* cols, bool* r);
bool freeLista(Node* ini);
Node* mudarVal(Node* ini, int* lins, int* cols, int novo_valor, int lin, int col, bool* res);
bool guardarMatriz(const char* ficheiro, Node* ini, int* lins, int* cols);
Node* insereValor(Node* ini, int* cols, int* lins, int valor, int posicao);
Node* acrescentarColuna(Node* ini, int* valores, int* lins, int* cols, int col, bool* res);
Node* acrescentarLinha(Node* ini, int* valores, int* lins, int* cols, int lin, bool* res);
Node* eliminavalor(Node* ini, int valor, int posicao);
Node* eliminaColuna(Node* ini, int* valores, int* lins, int* cols, int col, bool* res);
Node* eliminarLinha(Node* ini, int* valores, int* lins, int* cols, int lin, bool* res);
#pragma endregion