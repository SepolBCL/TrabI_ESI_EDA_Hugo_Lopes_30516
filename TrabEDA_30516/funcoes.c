/** * * * * * * * * * * * * * * * * * * * * * * *
 * @file   funcoes.c
 * @author Hugo Lopes_30516
 *
 * @brief Funções do programa 
 *
 * @date  March 2024
 * * * * * * * * * * * * * * * * * * * * * * * **/
#define _CRT_SECURE_NO_WARNINGS

#include "header.h"
#include<stdio.h>
#include<malloc.h>
#include <stdbool.h>


#pragma region F1_Função para alocar espaço na memória e criar um novo número.

/**
 * Função para alocar espaço na memória e criar um novo número.
 * 
 * \param num
 * \return Retorna um apontador para o novo número criado, ou NULL se a alocação de memória falhar
 */
Node* novoNo(int num)
{
    Node* aux = (Node*)malloc(sizeof(Node)); // Aloca memória para o novo número
    if (aux == NULL) return NULL; 
    aux->num = num; 
    aux->prox = NULL; 
    return aux; 
}

#pragma endregion


#pragma region F2_Função para inserir um numero no início.

/**
 * Função para inserir um numero no início.
 * 
 * \param ini
 * \param novonum
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* InsereInicio(Node* ini, Node* novonum)
{
    if (novonum == NULL) return ini;
    if (ini == NULL) ini = novonum;
    else
    {
        novonum->prox = ini;
        ini = novonum;
    }
    return ini;
}
#pragma endregion


#pragma region F3_Função para inserir um numero no final.

/**
 * Função para inserir um numero no final.
 * 
 * \param ini
 * \param novonum
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* InsereFim(Node* ini, Node* novonum) 
{
    if (novonum == NULL) return ini;
    if (ini == NULL)
        return novonum; // Se a lista estiver vazia, o primeiro numero será o início
    else {
        Node* aux = ini;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novonum; // Atualiza o apontador próximo do último número
    }
    return ini; 
}
#pragma endregion


#pragma region F4_Imprime numero da matriz.

/**
 * Imprime numero da matriz.
 * 
 * \param numInt
 * \return Retorna verdadeiro se existit numero, senão retorna false.
 */
bool imprnumero(Node* numInt)
{
    if (numInt == NULL)return false;
    printf("%d ", numInt->num);
    return true;
}
#pragma endregion


#pragma region F5_Função para imprimir a matriz.

/**
 * Função para imprimir a matriz.
 * 
 * \param ini
 * \param lins
 * \param cols
 * \return Retorna verdadeiro se imprimir a lista ligada,senão falso.
 */
bool imprMatriz(Node* ini, int lins, int cols) 
{
    if (cols < 0 || lins < 0) return false;
    Node* aux = ini;
    printf("********************************************************************\n");
    printf("\n");
    // Percorre a lista ligada e imprime os elementos em forma de matriz
    for (int i = 0; i < lins; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (aux != NULL) 
            {
                printf("%d\t", aux->num);
                aux = aux->prox;
            }
            else 
            {
                printf("0\t"); // Se a lista acabar, imprime 0
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("********************************************************************\n");
    printf("\n");
    return true;
}

#pragma endregion


#pragma region F6_Função para ler uma matriz de um ficheiro e criar uma lista ligada.

/**
 * Função para ler uma matriz de um ficheiro e criar uma lista ligada.
 * 
 * \param ficheiro
 * \param lins
 * \param cols
 * \param r
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* lerMatriz(const char* ficheiro, int* lins, int* cols, bool* r)
{
    Node* ini = NULL;
    FILE* fp = fopen(ficheiro, "r");
    if (fp == NULL)
    {
        if (r != NULL)
            *r = false;
        return NULL;
    }
    if (r != NULL)
        *r = true;
    int num;
    char delimitador; // Variável para o delimitador
    *lins = 1; // Inicializa o número de linhas
    *cols = 0; // Inicializa o número de colunas

    // Ciclo para ler os números do ficheiro e criar nós para cada elemento da matriz
    while (fscanf(fp, "%d%c", &num, &delimitador) != EOF)
    {
        Node* novo = novoNo(num); // Chama a função para alocar memória
        if (novo == NULL)
            return NULL;
        ini = InsereFim(ini, novo); // Chama a função para inserir o novo número no final 
        (*cols)++;

        // Verifica se chegou ao final da linha 
        if (delimitador == '\n')
        {
            (*lins)++; // Incrementa o número de linhas
            *cols = 0; // Reinicia o número de colunas para a próxima linha
        }
    }

    fclose(fp); 

    return ini; 
}

#pragma endregion


#pragma region F7_Função para limpar a memória alocada  da lista ligada.

/**
 * Função para limpar a memória alocada  da lista ligada.
 * 
 * \param ini
 * \return  Retorna verdadeiro se a memoria foi limpa, falso caso contrário.
 */
bool freeLista(Node* ini) 
{
    if (ini == NULL)
        return true; // Lista vazia, nada a liberar

    Node* aux = ini;
    while (aux != NULL) 
    {
        Node* prox = aux->prox;
        free(aux);
        aux = prox;
    }
    return true;
}

#pragma endregion


#pragma region F8_Função para modificar um valor da matriz.

/**
 * Função para modificar um valor da matriz.
 * 
 * \param ini
 * \param lins
 * \param cols
 * \param novo_valor
 * \param lin
 * \param col
 * \param res
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* mudarVal(Node* ini, int* lins, int* cols, int novo_valor, int lin, int col, bool* res)
{
    *res = false;

    if (ini == NULL || lin <= 0 || col <= 0 || lin > *lins || col > *cols)

        return ini;

    Node* aux = ini;
    int pos = (lin - 1) * (*cols)+(col - 1); // Ajustando para a indexação começar de 1
    int i;

    // Percorre a lista até a posição desejada
    for (i = 0; i < pos && aux != NULL; i++)
    {
        aux = aux->prox;
    }

    // Verifica se a posição foi encontrada
    if (i == pos && aux != NULL)
    {
        // Altera o valor do nó atual
        aux->num = novo_valor;
        *res = true;
    }

    return ini;
}

#pragma endregion


#pragma region F9_Função para guardar a matriz num Ficheiro.

/**
 * Função para guardar a matriz num Ficheiro.
 *
 * \param ficheiro
 * \param ini
 * \param lins
 * \param cols
 * \return Retorna verdadeiro se o ficheiro foi guardado, falso caso contrário.
 */
bool guardarMatriz(const char* ficheiro, Node* ini, int* lins, int* cols) 
{
    FILE* fp = fopen(ficheiro, "w");
    if (fp == NULL) return false;
    fprintf(fp, "FICHEIRO ALTERADO\n");
    Node* atual = ini;
    
    // Percorre a lista ligada e escreve os elementos em forma de matriz no arquivo
    for (int i = 0; i < *lins; i++) 
    {
        for (int j = 0; j < *cols; j++) 
        {
            if (atual != NULL) 
            {
                fprintf(fp, "%d\t ", atual->num);
                atual = atual->prox;
            }
            else {
                fprintf(fp, "0 "); // Se a lista acabar, escreve 0
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return true;
}

#pragma endregion


#pragma region F10_Função para inserir valores e aloca memoria atravez da função "novoNo".

/**
 * Função para inserir valores e aloca memoria atravez da função "novoNo".
 *
 * \param ini
 * \param valor
 * \param posicao
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* insereValor(Node* ini,int* cols, int* lins, int valor, int posicao)
{   
        
    Node* aux = novoNo(valor); // Chamada da função para criar novos valores 
    if (aux == NULL) return ini;

    if (posicao == 0) 
    {
        aux->prox = ini;
        return aux;
    }

    Node* novo = ini;

    for (int i = 1; i < posicao - 1 && novo != NULL; i++)
    {
        novo = novo->prox;
    }

    if (novo == NULL) return ini;
    aux->prox = novo->prox;
    novo->prox = aux;
    return ini;
}

#pragma endregion


#pragma region F11_Função para acrescentar coluna.

/**
 * Função para acrescentar coluna.
 *
 * \param ini
 * \param valores
 * \param lins
 * \param cols
 * \param col
 * \param res
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* acrescentarColuna(Node* ini, int* valores, int* lins, int* cols, int col, bool* res)
{
    *res = false;

    if (col < 0 || col > *cols || *lins <= 0)
    {
        *res = false;
        return ini;
    }

    for (int i = 0; i < (*lins); i++)
    {
        ini = insereValor(ini,cols,lins, valores[i], col);// Chamada da função para inserir nova coluna
        col = col + (*cols)+1; // Calculo para inserir corretamente os valores
    }
    *res = true;
    (*cols)++;
    return ini;
}

#pragma endregion


#pragma region F12_Função para acrescentar linha.

/**
 * Função para acrescentar linha.
 *
 * \param ini
 * \param valores
 * \param lins
 * \param cols
 * \param lin
 * \param res
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* acrescentarLinha(Node* ini, int* valores, int* lins, int* cols, int lin, bool* res)
{
    *res = false;
    if (lin < 0 || lin > *lins)
    {
        *res = false;
        return ini;
    }

    int pos_lin = (*cols) * (lin - 1) + 1;// Calculo para inserir corretamente os valores
    for (int i = 0; i < (*cols); i++)
    {
        ini = insereValor(ini,cols,lins, valores[i], pos_lin);// Chamada da função para inserir nova linha
        pos_lin++;
    }
    *res = true;
    (*lins)++;
    return ini;
}

#pragma endregion


#pragma region F13_Função para eliminar um valor específico da lista.

/**
 * Função para eliminar um valor específico da lista.
 * 
 * \param ini
 * \param valor
 * \param posicao
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* eliminavalor(Node* ini, int valor, int posicao)
{
    Node* ant = NULL;
    Node* aux = ini;
    int pos = 1;

    // Procura pelo valor na lista
    while (aux != NULL && aux->num != valor && pos!=posicao) //REVER 
    {
        ant = aux;
        aux = aux->prox;
        pos++;
    }
       
    if (aux == NULL) return ini;
       
    if (ant == NULL) 
    {
        
        ini = aux->prox;
    }
    else 
    {
        
        ant->prox = aux->prox;
    }

    free(aux); 
    return ini;
}

#pragma endregion


#pragma region F14_Função para eliminar coluna.

/**
 * Função para eliminar coluna.
 * 
 * \param ini
 * \param valores
 * \param lins
 * \param cols
 * \param col
 * \param res
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* eliminaColuna(Node* ini, int* valores, int* lins, int* cols, int col, bool* res)
{
    *res = false;

    if (col < 0 || col > *cols || *lins <= 0)
    {
        *res = false;
        return ini;
    }
    
    for (int i = 0; i < (*lins); i++)
    {
        
        ini = eliminavalor(ini,valores[i], col);// Chamada da função para eliminar nova coluna
        col = col + (*cols);// Calculo para eliminar na posição correta os valores
    }
    *res = true;
    (*cols)--;
    return ini;
}

#pragma endregion


#pragma region F15_Função para eliminar linha.

/**
 * Função para eliminar linha.
 * 
 * \param ini
 * \param valores
 * \param lins
 * \param cols
 * \param lin
 * \param res
 * \return Retorna o apontador para o início da lista ligada.
 */
Node* eliminarLinha(Node* ini, int* valores, int* lins, int* cols, int lin, bool* res)
{
    *res = false;
    if (lin < 0 || lin > *lins)
    {
        *res = false;
        return ini;
    }

    int pos_lin = (*cols) * (lin-1);// Calculo para eliminar corretamente os valores
    for (int i = 0; i < (*cols); i++)

    {
        ini = eliminavalor(ini, valores[i], pos_lin);// Chamada da função para eliminar nova linha
    }
    *res = true;
    (*lins)--;
    return ini;
}

#pragma endregion