/*Created by luizsg on 30/11/2024*/
/*Updated by luizsg on 07/05/2025*/

#include <iostream>
#include <cstdlib> //Para usar o system()
#include <stdio.h>
#include <windows.h>

using namespace std;

//protótipos
void menu();
void sincronizarHorario();
void automacao();

//Automacao que cria um batch no computador com uma automacao de sincronizacao de horario
void automacao()
{
    //Pega C:\Users\<usuário>\AppData\Roaming porque é diferente em cada ambiente
    const char* caminhoBatch = getenv("APPDATA");
    string caminhoCompleto = string(caminhoBatch) + "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\sincronizar_horario.bat";
    
    //Codigo do batch
    FILE* arquivo = fopen(caminhoCompleto.c_str(), "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "@echo off\n");
        fprintf(arquivo, "net time \\\\172.16.0.111 /SET /YES\n");
        fprintf(arquivo, "exit\n");
        fclose(arquivo);
        std::cout << "\n[ * ]Automacao ativada! O horario sera sincronizado a cada inicializacao.\n\n";
    } else {
        std::cout << "\n[ * ]Erro ao criar o script de inicialização. Verifique permissoes.\n\n";
    }
    
    system("pause");
    menu();
}

//Sincronizador
void sincronizarHorario()
{
    const char* comand = "net time \\\\172.16.0.111 /SET /YES";
    
    std::cout << "\n[ * ]Buscando horario em servidor NTP...\n\n";
    int retorno = system(comand);
    
    if(retorno == 0)
    {
        std::cout << "[ * ]Horario sincronizado!\n\n";
    } else
    {
        std::cout << "\n[ * ]Erro ao executar sincronização. Codigo de retorno" << retorno << "\n"; 
    }
    //Sleep(5000);
    //getchar();
    system("pause");
    menu();
}

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
    printf("2. Automatizar sincronizacao\n");
    printf("0. Sair\n\n");
    printf("Escolha uma opc@o: ");
    scanf("%d", &escolha);

    switch (escolha) 
    {
        case 1:
            sincronizarHorario();
            break;
        case 2:
            automacao();
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
