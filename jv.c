#include <stdio.h>
#include <string.h>
void mostrar(char tabuleiro[10]){
int l, c, i = 0;
for(l = 0; l < 3; l++){
for(c = 0; c < 3; c++){
printf("[%c] ", tabuleiro[i]);
i++;
}
printf("\n");
}
}

int verificar(char tabuleiro[10], int vez){
int i, contador = 0;
for(i = 0; i < 9; i++){
if(tabuleiro[i] == 'X' || tabuleiro[i] == 'O') contador++;
}
if((tabuleiro[0] == ((vez % 2 == 0)?'O':'X') && tabuleiro[4] == ((vez % 2 == 0)?'O':'X') && tabuleiro[8] == ((vez % 2 == 0)?'O':'X')) ||
(tabuleiro[2] == ((vez % 2 == 0)?'O':'X') && tabuleiro[4] == ((vez % 2 == 0)?'O':'X') && tabuleiro[6] == ((vez % 2 == 0)?'O':'X')) ||
(tabuleiro[0] == ((vez % 2 == 0)?'O':'X') && tabuleiro[1] == ((vez % 2 == 0)?'O':'X') && tabuleiro[2] == ((vez % 2 == 0)?'O':'X')) ||
(tabuleiro[3] == ((vez % 2 == 0)?'O':'X') && tabuleiro[4] == ((vez % 2 == 0)?'O':'X') && tabuleiro[5] == ((vez % 2 == 0)?'O':'X')) ||
(tabuleiro[6] == ((vez % 2 == 0)?'O':'X') && tabuleiro[7] == ((vez % 2 == 0)?'O':'X') && tabuleiro[8] == ((vez % 2 == 0)?'O':'X')) ||
(tabuleiro[0] == ((vez % 2 == 0)?'O':'X') && tabuleiro[3] == ((vez % 2 == 0)?'O':'X') && tabuleiro[6] == ((vez % 2 == 0)?'O':'X')) ||
(tabuleiro[1] == ((vez % 2 == 0)?'O':'X') && tabuleiro[4] == ((vez % 2 == 0)?'O':'X') && tabuleiro[7] == ((vez % 2 == 0)?'O':'X')) ||
(tabuleiro[2] == ((vez % 2 == 0)?'O':'X') && tabuleiro[5] == ((vez % 2 == 0)?'O':'X') && tabuleiro[8] == ((vez % 2 == 0)?'O':'X'))){
printf("O Jogador %d (%c) ganhou\n", vez, ((vez % 2 == 0)?'O':'X'));
return 1;
}
if(contador == 9){
printf("Empate\n");
return 1; // Jogo acabar.
}
return 0; // Jogo continuar.
}

void main(){
char tabuleiro[10];
memset(&tabuleiro, '\0', sizeof(tabuleiro));
int j1, j2, vez = 1, j[vez], contador = 1, status = 0;
printf("##### JOGO DA VELHA #####\n");
printf("Jogador 1: X\nJogador 2: O\n");
mostrar(tabuleiro);
while(status == 0){
printf("JOGADOR %d: ", vez);
scanf("%d", &j[vez]);
if(tabuleiro[j[vez]-1] == 'X' || tabuleiro[j[vez]-1] == 'O' || j[vez] < 1 || j[vez] > 9){ // Verifica se o lugar que o jogador escolheu é válido.
while(tabuleiro[j[vez]-1] == 'X' || tabuleiro[j[vez]-1] == 'O' || j[vez] < 1 || j[vez] > 9){
printf("Jogada invalida\n");
printf("JOGADOR %d: ", vez);
scanf("%d", &j[vez]);
}
}
tabuleiro[j[vez]-1] = (vez == 1)?'X':'O'; // Verifica se é o jogador 1 ou 2 para jogar X ou O.
mostrar(tabuleiro);
status = verificar(tabuleiro, vez); // Verifica se alguém ganhou ou empate.
vez = (++contador % 2 == 0)?2:1; // Verifica se a próxima vez é a do jogador 1 ou 2.

}
printf("##### FIM DE JOGO #####\n");
} 
