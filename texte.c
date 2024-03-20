#include <stdio.h>
#include <stdlib.h>
#include "tarefa.c"

int main()
{
    char id[50];
    int prioridade;
    int dia;
    int mes ;
    int ano;
    int op;

    Tarefa *tarefa = lst_cria();

        do{
        printf("[1] Inserir_Nova_Tarefa\n[2] Listar_Tarefas\n[3] Concluir_Tarefa\n[0] Sair\n");
        scanf(" %d",&op);
        switch(op)
        {
            case 1:
                printf("Designação_Da_Tarefa: ");
                scanf(" ");
                fgets(id, sizeof(id), stdin);
                printf("Prioridade: ");
                scanf(" %d",&prioridade);
                printf("Data(dd/mm/ano): ");
                scanf(" %d",&dia);
                scanf(" %d",&mes);
                scanf(" %d",&ano);
                tarefa = lst_inseri(tarefa,id,prioridade,dia,mes,ano);
            break;
            case 2:
                //imprimir_lista(tarefa);
                lista_tarefa(tarefa);
                break;
            case 3:
                printf("Designação_Da_Tarefa: ");
                scanf(" ");
                fgets(id, sizeof(id), stdin);
                complete(id,tarefa);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida");
        }

    }while(op != 0);

        return 0;
    }


