#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Paciente
{
    /* data */
    char nome[100];
    char idade[50];
    char Rua[100];
    char Numero[50];
    char Bairro[100];
    char Cidade[100];
    char Estado[100];
    char CEP[50];
    char Telefone[50];
    char CPF[50];
    char DataNascimento[50];
    char comorbidades[50];
};

int main()
{
    struct Paciente paciente;
    int senha;
    int i;

    printf("Digite sua senha:");
    scanf("%d", &senha);

    if (senha == 123)
    {
        printf("Acesso permitido");
        printf("\n\n");

        // Inserir um loop, para que o usuário possa inserir quantos pacientes quiser
        while (true)
        {
            // Dados do Paciente
            printf("Digite o nome do paciente:");
            scanf("%s", paciente.nome);
            printf("\n");

            printf("Digite a idade do paciente:");
            scanf("%s", paciente.idade);
            printf("\n");

            printf("Digite o endereco do paciente:");
            scanf("%s", paciente.Rua);
            printf("\n");

            printf("Digite o numero da casa do paciente:");
            scanf("%s", paciente.Numero);
            printf("\n");

            printf("Digite o bairro do paciente:");
            scanf("%s", paciente.Bairro);
            printf("\n");

            printf("Digite a cidade do paciente:");
            scanf("%s", paciente.Cidade);
            printf("\n");

            printf("Digite o estado do paciente:");
            scanf("%s", paciente.Estado);
            printf("\n");

            printf("Digite o CEP do paciente:");
            scanf("%s", paciente.CEP);
            printf("\n");

            printf("Digite o telefone do paciente:");
            scanf("%s", paciente.Telefone);
            printf("\n");

            printf("Digite o CPF do paciente:");
            scanf("%s", paciente.CPF);
            printf("\n");

            printf("Digite a data de nascimento do paciente:");
            scanf("%s", paciente.DataNascimento);
            printf("\n");

            printf("Digite as comorbidades do paciente:");
            scanf("%s", paciente.comorbidades);
            printf("\n");

            // Salvar dados do paciente em um arquivo .csv
            printf("Salvando os dados do Paciente, Por favor aguarde...\n");
            FILE *arquivo;
            char *nomeArquivo;
            char *nomePaciente;
            nomePaciente = paciente.nome;
            nomeArquivo = strcat(nomePaciente, ".csv");
            arquivo = fopen(nomeArquivo, "w");
            fprintf(arquivo, "nome,idade,idade,rua,numero,bairro,cidade,estado,cep,telefone,cpf,datanascimento,comorbidades\n");
            fprintf(arquivo, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", paciente.nome, paciente.idade, paciente.Rua, paciente.Numero, paciente.Bairro, paciente.Cidade, paciente.Estado, paciente.CEP, paciente.Telefone, paciente.CPF, paciente.DataNascimento, paciente.comorbidades);
            fclose(arquivo);
            printf("Dados do Paciente salvos com sucesso!\n\n");

            // Transformar idade em int
            int idade;
            idade = atoi(paciente.idade);

            // Verificndo se o paciente tem mais de 65 e se tem alguma comorbidade e salvar CEP e idade do paciente em um arquivo .txt
            if (idade > 65)
            {
                printf("O paciente tem mais de 65 anos\n");
                printf("\n");
                // Verifica se o paciente tem comorbidades
                if (paciente.comorbidades != NULL)
                {
                    // Verificar se o pacinente tem diabetes ou hipertensao ou obesidade ou tuberculose ou outros
                    if(paciente.comorbidades == "diabetes" || paciente.comorbidades == "hipertensao" || paciente.comorbidades == "obesidade" || paciente.comorbidades == "tuberculose" || paciente.comorbidades == "outros")
                    {
                        printf("O paciente tem comorbidades\n");
                        printf("\n");
                        printf("Salvando os dados do Paciente, Por favor aguarde...\n");
                        FILE *arquivo;
                        char *nomeArquivo;
                        nomeArquivo = strcat(paciente.nome, ".txt");
                        arquivo = fopen(nomeArquivo, "w");
                        fprintf(arquivo, "CEP: %s\n", paciente.CEP);
                        fprintf(arquivo, "Idade: %s\n", paciente.idade);
                        fclose(arquivo);
                        printf("Dados para Secretaria da Saude salvos com sucesso!\n\n");
                    }
                }
                else
                {
                    printf("O paciente nao tem comorbidades\n");
                    printf("\n");
                }
            }
            else
            {
                printf("O paciente nao tem mais de 65 anos\n");
                printf("\n");
            }

            // Verificar se o usuario quer continuar inserindo paciente

            printf("Deseja continuar inserindo pacientes?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &i);
            printf("\n");

            if (i == 2)
            {
                printf("Programa finalizado\n");
                break;
            }

            // Resetar todas as variaveis
            memset(&paciente, 0, sizeof(paciente));
            arquivo = NULL;
            nomeArquivo = NULL;
            nomePaciente = NULL;
        }
    }
    else
    {
        printf("Acesso negado\n\n");
    }

    system("Pause");
    return 0;
}
