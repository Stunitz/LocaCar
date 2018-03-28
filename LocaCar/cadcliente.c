#include <stdio.h> // biblioteca padrao de entra e saida
#include <stdlib.h> // biblioteca com funçoes padrao da linguagem 
#include <math.h> // biblioteca com formulas e funçoes matematicas
#include <conio.h> // biblioteca com mais algumas funçoes padrao da linguagem 
#include <locale.h> // biblioteca de acentuação em portugues
#include <windows.h>// biblioteca de opcoes graficas
#include <time.h>// biblioteca de temporizador
#include <string.h>

#include "caixa.h"
#ifndef CADCLIENTE_C
#define CADCLIENTE_C


 typedef struct lista {
	char cpf [14];
	long int card;
	long int cod;
	char nome [50];
	char endereco [60];
	struct lista* prox;
}Lista;


Lista* inserir_clientes(Lista* primeiro);
void listar_clientes(Lista* primeiro);
Lista* excluir_clientes(Lista* primeiro);
void alterar_clientes(Lista* primeiro);
void ver_locacao(Lista *primeiro);





//Funçoes que serão usadas

		
void cad_cli(int a){
	a = a;
	menu1(a);
}
	//Comando de repetição
void menu1(int a){

	setlocale(LC_ALL, "PORTUGUESE");
	static Lista *primeiro= NULL;;
	int opcao, cpf, card;
	
	if(a==0){
		ani_carro(62);
		cad_locacao(primeiro);
	}else{
		do{
			ani_carro(62);
			gotoxy(1,1); 
			caixa(7);
			card=0;
			gotoxy(20,2); 
			printf("CADASTRO DE CLIENTES");
			gotoxy(3,5); 
			printf("1 - Novo Cliente");
			gotoxy(3,6); 
			printf("2 - Listar Clientes");
			gotoxy(3,7);
			printf("3 - Exluir Cliente");
			gotoxy(3,8);
			printf("4 - Alterar Cliente");
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
					caixa(7);
					gotoxy(19,2);
					printf("CADASTRAR NOVO CLIENTE");
					primeiro= inserir_clientes(primeiro);
					getch();
					system("cls");
					break;
					
				case 2:
					//listar clientes
					system("cls");
					ani_carro(62);
					listar_clientes(primeiro);
					getch();
					system("cls");
					ani_carro(62);
					break;
						
				case 3:
					//Excluir clientes
					system ("cls");
					ani_carro(62);
					gotoxy(1,1); 
					caixa(3);
					gotoxy(22,2);
					printf ("EXCLUIR CLIENTE");
					primeiro= excluir_clientes(primeiro);
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
					printf("ALTERAR CLIENTES CADASTRADOS");
					alterar_clientes(primeiro);
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

Lista* inserir_clientes (Lista *primeiro){
	Lista cliente;
	Lista *atual= primeiro;
	char identificador= 'F';
	int a=0,b=0,c=0;
	
	//Lendo informações do cliente.//Lendo informações do cliente.
	gotoxy(3,5);
	printf ("Código: ");
	scanf ("%d", &cliente.cod);
	gotoxy(3,6);
	printf ("CPF: ");
	scanf(" %s", &cliente.cpf);
	gotoxy(3,7);
	printf("Nome: ");
	fflush (stdin); fgets(cliente.nome, 40, stdin);
	gotoxy(3,8);
	printf ("Endereço: ");
	fflush(stdin); fgets(cliente.endereco, 40, stdin);
	gotoxy(3,9);
	printf ("Número do cartão: ");
	scanf ("%d", &cliente.card); printf ("\n");
	
	//Verificar cadastro Existente
	for(atual=primeiro; atual!=NULL; atual=atual->prox){
		if(atual->cod==cliente.cod){
			identificador= 'V';
			a=1;
			if(strcmp(cliente.cpf,atual->cpf)==0)
				b=1;
			if(atual->card==cliente.card)
				c=1;
			break;
		}
		if(strcmp(cliente.cpf,atual->cpf)==0){
			identificador= 'V';
			b=1; // para mensagem de erro
			if(atual->card==cliente.card)
				c=1;
			break;
		}
		if(atual->card==cliente.card){
			identificador= 'V';
			c=1;
			break;
		}	
	}
	
	if (identificador!='V' && (strlen(cliente.nome) !=1 && strlen(cliente.endereco)!=1)){
		//Guardando as informacoes
		Lista* NovoCliente=(Lista*) malloc (sizeof(Lista));
		strcpy(NovoCliente->nome, cliente.nome);
		strcpy(NovoCliente->endereco, cliente.endereco);
		strcpy(NovoCliente->cpf, cliente.cpf);
		NovoCliente->cod= cliente.cod;
		NovoCliente->card= cliente.card;
		NovoCliente->prox= primeiro;
		gotoxy(15,12);
		printf("Cadastro efetuado com sucesso!");
		_sleep(1500);
		gotoxy(8,12);
		printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
		return NovoCliente;
	} else{
		gotoxy(21,12);
		printf("Cadastro inválido!");
		_sleep(1500);
		if(a==1){
			gotoxy(18,12);
			printf("Código já foi registrado!");
			_sleep(2000);
		}
		if(b==1){
			gotoxy(18,12);
			printf("   CPF já foi registrado!");
			_sleep(2000);
		}
		if(c==1){
			gotoxy(18,12);
			printf("Cartão já foi registrado!");
			_sleep(2000);
		}
		gotoxy(8,12);
		printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
		return primeiro;
	}
}

void listar_clientes (Lista* primeiro){
	Lista* atual; //Ponteiro para percorrer a lista sem perder a referência do primeiro elemento da lista
	int c=0, d=5;
	//Imprimir os clientes da lista com as sua informações.
	for(atual= primeiro ; atual!= NULL; atual= atual->prox)
		c+=7;
	
	gotoxy(1,1); 
	caixa(c);
	gotoxy(20,2);
	printf("CLIENTES CADASTRADOS");
	for(atual= primeiro ; atual!= NULL; atual= atual->prox){
		gotoxy(3,d++);
		printf ("Código: ");
		printf("%d", atual->cod);
		gotoxy(3,d++);
		printf ("Nome: ");
		printf ("%s", atual->nome);
		gotoxy(3,d++);
		printf ("CPF: ");
		printf ("%s", atual->cpf);
		gotoxy(3,d++);
		printf ("Endereço: ");
		printf ("%s", atual->endereco);
		gotoxy(3,d++);
		printf ("Número do cartão: ");
		printf ("%d", atual->card);
		gotoxy(3,d++);
		gotoxy(3,d++);
	} 
	
	if (primeiro==NULL){
		gotoxy(1,1); 
		caixa(0);
		gotoxy(20,2);
		printf("CLIENTES CADASTRADOS");
		gotoxy(17,4);
		printf ("Nenhum cliente cadastrado!");
		_sleep(2000);
		gotoxy(8,4);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
	}else{
		gotoxy(8,d++);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
	}
}

Lista* excluir_clientes(Lista *primeiro){
	
	Lista *anterior= NULL; //Ponteiro para saber o elemento anterior ao elemento atual.
	Lista *atual= primeiro; //Ponteiro para percorrer a lista sem perder o primeiro elemento.
	int long cod;
	
	//Requisitando e lendo o CPF do cliente a sert excluido.
	gotoxy(3,5);
	printf("Código do cliente a ser excluido: ");
	fflush(stdin);
	scanf("%d", &cod);
	
	//Procurando o cliente na lista
	while(atual!= NULL && atual->cod!=cod){
		anterior= atual;
		atual= atual->prox;
	}
	//Mensagem caso cliente nao seja encontrado.
	if(atual==NULL){
		gotoxy(18,8);
		printf ("Cliente não encontrado!");
		_sleep(1500);
		gotoxy(8,8);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
		return primeiro;
	}
	
	//Excluir o primeiro cliente da lista
	if(anterior==NULL){
		gotoxy(15,8);
		printf("Cliente excluído com sucesso!");
		primeiro= atual->prox;
		//Excluir do meio da lista.
	} else{
		gotoxy(15,8);
		printf("Cliente excluído com sucesso!");
		anterior->prox= atual->prox;
	}
	//Desalocar o espaco da memoria.
	free(atual);
	_sleep(1500);
	gotoxy(8,8);
	printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
	return primeiro;
}

//Função para alterar cadastro de clientes.
void alterar_clientes(Lista* primeiro){
	char nome_substituto[40], endereco_substituto[40];
	int long cod;
	Lista* atual=primeiro;
	
	//Requisitando o CPF do cliente a ser alterado.
	gotoxy(3,5);
	printf ("Código do cliente a ser alterado: ");
	fflush(stdin);
	scanf("%d", &cod);
	
	//Procurando o cliente na lista
	while(atual!= NULL && atual->cod!=cod){
		atual= atual->prox;
	}
	
	//alterando os dados do cliente.
	if(atual!=NULL){
		gotoxy(3,6);
		printf("Novo nome: ");
		fflush(stdin); fgets(nome_substituto, 40, stdin);
		strcpy(atual->nome, nome_substituto);
		gotoxy(3,7);
		printf ("Novo endereço: ");
		fflush(stdin); fgets(endereco_substituto, 40, stdin); printf ("\n");
		strcpy(atual->endereco, endereco_substituto);
		gotoxy(15,10);
		printf("Dados alterados com sucesso!");
	} else{
		gotoxy(18,10);
		printf("Cliente não encontrado!");
	}
	_sleep(1500);
	gotoxy(8,10);
	printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
}


void cad_locacao(Lista *primeiro){

	Lista *atual = primeiro;
	int long cod;
	
	gotoxy(2,5);
	printf("Código do cliente: ");
	fflush(stdin);
	scanf("%d", &cod);
	
	while(atual!= NULL && atual->cod!=cod){
		atual= atual->prox;
	}
	
	if(atual==NULL){
		gotoxy(18,8);
		printf ("Cliente não encontrado!");
		_sleep(1500);
		gotoxy(8,8);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
		return primeiro;
	}else{
		system("cls");
		ani_carro(62);
		gotoxy(1,1); 
		caixa(3);
		gotoxy(21,2);
		printf("CADASTRAR LOCAÇÃO");
		cad_carro(0);
	}
}


#endif
