#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ingresso.h"
#include "usuario.h"

static char Filmes [6][20] = {{"casa monstro"},{"Homem-Aranha"},{"Duna"},{"Panico"},{"turma da monica"},{"Eragon"}};
static char Hora [6][6] = {{"14:00"},{"16:00"},{"18:00"},{"19:00"},{"20:00"},{"22:00"}};
static int Cadeira [6] = {20,20,20,20,20,20};
static char preco [2][4] = {{""},{"20"}};


int admin()
{
    int escolha;
    int i;
    printf("Seja Bem-vindo Admin!\n");
    printf("[0]Alterar Filmes em catalogo\n");
    printf("[1]Alterar Horario dos filmes\n");
    printf("[2]Fazer Backup\n");
    printf("[3]Mudar valor do ingresso\n");
    printf("Qual op��o deseja:");
    scanf("%d",&escolha);
    system("cls");
    printf("|-------------------------------------------------\n");
    printf("| [0] %s Horario: %s Cadeiras: %d\n",Filmes[0],Hora[0],Cadeira[0]);
    printf("|-------------------------------------------------\n");
    printf("| [1] %s Horario: %s Cadeiras: %d \n",Filmes[1],Hora[1],Cadeira[1]);
    printf("|-------------------------------------------------\n");
    printf("| [2] %s Horario: %s Cadeiras: %d \n",Filmes[2],Hora[2],Cadeira[2]);
    printf("|-------------------------------------------------\n");
    printf("| [3] %s Horario: %s Cadeiras: %d \n",Filmes[3],Hora[3],Cadeira[3]);
    printf("|-------------------------------------------------\n");
    printf("| [4] %s Horario: %s Cadeiras: %d \n",Filmes[4],Hora[4],Cadeira[4]);
    printf("|-------------------------------------------------\n");
    printf("| [5] %s Horario: %s Cadeiras: %d \n",Filmes[5],Hora[5],Cadeira[5]);
    printf("|-------------------------------------------------\n");
    printf("Valor do ingresso : R$%s\n",preco[1]);
    if(escolha==0)
    {

        printf("Qual opcao deseja alterar:");
        scanf(" %d",&i);
        fflush(stdin);
        printf("Digite um novo filme:");
        gets(Filmes[i]);
        system("cls");
        printf("Filme alterado");
        return 0;
    }
    else if(escolha==1)
    {
        printf("Qual opcao deseja alterar:");
        scanf(" %d",&i);
        fflush(stdin);
        printf("Digite um novo horario:");
        gets(Hora[i]);
        system("cls");
        printf("Horario alterado");
        return 0;
    }
    else if (escolha==2)
    {
        Backup();

    }
    else if(escolha==3)
    {
        printf("Digite um novo valor:");
        fflush(stdin);
        gets(preco[1]);
        system("cls");
        printf("Valor alterado");
    }



}


void ingresso()
{
    int entrada;
    printf("Seja Bem-vindo! Esses s�o os filmes em catalogo:\n");
    printf("|-------------------------------------------------\n");
    printf("| [0] %s Horario: %s Cadeiras: %d\n",Filmes[0],Hora[0],Cadeira[0]);
    printf("|-------------------------------------------------\n");
    printf("| [1] %s Horario: %s Cadeiras: %d \n",Filmes[1],Hora[1],Cadeira[1]);
    printf("|-------------------------------------------------\n");
    printf("| [2] %s Horario: %s Cadeiras: %d \n",Filmes[2],Hora[2],Cadeira[2]);
    printf("|-------------------------------------------------\n");
    printf("| [3] %s Horario: %s Cadeiras: %d \n",Filmes[3],Hora[3],Cadeira[3]);
    printf("|-------------------------------------------------\n");
    printf("| [4] %s Horario: %s Cadeiras: %d \n",Filmes[4],Hora[4],Cadeira[4]);
    printf("|-------------------------------------------------\n");
    printf("| [5] %s Horario: %s Cadeiras: %d \n",Filmes[5],Hora[5],Cadeira[5]);
    printf("|-------------------------------------------------\n");
    printf("Valor do ingresso : R$%s\n",preco[1]);
    int opcao;
    printf("Qual filme deseja assistir: ");
    scanf(" %d",&opcao);
    printf("\nDeseja comprar meia entrada? [1]Sim [2]Nao :");
    scanf(" %d",&entrada);

    if(opcao<=5)
    {
        printf("Bilhete comprado!\n");
        Cadeira[opcao]--;
        printf("---------------------------------------------------------\n");
        printf("                        Seu ingresso                       \n");
        printf("        Filme:%s                    Horario:%s                    \n",Filmes[opcao],Hora[opcao]);
        if (entrada == 1)
        {
            printf("                   * Meia entrada             \n");
        }
        printf("---------------------------------------------------------\n");
    }
    return;
}
