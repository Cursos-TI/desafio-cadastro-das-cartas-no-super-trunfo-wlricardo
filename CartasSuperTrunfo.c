#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    // Definição das variáveis
    char estado1, estado2;
    char codigo1[3], codigo2[3];
    char cidade1[20], cidade2[20];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    // Leitura dos dados da Carta 1
    printf("\nFORNEÇA DADOS DA CARTA 1:");
    printf("\nEstado: ");
    scanf(" %c", &estado1);
    printf("Código: ");
    scanf(" %2[^\n]", codigo1); // Lê no máximo 2 caracteres
    printf("Cidade: ");
    scanf(" %20[^\n]", codigo1); // Lê no máximo 20 caracteres
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Area: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    printf("-----------------------------");

    // Leitura dos dados da Carta 2
    printf("\nFORNEÇA DADOS DA CARTA 2:");
    printf("\nEstado: ");
    scanf(" %c", &estado2);
    printf("Código: ");
    scanf(" %2[^\n]", codigo2); // Lê no máximo 2 caracteres
    printf("Cidade: ");
    scanf(" %20[^\n]", codigo2); // Lê no máximo 20 caracteres
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Area: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    printf("\n-----------------------------");
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
