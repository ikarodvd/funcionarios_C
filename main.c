#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <string.h>

typedef struct funcionarios aux; //typedef da struct para facilitar na hora de declarar e também na hora de ler o tamanho 
//da mesma no momento de passar dados para o arquivo ou para lê-los
static int x = 0; // "contador mestre" utilizado para verificações de posições dos funcionários cadastrados, importante
struct funcionarios{
    char nome[40];
    int idade;
    int horas;
    int id;
};
aux funcionarios [21]; //criada um vetor de struct 

void menu (){ //menu utilizado no int main() para escolha do usuário
    printf ("\n1 Ler registro\n");
    printf ("2 Ordenar por ordem alfabetica\n");
    printf ("3 Ordenar por horas trabalhadas\n");
    printf ("4 Alterar dados do funcionario\n");
    printf ("5 Apagar funcionario\n");
    printf ("6 Salvar\n");
    printf ("0 Sair\n");
}

void ordenarpornome(){ // ordena por ordem alfabética os funcionários cadastrados no programa
       struct funcionarios temp; // variável auxiliar para manter o valor comparado que será permutado na ordenação,
       //garantindo que não haja perca de dados durante o processo
            for (int i = 0 ; i < x ; i++){
                for (int j = 0 ; j < x ; j ++ ){
                if (funcionarios[j].horas<funcionarios[j+1].horas){
                    temp = funcionarios[j];
                    funcionarios[j]=funcionarios[j+1];
                    funcionarios[j+1]=temp;
                    }
                }
            }
    printf("\nOrdenados por nome:\n");

     for(int i = 0; i < x; ++i) // estrura de repetição que vai de 0 até o valor de usuários cadastrados (máximo 21)
    {  
		printf("\n ID: %d", funcionarios[i].id); // exibe o ID do funcionário, seu código de identificação
		printf("\n Funcionario: %s", funcionarios[i].nome); // exibe o nome do funcionário 
		printf("\n Idade: %d", funcionarios[i].idade);	//exibe a idade do funcionário
        printf("\n Horas: %d", funcionarios[i].horas); //exibe as horas trabalhadas pelo respectivo funcionário
    }
		
}

void Ordenadoporhoras(){ //ordena os funcionários utilizando como parametro as horas trabalhadas
 	struct funcionarios temp; // variável auxiliar para manter o valor comparado que será permutado na ordenação,
       //garantindo que não haja perca de dados durante o processo 
    for(int i = 0; i < x; i++){
        for(int o = i + 1; o < x; o++){
            if(funcionarios[o].horas < funcionarios[i].horas)
            {
                temp = funcionarios[i];
                funcionarios[i] = funcionarios[o]; 
                funcionarios[o] = temp;
            }
        }
    }
    printf("\nOrdenados por hora:\n");
    for(int k = 0; k < x; k++)	{
		printf("\n ID: %d",funcionarios[k].id);//informa o ID do respectivo funcionário
		printf("\n Funcionario: %s",funcionarios[k].nome);//informa o nome do funcionário
		printf("\n Idade: %d",funcionarios[k].idade);//informa a idade do funcionário
		printf("\n Horas: %d",funcionarios[k].horas);//informa as horas trabalhadas pelo respectivo funcionário
	}

}

void cadastro (){ //função utilizada para cadastrar novos funcionários no programa

    if (x==21){//verifica se o valor de x, que é "contador global" não é igual ao tamanho máximo permitido de funcionários 
        printf ("NAO HA ESPACOS PARA NOVOS USUARIOS\n");// caso seja, essa mensagem é exibida, informando que o programa atingiu 
        //sua capacidade máxima de funcionários
    }else{ // caso seja vavoravel a condicação, as acoes abaixo acontecerão
        printf ("Informe o nome do funcionario\n"); // solicita noma do funcionário
        fflush(stdin); // limpa o buffer de memória do dispositivo de entrada padrão. Apesar de que o getchar ser mais recomendável,
        //ele apresentou algumas falhas, sendo necessário trocá-lo pelo fflush
        gets(funcionarios[x].nome);//grava o nome do funcionário recentemente cadastrado para a posição x da struct funcionários
        printf ("Informe a idade do funcionario");//solicita idade
        scanf ("%i", &funcionarios[x].idade);//grava a idade na posicao x do vetor de struct funcionários
        printf ("Informe as horas trabalhadas do funcionario");//solicita horas trabalhadas pelo funcionário
        scanf ("%i",&funcionarios[x].horas); // grava as horas trabalhadas na posição x da struct funcionários 
        funcionarios[x].id = x;// define o valor do id (número de identificação de funcionário no referido sistema) para que seja mais fácil
        //a localização do mesmo
        x++;// incrementa o valor de x para x=x+1, para que o próximo funcionário não seja grava incorretamente em outro local do vetor de structs
    }

}

void apagar(){ // apaga um funcionário presente no programa
int id; // variavel auxiliar utilizada para comparar os números de identificações dos usuários
int auxc = 0;
	system("cls");// limpa o terminal
    printf("Insira o id do funcionarios que deseja excluir:\n");//solicita o número de identificação do funcionário a ser deletado
    scanf("%i", &id);//armazena tal valor na variável id
    for(int i = 0; i < x; i++){ //for de 0 até x, que se trata do número máximo de usuários cadastrados no sistema
        if(id == funcionarios[i].id){ 
            for(int j = i; j < x; j++) {
                funcionarios[j] = funcionarios[j + 1];
            }
            strcpy(funcionarios[x].nome, ""); // remove o nome da posição x e coloca um "" no lugar
            funcionarios[x].idade = 0; // zera a idade dessa posição do vetor
            funcionarios[x].horas = 0;// zera a idade dessa posição do vetor 
            x--;//diminui uma posição do vetor para que o próximo usuário cadastrado possa utilizá-la, garantindo que o programa não fique com espaçoes no vetor sem serem utilizados pelo usuário
            printf("\nFuncionario deletado.\n"); //informa sucesso ao deletar o funcionário
            getch(); //aguarda ação do usuário pelo dispositivo de entrada padrão
            auxc = 1; 
            for(int k = 0; k < x; k++)  {
                funcionarios[k].id = k;
            }
        }
    } if(auxc == 0){   // caso não seja válido o valor do usuário     
        printf("\nCadastro invalido\n");//mensagem de erro exibida no terminal
        getch();//espera ação do usuário através do dispositivo de entrada padrão
    }
	
}

void alterar(){ //altera informações de determinado usuário do sistema
    int id, ope; //variaveis auxiliares necessárias para a função 
    system("cls"); // limpa o terminal
   
    printf("\nDigite o ID do funcionario: ");
    scanf("%d", &id);//grava o ID do funcionário 

    printf("Nome:  %s\n", funcionarios[id].nome); //exibe o nome do usuario na posicao id digitida
    printf("Idade:  %d\n", funcionarios[id].idade);//exibe a idade do usuario na posicao id digitida
    printf("Horas Trabalhadas:  %d \n", funcionarios[id].horas);//exibe as horas trabalhadas do usuario na posicao id digitida
	printf("\n\n 1- mudar nome\n");// informa se o usuário deseja mudar o nome
	printf(" 2- mudar idade\n"); // ou a idade
	printf(" 3- mudar horas trabalhadas\n"); // ou as horas trabalhadas
	scanf("%d", &ope);//grava a ação digitada pelo usuário

	switch (ope)// switch (escolha)a partir da ação do usuário 
	{

		case 1:		
			mudar_nome(id); //invoca a função mudar_nome
		break;

		case 2:
			mudar_idade(id);//invoca a função mudar_idade
		break;
		case 3:
			mudar_horas(id);//invoca a função mudar_horas
		break;
		default:
			system("cls");// limpa  terminal
			printf("\ninvalido\n"); // caso a opção digitada não seja uma opção válida
			system("pause"); // pausa o terminal
		break;
	}
}

void mudar_nome(int id){ // muda o nome de um funcionário registrado no programa atráves do switch case 	
	system("cls");
	printf("\nNome: %s\n", funcionarios[id].nome); //informa o nome antigo
	printf("\nDigite o novo nome: ");
	fflush(stdin);
    gets(funcionarios[id].nome) ;// grava o novo nome
	printf("\nFuncionario atualizado com sucesso!\n");
	system("pause"); //pausa o terminal
}

void mudar_idade(int id)// muda a idade de um funcionário registrado no programa atráves do switch case
{
	system("cls");
	printf("\nIdade atual: %d\n", funcionarios[id].idade);//informa a idade antiga
	printf("\nRegistre a nova idade: ");
	scanf("%d", &funcionarios[id].idade);// grava nova idade
	system("cls");
	printf("Idade atualizada com sucesso!\n");
	system("pause");//pausa o terminal
}


void mudar_horas(int id){// muda as horas trabalhadas de um funcionário registrado no programa atráves do switch case
    system("cls");
	printf("Horas trabalhadas atual: %d\n", funcionarios[id].horas);//informa as horas trabalhadas antiga
    printf("Digite as horas trabalhadas atualizadas: ");
    scanf("%d", &funcionarios[id].horas);// grava novas horas trabalhadas
    system("cls");
    printf("Horas atualizada com sucesso!\n");
	system("pause");
}
void escrita(); // prototipo da função escrita (), foi utilizdo esse método de declaração para melhorar a construção do programa
//garantindo uma boa separação do que são as funções de arquivo de funções comuns às funções do programa
void leitura();// prototipo da função leitura (), foi utilizdo esse método de declaração para melhorar a construção do programa
//garantindo uma boa separação do que são as funções de arquivo de funções comuns às funções do programa
int main(){ 
leitura(); // invoca a função leitura para gravar dados no vetor de structs

    int op; // operador para registrar a escolha do usuário para o do while
    do {
        menu(); //exibe o menu do usuário
        scanf ("%i",&op); // verifica a escolha do usuário 
        switch (op)
        {
        case 1:
            cadastro(); // invoca a função cadastro()
        break;
        
        case 2:
            ordenarpornome(); //invoca a função ordenarpornome()
            
            break;
        
        case 3:
            Ordenadoporhoras(); //invoca a função Ordenarporhoras()
            break;
        
        case 4:
            alterar(); //invoca a função alterar()
            
            break;
        
        case 5:
            apagar(); //invoca a função apagar();
            
            break;
        case 0: //sai do switch case e volta para o while, que também será encerrado, dando fim a execução do programa

        break;
        case 6:
            escrita(); // invoca a função escrita
        break; 

        default:
            //retorna o própio menu qunado o usuário digita um valor invalido para o switch case
            break;
        }

    }while(op!=0); // executa o programa enquanto o op é diferente de 0 

}


escrita(){ // grava os dados presentes no vetor de struct no arquivo txt
    FILE* arq = fopen ("funcionarios.txt","w"); // abre, a partir da variavel arq, o arquivo "funcionarios.txt"
    if(arq!=NULL){ 
        for(int i = 0 ; i < x ; i++){ // for de 0 até a quantidade máxima de funcionários cadastrados
            fwrite(&funcionarios[i],sizeof(aux),1,arq); // grava os funcionários no arquivo
        }
        printf("FUNCIONARIOS GRAVADOS NA MEMORIA\n"); // informa sucesso
    }else{
        printf ("erro!\n");//informa erro
    }
    getch(); //aguarda acao do usuario a partir do dispositivo de entrada padrão
    fclose(arq); // fecha o arquivo aberto pela variavel arq, garantindo que todos os dados manipulados durante o processo
    //sejam salvos
}
leitura(){ // realiza a leitura dos dados do arquivo para a struct de funcionarios
    FILE* arq = fopen("funcionarios.txt","r"); // abre o arquivo em modo leitura, garantindo que não haja o risco de perca dos dados presentes nele
    aux temporal; //criada uma variável temporária do tipo aux(typedef de funcionarios)
    if(arq!=NULL){
        while(fread(&temporal,sizeof(aux),1,arq)==1){
            funcionarios[x]=temporal; // transfere os dados da variavel temporária para a posição x do "contador global"
            //que, no caso da primeira execução do programa, é igual a zero
            x++;//incrementa em +1 o valor de x para que seja armazenada, na próxima posição do vetor, a próxima informação do funcionário presente no arquivo
        }
    }else{
        printf ("ERRO! SAINDO\n"); //informa erro ao abrir o arquivo
    }
    fclose(arq); // fecha o arquivo aberto pela variavel arq, garantindo que todos os dados manipulados durante o processo
    //sejam salvos
}