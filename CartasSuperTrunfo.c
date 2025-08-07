#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>
#include <stdlib.h> // Para usar a função system()

// Criando um contador de milisegundos
#ifdef _WIN32
    #include <windows.h> // Para usar a função Sleep() no Windows
    void esperar() {
        Sleep(4000); // Windows: conta 1000 milissegundos (1 segundo)
    }
#else
    #include <unistd.h> // Para usar a função sleep() no Linux/MacOS
    void esperar() {
        sleep(1); // Linux/MacOS: conta 1 segundo
    }
#endif

// Função para limpar a tela
void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    //printf("\033[2J\033[H"); 
}

int main() {
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[20], cidade2[20];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;

    /* Solicitando as informações sobre as duas cartas */
    
    // Carta 1
    printf("FORNEÇA DADOS DA CARTA 1:");
    printf("\nEstado: ");
    scanf(" %c", &estado1);
    printf("Código: ");
    scanf(" %3[^\n]", codigo1); // Lê no máximo 3 caracteres
    printf("Cidade: ");
    scanf(" %19[^\n]", cidade1); // Lê no máximo 19 caracteres + '\n'
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Area: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    printf("\nDados inseridos com sucesso...\n");
    esperar();
    
    // Carta 2
    printf("\nFORNEÇA DADOS DA CARTA 2:");
    printf("\nEstado: ");
    scanf(" %c", &estado2);
    printf("Código: ");
    scanf(" %3[^\n]", codigo2); // Lê no máximo 3 caracteres
    printf("Cidade: ");
    scanf(" %19[^\n]", cidade2); // Lê no máximo 19 caracteres + '\n'
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Area: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    printf("\nDados inseridos com sucesso...\n");
    esperar();

    // Exibição dos resultados
    printf("\n-----------------------");
    printf("\nCartas registradas:\n");
    printf("\nCARTA 1:");
    printf("\nEstado: %c", estado1);
    printf("\nCódigo: %s", codigo1);
    printf("\nCidade: %s", cidade1);
    printf("\nPopulação: %d habitantes", populacao1);
    printf("\nArea: %.2f km²", area1);
    printf("\nPIB: R$ %.2f", pib1);
    printf("\nPontos turísticos: %d\n", pontos_turisticos1);

    printf("\nCARTA 2:");
    printf("\nEstado: %c", estado2);
    printf("\nCódigo: %s", codigo2);
    printf("\nCidade: %s", cidade2);
    printf("\nPopulação: %d habitantes", populacao2);
    printf("\nArea: %.2f km²", area2);
    printf("\nPIB: R$ %.2f", pib2);
    printf("\nPontos turísticos: %d", pontos_turisticos2);
}