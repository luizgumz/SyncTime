/*Created by luizsg on 30/11/2024*/
/*Updated by luizsg on 07/05/2025*/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>

using namespace std;

//protótipos
void menu();
void verificadorPermissoes();
void sincronizarHorario();

//Sincronizador


//Menu
void menu()
{
    int escolha;
    system("cls");
    printf("============================================\n");
    printf("       Sincronizador - Versao 2.1\n");
    printf("--------------------------------------------\n");
    printf("       Desenvolvido por Luiz Gumz\n");
    printf("============================================\n\n");

    printf("1. Sincronizar horario agora\n");
    printf("2. Automatizar sincronizacao(Em atualizac@o futura...)\n");
    printf("3. Exibir logs(Em atualizac@o futura...)\n");
    printf("0. Sair\n\n");
    printf("Escolha uma opc@o: ");
    scanf("%d", &escolha);

    switch (escolha) 
    {
        case 1:
            printf("[ * ]Buscando horário em servidor NTP...\n");
            net time \\172.16.0.111 /SET /YES
            printf("\n[ * ]Horário sincronizado! \nVoltando para o menu...");
            menu();
            break;
        case 2:
            //configurarAutomacao();
            break;
        case 3:
            //exibirLogs();
            break;
        case 0:
            printf("Saindo...\n");
            //exit(0);
        default:
            printf("Opção invalida. Tente novamente.\n");
    }
}


int main()
{
 
    menu();
    return 0;
}
