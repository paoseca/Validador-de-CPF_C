#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

void imprimeRegiao(int cpf[])
{
    if (cpf[8] == 0)
        printf("\nRio Grande do Sul");
    if (cpf[8] == 1)
        printf("\nDistrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins");
    if (cpf[8] == 2)
        printf("\nAmazonas, Pará, Roraima, Amapá, Acre e Rondônia");
    if (cpf[8] == 3)
        printf("\nCeará, Maranhão e Piauí");
    if (cpf[8] == 4)
        printf("\nParaíba, Pernambuco, Alagoas e Rio Grande do Norte");
    if (cpf[8] == 5)
        printf("\nBahia e Sergipe");
    if (cpf[8] == 6)
        printf("\nMinas Gerais");
    if (cpf[8] == 7)
        printf("\nRio de Janeiro e Espírito Santo");
    if (cpf[8] == 8)
        printf("\nSão Paulo");
    if (cpf[8] == 9)
        printf("\nParaná e Santa Catarina");
}

bool todosRepetidos(int cpf[])
{
    int i;
    for (i = 1; i <= 10; i++)
    {
        if (cpf[0] != cpf[i])
            return false;
    }
    return true;
}

int digitoVerificador(int cpf[], int mult[], int N)
{

    int i, soma = 0;
    for (i = 0; i < N; i++)
    {
        soma = soma + cpf[i] * mult[i];
    }
    int resto = ((soma * 10) % 11) % 10;
    return resto;
} // fim da função

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int cpf[11];
    int m1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int m2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    int i, j = 0, tam;
    char entrada[50];
    printf("Entre com o CPF: ");
    fgets(entrada, 50, stdin);
    tam = strlen(entrada);
    for (i = 0; i < tam; i++)
    {
        if (entrada[i] >= 48 && entrada[i] <= 57)
        {
            cpf[j] = entrada[i] - 48;
            j++;
        }
    }

    if (digitoVerificador(cpf, m1, 9) == cpf[9] &&
        digitoVerificador(cpf, m2, 10) == cpf[10] &&
        !todosRepetidos(cpf))
    {
        printf("\nCPF válido.");
        imprimeRegiao(cpf);
    }
    else
    {
        printf("\nErro no CPF.");
    }
    return 0;
}
