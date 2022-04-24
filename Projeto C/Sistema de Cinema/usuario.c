#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "usuario.h"
static char nome[100][50] = {{"admin"}};
static char senha[100][50] = {{"admin"}};
static int n = 1;
int logincadastro(int c)
{


    char i;

    printf("Digite 1 para fazer o cadastro ou 2 para fazer o login: ");
    scanf(" %c",&i);
    system("cls");

    if (i == '1')
    {

        char t;
        printf("Vamos realizar o seu cadastro \n");
        printf("Nome:");
        scanf(" %s",&nome[n]);
        printf("Senha:");
        scanf(" %s",&senha[n]);
        printf("\nCadastro concluido\n");
        printf("Pressione qualquer tecla para ir ao login:");
        scanf(" %c",&t);
        n++;
        i = '2';
        system("cls");

    }
    if (i == '2')
    {
        int cont;
        int login;
        int password;
        char tempnome[50];
        char tempsenha[50];
        printf("Digite seu nome:");
        scanf(" %s",&tempnome);
        printf("Digite sua senha:");
        scanf(" %s",&tempsenha);
        system("cls");
        for(cont=0; cont<100; cont++)
        {
            login = strcmp(tempnome,nome[cont]);
            password = strcmp(tempsenha,senha[cont]);
            if (login == 0  && password == 0)
            {
                login = strcmp(tempnome,"admin");
                password = strcmp(tempsenha,"admin");
                if( login == 0 && password == 0)
                {
                    printf("Login efetuado com sucesso !\n");
                    c = 2;
                    system("cls");
                    return c;
                }
                else
                {
                    printf("Login efetuado com sucesso !\n");
                    c = 0;
                    system("cls");
                    return c;
                }
            }

        }
        printf("Nome ou senha incorretos, voltando para a tela inicial");
        c=1;
        return c;

    }
    if(i != '1' && i != '2')
    {
        printf("Você Digitou um numero incorreto!");
        c=1;
        return c;
    }
}
void Backup()
{
    int j;
    FILE *file;
    file = fopen("backup.txt","w");
    for(j=0; j<100; j++)
    {
        if (j<n)
        {

            fprintf(file,nome[j]);
            fprintf(file,"\n");
            fprintf(file,senha[j]);
            fprintf(file,"\n");
        }


    }
    fclose(file);
    char chave []=("CDEFGHIJKLM");
    cripto(chave);
    system("cls");
    printf("Foram criado dois arquivos um com o backup e outro ciptografado que foram salvos na pasta do programa, recomendamos que guarde o arquivos em um hd externo.\n chave usada: 'CDEFGHIJKLM' ");
    return 0;
}
int cripto(char *digitar[])
{
    FILE *arq1, *arq2;
    char *chave;
    int c;
    chave = digitar;

    if (*chave != '\0')
    {
        arq1 = fopen("backup.txt","rb"); //Arquivo que vai ser criptografado
        if(arq1 != NULL)
        {
            arq2 = fopen("criptografado.txt", "wb");//Arquivo com texto criptografado
            if(arq2 != NULL)
            {

                while ((c = getc(arq1)) != EOF)
                {
                    if(!*chave) chave = digitar ;

                    c ^= *(chave++); //Xor com o carctere de arq1 e a chave

                    putc(c,arq2); //Coloca o caractere no arquivo criptografado


                }
                fclose(arq2);
            }
            fclose(arq1);
        }
    }
    //Para descriptografar basta inverter os arquivos e usar a mesma chave
    return 1;
}

