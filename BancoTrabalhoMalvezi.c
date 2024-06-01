#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Estruturas do MENU DO CLIENTE!!
typedef struct saldo{
    int senha;
    int valor;
} SALDO;

typedef struct deposito{
    int valor1;
    int valor2;
    int valor3;
    int valor4;
} DEPOSITO;

typedef struct saque{
    int senha;
    int valor_saque;
} SAQUE;

typedef struct extrato{
    int senha;
    int extrato_excel;
} EXTRATO;

typedef struct limite{
    int senha;
    int limite_disponivel;
    int limite_indisponivel;
} LIMITE;

typedef struct menuprincipal{
    int funcionario;
    int cliente;
    int sair;
} MENUPRINCIPAL;

void saldo();
void deposito();
void saque();
void extrato();
void limite();
void sair();
void menuprincipal();

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcoes;
    //Leitura e escolha das OPÇÕES DO MENU DO CLIENTE!!

    do{ 
        printf("\nBEM-VINDO AO MENU DO CLIENTE\n\n");
        printf("INSIRA UM NÚMERO PARA A OPÇÃO DESEJADA:\n\n");
        printf("[1] <-- SALDO\n");
        printf("[2] <-- DEPÓSITO\n");
        printf("[3] <-- SAQUE\n");
        printf("[4] <-- EXTRATO\n");
        printf("[5] <-- LIMITE\n");
        printf("[6] <-- SAIR\n\n");
        scanf("%d", &opcoes);

        switch (opcoes){
            case 1:
                saldo();
                break;
            case 2:
                deposito();
                break; 
            case 3:
                saque();
                break;
            case 4:
                extrato();
                break;
            case 5:
                limite();
                break;
            case 6:
                sair();
                getchar();
                break;
            default:
                printf("OPÇÃO INVÁLIDA, TENTE NOVAMENTE!\n");
                getchar(); //Para/interrompe o programa e volta ao início para que o usuário tecle outra coisa.
                break;                    
        }
    } while (opcoes != 6);

    return 0;
}

//Implementação da função de SALDO!!
void saldo(){
    int senha = 12345;
    int saldo = 1000;
    int opcao;

    printf("\nDIGITE A SENHA DO CLIENTE:\n");
    scanf("%d", &senha);
    if(senha == 12345){
        printf("SENHA CORRETA\n\nSALDO DISPONÍVEL: R$%d,00\n", saldo);
        printf("APERTE \"ENTER\" PARA RETORNAR\n");
        fflush(stdin);
        getchar();
    }
    else{
        printf("SENHA INCORRETA\n");
        printf("DIGITE \"1\" PARA VOLTAR AO MENU PRINCIPAL\n");
        scanf("%d", &opcao);
    }
}

//Implementação da função de SALDO!!
void deposito(){
    int valor1 = 50;
    int valor2 = 100;
    int valor3 = 200;
    int valor4;
    int opcao_valores;

    do{
        printf("\nESCOLHA UM VALOR A SER DEPOSITADO:\n\n");
        printf("[1] <-- R$50,00\n");
        printf("[2] <-- R$100,00\n");
        printf("[3] <-- R$200,00\n");
        printf("[4] <-- OUTRO VALOR\n\n");
        scanf("%d", &opcao_valores);

        switch(opcao_valores){
            case 1: 
               printf("\nDEPOSITANDO R$50,00\n");
               printf("AGUARDE...\nDEPÓSITO CONFIRMADO!\n");
               scanf("%d", &valor1);
               printf("APERTE \"ENTER\" PARA RETORNAR\n");
               fflush(stdin);
               getchar();
               break;
            case 2:
               printf("\nDEPOSITANDO R$100,00\n");
               printf("AGUARDE...\nDEPÓSITO CONFIRMADO!\n");
               scanf("%d", &valor2);
               printf("APERTE \"ENTER\" PARA RETORNAR\n");
               fflush(stdin);
               getchar();
               break;
            case 3:
               printf("\nDEPOSITANDO R$200,00\n");
               printf("AGUARDE...\nDEPÓSITO CONFIRMADO!\n");
               scanf("%d", &valor3);
               printf("APERTE \"ENTER\" PARA RETORNAR\n");
               fflush(stdin);
               getchar();
               break;
            case 4:
               printf("\nINSIRA OUTRO VALOR:\n");
               scanf("%d", &valor4);
               fflush(stdin);
               getchar();
               printf("AGUARDE...\nDEPÓSITO CONFIRMADO!\n");
               printf("APERTE \"ENTER\" PARA RETORNAR\n");
               fflush(stdin);
               getchar();
               break;
            default:
               printf("OPÇÃO INVÁLIDA\n");
               fflush(stdin);
               getchar();
               break;
        }
    }while(opcao_valores != 4);

}

//Implementação da função de SAQUE!!
void saque(){
    int senha = 12345;
    int valor_saque;
    int saldo = 1000;
    int saldo_novo;
    
    do{
        printf("DIGITE A SENHA DO CLIENTE:\n");
        scanf("%d", &senha);
        if(senha == 12345){
            printf("SENHA CORRETA\n");
            break;
        }
        else{
            printf("SENHA INCORRETA\n");
            return;
        }
    }while(1);

    do{
        printf("INFORME O VALOR DO SAQUE: ");
        scanf("%d", &valor_saque);
        if(valor_saque <= saldo){
            saldo_novo = saldo - valor_saque;
            printf("VALOR DEBITADO DO SALDO: R$%d,00\n", valor_saque);
            fflush(stdin);
            getchar();
            break;
        }
        else if(valor_saque > saldo){
            printf("SALDO INSUFICIENTE\n");
            return;
        }
    }while(1);
    

}

//Implementação da função do EXTRATO!!
void extrato(){
    int senha = 12345;
    FILE *file;

    do{
        printf("DIGITE A SENHA DO CLIENTE: \n");
        scanf("%d", &senha);
        
        if(senha == 12345){
            printf("SENHA CORRETA\n");
            file = fopen("extrato.csv", "w");

            if(file == NULL){
                printf("ARQUIVO NÃO ENCONTRADO\n");
                return;
            }

            fprintf(file,"DATA:\t\tDESCRIÇÃO:\tVALOR:\n");
            fprintf(file,"01/04/2024\tSAQUE\t\tR$50,00\n");
            fprintf(file,"03/04/204\tDEPÓSITO\tR$300,00\n");
            fprintf(file,"10/04/2024\tDEPÓSITO\tR$140,00\n");
            fprintf(file,"22/04/2024\tSAQUE\t\tR$200,00\n");
            fprintf(file,"30/04/2024\tDEPÓSITO\tR$50,00\n");

            fclose(file);

            printf("EXTRATO GERADO COM SUCESSO, ABRA 'extrato.csv' PARA VER O RELATÓRIO COMPLETO!\n");
            printf("APERTE \"ENTER\" PARA RETORNAR\n");
            fflush(stdin);
            getchar();
        }
        else{
            printf("SENHA INCORRETA");
            return;
        }
    }while(1);
}

//Implementação da função para ver o LIMITE!!
void limite(){
    int senha = 12345;
    int limite = 2000;
    int valor;

    do{
        printf("DIGITE A SENHA DO CLIENTE:\n");
        scanf("%d", &senha);
        if(senha == 12345){
            printf("SENHA CORRETA\n");
            printf("CONSULTAR LIMITE\nINSIRA UM VALOR:\n");
            scanf("%d", &valor);
        if(valor <= limite){
            printf("LIMITE DISPONÍVEL\n");
            fflush(stdin);
            getchar();
            break;
        }    
        else{
            printf("LIMITE INDISPONÍVEL\n");
            fflush(stdin);
            getchar();
            break;
        }
        }else{
            printf("SENHA INCORRETA\n");
            return;
        }
        
    }while(1);
        
}

//Implementação da função que VOLTA AO MENU PRINCIPAL!!
void sair(){

    printf("OBRIGADO PELA CONFIANÇA, ATÉ BREVE...\n");
} 

//ACABOOOOOOOOOOOOU, É TETRAAAAAAAAAA🇧🇷🇧🇷🇧🇷!!!!!