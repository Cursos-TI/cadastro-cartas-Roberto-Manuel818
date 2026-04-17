#include <stdio.h>
int main() {
    // DECLARAÇÃO DAS VARIÁVEIS
    // CARTA 1
    char codigo1[4];
    // ARMAZENA A POPULAÇÃO DA CARTA 1
    int populacao1;
    // ARMAZENA A ÁREA DA CARTA 1
    float area1;
    // ARMAZENA O PIB DA CARTA 1
    float pib1;
    // ARMAZENA A QUANTIDADE DE PONTOS TURÍSTICOS DA CARTA 1
    int pontos1;
    // CARTA 2
    char codigo2[4];
    // ARMAZENA A POPULAÇÃO DA CARTA 2
    int populacao2;
    // ARMAZENA A ÁREA DA CARTA 2
    float area2;
    // ARMAZENA O PIB DA CARTA 2
    float pib2;
    // ARMAZENA A QUANTIDADE DE PONTOS TURÍSTICOS DA CARTA 2
    int pontos2;
    // ENTRADA DE DADOS - CARTA 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite a populacao: ");
    scanf("%d", &populacao1);
    printf("Digite a area: ");
    scanf("%f", &area1);
    printf("Digite o PIB: ");
    scanf("%f", &pib1);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontos1);
    // ENTRADA DE DADOS - CARTA 2
    printf("=== Cadastro da Carta 2 ===\n");
    printf("Digite o codigo da carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Digite a populacao: ");
    scanf("%d", &populacao2);
    printf("Digite a area: ");
    scanf("%f", &area2);
    printf("Digite o PIB: ");
    scanf("%f", &pib2);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontos2);
    // EXIBIÇÃO DOS DADOS
    printf("\n=== Dados das Cartas ===\n");
    // CARTA 1
    printf("\nCarta: %s\n", codigo1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos1);
    // CARTA 2
    printf("\nCarta: %s\n", codigo2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos2);
    // CÁLCULO DA DENSIDADE POPULACIONAL
    // CALCULA A DENSIDADE DA CARTA 1
    float densidade1 = populacao1 / area1;
    // CALCULA A DENSIDADE DA CARTA 2
    float densidade2 = populacao2 / area2;
    // MOSTRA AS DENSIDADES CALCULADAS
    printf("\n=== Densidade Populacional ===\n");
    printf("Carta %s: %.2f\n", codigo1, densidade1);
    printf("Carta %s: %.2f\n", codigo2, densidade2);
    // COMPARAÇÃO DAS CARTAS
    printf("\n=== Resultado da Comparacao ===\n");

    // SE A DENSIDADE DA CARTA 1 FOR MENOR, ELA VENCE
    if (densidade1 < densidade2) {
        printf("Vencedor: Carta %s (menor densidade populacional)\n", codigo1);
    }
    // SE A DENSIDADE DA CARTA 2 FOR MENOR, ELA VENCE
    else if (densidade2 < densidade1) {
        printf("Vencedor: Carta %s (menor densidade populacional)\n", codigo2);
    }
    // CASO AS DENSIDADES SEJAM IGUAIS
    else {
        printf("Empate! As duas cartas possuem a mesma densidade populacional.\n");
    }

    return 0;
}