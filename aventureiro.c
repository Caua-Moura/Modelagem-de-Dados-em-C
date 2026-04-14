#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// constantes globais
#define sizeText 50

// Estrutura para armazenar as informações de cada território
struct territorio {
    char territory[sizeText];
    char color[sizeText];
    int soldiers;
};

// limpar buffer
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// cadastrar territorios
void cadastrar(struct territorio *war, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nDigite o nome do territorio %d: ", i + 1);
        fgets(war[i].territory, sizeText, stdin);

        printf("Digite a cor do territorio %d: ", i + 1);
        fgets(war[i].color, sizeText, stdin);

        printf("Digite a quantidade de soldados: ");
        scanf("%d", &war[i].soldiers);
        limparBufferEntrada();

        printf("Territorio %d cadastrado!\n", i + 1);
    }
}

// mostrar territorios
void mostrar(struct territorio *war, int n) {
    int i;
    printf("\n===== TERRITORIOS =====\n");
    for (i = 0; i < n; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s", war[i].territory);
        printf("Cor: %s", war[i].color);
        printf("Soldados: %d\n", war[i].soldiers);
    }
}

// função de ataque
void atacar(struct territorio *atacante, struct territorio *defensor) {
    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\n===== ATAQUE =====\n");
    printf("Atacante tirou: %d\n", dadoA);
    printf("Defensor tirou: %d\n", dadoD);

    if (dadoA > dadoD) {
        printf("Atacante venceu!\n");

        int tropas_transferidas = atacante->soldiers / 2;

        defensor->soldiers = tropas_transferidas;
        strcpy(defensor->color, atacante->color);

        atacante->soldiers -= tropas_transferidas;
    } else {
        printf("Defensor venceu!\n");
        atacante->soldiers -= 1;
    }
}

// liberar memoria
void liberarMemoria(struct territorio *war) {
    free(war);
}

int main() {
    int n;
    int a, d;

    srand(time(NULL));

    printf("====================================\n");
    printf("Bem vindo ao jogo WAR!\n");
    printf("====================================\n");

    // quantidade dinamica
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &n);
    limparBufferEntrada();

    // alocação dinâmica
    struct territorio *war;
    war = (struct territorio*) calloc(n, sizeof(struct territorio));

    // cadastro
    cadastrar(war, n);

    // mostrar inicial
    mostrar(war, n);

    // escolher ataque
    printf("\nEscolha o territorio atacante (numero): ");
    scanf("%d", &a);

    printf("Escolha o territorio defensor (numero): ");
    scanf("%d", &d);

    // validação
    if (a < 1 || a > n || d < 1 || d > n) {
        printf("Escolha invalida!\n");
    } else if (strcmp(war[a-1].color, war[d-1].color) == 0) {
        printf("Nao pode atacar territorio da mesma cor!\n");
    } else {
        atacar(&war[a-1], &war[d-1]);
    }

    // mostrar depois do ataque
    mostrar(war, n);

    // liberar memoria
    liberarMemoria(war);

    return 0;
}
