#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o (acentua��o)
#include <string.h> //biblioteca respons�vel por cuidar das strings
//bibliotecas sempre no come�o do c�digo.

int registro() //fun��o respons�vel� por cadastrar os usuarios no sistema
{
	//inicio cria��o de variaveis/strings
	
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40]; 					//[] colchetes quer dizer que � uma string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria�ao de variaveis
	
	printf("Digite o CPF a ser cadastrado: \n"); //coleta de infos do user
	scanf("%s", cpf); 				//%s - armazena strings na variavel cpf, a informa��o digitada entrar� no lugar de %s
	
	strcpy(arquivo, cpf); 			//string copy - copia os valores de uma string
	
	FILE *file; 					//FILE - fun��o de CRIAR um arquivo. file arquivo a ser criado
	file = fopen(arquivo, "w"); 	//fopen - abra o arquivo tal. "w" vem de write, escreva um novo arquivo
	fprintf(file,cpf);				 // fprintf - SALVAR o arquivo digitado
	fclose(file);					//fclose - fechar o arquivo
	
	file = fopen(arquivo, "a");		//abrir o arquivo, "a" acessar o existente
	fprintf(file, ",");				//adicionei a virgula para separar as informa��es coletadas
	fclose(file);					//fechei o arquivo
	
	printf("Digite o NOME a ser cadastrado: \n"); //coleta dados do user
	scanf("%s",nome);							//%s armazena strings na variavel nome
	
	file = fopen(arquivo, "a");  //abrir o arquivo existente
	fprintf(file,nome);  		//SALVAR a informa��o
	fclose(file);				//fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo existente
	fprintf(file, ",");         //adi��o da virgula
	fclose(file);				//fechar arquivo
	
	printf("Digite o SOBRENOME a ser cadastrado: \n");		//coleta de dados do user
	scanf("%s",sobrenome);			//armazena strings na variavel sobrenome
	
	file = fopen(arquivo, "a");			//abrir arquivo existente
	fprintf(file,sobrenome);		//salvar info no arquivo
	fclose(file);					//fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo existente
	fprintf(file, ",");			//add virgula
	fclose(file);				//fechar arquivo
	
	printf("Digite o CARGO a ser cadastrado: \n");		//coleta de dados do usuario
	scanf("%s",cargo);				//armazena strings na variavel cargo
	
	file = fopen(arquivo, "a");		//abrir arquivo existente
	fprintf(file,cargo);			//salvar info no arquivo
	fclose(file);					//fechar arquivo
	
	system("pause");				//pausa o programa
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	//inicio cria��o das variaveis
	char cpf[40];			
	char conteudo[200];
	//fim da cria��o das variaveis
	
	printf("Digite o CPF a ser consultado: \n");		//coleta de dados do user
	scanf("%s",cpf);			//armazena string na variavel cpf
	
	FILE *file;			//busca o arquivo
	file = fopen(cpf, "r"); 			//"r" - vem de read, ler o arquivo
	
	if(file == NULL)			//se o arquivo estiver vazio/nao existir
	{
		printf("N�o foi poss�vel abrir o arquivo! CPF n�o localizado nos registros.\n");		//mensagem de retorno ao user
		system("pause");			//pausa sistema para ler a mensagem
	}
	
	while(fgets(conteudo, 200, file) != NULL) //WHILE - enquanto FGETS - (file gets) busque no arquivo
	{
		printf("\nEssas s�o as informa��es do Usu�rio: \n\n");		//apresenta as infos a serem consultadas pelo user
		printf("%s", conteudo); 			//infos coletadas
		printf("\n\n");			//estetico
		system("pause");			//pausa sistema para leitura da mensagem
	}	
	fclose(file);		//fecha o arquivo
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF do USU�RIO a ser DELETEADO: ");			//coleta de dado do user
	scanf("%s", cpf);			//armazena string na variavel cpf

	remove(cpf);			//exclui a string armazenada da variavel cpf
	
	FILE *file;			//busca arquivo
	file = fopen(cpf,"r");		//abre e l� arquivo
	
	if(file == NULL)			//se a informa��o nao constar no arquivo
	{
		printf("O usu�rio n�o se encontra no sistema! \n");		//mensagem de retorno
		system("pause");			//pausa o programa
	}
	
	fclose(file);		//fecha o arquivo
}

int main()
{
	int opcao=0; //definindo variaveis
	int laco=1; 
	char senhadigitada[10]="admin"; 		//cria��o de variavel string
	int comparacao;			//cria��o da variavel de compara��o
	setlocale(LC_ALL, "Portuguese");
	
	printf("~~~~ Cart�rio da Gatol�ndia ~~~~\n\n");			//cria��o da tela de login do usuario
	printf("Login de Administrador\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");			//strcmp - compara��o de strings
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;) 		//para quando
		{
		
		system("cls"); //limpar as infos da interface
		
			setlocale(LC_ALL, "Portuguese");  //computador vai entender que o texto est� em portugu�s. definindo linguagem.
		
			printf("~~~~ Cart�rio da Gatol�ndia ~~~~\n\n"); //In�cio do menu. SEMPRE utilizar o ; para indicar o comando pro PC.
			printf("\tMENU PRINCIPAL\n\n"); 
			printf("\t1 - Registro\n");
			printf("\t2 - Consulta\n");
			printf("\t3 - Deletar\n");
			printf("\t4 - Sair do sistema\n\n\n");
			printf("Escolha sua op��o:"); //fim do menu
		
			scanf("%d", &opcao); //scanf - coletar o que o user digitar. %d - armazenar na variavel opcao (&opcao) 
		
			system("cls"); //limpar as informa��es da tela
			
			switch(opcao)		//inicio da sele�ao do menu
			{	
				case 1:  // dois pontos para ditar a instru��o da op��o (no lugar dos colchetes)
				registro();	//chamada de fun��es
				break; // break funciona para encerrar a instru��o da op��o
				
				case 2:
				consulta();	//chamada de fun��es
				break;
				
				case 3:
				deletar();	//chamada de fun��es
				break;
				
				case 4:		//chama a fun��o
				printf("Obrigado por utilizar o sistema!\n");
				return 0;		//retorna valor 0, quebra la�o, fun��o, sai do sistema
				break;
				
				default: //se nao for um dos casos
					printf("Essa op��o n�o est� dispon�vel!\n");
					system("pause");
				break;
			}   //fim da sele��o
		
		}
	}
	
	else
		printf("Senha incorreta!");
		
}
