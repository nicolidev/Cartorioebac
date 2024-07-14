#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioeca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//Final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informações usuário
	scanf("%s",cpf);	//%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo,"w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,"CPF: "); //Identifica a informação que virá a seguir
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,"\nNome: "); //Definindo qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	printf("Digite o nome a ser cadastrado:"); //Mensagem de comunicação com o usuário
	scanf("%s" , nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,nome); //Definindo qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,"\nSobrenome: "); //Definindo qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:"); //Mensagem de comunicação com o usuário
	scanf("%s" , sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //Comando para abrir o arquivo
	fprintf(file,sobrenome); //Definind qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,"\nCargo: "); //Definindo qual arquivo o sistema deve abrir
	fclose(file); //Comando para fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); //Mensagem de comunicação com o usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Comando para abrir o arquivo
	fprintf(file,cargo); //Definindo qual arquivo o sistema deve abrir
	fprintf(file, "\n\n"); //Pulando linha
	fclose(file); //Comando para fechar o arquivo
	
	system("pause"); //Pause na tela	
	
}

int consulta() //Função responsável por consultar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:"); //Mensagem de comunicação com o usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //Acessando o arquivo
	file = fopen(cpf,"r"); //Abrir/ler o arquivo, "r" significa ler
	
	if(file == NULL) //Comando caso o arquivo for igual a nulo
	{
		printf("Arquivo não localizado.\n\n"); //Mensagem de comunicação com o usuário
	}
	
	printf("\nEssas são as informações do usuário:\n\n"); //Mensagem de comunicação com o usuário
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);	 //%s refere-se a string	
	}
	
	system("pause");
	
	
}

int deletar () //Função responsável por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Mensagem de comunicação com o usuário
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); //Função importado da biblioteca + deleta o arquivo conforme o nome do arquivo informado ()
	
	FILE *file; //Acessando o arquivo
	file = fopen(cpf,"r"); //Abrir/ler o arquivo, "r" significa ler
	
	if(file == NULL)	//Comando caso o arquivo for igual a nulo
	{
		printf("Usuário não encontrado no sistema. \n"); //Mensagem de comunicação com o usuário
		system("pause"); //Pause na tela
	}
	
	else(cpf == 0); //Comando caso o arquivo informado for existente   
	{
	printf("Usuário deletado com sucesso. \n");	//Mensagem de comunicação com o usuário 
	system("pause"); //Pause na tela
	}
	
}

int main ()
{
	int opcao=0; //Definindo das variáveis
	int laco=1;  //Criando variável do tipo 1
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ### \n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d" , &opcao); //Armazendo a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.");
			return 0;
			break;
			
			default: //chamda de funções
			printf("Essa opção não está disponível.\n\n"); //Aviso ao usuário de erro de opção digitada
			system("pause"); //Pause na tela 
			break;
			
			//Fim da seleção	
		}
	}
}
