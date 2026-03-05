#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constantes globais
#define sizeText 50

// Estrutura para armazenar as informações de cada território
struct territorio {
    char territory[sizeText];
    char color[sizeText];
    int soldiers;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct territorio war[5]; // array para armazenar os 5 territórios
    int i;

    // Texto de introdução
    printf("=================================================\n");
    printf("Bem vindo ao jogo WAR!\n");
    printf("Neste jogo, cada jogador deve escolher um territorio e tentar conquistar os territorios adversarios.\n");
    printf("=================================================\n");

    printf("Cadastre 5 territorios para jogar!\n");
    printf("=================================================\n");

    // Cadastro de territórios
    for (i = 0; i < 5; i++) {
        printf("\nDigite o nome do territorio %d: ", i + 1);
        fgets(war[i].territory, sizeText, stdin);

        printf("Digite a cor do seu territorio %d: ", i + 1);
        fgets(war[i].color, sizeText, stdin);

        printf("Digite a quantidade de soldados do territorio %d: ", i + 1);
        scanf("%d", &war[i].soldiers); 
      
        limparBufferEntrada();

        printf("XD Territorio %d cadastrado com sucesso! XD\n", i + 1);
    }

    // Amostragem de territórios cadastrados
    printf("\n=================================================\n");
    printf("Os Territorios sao:\n");

    for (i = 0; i < 5; i++) {
        printf("=================================================\n");
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s", war[i].territory); 
        printf("Cor: %s", war[i].color);
        printf("Soldados: %d\n", war[i].soldiers);
        printf("=================================================\n");
    }

    return 0; 
}
