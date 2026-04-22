#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura Carta
typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

// Função para cadastrar carta manualmente
void cadastrarCarta(Carta *carta) {
    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    printf("Digite a populacao: ");
    scanf("%d", &carta->populacao);
    printf("Digite a area: ");
    scanf("%f", &carta->area);
    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta->pontos);

    // Calcula propriedades derivadas
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontos 
                        + carta->pibPerCapita - carta->densidade;
}

// Função para gerar carta aleatória (computador)
void gerarCartaAleatoria(Carta *carta) {
    sprintf(carta->codigo, "C%02d", rand() % 100);
    carta->populacao = rand() % 10000000 + 100000;
    carta->area = (rand() % 10000) + 100;
    carta->pib = carta->populacao * (rand() % 1000);
    carta->pontos = rand() % 50;

    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontos 
                        + carta->pibPerCapita - carta->densidade;
}

// Função para exibir carta
void exibirCarta(Carta carta) {
    printf("\n=== Carta %s ===\n", carta.codigo);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontos);
    printf("Densidade Populacional: %.2f\n", carta.densidade);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função principal
int main() {
    srand(time(NULL));

    int modo;
    do {
        printf("\033[1;34m=== MODO DE JOGO ===\033[0m\n");
        printf("1 - Jogar com amigo\n");
        printf("2 - Jogar contra o computador\n");
        printf("Escolha: ");
        scanf("%d", &modo);
    } while (modo != 1 && modo != 2);

    Carta carta1, carta2;

    if (modo == 1) {
        printf("\n=== Cadastro da Carta 1 ===\n");
        cadastrarCarta(&carta1);

        printf("\n=== Cadastro da Carta 2 ===\n");
        cadastrarCarta(&carta2);
    } else {
        printf("\n=== Sua Carta ===\n");
        cadastrarCarta(&carta1);

        printf("\n=== Carta do Computador ===\n");
        gerarCartaAleatoria(&carta2);
        exibirCarta(carta2);
    }

    int escolha;
    do {
        printf("\n=== Escolha o modo de comparação ===\n");
        printf("1 - Comparar um atributo\n");
        printf("2 - Comparar todos os atributos (placar)\n");
        printf("3 - Comparar Super Poder\n");
        scanf("%d", &escolha);
    } while (escolha < 1 || escolha > 3);

    printf("\n\033[1;32m=== Resultado ===\033[0m\n");

    switch (escolha) {
        case 1: {
            int atributo;
            do {
                printf("1-Pop 2-Area 3-PIB 4-Pontos 5-Densidade 6-PIBcapita\n");
                scanf("%d", &atributo);
            } while (atributo < 1 || atributo > 6);

            switch (atributo) {
                case 1: printf("%s venceu\n", (carta1.populacao > carta2.populacao) ? carta1.codigo : carta2.codigo); break;
                case 2: printf("%s venceu\n", (carta1.area > carta2.area) ? carta1.codigo : carta2.codigo); break;
                case 3: printf("%s venceu\n", (carta1.pib > carta2.pib) ? carta1.codigo : carta2.codigo); break;
                case 4: printf("%s venceu\n", (carta1.pontos > carta2.pontos) ? carta1.codigo : carta2.codigo); break;
                case 5: printf("%s venceu\n", (carta1.densidade < carta2.densidade) ? carta1.codigo : carta2.codigo); break;
                case 6: printf("%s venceu\n", (carta1.pibPerCapita > carta2.pibPerCapita) ? carta1.codigo : carta2.codigo); break;
            }
            break;
        }

        case 2: {
            int p1=0,p2=0;
            if (carta1.populacao > carta2.populacao) p1++; else if (carta2.populacao > carta1.populacao) p2++;
            if (carta1.area > carta2.area) p1++; else if (carta2.area > carta1.area) p2++;
            if (carta1.pib > carta2.pib) p1++; else if (carta2.pib > carta1.pib) p2++;
            if (carta1.pontos > carta2.pontos) p1++; else if (carta2.pontos > carta1.pontos) p2++;
            if (carta1.densidade < carta2.densidade) p1++; else if (carta2.densidade < carta1.densidade) p2++;
            if (carta1.pibPerCapita > carta2.pibPerCapita) p1++; else if (carta2.pibPerCapita > carta1.pibPerCapita) p2++;

            printf("Placar: %d x %d\n", p1, p2);
            printf("%s venceu\n", (p1 > p2) ? carta1.codigo : carta2.codigo);
            break;
        }

        case 3: {
            printf("%s venceu\n", (carta1.superPoder > carta2.superPoder) ? carta1.codigo : carta2.codigo);
            break;
        }
    }

    return 0;
}
