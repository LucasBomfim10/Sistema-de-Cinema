#include <stdio.h>
#include <stdlib.h>
#include "layout.h"
#include "usuario.h"
#include "ingresso.h"
int main()
{

    int i;
    int cadastro;
    for(i=0; i<100; i++)
    {


        paginainicial();
        cadastro = logincadastro(cadastro);
        if (cadastro==0)
        {
            int t=1;
            while (t==1)
            {

                ingresso();
                printf("Deseja comprar outro ingresso ? [1]Sim [2]Nao [3]Tela inicial :");
                scanf(" %d",&t);
                system("cls");
                if(t==2)
                {
                    i=100;
                }


            }
        }
        else if (cadastro == 2)
        {
            admin();

        }
    }
    return 0;
}
