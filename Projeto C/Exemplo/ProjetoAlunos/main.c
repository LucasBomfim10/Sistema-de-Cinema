#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "funcoesmatematicas.h"


void saidastr(char *mensagem)
{
    printf("%s", mensagem);
}

void saidafloat(char *mensagem, float valor)
{
    printf("%s%.2f", mensagem, valor);
}

char *entradastr(char *mensagem)
{
    char *v = (char *) malloc((sizeof(char) * sizeof(v)));
    printf("%s", mensagem);
    gets(v);
    return v;
}

float entradafloat(char *mensagem)
{
    float n;
    printf("%s", mensagem);
    scanf("%f", &n);
    return n;
}

// referencia = valor para aprovacao
void checa_aprovacao(float m, float referencia)
{
    if (m >= referencia)
    {
        printf("\n => status = APROVADO\n\n\n");
    }
    else
    {
        printf("\n => status = REPROVADO\n\n\n");
    }
}

void finalizar()
{
    system("cls");
    system("color 2E");
    saidastr("\n\n #################### FIM ####################\n\n");
}

void inicializar()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls"); // system("clear"); linux
    system("color 1F");
    saidastr("#################### Exemplo Notas Alunos ####################\n\n\n");
}

void gerente()
{
    char *nome;
    float mediafinal,notas[3];
    nome = entradastr("Digite nome Aluno: ");
    notas[0] = entradafloat("\nDigite nota 1: ");
    notas[1] = entradafloat("Digite nota 2: ");
    notas[2] = entradafloat("Digite nota 3: ");
    mediafinal = mediaa(notas, 3);
    saidafloat("\n Média Final= ", mediafinal);
    saidastr("\n _______________________________ ");
    saidastr("\n  ALUNO: ");
    saidastr(nome);
    checa_aprovacao(mediafinal, 6);
    system("pause");
}

int main()
{
    inicializar();
    gerente();
    finalizar();
    return 0;
}
