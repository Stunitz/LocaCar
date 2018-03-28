#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include "caixa.h"

#include "cadcarro.c"
#include "cadcliente.c"

typedef struct lista3 {
	char data_ent [40];
	char data_dev [40];
	long int cod;
	float valor;
	struct lista3* prox3;
}Lista3;

//Funçoes que serão usadas
Lista3* inserir_locacao(Lista3* primeiro3);
void listar_locacao(Lista3* primeiro3);
Lista3* excluir_locacao(Lista3* primeiro3);
void alterar_locacao(Lista3* primeiro3);

//int main(){	
void cad_alugar(int c){
	c = c;
	menu3(c);
}

void menu3(int c){
	int op2, a; // opção2
	static Lista *primeiro3= NULL;;
	
	if(c==0){
		ani_carro(62);
		gotoxy(1,1); 
		caixa(6);
		gotoxy(21,2);
		printf("CADASTRAR LOCAÇÃO");
		primeiro3=inserir_locacao(primeiro3);
	}else{
		do{
		 	setlocale (LC_ALL,"portuguese"); // seleciona lingua em portugues
			ani_carro(62);
			gotoxy(1,1);
			caixa(7);
			gotoxy(26,2);
			printf("LOCAÇÕES");
			gotoxy(3,5);
			printf("1) Alugar um carro");
			gotoxy(3,6);
			printf("2) Listar Locações");
			gotoxy(3,7);
			printf("3) Excluir Locação");
			gotoxy(3,8);
			printf("4) Alterar Locação");
			gotoxy(3,9);
			printf("0) Voltar");
			gotoxy(3,12);
			printf("Informe uma Opção: ");
	 	   	gotoxy(23,12); // coloca ponteiro no inicio
			scanf("%d", &op2);
	
		
			// verificação do valor de op2:
			switch(op2){	
	        	case 1:
				system ("cls"); // limpar a tela:
				ani_carro(62);
	        	gotoxy(1,1); 
				caixa(3);
				gotoxy(21,2);
				printf("CADASTRAR LOCAÇÃO");
				cad_cli(0);	// cadastra nova locação (não esquecer de colocar o cliente)
	//			printf("\n FALTA OPÇÃO... (cad_locação)\n");
				_sleep(1000);
				break;	
	
				case 2:
				system ("cls"); // limpar a tela:
				ani_carro(62);
				listar_locacao(primeiro3);
				_sleep(1000);
				break;	
	
				case 3:
				system ("cls");
				ani_carro(62);
				gotoxy(1,1); 
				caixa(0);
				gotoxy(22,2);
				printf ("EXCLUIR LOCAÇÃO");
				primeiro3= excluir_locacao(primeiro3);
				getch();
				_sleep(1000);
				break;	
	
				case 4:
				system("cls");
				ani_carro(62);
				gotoxy(1,1); 
				caixa(6);
				gotoxy(16,2);
				printf("ALTERAR CLIENTES CADASTRADOS");
				alterar_locacao(primeiro3);
				_sleep(1000);
				break;	
	
				case 0: // sair
				system ("cls"); // limpar a tela:
				ani_carro(62);
				printf("\n Voltando ao Menu Principal...\n");
				_sleep(1000);
				break;
				
				default: // equivalente ao 'else'
				gotoxy(23,12);
				printf ("OPÇÃO INVALIDA!\n");
				_sleep(1000);
				break;
				}// fim switch 
				ani_carro(62);
				system ("cls"); // limpar a tela:
		}while(op2 != 0);	 
	}
}


Lista3* inserir_locacao (Lista3 *primeiro3){
	Lista3 locacao;
	Lista3 *atual3= primeiro3;
	char identificador3= 'F';
	int a=0,b=0;
	
	//Lendo informações do cliente.//Lendo informações do cliente.
	gotoxy(3,5);
	printf ("Código da Locação: ");
	scanf ("%d", &locacao.cod);
	gotoxy(3,6);
	printf ("Data de Retirada: ");
	scanf ("%s", &locacao.data_ent);
	gotoxy(3,7);
	printf ("Data de Devolução: ");
	scanf(" %s", &locacao.data_dev) ;
	gotoxy(3,8);
	printf("Valor de Locação: ");
	scanf(" %f", &locacao.valor);
	
	//Verificar cadastro Existente
	for(atual3=primeiro3; atual3!=NULL; atual3=atual3->prox3){
		if(atual3->cod==locacao.cod){
			identificador3= 'V';	
			 a=0;
			 if(locacao.valor<=0){
			 	identificador3= 'V';	
				 b=0;
				 }
				 break;
		}
		if(locacao.valor<=0){
		 	identificador3= 'V';	
			 b=0;
		}
		
		
	}
	
	if (identificador3!='V' && (strlen(locacao.data_ent ) !=1 && (strlen(locacao.data_dev ) !=1))){
		//Guardando as informacoes
		Lista3* NovoLocacao=(Lista3*) malloc (sizeof(Lista3));
		strcpy(NovoLocacao->data_ent , locacao.data_ent );
		strcpy(NovoLocacao->data_dev , locacao.data_dev );
		NovoLocacao->cod= locacao.cod;
		NovoLocacao->valor= locacao.valor;
		NovoLocacao->prox3= primeiro3;
		gotoxy(15,10);
		printf("Cadastro efetuado com sucesso!");
		_sleep(1500);
		gotoxy(8,11);
		printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
		getch();
		return NovoLocacao;
	} else{
		gotoxy(21,11);
		printf("Cadastro inválido!");
		_sleep(1500);
		if(a==1){
			gotoxy(18,11);
			printf("Código já foi registrado!");
			_sleep(2000);
		}
		if(b==1){
			gotoxy(18,11);
			printf("   Valor invalído!");
			_sleep(2000);
		}
		
		gotoxy(8,11);
		printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
		getch();
		return primeiro3;
	}
}

void listar_locacao (Lista3* primeiro3){
	
	Lista3* atual3; //Ponteiro para percorrer a lista sem perder a referência do primeiro3 elemento da lista
	int c=0, d=5;
	//Imprimir os locacao da lista com as sua informações.
	for(atual3= primeiro3 ; atual3!= NULL; atual3= atual3->prox3)
		c+=6;
	
	gotoxy(1,1); 
	caixa(c);
	gotoxy(20,2);
	printf("LOCAÇÕES CADASTRADAS");
	for(atual3= primeiro3 ; atual3!= NULL; atual3= atual3->prox3){
		gotoxy(3,d++);
		printf ("Código: ");
		printf("%d", atual3->cod);
		gotoxy(3,d++);
		printf ("Data de Retirada: ");
		printf ("%s", atual3->data_ent);
		gotoxy(3,d++);
		printf ("Data de Devolução: ");
		printf ("%s", atual3->data_dev);
		gotoxy(3,d++);
		printf ("Valor da Locação: ");
		printf ("R$%2.f", atual3->valor);
		gotoxy(3,d++);
		gotoxy(3,d++);
	} 
	
	if (primeiro3==NULL){
		gotoxy(1,1); 
		caixa(0);
		gotoxy(20,2);
		printf("LOCAÇÕES CADASTRADAS");
		gotoxy(17,4);
		printf ("Nenhuma locação cadastrada!");
		_sleep(2000);
		gotoxy(8,4);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
		getch();
	}else{
		gotoxy(8,d++);
		printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
		getch();
	}
}

Lista3* excluir_locacao(Lista3 *primeiro3){

	Lista3 *anterior= NULL; //Ponteiro para saber o elemento anterior ao elemento atual3.
	Lista3 *atual3= primeiro3; //Ponteiro para percorrer a lista sem perder o primeiro3 elemento.
	int long cod;
	
	gotoxy(3,4);
	printf("Código da locação: ");
	fflush(stdin);
	scanf("%d", &cod);
	
	//Procurando o cliente na lista
	while(atual3!= NULL && atual3->cod!=cod){
		anterior= atual3;
		atual3= atual3->prox3;
	}
	//Mensagem caso cliente nao seja encontrado.
	if(atual3==NULL){
		gotoxy(22,4);
		printf ("Locação não encontrada!");
		_sleep(1500);
		gotoxy(3,4);
		printf ("     PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
		return primeiro3;
	}
	
	//Excluir o primeiro3 carro da lista
	if(anterior==NULL){
		gotoxy(3,4);
		printf("       Locação excluída com sucesso!");
		primeiro3= atual3->prox3;
		//Excluir do meio da lista.
	} else{
		gotoxy(3,4);
		printf("       Locação excluída com sucesso!");
		anterior->prox3= atual3->prox3;
	}
	//Desalocar o espaco da memoria.
	free(atual3);
	_sleep(1500);
	gotoxy(3,8);
	printf ("       PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU");
	return primeiro3;
}

//Função para alterar cadastro de locacao.
void alterar_locacao(Lista3* primeiro3){

	char data_ent_substituto[40],data_dev_substituto[40];
	int long cod;
	float valor_substituto;
	Lista3* atual3=primeiro3;
	
	//Requisitando o código do carro a ser alterado.
	gotoxy(3,5);
	printf ("Código da locação a ser alterado: ");
	fflush(stdin);
	scanf("%d", &cod);
	
	//Procurando o carro na lista
	while(atual3!= NULL && atual3->cod!=cod){
		atual3= atual3->prox3;
	}
	
	//alterando os dados do carro.
	if(atual3!=NULL){
		gotoxy(3,6);
		printf("Nova data de retirada: ");
		fflush(stdin); fgets(data_ent_substituto, 40, stdin);
		strcpy(atual3->data_ent, data_ent_substituto);
		gotoxy(3,7);
		printf ("Nova data de devolução: ");
		fflush(stdin); fgets(data_dev_substituto, 40, stdin); printf ("\n");
		strcpy(atual3->data_dev , data_dev_substituto);
		gotoxy(3,8);
		printf("Novo valor da locação: ");
		scanf("R$%f", valor_substituto);
		atual3->valor= valor_substituto;
		gotoxy(15,11);
		printf("Dados alterados com sucesso!");
		_sleep(1500);

	} else{
		gotoxy(15,11);
		printf("Locação não encontrado!");
		_sleep(1500);
	}
	_sleep(1500);
	gotoxy(8,11);
	printf ("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
	getch();
}




