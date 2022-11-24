#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

//Entrada: Inicialização das variáveis, do tabuleiro e das funções
char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void player1Move();
void player2Move();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{   

//Processamento: O tabuleiro é resetado, os participantes jogam até houver um vencedor, e ai o ganhador aparece na tela

	setlocale(LC_ALL, "Portuguese");
	char winner = ' ';
   	char response = ' ';
	int players = 0;
	
	
	printf("BEM-VINDO!\n");
	printf("QUANTOS JOGADORES IRÃO PARTICIPAR?? (1/2): ");
	scanf("%d", &players);
   do
   {
      winner = ' ';
      response = ' ';
      
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
        printBoard();

        player1Move();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)
        {
        	break;
        }
         
        if(players == 2){
        	printBoard();
         
        	player2Move();
         	winner = checkWinner();
         	if(winner != ' ' || checkFreeSpaces() == 0)
         		{
            		break;
         		}
		}
		else{
			computerMove();
         	winner = checkWinner();
         	if(winner != ' ' || checkFreeSpaces() == 0)
         	{
            	break;
         	}
		}
        
      	}
      	
      printBoard();
      printWinner(winner);

      	printf("\nQUER JOGAR NOVAMENTE? (Y/N): ");
      	scanf("%c");
      	scanf("%c", &response);
    	response = toupper(response);
    	if(response == 'Y'){
    	printf("QUANTOS JOGADORES IRÃO PARTICIPAR? (1/2): ");
    	scanf("%d", &players);
    	}
   } while (response == 'Y');

   printf("OBRIGADO POR JOGAR!");

   return 0;
}
//Função que resetará o tabuleiro assim que chamado.
void resetBoard()
{
for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
//Função para estilizar o tabuleiro do jogo
void printBoard()
{
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}
//função para checar se há espaços vazios.
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
//Função com os movimentos do jogador 1.
void player1Move()
{
   int x;
   int y;

   do
   {
      printf("INSERIR LINHA #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("INSIRA COLUNA #(1-3): ");
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' ')
      {
         printf("Movimento inválido!\n");
      }
      else
      {
         board[x][y] = PLAYER1;
         break;
      }
   } while (board[x][y] != ' ');
   
}
//Função que torna possível o multijogador e os movimentos do player 2.
void player2Move() 
{
   int x;
   int y;

   do
   {
      printf("INSERIR LINHA #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("INSERIR COLUNA#(1-3): ");
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' ')
      {
         printf("Movimento inválido!\n");
      }
      else
      {
         board[x][y] = PLAYER2;
         break;
      }
   } while (board[x][y] != ' ');
   
}

//Função que realiza os movimentos do adversário (o computador)
void computerMove()
{
   srand(time(0));
   int x;
   int y;

   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');
      
      board[x][y] = PLAYER2;
   }
   else
   {
      printWinner(' ');
   }
}
//Função que irá conferir o vencedor.
char checkWinner()
{
   //check rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}
//saída: mostrar quem ganhou a partida
void printWinner(char winner)
{
   if(winner == PLAYER1)
   {
      printf("JOGADOR 1 GANHOU!");
   }
   else if(winner == PLAYER2)
   {
      printf("JOGADOR 2 GANHOU!");
   }
   else{
      printf("EMPATE!");
   }
}
