#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioeca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//Final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informa��es usu�rio
	scanf("%s",cpf);	//%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo,"w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,"CPF: "); //Identifica a informa��o que vir� a seguir
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,"\nNome: "); //Definindo qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	printf("Digite o nome a ser cadastrado:"); //Mensagem de comunica��o com o usu�rio
	scanf("%s" , nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,nome); //Definindo qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,"\nSobrenome: "); //Definindo qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:"); //Mensagem de comunica��o com o usu�rio
	scanf("%s" , sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //Comando para abrir o arquivo
	fprintf(file,sobrenome); //Definind qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,"\nCargo: "); //Definindo qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //Mensagem de comunica��o com o usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,cargo); //Definindo qual arquivo o sistema deve abrir
	fprintf(file, "\n\n"); //Pulando linha
	fclose(file); //Comando para fechar o arquivo
	
	system("pause"); //Pause na tela	
	
}

int consulta() //Fun��o respons�vel por consultar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:"); //Mensagem de comunica��o com o usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //Acessando o arquivo
	file = fopen(cpf,"r"); //Abrir/ler o arquivo, "r" significa ler
	
	if(file == NULL) //Comando caso o arquivo for igual a nulo
	{
		printf("Arquivo n�o localizado.\n\n"); //Mensagem de comunica��o com o usu�rio
	}
	
	printf("\nEssas s�o as informa��es do usu�rio:\n\n"); //Mensagem de comunica��o com o usu�rio
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);	 //%s refere-se a string	
	}
	
	system("pause");
	
	
}

int deletar () //Fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Mensagem de comunica��o com o usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //Fun��o importado da biblioteca + deleta o arquivo conforme o nome do arquivo informado ()
	
	FILE *file; //Acessando o arquivo
	file = fopen(cpf,"r"); //Abrir/ler o arquivo, "r" significa ler
	
	if(file == NULL)	//Comando caso o arquivo for igual a nulo
	{
		printf("Usu�rio n�o encontrado no sistema. \n"); //Mensagem de comunica��o com o usu�rio
		system("pause"); //Pause na tela
	}
	
	else(cpf == 0); //Comando caso o arquivo informado for existente   
	{
	printf("Usu�rio deletado com sucesso. \n");	//Mensagem de comunica��o com o usu�rio 
	system("pause"); //Pause na tela
	}
	
}

int main ()
{
	int opcao=0; //Definindo das vari�veis
	int laco=1;  //Criando vari�vel do tipo 1
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ### \n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazendo a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.");
			return 0;
			break;
			
			default: //chamda de fun��es
			printf("Essa op��o n�o est� dispon�vel.\n\n"); //Aviso ao usu�rio de erro de op��o digitada
			system("pause"); //Pause na tela 
			break;
			
			//Fim da sele��o	
		}
	}
}
