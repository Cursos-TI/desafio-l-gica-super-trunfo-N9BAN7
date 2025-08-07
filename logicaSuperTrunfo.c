#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
typedef struct {
    char nome[50];
    int populacao;
    float densidade_demografica;
    int area;
    float pib;
} Carta;

// Cartas pré-cadastradas
Carta carta1 = {"Brasil", 215300000, 25.04, 8515767, 1870.0};
Carta carta2 = {"Argentina", 45810000, 16.48, 2780400, 632.7};

// Protótipos das funções
int compara_maior(float valor1, float valor2);
int compara_menor(float valor1, float valor2);
void exibir_resultado(const char *titulo, float valor1, float valor2, int resultado_comparacao);
void exibir_menu(int escolha_anterior);
float obter_valor_atributo(const Carta *carta, int atributo_id);

int main() {
    int escolha1 = 0, escolha2 = 0;
    float soma_carta1 = 0.0, soma_carta2 = 0.0;
    
    printf("--- Super Trunfo: Desafio Final ---\n\n");

    // Escolha do primeiro atributo
    while (1) {
        printf("Escolha o primeiro atributo para a comparacao:\n");
        exibir_menu(0);
        printf("Sua escolha: ");
        scanf("%d", &escolha1);

        if (escolha1 >= 1 && escolha1 <= 4) {
            break;
        }
        printf("Escolha invalida! Tente novamente.\n\n");
    }

    // Escolha do segundo atributo
    while (1) {
        printf("\nEscolha o segundo atributo para a comparacao:\n");
        exibir_menu(escolha1);
        printf("Sua escolha: ");
        scanf("%d", &escolha2);

        if (escolha2 >= 1 && escolha2 <= 4 && escolha2 != escolha1) {
            break;
        }
        printf("Escolha invalida ou repetida! Tente novamente.\n\n");
    }

    // Lógica da comparação do primeiro atributo
    float valor1_carta1 = obter_valor_atributo(&carta1, escolha1);
    float valor1_carta2 = obter_valor_atributo(&carta2, escolha1);
    int resultado1;
    
    // Densidade Demográfica vence o menor valor, os outros o maior
    if (escolha1 == 2) {
        resultado1 = compara_menor(valor1_carta1, valor1_carta2);
    } else {
        resultado1 = compara_maior(valor1_carta1, valor1_carta2);
    }

    // Lógica da comparação do segundo atributo
    float valor2_carta1 = obter_valor_atributo(&carta1, escolha2);
    float valor2_carta2 = obter_valor_atributo(&carta2, escolha2);
    int resultado2;

    if (escolha2 == 2) {
        resultado2 = compara_menor(valor2_carta1, valor2_carta2);
    } else {
        resultado2 = compara_maior(valor2_carta1, valor2_carta2);
    }

    // Calculando a soma dos atributos
    soma_carta1 = valor1_carta1 + valor2_carta1;
    soma_carta2 = valor1_carta2 + valor2_carta2;

    // Exibição dos resultados detalhados
    printf("\n--- Detalhes da Comparacao ---\n");
    printf("Comparando %s e %s\n\n", carta1.nome, carta2.nome);
    
    const char *titulo1, *titulo2;
    switch (escolha1) {
        case 1: titulo1 = "Populacao"; break;
        case 2: titulo1 = "Densidade Demografica"; break;
        case 3: titulo1 = "Area"; break;
        case 4: titulo1 = "PIB"; break;
    }
    switch (escolha2) {
        case 1: titulo2 = "Populacao"; break;
        case 2: titulo2 = "Densidade Demografica"; break;
        case 3: titulo2 = "Area"; break;
        case 4: titulo2 = "PIB"; break;
    }
    
    exibir_resultado(titulo1, valor1_carta1, valor1_carta2, resultado1);
    exibir_resultado(titulo2, valor2_carta1, valor2_carta2, resultado2);

    printf("\n--- Resultado Final ---\n");
    printf("Soma dos atributos %s: %.2f\n", carta1.nome, soma_carta1);
    printf("Soma dos atributos %s: %.2f\n\n", carta2.nome, soma_carta2);

    // Comparação final da soma
    int resultado_final = compara_maior(soma_carta1, soma_carta2);
    switch (resultado_final) {
        case 1:
            printf("Vencedor: %s!\n", carta1.nome);
            break;
        case 2:
            printf("Vencedor: %s!\n", carta2.nome);
            break;
        default:
            printf("Empate!\n");
            break;
    }

    return 0;
}

// Implementação das funções auxiliares
int compara_maior(float valor1, float valor2) {
    return (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
}

int compara_menor(float valor1, float valor2) {
    return (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
}

void exibir_resultado(const char *titulo, float valor1, float valor2, int resultado_comparacao) {
    printf("%s:\n", titulo);
    printf("  %s: %.2f\n", carta1.nome, valor1);
    printf("  %s: %.2f\n", carta2.nome, valor2);
    printf("  Vencedor: %s\n\n", (resultado_comparacao == 1) ? carta1.nome : (resultado_comparacao == 2) ? carta2.nome : "Empate");
}

void exibir_menu(int escolha_anterior) {
    if (escolha_anterior != 1) printf("1. Populacao\n");
    if (escolha_anterior != 2) printf("2. Densidade Demografica\n");
    if (escolha_anterior != 3) printf("3. Area\n");
    if (escolha_anterior != 4) printf("4. PIB\n");
}

float obter_valor_atributo(const Carta *carta, int atributo_id) {
    switch (atributo_id) {
        case 1: return (float)carta->populacao;
        case 2: return carta->densidade_demografica;
        case 3: return (float)carta->area;
        case 4: return carta->pib;
        default: return 0.0;
    }
}
