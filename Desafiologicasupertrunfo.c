#include <stdio.h>
#include <string.h> 

// Função criada para calcular a densidade populacional
float calcular_densidade_p(unsigned long int populacao, float area){
    return populacao / area;
}

// Função para calcular o Pib per capita
float calcular_pib_per_capita(float pib, unsigned long int populacao){
    return (pib *1000000000) / populacao; // realizo a multiplicação do PIB que está em bilhões, para convertê-lo em reais
}

//Função para calcular o Super Poder das cartas
float calcular_superpoder(unsigned long int populacao,  float area, float pib, float pontos_t, float pibpercapita, float densidadep){
    return populacao + area + (pib * 1000000000) + pontos_t + pibpercapita + (1 / densidadep);
}

int main() {
    // Aqui eu declaro as variaveis da primeira carta
    char estado; 
    char codigo[5]; 
    char cidade[25];
    unsigned long int populacao = 0;
    float area = 0;
    float pib = 0;
    int pontos_t = 0;

    // Aqui eu declaro as variaveis da segunda carta
    char estado2; 
    char codigo2[5]; 
    char cidade2[25];
    unsigned long int populacao2 = 0;
    float area2 = 0;
    float pib2 = 0;
    int pontos_t2 = 0;

    // Peço para o usuario digitar os dados da carta 1
    printf("Digite um estado com uma letra de A-H:\n");
    scanf(" %c", &estado);

    printf("Digite um codigo para a sua cidade com a letra do estado seguida de um número de 01-04:\n");
    scanf("%4s", codigo);
    getchar(); // Estava com alguns erros, o programa pulava algumas linhas no terminal, então dei uma pesquisada e colocar alguns getchar(), ajudaram a não ocorrer mais
               // para limpar o buffer de entrada do ENTER
    printf("Digite uma cidade:\n");
    fgets(cidade, sizeof(cidade), stdin);  // Precisei colocar este fgets para ler cidades com espaços entre o nome
    cidade[strcspn(cidade, "\n")] = 0;     

    printf("Digite a população da sua cidade:\n");
    scanf("%d", &populacao);

    printf("Digite a area em km² da sua cidade:\n");
    scanf("%f", &area);

    printf("Digite o pib da sua cidade:\n");
    scanf("%f", &pib);

    printf("Digite o numero de pontos turísticos da sua cidade:\n");
    scanf("%d", &pontos_t);
    getchar(); 

    //peço para o usuario digitar os dados da carta 2
    printf("Digite outro estado com uma letra de A-H(Não repita a letra do primeiro Estado):\n");
    scanf(" %c", &estado2);

    printf("Digite um codigo para a sua outra cidade com a letra do estado seguida de um número de 01-04:\n");
    scanf("%s", codigo2);
    getchar();

    printf("Digite a sua outra cidade:\n");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;

    printf("Digite a população da sua outra cidade:\n");
    scanf("%d", &populacao2);

    printf("Digite a area em km² da sua outra cidade:\n");
    scanf("%f", &area2);

    printf("Digite o pib da sua outra cidade:\n");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turísticos da sua outra cidade:\n");
    scanf("%d", &pontos_t2);

    //Calculos de todos atributos pedidos das cartas
    float densidadep1 = calcular_densidade_p(populacao, area);
    float pibpercapita1 = calcular_pib_per_capita(pib, populacao);
    float superpoder1 = calcular_superpoder(populacao, area, pib,pontos_t, pibpercapita1, densidadep1);

    float densidadep2 = calcular_densidade_p(populacao2, area2);
    float pibpercapita2 = calcular_pib_per_capita(pib2, populacao2);
    float superpoder2 = calcular_superpoder(populacao2, area2, pib2, pontos_t2, pibpercapita2, densidadep2);

    // Aqui eu exibo no terminal a primeira carta
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de pontos turísticos: %d\n", pontos_t);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadep1);
    printf("PIB per Capita: %.2f reais\n", pibpercapita1);
    printf("Super Poder: %.2f\n", superpoder1); // Incluí o SUPERPODER

    // Aqui eu exibo no terminal a segunda carta
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de pontos turísticos: %d\n", pontos_t2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadep2);
    printf("PIB per Capita: %.2f reais\n", pibpercapita2);
    printf("Super Poder: %.2f\n", superpoder2); // Incluí o SUPERPODER

    //Comparação das cartas: (código antigo)
    // 1 + (valor1 < valor2) → Retorna 1 se a Carta 1 vencer, ou 2 se a Carta 2 vencer.
    // (valor1 > valor2) * 1 → Retorna 1 se a Carta 1 vencer, ou 0 se a Carta 2 vencer.
    /*printf("Comparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", 1 + (populacao < populacao2), (populacao > populacao2) * 1);
    printf("Área: Carta %d venceu (%d)\n", 1 + (area < area2), (area > area2) * 1);
    printf("PIB: Carta %d venceu (%d)\n", 1 + (pib < pib2), (pib > pib2) * 1);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", 1 + (pontos_t < pontos_t2), (pontos_t > pontos_t2) * 1);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 1 + (densidadep1 > densidadep2), (densidadep1 < densidadep2) * 1); 
    printf("PIB per Capita: Carta %d venceu (%d)\n", 1 + (pibpercapita1 < pibpercapita2), (pibpercapita1 > pibpercapita2) * 1);
    printf("Super Poder: Carta %d venceu (%d)\n", 1 + (superpoder1 < superpoder2), (superpoder1 > superpoder2) * 1);*/

    // Exibir o menu de escolha
    int atributo1, atributo2;
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - Super Poder\n");
    scanf("%d", &atributo1);

    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    scanf("%d", &atributo2);

    // Validar as escolhas
    if (atributo1 < 1 || atributo1 > 6 || atributo2 < 1 || atributo2 > 6 || atributo1 == atributo2) {
        printf("Escolhas inválidas. Tente novamente com dois atributos diferentes entre 1 e 6.\n");
        return 1;
}

    // Variáveis para armazenar os valores dos atributos
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    // Obter valores do primeiro atributo
    switch (atributo1) {
        case 1:
            valor1_carta1 = populacao;
            valor1_carta2 = populacao2;
            break;
        case 2:
            valor1_carta1 = area;
            valor1_carta2 = area2;
            break;
        case 3:
            valor1_carta1 = pib;
            valor1_carta2 = pib2;
            break;
        case 4:
            valor1_carta1 = pontos_t;
            valor1_carta2 = pontos_t2;
            break;
        case 5:
            valor1_carta1 = densidadep1;
            valor1_carta2 = densidadep2;
            break;
        case 6:
            valor1_carta1 = superpoder1;
            valor1_carta2 = superpoder2;
            break;
}

    // Obter valores do segundo atributo
    switch (atributo2) {
        case 1:
            valor2_carta1 = populacao;
            valor2_carta2 = populacao2;
            break;
        case 2:
            valor2_carta1 = area;
            valor2_carta2 = area2;
            break;
        case 3:
            valor2_carta1 = pib;
            valor2_carta2 = pib2;
            break;
        case 4:
            valor2_carta1 = pontos_t;
            valor2_carta2 = pontos_t2;
            break;
        case 5:
            valor2_carta1 = densidadep1;
            valor2_carta2 = densidadep2;
            break;
        case 6:
            valor2_carta1 = superpoder1;
            valor2_carta2 = superpoder2;
            break;
}

    // Mostrar valores
    printf("\nComparando atributos:\n");
    printf("Atributo 1: %.2f (Carta 1) vs %.2f (Carta 2)\n", valor1_carta1, valor1_carta2);
    printf("Atributo 2: %.2f (Carta 1) vs %.2f (Carta 2)\n", valor2_carta1, valor2_carta2);

    // Somar os pontos (lembrando que para densidade, menor vence)
    float pontos_carta1 = 0, pontos_carta2 = 0;

    // Atributo 1
    if (atributo1 == 5) {
        if (valor1_carta1 < valor1_carta2) pontos_carta1++;
        else if (valor1_carta2 < valor1_carta1) pontos_carta2++;
    } else {
        if (valor1_carta1 > valor1_carta2) pontos_carta1++;
        else if (valor1_carta2 > valor1_carta1) pontos_carta2++;
}

// Atributo 2
    if (atributo2 == 5) {
        if (valor2_carta1 < valor2_carta2) pontos_carta1++;
        else if (valor2_carta2 < valor2_carta1) pontos_carta2++;
    } else {
        if (valor2_carta1 > valor2_carta2) pontos_carta1++;
        else if (valor2_carta2 > valor2_carta1) pontos_carta2++;
}

    // Mostrar resultado
    printf("\nPontuação final:\n");
    printf("Carta 1: %.0f pontos\n", pontos_carta1);
    printf("Carta 2: %.0f pontos\n", pontos_carta2);

    if (pontos_carta1 > pontos_carta2)
        printf("Resultado: Carta 1 venceu!\n");
    else if (pontos_carta2 > pontos_carta1)
        printf("Resultado: Carta 2 venceu!\n");
    else
        printf("Resultado: Empate!\n");

        
    return 0;

}