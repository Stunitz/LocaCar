#include <stdio.h> // biblioteca padrao de entra e saida
#include <stdlib.h> // biblioteca com funçoes padrao da linguagem 
#include <math.h> // biblioteca com formulas e funçoes matematicas
#include <conio.h> // biblioteca com mais algumas funçoes padrao da linguagem 
#include <locale.h> // biblioteca de acentuação em portugues
#include <windows.h>// biblioteca de opcoes graficas
#include <time.h>// biblioteca de temporizador
#include <string.h>// biblioteca de strings

// inclusão de outros arquivos .c
#include "caixa.h"
#include "cadcarro.c"
#include "cadlocacao.c"
#include "cadcliente.c"




// protótipos das funções:
void tela();
void senha2();
void menu();

// começo do programa	
int main() 
	{	
	tela(); // chama tela inicial	
	senha2();	// chama tela de senha e se passar vai ao menu()
	return 0;
}// fim main

//------------------------------------------------------------------------------------------------------------------------

void tela(){
	 	system("cls");

		printf("\n");
		printf("\n");		
		printf(" 7MMF                                     .g8'''bgd	 \n");                   
		printf("  MM                                    .dP'     `M  \n");
		printf("  MM         ,pW'Wq.   ,p6'bo   ,6'Yb.  dM'       `  ,6''Yb.  `7Mb,od8\n");
		printf("  MM        6W'   `Wb 6M'  OO  8)   MM  MM          8)   MM    MM' '''\n");
		printf("  MM      , 8M     M8 8M        ,pm9MM  MM.          ,pm9MM    MM     \n");
		printf("  MM     ,M YA.   ,A9 YM.    , 8M   MM  `Mb.     ,' 8M   MM    MM     \n");
		printf(".JMMmmmmMMM  `Ybmd9'   YMbmd'  `Moo9^Yo.  `'bmmmd'  `Moo9^Yo..JMML.   \n");
		printf("\n");
		printf("\n");
		setlocale (LC_ALL,"portuguese"); // seleciona lingua em portugues
		printf("\n       ### O Seu Software de Locação de Automóveis ###\n");
		printf("\n");
		printf("\n"); 
		_sleep(2000);
		system("cls");
		ani_carro(1);                  
		
	}
void ani_carro(int i){
	
	gotoxy(1,14);
	printf("________________________________________________________________________________________________________________________");
	for(i=i;i<=62;i++){
		gotoxy(i,1);
		printf("                  _________________");
		gotoxy(i,2);
		printf("              _.-'_____  _________ _`.");
		gotoxy(i,3);
		printf("            .` ,'      ||         | `.`.");
		gotoxy(i,4);
		printf("          .` ,'        ||         |   `.`.");
		gotoxy(i,5);
		printf("        .`  /          ||         |  ,' ] `....___");
		gotoxy(i,6);
		printf("      _`__.'''''''''''''''''''''''`''''''''|..___ `-.._");
		gotoxy(i,7);
		printf("    .'                  [='                '     `'-.._`.");
		gotoxy(i,8);
		printf(" ,:/.'''''''''''''''''''|''''''''''''''''''|'''''''''''\\'\\");
		gotoxy(i,9);
		printf("  //||    _..._         |               !! '    _..._  |)|");
		gotoxy(i,10);
		printf(" /|//   ,',---.`.       |                  |  .',---.`.\>|");
		gotoxy(i,11);
		printf(" (':/  //' .-. `\\\\      \\_________________/  //' .-. `\\\\|_)");
		gotoxy(i,12);
		printf(" `-...'||  '-'  ||________,,,,,,,,,,,,,,,__.'||  '-'  ||-");
		gotoxy(i,13);
		printf("       '.'.___.','                           '.'.___.','");
		gotoxy(i,14);
		printf("_________:-._.-:_______________________________:-._.-:");

	}

}

void senha2() {
  char usuario[20], senha[10];
  int tries = 4; // 3 tentativas se não sai
	int op; // opção

  do{
	    while(tries > 0) {
	  		setlocale (LC_ALL,"portuguese"); // seleciona lingua em portugues
			gotoxy(1,1);
			caixa(2);
			gotoxy(24,2);
		    printf("ADMINISTRADOR \n");
		    if(tries<4){
				gotoxy(3,7);
			    printf("Acesso Restrito - (%d tentativas)\n", tries);
			}
	
	    	gotoxy(3,4);
		    printf("Usuário: ");
			gotoxy(3,5);
		    printf("Senha: ");
		    gotoxy(12,4);
		    scanf("%s", &usuario);
		    gotoxy(10,5);
		    scanf("%s", &senha);
	      
		    if (strcmp(usuario,"adm") == 0 && strcmp(senha,"123") == 0) {    
				system("cls");
				setlocale (LC_ALL,"portuguese"); // seleciona lingua em portugues
				ani_carro(62);      
				gotoxy(1,1);
				caixa(2);
				gotoxy(24,2);
			    printf("ADMINISTRADOR \n");
			    gotoxy(3,4);
			    printf("Usuário: ");
				gotoxy(3,5);
			    printf("Senha: ");            
			    gotoxy(3,7);
			    printf("SEJA BEM VINDO!!!");
			    _sleep(1000);
				menu();	// chama menu principal
				system("cls");	
//				ani_carro(1);      
				printf("\nObrigado por usar o LocaCar...\n");
				_sleep(1500);
			  	break; // quando retornar do menu() sai da senha	
			}  
		    else {
				system("cls");
				ani_carro(62);      
				setlocale (LC_ALL,"portuguese"); // seleciona lingua em portugues
				gotoxy(1,1);
				caixa(2);
				gotoxy(24,2);
			    printf("ADMINISTRADOR \n");
			    gotoxy(3,4);
			    printf("Usuário: ");
				gotoxy(3,5);
			    printf("Senha: ");
			    gotoxy(3,7);
    		    printf("Usuário ou senha incorreto!");
			    tries--;
			    _sleep(1500);
			}
    	}
   		system ("cls"); // limpar a tela:
    }while(op != 0);
}

void menu(){
	int op; // opção
	do{
		setlocale (LC_ALL,"portuguese"); // seleciona lingua em portugues
		ani_carro(62);
		gotoxy(1,1);
		caixa(6);
		gotoxy(24,2);
		printf("MENU PRINCIPAL");
		gotoxy(3,5);
		printf("1) Clientes");
		gotoxy(3,6);
		printf("2) Carros");
		gotoxy(3,7);
		printf("3) Locações");
		gotoxy(3,8);
		printf("0) Sair");
		gotoxy(3,11);
		printf("Informe uma Opção: ");
		scanf("%d", &op);		

		// verificação do valor de op:
		switch(op){	
			case 1:
			system ("cls"); // limpar a tela:
			ani_carro(62);      
			_sleep(1000);
			cad_cli(1);	// menu de clientes
			break;	

			case 2:
			system ("cls"); // limpar a tela:
    		ani_carro(62);     
			_sleep(1000);
			cad_carro(1); // menu de carros		
			break;	

			case 3:
			system ("cls"); // limpar a tela:	
			ani_carro(62);
			cad_alugar(1);	// menu de locação
			break;	

			case 0: // sair
			printf("\nO programa sera finalizado...\n");
			_sleep(1000);
			break;
			
			default: // equivalente ao 'else'
			setlocale (LC_ALL,"portuguese"); 
			gotoxy(22,11);
			printf ("OPÇÃO INVALÍDA!");
			_sleep(1000);
		}// fim switch 
		system ("cls"); // limpar a tela:
	}while(op != 0);
	
}

