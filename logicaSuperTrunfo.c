#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
// Utilizamos uma struct para agrupar todas as propriedades de uma carta em uma única entidade.
typedef struct {
    char estado[3];
    char codigo_carta[5];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para exibir os dados completos de uma carta
// Isso ajuda a manter o código principal mais limpo e organizado.
void exibir_carta(Carta carta) {
    printf("--- Dados da Carta (%s) ---\n", carta.nome_cidade);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo_carta);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
    printf("PIB per capita: %.2f\n\n", carta.pib_per_capita);
}

// Função principal do programa
int main() {
    // Declaração das duas cartas que serão comparadas
    Carta carta1, carta2;

    // --- CADASTRO DAS CARTAS (Valores pré-definidos para simplificar o desafio) ---
    // Carta 1: São Paulo
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo_carta, "A01");
    strcpy(carta1.nome_cidade, "São Paulo");
    carta1.populacao = 12396372;
    carta1.area = 1521.11;
    carta1.pib = 763.8; // em bilhões de Reais
    carta1.pontos_turisticos = 250;

    // Carta 2: Rio de Janeiro
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo_carta, "B02");
    strcpy(carta2.nome_cidade, "Rio de Janeiro");
    carta2.populacao = 6775561;
    carta2.area = 1200.2;
    carta2.pib = 359.6; // em bilhões de Reais
    carta2.pontos_turisticos = 180;
    
    // --- CÁLCULOS E GERAÇÃO DE NOVOS ATRIBUTOS ---
    // A densidade populacional e o PIB per capita são calculados a partir dos dados existentes.
    // Usamos um cast (float) para garantir que o resultado seja um número de ponto flutuante.
    carta1.densidade_populacional = (float)carta1.populacao / carta1.area;
    carta2.densidade_populacional = (float)carta2.populacao / carta2.area;

    // O PIB per capita é o PIB total dividido pela população.
    carta1.pib_per_capita = (carta1.pib * 1000000000) / carta1.populacao;
    carta2.pib_per_capita = (carta2.pib * 1000000000) / carta2.populacao;

    // Exibindo os dados das cartas para que o usuário possa ver as informações
    exibir_carta(carta1);
    exibir_carta(carta2);
    
    // --- LÓGICA DE COMPARAÇÃO DAS CARTAS ---
    
    // Escolha do atributo para a comparação.
    // Para testar outros atributos, basta alterar o valor desta string.
    const char *atributo_escolhido = "pib_per_capita"; 

    printf("--- Comparação de cartas (Atributo: %s) ---\n\n", atributo_escolhido);

    // Estruturas de decisão if-else para realizar a comparação com base no atributo escolhido.
    // Usamos a função strcmp para comparar strings e decidir qual bloco de código executar.
    if (strcmp(atributo_escolhido, "populacao") == 0) {
        printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.nome_cidade, carta2.estado, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_escolhido, "area") == 0) {
        printf("Carta 1 - %s (%s): %.2f km²\n", carta1.nome_cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f km²\n", carta2.nome_cidade, carta2.estado, carta2.area);
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.area > carta1.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_escolhido, "pib") == 0) {
        printf("Carta 1 - %s (%s): %.2f bilhões\n", carta1.nome_cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f bilhões\n", carta2.nome_cidade, carta2.estado, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_escolhido, "densidade") == 0) {
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", carta1.nome_cidade, carta1.estado, carta1.densidade_populacional);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", carta2.nome_cidade, carta2.estado, carta2.densidade_populacional);
        // Regra especial: para densidade populacional, a carta com o menor valor vence.
        if (carta1.densidade_populacional < carta2.densidade_populacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else if (strcmp(atributo_escolhido, "pib_per_capita") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nome_cidade, carta2.estado, carta2.pib_per_capita);
        if (carta1.pib_per_capita > carta2.pib_per_capita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        printf("Erro: Atributo de comparação inválido ou não implementado.\n");
    }

    return 0;
}
