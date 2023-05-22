//Mariana Nunes Terol - UC22200554

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15

int le_valida_idade();

typedef struct Disciplina {
    char nome[50];
    int codigo;
    int carga_horaria;
    char profr[50];
    float notas[4];
} Disciplina;

typedef struct Professor {
    char nome[50];
    char funcional[50];
    char titulacao[50];
} Professor;

typedef struct Aluno {
    char nome[50];
    char matricula[15];
    int idade;
    Disciplina disciplina;
} Aluno;

void bubbleSort(Aluno* alunos, int n) {
    int i, j;
    Aluno temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (alunos[j].idade > alunos[j + 1].idade) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}


int main(void) {
    int i, j, qtd_alunos[TAM] = {0};
    int menor_idade = 100, maior_idade = 0;
    float media, maior_media = 0;
    char nome_maior_media[50];
    Aluno alunos[TAM];
    Professor professor[3];
    Disciplina disciplina[2];


    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\tAlunos\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    for (i = 0; i < TAM; i++) {
        printf("Informe o nome: ");
        scanf(" %[^\n]s", alunos[i].nome);

        printf("Informe a matricula: ");
        scanf(" %[^\n]s", alunos[i].matricula);

        alunos[i].idade = le_valida_idade();
        fflush(stdin); 

        if (alunos[i].idade < menor_idade) {
            menor_idade = alunos[i].idade;
        }

        if (alunos[i].idade > maior_idade) {
            maior_idade = alunos[i].idade;
        }

        printf("\n");
    }
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\tDisciplina\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    for (i = 0; i < 2; i++) {
        printf("Informe o nome da disciplina: ");
        scanf(" %[^\n]s", disciplina[i].nome);

        printf("Informe a carga horaria: ");
        scanf("%d", &disciplina[i].carga_horaria);

        printf("Informe o codigo da disciplina: ");
        scanf("%d", &disciplina[i].codigo);

        printf("Informe o professor responsavel: ");
        scanf(" %[^\n]s", disciplina[i].profr);

        printf("Informe as 4 notas (separadas por espaco): ");
        for (j = 0; j < 4; j++) {
            scanf("%f", &disciplina[i].notas[j]);
        }

        printf("\n");
    }
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\tProfessores\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    for (i = 0; i < 3; i++) {
        printf("Informe o nome do professor: ");
        scanf(" %[^\n]s", professor[i].nome);

        printf("Informe o funcional (matricula): ");
        scanf(" %[^\n]s", professor[i].funcional);

        printf("Informe a titulacao (especialista, mestre ou doutor): ");
        scanf(" %[^\n]s", professor[i].titulacao);

        printf("\n");
    }

    printf("\n");

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\tRegistro de estudantes: \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    for (i = 0; i < TAM; i++) {
        printf("Nome do aluno %d: %s\n", i + 1, alunos[i].nome);
        printf("Matricula do aluno %d: %s\n", i + 1, alunos[i].matricula);
        printf("Idade do aluno %d: %d\n\n", i + 1, alunos[i].idade);
    }

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-\n");
    printf("\tIdade dos Alunos\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-\n");
    printf("Maior idade: %d\n", maior_idade);
    printf("Menor idade: %d\n", menor_idade);

    printf("\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\tNotas dos estudantes: \n");
    for (i = 0; i < TAM; i++) {
        media = 0;
        for (j = 0; j < 4; j++) {
            media += disciplina[i].notas[j];
        }
        media /= 4;
        printf("Media das notas do aluno %d: %.2f\n", i + 1, media);
        printf("Nome da disciplina: %s\n\n", disciplina[i].nome);
        if (media > maior_media) {
            maior_media = media;
            strcpy(nome_maior_media, alunos[i].nome);
        } else if (media == maior_media) {
            strcat(nome_maior_media, " e ");
            strcat(nome_maior_media, alunos[i].nome);
        }
    }

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\tEstudante(s) com a maior media (%.2f):\n", maior_media);
    printf("%s\n", nome_maior_media);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    printf("\n");


    qtd_alunos[0] = TAM;
    bubbleSort(alunos, TAM);

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\tAlunos matriculados na primeira disciplina ordenados por idade:\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-\n");
    for (i = 0; i < qtd_alunos[0]; i++) {

        printf("%d\n\n", disciplina[0].codigo);
        printf("%s\n\n", disciplina[0].profr);
        printf("%s\n\n", alunos[i].nome);
        printf("%d\n\n", alunos[i].idade);
        printf("\n");
    }
   
    printf("\n");
    
    qtd_alunos[1] = TAM;
    bubbleSort(alunos, TAM);

    for (i = 0, j = TAM - 1; i < j; i++, j--) {
    Aluno temp = alunos[i];
    alunos[i] = alunos[j];
    alunos[j] = temp;
    }

    printf("\n");

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\tAlunos matriculados na segunda disciplina ordenados por idade em ordem decrescente:\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-\n");
    for (i = 0; i < qtd_alunos[1]; i++) {

        printf("%d\n\n", disciplina[1].codigo);
        printf("%s\n\n", disciplina[1].profr);
        printf("%s\n\n", alunos[i].nome);
        printf("%d\n\n", alunos[i].idade);
        printf("\n");
    }

    return 0;
}



int le_valida_idade() {
    int idade = 0, cont = 0;
    
    do {
        if (cont > 0) {
            printf("Idade invalida - entre 16 e 26\n");
        }
        printf("Informe a idade: ");
        scanf("%d", &idade);
        cont++;

    } while (idade < 16 || idade > 26);

    return idade;
}


/*
Elabore um programa utilizando as estruturas Professor, Disciplina e Estudante.

Professor (nome, funcional, titulacao (especialista, mestre ou doutor)).
Disciplina (nome, codigo, carga_horaria, professor_responsavel (escolhidos dentre os professores cadastrados)).
Estudante (nome, matricula, idade).

Serão cadastrados 3 professores, 2 disciplinas e no máximo 15 estudantes distribuídos entre as duas disciplinas, uma disciplina não poderá ter mais que 10 estudantes matriculados.

Apresente um relatório dos alunos matriculados na primeira disciplina ordenados por idade.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

Apresente um relatório dos alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente.
codigo_disciplina   nome_professor  nome_estudante  idade_estudante

Utilize o bubble sort para ordenação utilizano um procedimento com passagem de parâmetros por referência.

Idade do estudante deverá estar validada entre 16 e 26 por meio de uma função le_valida_idade.
*/
