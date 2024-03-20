#include <stdio.h>
#include <stdlib.h>
#include "tarefa.h"

struct data
{
    int dia;
    int mes;
    int ano;
};

struct tarefa
{
    char id [50];
    int prioridade;
    Data date;
    struct tarefa *anterior;
    struct tarefa *proximo;
};

//criar_Lista
Tarefa *lst_cria()
{
    return NULL;
}

//Inserir_elemento
Tarefa* lst_inseri(Tarefa* l, char id[50], int prioridade, int dia, int mes, int ano)
{

    Tarefa* novo = (Tarefa*)malloc(sizeof(Tarefa));
    Data *data = (Data*)malloc(sizeof(Data));

    if(novo == NULL || data == NULL)
    {
        printf("Erro ao adicionar a Tarefa");
        return NULL;
    }
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    novo->date = *data;
    novo->prioridade = prioridade;
    strcpy(novo->id, id);

    if (l == NULL) {
        novo->anterior = NULL;
        novo->proximo = NULL;
        return novo;
    }

    // Se a lista não estiver vazia
    novo->proximo = l;
    novo->anterior = NULL;
    l->anterior = novo;

    // Retorna a nova cabeça da lista
    return novo;
}
Tarefa *complete(char caract[50] , Tarefa *tarefa)
{

    Tarefa *p = tarefa;
    if (p == NULL)
    {
        printf("Lista de tarefas vazia.\n");
        return NULL;
    }
    while (p != NULL && strcmp(p->id, caract) != 0)
    {
        p = p->proximo;
    }

    if (p != NULL)
    {
        if (p->anterior != NULL)
        {
            p->anterior->proximo = p->proximo;
        }

        if (p->proximo != NULL)
        {
            p->proximo->anterior = p->anterior;
        }

        Tarefa *temp = p->proximo;
        free(p);

        printf("Tarefa '%s' concluída e removida da lista.\n", caract);

        return temp;
    }
    else
    {
        printf("Tarefa '%s' não encontrada na lista.\n", caract);
        return tarefa;
    }

}

void imprimir_lista(Tarefa *tarefa)
{
    Tarefa *p;
    for( p = tarefa; p != NULL ;  p = p->proximo)
    {
        printf("%s\n",p->id);
    }
}

void lista_tarefa(Tarefa *tarefa) {
    Tarefa *aux = tarefa;
    if(tarefa == NULL)
    {
        printf("Lista de Tarefas vazia\n");
    }
    while (aux != NULL) {
        Tarefa *aux1;
        for (aux1 = aux->proximo; aux1 != NULL; aux1 = aux1->proximo) {
            if (aux1->prioridade > aux->prioridade) {
                int temp_prioridade = aux1->prioridade;
                aux1->prioridade = aux->prioridade;
                aux->prioridade = temp_prioridade;

                char temp_id[50];
                strcpy(temp_id, aux1->id);
                strcpy(aux1->id, aux->id);
                strcpy(aux->id, temp_id);
            }
        }
        printf("%s\n", aux->id);
        aux = aux->proximo;
    }
}

