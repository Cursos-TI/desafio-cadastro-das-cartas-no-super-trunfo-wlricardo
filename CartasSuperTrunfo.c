// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>
#include <stdlib.h> // Para usar a função system()
#include <string.h> // Para usar as funções strcspn(), fgets() e sscanf()

#define MAX 100     // Tamanho máximo para strings

// Temporizador de 2 segundos:
/* A função esperar() irá pausar a execução do programa por 2 segundos (2000 milissegundos) para permitir que o usuário
   visualize os dados inseridos antes de limpar a tela. */
#ifdef _WIN32
#include <windows.h> // Para usar a função Sleep() no Windows
void esperar()
{
    Sleep(2000); // Windows: conta 2000 milissegundos (2 segundos)
}
#else
#include <unistd.h> // Para usar a função sleep() no Linux/MacOS
void esperar()
{
    sleep(2); // Linux/MacOS: conta 2 segundos
}
#endif

// Limpar a tela:
/* A função limpar_tela() irá limpar a tela do console, dependendo do sistema operacional (Windows ou Linux/MacOS). A
   diretiva de pré-processamento #ifdef _WIN32 é usada para verificar se o sistema operacional é Windows. Se for Windows,
   a função Sleep() da biblioteca <windows.h> é usada para pausar a execução. Se não for Windows, a função sleep() da
   biblioteca <unistd.h> é usada para pausar a execução. */
void limpar_tela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Calcular super poder
/* A função calcular_super_poder calcula a soma dos valores numéricos das variáveis das cartas 1 e 2. 
   No caso da densidade populacional, será tomado seu inverso */
double calcular_super_poder(unsigned long int populacao, float area, double pib, int pontos_turisticos)
{
    return (populacao + area + pib + pontos_turisticos + calcular_densidade_populacional(populacao, area) + calcular_pib_per_capita(pib, populacao));
}

// Calcular densidade populacional
/* A função calcular_densidade_populacional recebe a população e a área de uma carta e calcula a densidade populacional.
   Se a área for zero, a densidade populacional será definida como 0.0 para evitar divisão por zero. */
double calcular_densidade_populacional(unsigned long int populacao, float area)
{

    if (area != 0) 
    {
        return (double)populacao / area; // Calcula a densidade populacional
    } else
    {
        return 0.0; 
    }
}

// Calcular PIB per capita
/* A função calcular_pib_per_capita recebe o PIB e a população de uma carta e calcula o PIB per capita.
   Se a população for zero, o PIB per capita será definido como 0.0 para evitar divisão por zero. */
double calcular_pib_per_capita(double pib, unsigned long int populacao)
{
    if (populacao != 0) 
    {
        return (pib * 1000000000.0) / (double)populacao; // Calcula o PIB per capita
    } else
    {
        return 0.0; // Se a população for zero, define-se o pib_per_capita como 0.0
    }
}

// Comparar cartas
/* A função comparar_cartas recebe os dados das duas cartas e compara seus valores, retornando o resultado da comparação. */
void comparar_cartas(unsigned long int populacao1, unsigned long int populacao2, float area1, float area2,
    double pib1, double pib2, int pontos_turisticos1, int pontos_turisticos2, double densidade_populacional1, 
    double densidade_populacional2, double pib_per_capita1, double pib_per_capita2, double super_poder1, double super_poder2)
{
    int populacao = 0;                  // Variável para armazenar maior população
    int area = 0;                       // Variável para armazenar maior área
    int pib = 0;                        // Variável para armazenar maior PIB
    int pontos_turisticos = 0;          // Variável para armazenar maior número de pontos turísticos
    int densidade_populacional = 0;     // Variável para armazenar menor densidade populacional
    int pib_per_capita = 0;             // Variável para armazenar maior PIB per capita
    int super_poder = 0;                // Variável para armazenar maior Super Poder

    int flag = 0;                       // Variável para indicar se o vencendor é a Carta 1 (1) ou a Carta 2 (0)

    // Comparar população
    populacao = (populacao1 > populacao2) ? 1 : 2;                  // Define a carta vencedora com base na população
    flag = (populacao1 > populacao2) ? 1 : 0;                       // Define a flag com base na comparação 
    printf("\nPopulação................: Carta %d venceu (%d)", populacao, flag);  
    
    // Comparar área
    area = (area1 > area2) ? 1 : 2;                                 // Define a carta vencedora com base na área
    flag = (area1 > area2) ? 1 : 0;                                 // Define a flag com base na comparação
    printf("\nÁrea.....................: Carta %d venceu (%d)", area, flag);
    
    // Comparar PIB
    pib = (pib1 > pib2) ? 1 : 2;                                    // Define a carta vencedora com base no PIB
    flag = (pib1 > pib2) ? 1 : 0;                                   // Define a flag com base na comparação
    printf("\nPIB......................: Carta %d venceu (%d)", pib, flag);    
            
    // Comparar pontos turísticos
    pontos_turisticos = (pontos_turisticos1 > pontos_turisticos2) ? 1 : 2; // Define a carta vencedora com base nos pontos turísticos
    flag = (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0;     // Define a flag com base na comparação
    printf("\nPontos turísticos........: Carta %d venceu (%d)", pontos_turisticos, flag);
            
    // Comparar PIB per capita
    pib_per_capita = (pib_per_capita1 > pib_per_capita2) ? 1 : 2; // Define a carta vencedora com base no PIB per capita
    flag = (pib_per_capita1 > pib_per_capita2) ? 1 : 0;           // Define a flag com base na comparação
    printf("\nPIB per capita...........: Carta %d venceu (%d)", pib_per_capita, flag);
            
    // Comparar densidade populacional
    densidade_populacional = (densidade_populacional1 < densidade_populacional2) ? 1 : 2; // Define a carta vencedora com base na densidade populacional
    flag = (densidade_populacional1 < densidade_populacional2) ? 1 : 0; // Define a flag com base na comparação
    printf("\nDensidade populacional...: Carta %d venceu (%d)", densidade_populacional, flag);
            
    // Comparar Super Poder
    super_poder = (super_poder1 > super_poder2) ? 1 : 2; // Define a carta vencedora com base no Super Poder
    flag = (super_poder1 > super_poder2) ? 1 : 0;         // Define a flag com base na comparação
    printf("\nSuper Poder..............: Carta %d venceu (%d)", super_poder, flag);            
}
    

int main()
{
    limpar_tela();          // Limpa a tela ao iniciar o programa

    char input[MAX];        // String para capturar a entrada do usuário
    char estado1, estado2;
    char codigo1[10], codigo2[10];
    char cidade1[MAX], cidade2[MAX];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    double pib1, pib2;
    double densidade_populacional1, densidade_populacional2;
    double pib_per_capita1, pib_per_capita2;
    double super_poder1, super_poder2;
    int pontos_turisticos1, pontos_turisticos2;

    /* Solicitando as informações sobre as duas cartas */

    // Carta 1
    printf("FORNEÇA DADOS DA CARTA 1:");
    printf("\nEstado: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, " %c", &estado1);             // Lê o caractere, ignorando espaços

    printf("Código: ");
    fgets(codigo1, sizeof(codigo1), stdin);
    codigo1[strcspn(codigo1, "\n")] = 0;        // Remove o '\n' do final da string

    printf("Cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;        // Remove o '\n' do final da string

    printf("População: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lu", &populacao1);          // Lê o inteiro a partir da string

    printf("Area: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%f", &area1);                // Lê o float a partir da string

    printf("PIB: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lf", &pib1);                // Lê o float a partir da string

    printf("Pontos turísticos: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &pontos_turisticos1);   // Lê o inteiro a partir da string

    // Cálculo das variáveis derivadas
    densidade_populacional1 = calcular_densidade_populacional(populacao1, area1); 
    pib_per_capita1 = calcular_pib_per_capita(pib1, populacao1); 
    super_poder1 = calcular_super_poder(populacao1, area1, pib1, pontos_turisticos1);
    
    printf("\nDados inseridos com sucesso...\n");
    esperar();
    limpar_tela();                                          // Limpa a tela após inserir os dados da primeira carta

    // Carta 2
    printf("FORNEÇA DADOS DA CARTA 2:");
    printf("\nEstado: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, " %c", &estado2);                         // Lê o caractere

    printf("Código: ");
    fgets(codigo2, sizeof(codigo2), stdin);
    codigo2[strcspn(codigo2, "\n")] = 0;                    // Remove o '\n' do final da string

    printf("Cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;                    // Remove o '\n' do final da string

    printf("População: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lu", &populacao2);                      // Lê o inteiro a partir da string

    printf("Area: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%f", &area2);                            // Lê o float a partir da string

    printf("PIB: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%lf", &pib2);                            // Lê o float a partir da string

    printf("Pontos turísticos: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &pontos_turisticos2);               // Lê o inteiro a partir da string

    // Cálculo das variáveis derivadas
    densidade_populacional2 = calcular_densidade_populacional(populacao2, area2); 
    pib_per_capita2 = calcular_pib_per_capita(pib2, populacao2); 
    super_poder2 = calcular_super_poder(populacao2, area2, pib2, pontos_turisticos2);

    printf("\nDados inseridos com sucesso...\n");
    esperar();
    limpar_tela(); // Limpa a tela após inserir os dados da segunda carta

    // Exibição dos resultados
    printf("-------------------------");
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
    printf("\n-PIB per capita: R$ %.2lf", pib_per_capita1);
    printf("\n-Super Poder: %.2lf\n", super_poder1);

    printf("\nCARTA 2:");
    printf("\n-Estado: %c", estado2);
    printf("\n-Código: %s", codigo2);
    printf("\n-Cidade: %s", cidade2);
    printf("\n-População: %lu habitantes", populacao2);
    printf("\n-Area: %.2f km²", area2);
    printf("\n-PIB: R$ %.2lf bilhões", pib2);
    printf("\n-Pontos turísticos: %d", pontos_turisticos2);
    printf("\n-Densidade populacional: %.2lf habitantes/km²", densidade_populacional2);
    printf("\n-PIB per capita: R$ %.2lf", pib_per_capita2);
    printf("\n-Super Poder: %.2lf\n", super_poder2);

    printf("\n-------------------------\n");
    printf("Comparação entre as cartas:\n");
    comparar_cartas(populacao1, populacao2, area1, area2, pib1, pib2, pontos_turisticos1, pontos_turisticos2,
        densidade_populacional1, densidade_populacional2, pib_per_capita1, pib_per_capita2, super_poder1, super_poder2);

    printf("\n\n-----FIM DO PROGRAMA-----\n\n");

    return 0;
}