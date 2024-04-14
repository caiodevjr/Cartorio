#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região (acentuação)
#include <string.h> //biblioteca responsável por cuidar das strings
//bibliotecas sempre no começo do código.

int registro() //função responsávelç por cadastrar os usuarios no sistema
{
	//inicio criação de variaveis/strings
	
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40]; 					//[] colchetes quer dizer que é uma string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criaçao de variaveis
	
	printf("Digite o CPF a ser cadastrado: \n"); //coleta de infos do user
	scanf("%s", cpf); 				//%s - armazena strings na variavel cpf, a informação digitada entrará no lugar de %s
	
	strcpy(arquivo, cpf); 			//string copy - copia os valores de uma string
	
	FILE *file; 					//FILE - função de CRIAR um arquivo. file arquivo a ser criado
	file = fopen(arquivo, "w"); 	//fopen - abra o arquivo tal. "w" vem de write, escreva um novo arquivo
	fprintf(file,cpf);				 // fprintf - SALVAR o arquivo digitado
	fclose(file);					//fclose - fechar o arquivo
	
	file = fopen(arquivo, "a");		//abrir o arquivo, "a" acessar o existente
	fprintf(file, ",");				//adicionei a virgula para separar as informações coletadas
	fclose(file);					//fechei o arquivo
	
	printf("Digite o NOME a ser cadastrado: \n"); //coleta dados do user
	scanf("%s",nome);							//%s armazena strings na variavel nome
	
	file = fopen(arquivo, "a");  //abrir o arquivo existente
	fprintf(file,nome);  		//SALVAR a informação
	fclose(file);				//fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo existente
	fprintf(file, ",");         //adição da virgula
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
	
	//inicio criação das variaveis
	char cpf[40];			
	char conteudo[200];
	//fim da criação das variaveis
	
	printf("Digite o CPF a ser consultado: \n");		//coleta de dados do user
	scanf("%s",cpf);			//armazena string na variavel cpf
	
	FILE *file;			//busca o arquivo
	file = fopen(cpf, "r"); 			//"r" - vem de read, ler o arquivo
	
	if(file == NULL)			//se o arquivo estiver vazio/nao existir
	{
		printf("Não foi possível abrir o arquivo! CPF não localizado nos registros.\n");		//mensagem de retorno ao user
		system("pause");			//pausa sistema para ler a mensagem
	}
	
	while(fgets(conteudo, 200, file) != NULL) //WHILE - enquanto FGETS - (file gets) busque no arquivo
	{
		printf("\nEssas são as informações do Usuário: \n\n");		//apresenta as infos a serem consultadas pelo user
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
	
	printf("Digite o CPF do USUÁRIO a ser DELETEADO: ");			//coleta de dado do user
	scanf("%s", cpf);			//armazena string na variavel cpf

	remove(cpf);			//exclui a string armazenada da variavel cpf
	
	FILE *file;			//busca arquivo
	file = fopen(cpf,"r");		//abre e lê arquivo
	
	if(file == NULL)			//se a informação nao constar no arquivo
	{
		printf("O usuário não se encontra no sistema! \n");		//mensagem de retorno
		system("pause");			//pausa o programa
	}
	
	fclose(file);		//fecha o arquivo
}

int main()
{
	int opcao=0; //definindo variaveis
	int laco=1; 
	char senhadigitada[10]="admin"; 		//criação de variavel string
	int comparacao;			//criação da variavel de comparação
	setlocale(LC_ALL, "Portuguese");
	
	printf("~~~~ Cartório da Gatolândia ~~~~\n\n");			//criação da tela de login do usuario
	printf("Login de Administrador\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");			//strcmp - comparação de strings
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;) 		//para quando
		{
		
		system("cls"); //limpar as infos da interface
		
			setlocale(LC_ALL, "Portuguese");  //computador vai entender que o texto está em português. definindo linguagem.
		
			printf("~~~~ Cartório da Gatolândia ~~~~\n\n"); //Início do menu. SEMPRE utilizar o ; para indicar o comando pro PC.
			printf("\tMENU PRINCIPAL\n\n"); 
			printf("\t1 - Registro\n");
			printf("\t2 - Consulta\n");
			printf("\t3 - Deletar\n");
			printf("\t4 - Sair do sistema\n\n\n");
			printf("Escolha sua opção:"); //fim do menu
		
			scanf("%d", &opcao); //scanf - coletar o que o user digitar. %d - armazenar na variavel opcao (&opcao) 
		
			system("cls"); //limpar as informações da tela
			
			switch(opcao)		//inicio da seleçao do menu
			{	
				case 1:  // dois pontos para ditar a instrução da opção (no lugar dos colchetes)
				registro();	//chamada de funções
				break; // break funciona para encerrar a instrução da opção
				
				case 2:
				consulta();	//chamada de funções
				break;
				
				case 3:
				deletar();	//chamada de funções
				break;
				
				case 4:		//chama a função
				printf("Obrigado por utilizar o sistema!\n");
				return 0;		//retorna valor 0, quebra laço, função, sai do sistema
				break;
				
				default: //se nao for um dos casos
					printf("Essa opção não está disponível!\n");
					system("pause");
				break;
			}   //fim da seleção
		
		}
	}
	
	else
		printf("Senha incorreta!");
		
}
