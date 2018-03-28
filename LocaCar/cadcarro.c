#include <stdio.h> // biblioteca padrao de entra e saida
#include <stdlib.h> // biblioteca com funçoes padrao da linguagem 
#include <math.h> // biblioteca com formulas e funçoes matematicas
#include <conio.h> // biblioteca com mais algumas funçoes padrao da linguagem 
#include <locale.h> // biblioteca de acentuação em portugues
#include <windows.h>// biblioteca de opcoes graficas
#include <time.h>// biblioteca de temporizador
#include <string.h>

#include "caixa.h"
#ifndef CADCARRO_C
#define CADCARRO_C


typedef struct lista2 {
	char placa [7];
	long int cod;
	char modelo [40];
	struct lista2* prox2;
}Lista2;

//Funçoes que serão usadas
Lista2* inserir_carros(Lista2* primeiro2);
void listar_carros(Lista2* primeiro2);
Lista2* excluir_carros(Lista2* primeiro2);
void alterar_carros(Lista2* primeiro2);
void ver_locacao2(Lista2 *primeiro2);
	
void cad_carro(int b){
	b = b; 
	menu2(b);
}
	//Comando de repetição
void menu2 (int b) {
		//Váriaveis
	setlocale(LC_ALL, "PORTUGUESE");
	static Lista2 *primeiro2= NULL;
	int opcao, placa;
	if(b==0){
		cad_locacao2(primeiro2);
	}else{
		do{
			ani_carro(62);
			gotoxy(1,1); 
			caixa(7);
			gotoxy(20,2); 
			printf("CADASTRO DE CARROS");
			gotoxy(3,5); 
			printf("1 - Novo Carro");
			gotoxy(3,6); 
			printf("2 - Listar Carros");
			gotoxy(3,7);
			printf("3 - Exluir Carros");
			gotoxy(3,8);
			printf("4 - Alterar Carros");
			gotoxy(3,9);
			printf("0 - Voltar");	
			gotoxy(3,12);
			printf("Informe uma Opção: ");
	
			scanf ("%d", &opcao);
			//Opções
			switch(opcao){
				case 1:
					fflush(stdin);
					system("cls");
					ani_carro(62);
					gotoxy(1,1); 
					caixa(5);
					gotoxy(19,2);
					printf("CADASTRAR NOVO CARRO");
					primeiro2 = inserir_carros(primeiro2);
					getch();
					system("cls");
					break;
					
				case 2:
					//listar clientes
					system("cls");
					ani_carro(62);
					listar_carros(primeiro2);
					getch();
					system("cls");
					break;
						
				case 3:
					//Excluir clientes
					system ("cls");
					ani_carro(62);
					gotoxy(1,1); 
					caixa(4);
					gotoxy(22,2);
					printf ("EXCLUIR CARROS");
					primeiro2= excluir_carros(primeiro2);
					getch();
					system("cls");
					break;
							
				case 4:
					//Alterar cliente
					system("cls");
					ani_carro(62);
					gotoxy(1,1); 
					caixa(5);
					gotoxy(16,2);
					printf("ALTERAR CARROS CADASTRADOS");
					alterar_carros(primeiro2);
					getch();
					system("cls");
					break;
								
				case 0:
					//Sair
					opcao= 0;
					break;
									
				default: 
				gotoxy(22,12);
				printf ("OPÇÃO INVALÍDA!");
				_sleep(1500);
				system("cls");
				ani_carro(62);
				break;
			}
		} while(opcao!=0);
	}
}

Lista2* inserir_carros (Lista2 *primeiro2){
	Lista2 carros;
	Lista2 *atual2= primeiro2;
	char identificador2= 'F';
	int a=0,b=0;
	
	//Lendo informações do cliente.//Lendo informações do cliente.
	gotoxy(3,5);
	printf ("Código: ");
	scanf ("%d", &carros.cod);
	gotoxy(3,6);
	printf ("Placas: ");
	scanf(" %s", &carros.placa);
	gotoxy(3,7);
	printf("Carro: ");
	fflush (stdin); fgets(carros.modelo, 40, stdin);
	
	//Verificar cadastro Existente
	for(atual2=primeiro2; atual2!=NULL; atual2=atual2->prox2){
		if(atual2->cod==carros.cod){
			identificador2= 'V';
			a=1;
			if(strcmp(carros.placa,atual2->placa)==0)
				b=1;
			break;
		}
		if(strcmp(carros.placa,atual2->placa)==0){
			identificador2= 'V';
			b=1;
			break;
		}
	}
	
	if (identificador2!='V' && (strlen(carros.modelo) !=1)){
		//Guardando as informacoes
		Lista2* NovoCarros=(Lista2*) malloc (sizeof(Lista2));
		strcpy(NovoCarros->modelo, carros.modelo);
		strcpy(NovoCarros->placa, carros.placa);
		NovoCarros->cod= carros.cod;
		NovoCarros->prox2= primeiro2;
		gotoxy(15,10);
		printf("Cadastro efetuado com sucesso!");
		_sleep(1500);
		gotoxy(8,10);
		printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
		return NovoCarros;
	} else{
		gotoxy(21,10);
		printf("Cadastro inválido!");
		_sleep(1500);
		if(a==1){
			gotoxy(18,10);
			printf("Código já foi registrado!");
			_sleep(2000);
		}
		if(b==1){
			gotoxy(18,10);
			printf("   Placa já foi registrada!");
			_sleep(2000);
		}
		
		gotoxy(8,10);
		printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
		return primeiro2;
	}
}

void listar_carros (Lista2* primeiro2){
	Lista2* atual2; //Ponteiro para percorrer a lista sem perder a referência do primeiro2 elemento da lista
	int c=0, d=5;
	//Imprimir os carros da lista com as sua informações.
	for(atual2= primeiro2 ; atual2!= NULL; atual2= atual2->prox2)
		c+=5;
	
	gotoxy(1,1); 
	caixa(c);
	gotoxy(20,2);
	printf("CARROS CADASTRADOS");
	for(atual2= primeiro2 ; atual2!= NULL; atual2= atual2->prox2){
		gotoxy(3,d++);
		printf ("Código: ");
		printf("%d", atual2->cod);
		gotoxy(3,d++);
		printf ("Carro: ");
		printf ("%s", atual2->modelo);
		gotoxy(3,d++);
		printf ("Placa: ");
		printf ("%s", atual2->placa);
		gotoxy(3,d++);
		gotoxy(3,d++);
	} 
	
	if (primeiro2==NULL){
		gotoxy(1,1); 
		caixa(0);
		gotoxy(20,2);
		printf("CARROS CADASTRADOS");
		gotoxy(17,4);
		printf ("Nenhum carro cadastrado!");
		_sleep(2000);
		gotoxy(8,4);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
	}else{
		gotoxy(8,d++);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
	}
}

Lista2* excluir_carros(Lista2 *primeiro2){
	
	Lista2 *anterior= NULL; //Ponteiro para saber o elemento anterior ao elemento atual2.
	Lista2 *atual2= primeiro2; //Ponteiro para percorrer a lista sem perder o primeiro2 elemento.
	int long cod;
	
	gotoxy(3,5);
	printf("Código do carro a ser excluído: ");
	fflush(stdin);
	scanf("%d", &cod);
	
	//Procurando o cliente na lista
	while(atual2!= NULL && atual2->cod!=cod){
		anterior= atual2;
		atual2= atual2->prox2;
	}
	//Mensagem caso cliente nao seja encontrado.
	if(atual2==NULL){
		gotoxy(18,9);
		printf ("Carro não encontrado!");
		_sleep(1500);
		gotoxy(8,9);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
		return primeiro2;
	}
	
	//Excluir o primeiro2 carro da lista
	if(anterior==NULL){
		gotoxy(3,6);
		printf("Carro excluído com sucesso!");
		primeiro2= atual2->prox2;
		//Excluir do meio da lista.
	} else{
		gotoxy(3,6);
		printf("Carro excluído com sucesso!");
		anterior->prox2= atual2->prox2;
	}
	//Desalocar o espaco da memoria.
	free(atual2);
	_sleep(1500);
	gotoxy(8,9);
	printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
	return primeiro2;
}

//Função para alterar cadastro de carros.
void alterar_carros(Lista2* primeiro2){
	char modelo_substituto[40],placa_substituto[40];
	int long cod;
	Lista2* atual2=primeiro2;
	
	//Requisitando o código do carro a ser alterado.
	gotoxy(3,5);
	printf ("Código do carro a ser alterado: ");
	fflush(stdin);
	scanf("%d", &cod);
	
	//Procurando o carro na lista
	while(atual2!= NULL && atual2->cod!=cod){
		atual2= atual2->prox2;
	}
	
	//alterando os dados do carro.
	if(atual2!=NULL){
		gotoxy(3,6);
		printf("Novo carro: ");
		fflush(stdin); fgets(modelo_substituto, 40, stdin);
		strcpy(atual2->modelo, modelo_substituto);
		gotoxy(3,7);
		printf ("Nova placa: ");
		fflush(stdin); fgets(placa_substituto, 40, stdin); printf ("\n");
		strcpy(atual2->placa, placa_substituto);
		gotoxy(15,10);
		printf("Dados alterados com sucesso!");
	} else{
		gotoxy(18,10);
		printf("Carro não encontrado!");
	}
	_sleep(1500);
	gotoxy(8,10);
	printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
}

void cad_locacao2(Lista2 *primeiro2){

	Lista2 *atual2 = primeiro2;
	int long cod;
	
	gotoxy(2,5);
	printf(" Código do carro: ");
	fflush(stdin);
	scanf("%d", &cod);
	
	while(atual2!= NULL && atual2->cod!=cod){
		atual2= atual2->prox2;
	}
	
	if(atual2==NULL){
		gotoxy(20,8);
		printf ("Carro não encontrado!");
		_sleep(1500);
		gotoxy(8,8);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
		return primeiro2;
	}else{
		getch();
		system("cls");
		ani_carro(62);
		cad_alugar(0);
		gotoxy(21,2);
		printf("CADASTRAR LOCAÇÃO");
	}
}


#endif
