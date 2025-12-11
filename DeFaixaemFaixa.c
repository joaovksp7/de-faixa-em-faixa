#include <stdio.h>        // printf e scanf 
#include <conio.h>        // getch
#include <string.h>       // strcmp
#include <stdlib.h>       // exit    
#include <locale.h>       // setlocale

#define TRUE   1         // constante VERDADEIRA


typedef struct {          // registro 
       int  cod;            // identificador numérico para organizar a árvore binária
	   char questao[1000];  // texto da pergunta ou a recomendação final
} INFORMACAO;
       
typedef struct arv {
       INFORMACAO info;   // dados do registro
       struct arv* subd;  // ponteiro para o nodo da direita
       struct arv* sube;  // ponteiro para o nodo da esquerda
} ARVORE; 



void imprime_ARVORE  ( ARVORE *p );         // visualiza todas as folhas da arvore
void insere_recursivo( ARVORE** r, int cod ); // funo recursiva que insere os dados informados no inserir_dados
void inserir_dados ( ARVORE *p, int cod );  // insere os dados da arvore
void perguntas (ARVORE **p);


void imprime_ARVORE( ARVORE *p){
    if( p != NULL ) {
        // Verifica se é um nó folha (sem filhos), o que significa que é uma resposta final/recomendação
        if(p->sube == NULL && p->subd == NULL){
			printf( "\n /--------------------------------------------------------/ \n" ); 
        	printf( "\n %s \n", p->info.questao);
		}
        
        imprime_ARVORE( p->sube ); // Navega recursivamente para a esquerda
        
        imprime_ARVORE( p->subd ); // Navega recursivamente para a direita
    }
}

void insere_recursivo ( ARVORE** p, int cod, const char questao[500] ) {
	
	// Se o ponteiro for nulo, chegamos em uma posição vazia para inserir o novo nó
	if (!*p){
		ARVORE *no = (ARVORE *) malloc (sizeof(ARVORE)); // Aloca memória dinamicamente para o novo nó
		strcpy(no->info.questao, questao); // Copia o texto da questão/resposta
		no->info.cod = cod;
		no->sube = NULL; // Inicializa filho esquerdo como nulo
		no->subd = NULL; // Inicializa filho direito como nulo
		*p = no;         // Faz o ponteiro pai apontar para o novo nó
	} else{
		// Lógica da Árvore Binária de Busca (BST): menores à esquerda, maiores à direita
		if (cod < (*p)->info.cod)
			insere_recursivo(&(*p)->sube, cod, questao); // Insere na subárvore esquerda
			
		else if (cod > (*p)->info.cod)
			insere_recursivo(&(*p)->subd, cod, questao); // Insere na subárvore direita
			
		else
			printf( "Ja existe!\n" ); // Evita códigos duplicados
	}
}

void insere_dados (ARVORE **r){
	// Constroi a base de conhecimento (árvore de decisão) manualmente
	
	// Raiz: Urbano vs Natureza
    insere_recursivo(&(*r), 16, "Voce prefere: [1] Um destino mais urbano ou [2] Um destino com natureza e paisagens");

    // RAMO ESQUERDO: URBANO
    insere_recursivo(&(*r), 8,  "Voce prefere: [1] Um destino mais historico e antigo ou [2] Um destino mais agitado e moderno ");
        
        // Urbano -> Histrico
        insere_recursivo(&(*r), 4,  "Voce prefere: [1] Um destino para aproveitar melhor de dia ou [2] A noite");
            // Dia
            insere_recursivo(&(*r), 2,  "Voce prefere: [1] Um destino mais sofisticado ou [2] Um destino mais acessivel");
            insere_recursivo(&(*r), 1,  "RECOMENDAMOS PARA VOCE: Oktoberfest \n \n CIDADE: Santa Cruz do Sul \n VALOR: A partir de R$ 35,00 (Mais alimentao e bebidas) \n CONTATO: assemp@assempscs.com.br \n");
            insere_recursivo(&(*r), 3,  "RECOMENDAMOS PARA VOCE: Museu de Arte do Rio Grande do Sul (MARGS) \n \n CIDADE: Porto Alegre \n VALOR: Gratuito \n CONTATO: https://margs.rs.gov.br \n");
            // Noite
            insere_recursivo(&(*r), 6,  "Voce prefere: [1] Um destino mais sofisticado ou [2] Um destino mais acessivel");
            insere_recursivo(&(*r), 5,  "RECOMENDAMOS PARA VOCE: Chateau de La Fondue \n \n CIDADE: Gramado \n VALOR: A partir R$ 169,00 \n CONTATO: (54) 9962-53318 \n");
            insere_recursivo(&(*r), 7,  "RECOMENDAMOS PARA VOCE: Mercado Público (Bares e Jantar) \n \n CIDADE: Porto Alegre \n VALOR: Acessvel \n CONTATO: https://mercadopublico.com.br \n");

        // Urbano -> Moderno
        insere_recursivo(&(*r), 12, "Voce prefere: [1] Um destino para aproveitar melhor de dia ou [2] A noite");
            // Dia
            insere_recursivo(&(*r), 10, "Voce prefere: [1] Um destino mais sofisticado ou [2] Um destino mais acessivel");
            insere_recursivo(&(*r), 9,  "RECOMENDAMOS PARA VOCE: Rua Padre Chagas (Moinhos de Vento) \n \n CIDADE: Porto Alegre \n VALOR: Alto (Gastronomia e Lojas) \n CONTATO: NULL \n");
            insere_recursivo(&(*r), 11, "RECOMENDAMOS PARA VOCE: Parque da Redenção \n \n CIDADE: Porto Alegre \n VALOR: Acessvel \n CONTATO: NULL \n");
            // Noite
            insere_recursivo(&(*r), 14, "Voce prefere: [1] Um destino mais sofisticado ou [2] Um destino mais acessivel");
            insere_recursivo(&(*r), 13, "RECOMENDAMOS PARA VOCE: Cais Embarcadero \n \n CIDADE: Porto Alegre \n VALOR: Entrada Franca (mais alimentao e bebidas) \n CONTATO: https://caisembarcadero.com.br \n");
            insere_recursivo(&(*r), 15, "RECOMENDAMOS PARA VOCE: Bares da Cidade Baixa \n \n CIDADE: Porto Alegre \n VALOR: Acessvel \n CONTATO: NULL \n");

    // RAMO DIREITO: NATUREZA
    insere_recursivo(&(*r), 24, "Voce prefere: [1] Um destino com clima frio/temperado ou [2] Com clima quente, com foco em sol e agua");
        
        // Natureza -> Frio (Serra)
        insere_recursivo(&(*r), 20, "Voce prefere: [1] Um destino para aproveitar melhor de dia ou [2] A noite");
            // Dia
            insere_recursivo(&(*r), 18, "Voce prefere: [1] Um destino mais sofisticado ou [2] Um destino mais acessivel");
            insere_recursivo(&(*r), 17, "RECOMENDAMOS PARA VOCE: Vinícola Casa Valduga \n \n CIDADE: Bento Gonalves \n VALOR: A partir de R$ 80,00 \n CONTATO: (54) 2105-3154 \n");
            insere_recursivo(&(*r), 19, "RECOMENDAMOS PARA VOCE: Lago Negro \n \n CIDADE: Gramado \n VALOR: Gratuito (Pedalinho pago) \n CONTATO: (54) 99634-7551 \n");
            // Noite
            insere_recursivo(&(*r), 22, "Voce prefere: [1] Um destino mais sofisticado ou [2] Um destino mais acessivel");
            insere_recursivo(&(*r), 21, "RECOMENDAMOS PARA VOCE: Rua Coberta (Gastronomia) \n \n CIDADE: Gramado \n VALOR: Alto (Gastronomia e Lojas) \n CONTATO: @ruacobertaoficial \n");
            insere_recursivo(&(*r), 23, "RECOMENDAMOS PARA VOCE: Catedral de Pedra (Show de Luzes) \n \n CIDADE: Canela \n VALOR: Gratuito \n CONTATO: @catedraldepedracanela \n");

        // Natureza -> Quente (Litoral/Vero)
        insere_recursivo(&(*r), 28, "Voce prefere: [1] Um destino para aproveitar melhor de dia ou [2] A noite");
            // Dia
            insere_recursivo(&(*r), 26, "Voce prefere: [1] Um destino mais sofisticado ou [2] Um destino mais acessivel");
            insere_recursivo(&(*r), 25, "RECOMENDAMOS PARA VOCE: Parque da Guarita \n \n CIDADE: Torres \n VALOR: A partir de R$ 20,00 \n CONTATO: (51) 3626-9100 \n");
            insere_recursivo(&(*r), 27, "RECOMENDAMOS PARA VOCE: Molhes da Barra e Praia do Cassino \n \n CIDADE: Rio Grande \n VALOR: Gratuito \n CONTATO: NULL \n");
            // Noite
            insere_recursivo(&(*r), 30, "Voce prefere: [1] Um destino mais sofisticado ou [2] Um destino mais acessivel");
            insere_recursivo(&(*r), 29, "RECOMENDAMOS PARA VOCE: Restaurante Cantinho do Pescador \n \n CIDADE: Torres \n VALOR: Alto (Gastronomia e Lojas) \n CONTATO: (51) 3664-3036 \n");
            insere_recursivo(&(*r), 31, "RECOMENDAMOS PARA VOCE: Centrinho de Capão e Calçadão \n \n CIDADE: Capo da Canoa \n VALOR: Gratuito \n CONTATO:NULL\n");
}

void perguntas(ARVORE **p){
    int resp;
    if( p != NULL ){
        printf( " %s \n", (*p)->info.questao);
        // Verifica se é um nó folha: se for, mostra a mensagem de retorno e encerra a recursão
        if ((*p)->sube == NULL || (*p)->subd == NULL){
            printf("Pressione alguma tecla para voltar ao menu principal");
            return;
        }
        fflush(stdin);
        scanf("%d", &resp); // Lê a resposta do usuário (1 ou 2)
        system("cls");      // Limpa a tela para a próxima pergunta
        
        // Navegação baseada na escolha:
        if(resp == 1)
            perguntas( &(*p)->sube ); // Vai para a esquerda (opção 1)
        else if(resp == 2)
            perguntas( &(*p)->subd ); // Vai para a direita (opção 2)
        else
            perguntas(&(*p)); // Se opção inválida, repete a mesma pergunta
    }
    printf("\n");
}


int main( ) {
	           
    ARVORE *r = NULL;                            // declaracao da ARVORE, varivel do tipo ARVORE = ARVORE de ponteiros
    int op;	                                     // Variável para armazenar a opção do menu
    insere_dados(&r);                            // Inicializa a árvore com as perguntas e respostas
	    
    setlocale(LC_ALL, "Portuguese"); // Define a localização para permitir acentuação correta
    while( TRUE ){
         // Exibição do Menu Principal
         printf( "\n /--------------------------------------------------------/" ); 
         printf( "\n De Faixa em Faixa - Menu                             " );
         printf( "\n [1] Encontrar Ponto Turístico                        " );
         printf( "\n [2] Visualizar Todos os Pontos Turisticos            " );
		 printf( "\n [3] Informações                                      " );         
         printf( "\n [0] Sair                                             " );         
         printf( "\n /--------------------------------------------------------/" );      
         printf( "\n Opcao: " );
         scanf("%s", &op); // tecla de opcao do menu

        switch( op ) {
           case '1':   // rotina cria ARVORE       
                   perguntas( &r ); // Inicia o sistema de perguntas e respostas
                   break;
                                
           case '2':   // rotina inclui nodo no final da ARVORE (folha)
                   imprime_ARVORE( r ); // Exibe todas as folhas (destinos possíveis)
                   break;
                      
           case '3':   // rotina exclui nodo da ARVORE
         printf( "\n /---------------------------------------------------------/ " ); 
         printf( "\n De Faixa em Faixa - Informações                       " );
         printf( "\n\n                     ATENÇÃO!                        " );
         printf( "\n Todas as informações e dicas mostrados nesse algorit- " );
		 printf( "\n mo foram retiradas dos sites ou redes sociais dos des-" );         
         printf( "\n tinos turísticos indicados!                           " );         
         printf( "\n /---------------------------------------------------------/ \n" );      
                   break;
           
           case '0':  // termino do programa                                                 
                   exit( 1 ); 
                   break;                
                   
           default : 
                   printf( "\n Digite uma opcao!" );
                   break;
        } // switch( op )
        
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        system("pause");       // parada da tela, aguarda o usuário pressionar algo
        system("cls");         // limpa a tela do console antes de reexibir o menu
        printf( "\n" );
     } // fim do while
     
 return 0;
} // fim da função main