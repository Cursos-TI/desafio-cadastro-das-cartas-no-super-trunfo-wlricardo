// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>
#include <stdlib.h>     // Para usar a função system()
#include <string.h>     // Para usar as funções strcspn(), fgets() e sscanf()

#define MAX 100

// Temporizador de 2 segundos:
/* A função esperar() irá pausar a execução do programa por 2 segundos (2000 milissegundos) para permitir que o usuário
   visualize os dados inseridos antes de limpar a tela. */
#ifdef _WIN32
    #include <windows.h> // Para usar a função Sleep() no Windows
    void esperar() {
        Sleep(2000);     // Windows: conta 2000 milissegundos (2 segundos)
    }
#else
    #include <unistd.h>  // Para usar a função sleep() no Linux/MacOS
    void esperar() {
        sleep(2);        // Linux/MacOS: conta 2 segundos
    }
#endif

// Limpar a tela:
/* A função limpar_tela() irá limpar a tela do console, dependendo do sistema operacional (Windows ou Linux/MacOS). A 
   diretiva de pré-processamento #ifdef _WIN32 é usada para verificar se o sistema operacional é Windows. Se for Windows,
   a função Sleep() da biblioteca <windows.h> é usada para pausar a execução. Se não for Windows, a função sleep() da 
   biblioteca <unistd.h> é usada para pausar a execução. */
void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    limpar_tela();          // Limpa a tela ao iniciar o programa

    char input[MAX];        // String para capturar a entrada do usuário
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[MAX], cidade2[MAX];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    double pib1, pib2;
    double densidade_populacional1, densidade_populacional2;
    double pib_per_capita1, pib_per_capita2;
    int pontos_turisticos1, pontos_turisticos2;

    /* Solicitando as informações sobre as duas cartas */
    
    // Carta 1
    printf("FORNEÇA DADOS DA CARTA 1:");
    printf("\nEstado: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, " %c", &estado1);           // Lê o caractere, ignorando espaços

    printf("Código: ");
    fgets(codigo1, sizeof(codigo1), stdin);
    codigo1[strcspn(codigo1, "\n")] = 0;      // Remove o '\n' do final da string

    printf("Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;      // Remove o '\n' do final da string

    printf("População: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lu", &populacao1);        // Lê o inteiro a partir da string

    printf("Area: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%f", &area1);              // Lê o float a partir da string

    printf("PIB: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lf", &pib1);               // Lê o float a partir da string

    printf("Pontos turísticos: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &pontos_turisticos1); // Lê o inteiro a partir da string

    printf("\nDados inseridos com sucesso...\n");
    esperar();
    limpar_tela();                            // Limpa a tela após inserir os dados da primeira carta

    if(area1 != 0) {                                                    // Verifica se a área é diferente de zero para evitar divisão por zero
        densidade_populacional1 = (double)populacao1 / area1;           // Calcula a densidade populacional
    } else {
        densidade_populacional1 = 0.0;                                  // Se a área for zero, define-se a densidade_populacional como 0.0
    }

    if(populacao1 != 0) {                                               // Verifica se a população é diferente de zero para evitar divisão por zero
        pib_per_capita1 = (pib1 * 1000000000.0) / (double)populacao1;   // Calcula o PIB per capita
    } else {
        pib_per_capita1 = 0.0;                                          // Se a população for zero, define-se o pib_per_capita como 0.0
    }
    
    // Carta 2
    printf("\nFORNEÇA DADOS DA CARTA 2:");
    printf("\nEstado: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, " %c", &estado2);           // Lê o caractere

    printf("Código: ");
    fgets(codigo2, sizeof(codigo2), stdin);
    codigo2[strcspn(codigo2, "\n")] = 0;      // Remove o '\n' do final da string
    
    printf("Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;      // Remove o '\n' do final da string

    printf("População: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lu", &populacao2);        // Lê o inteiro a partir da string

    printf("Area: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%f", &area2);              // Lê o float a partir da string

    printf("PIB: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lf", &pib2);              // Lê o float a partir da string

    printf("Pontos turísticos: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &pontos_turisticos2); // Lê o inteiro a partir da string

    /* Cálculo da densidade populacional */
    if (area2 != 0) {                                                   // Verifica se a área é diferente de zero para evitar divisão por zero
        densidade_populacional2 = (double)populacao2 / area2;           // Calcula a densidade populacional
    } else {
        densidade_populacional2 = 0.0;                                  // Se a área for zero, define-se a densidade_populacional como 0.0
    }

    /* Cálculo do pib per capita */
    if (populacao2 != 0) {                                              // Verifica se a população é diferente de zero para evitar divisão por zero
        pib_per_capita2 = (pib2 * 1000000000.0) / (float)populacao2;    // Calcula o PIB per capita
    } else {
        pib_per_capita2 = 0.0;                                          // Se a população for zero, define-se o pib_per_capita como 0.0
    }

    printf("\nDados inseridos com sucesso...\n");
    esperar();
    limpar_tela();                            // Limpa a tela após inserir os dados da segunda carta

    // Exibição dos resultados
    printf("\n-------------------------");
    printf("\nCartas registradas:\n");
    printf("\nCARTA 1:");
    printf("\n-Estado: %c", estado1);
    printf("\n-Código: %s", codigo1);
    printf("\n-Cidade: %s", cidade1);
    printf("\n-População: %lu habitantes", populacao1);
    printf("\n-Area: %.2f km²", area1);
    printf("\n-PIB: R$ %.2lf bilhões", pib1);
    printf("\n-Pontos turísticos: %d", pontos_turisticos1);
    printf("\n-Densidade populacional: %.2lf habitantes/km²", densidade_populacional1);
    printf("\n-PIB per capita: R$ %.2lf\n", pib_per_capita1);

    printf("\nCARTA 2:");
    printf("\n-Estado: %c", estado2);
    printf("\n-Código: %s", codigo2);
    printf("\n-Cidade: %s", cidade2);
    printf("\n-População: %lu habitantes", populacao2);
    printf("\n-Area: %.2f km²", area2);
    printf("\n-PIB: R$ %.2lf bilhões", pib2);
    printf("\n-Pontos turísticos: %d", pontos_turisticos2);
    printf("\n-Densidade populacional: %.2lf habitantes/km²", densidade_populacional2);
    printf("\n-PIB per capita: R$ %.2lf\n", pib_per_capita2);    

    printf("\n-----FIM DO PROGRAMA-----\n\n");

    return 0;
}