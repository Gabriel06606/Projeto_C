#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int Cripto(char frase[30], char key[]){

    int tamanhoF;
    int tamanhoK = strlen(key);
    tamanhoF = strlen(frase);

    char *final = (char *) malloc(sizeof(char) * tamanhoF);

    FILE *file = fopen("file.txt", "w+");

    if (NULL == file) {
        printf("Arquivo não encontrado/inexistente");
    } else {
        for (int c = 0; c <= strlen(frase); c++) {
            final[c] = frase[c] ^ key[c % tamanhoK];
        }
        fputs(final, file);

    }
    fclose(file);
    free(final);
}

int Xor(char key[]) {
    char frase[30];
    printf("Digite a frase a ser criptografada: \n");
    scanf("%s", frase);
    Cripto(key, frase);
    printf("A frase foi criptografada com sucesso!\n");
}

int Descriptografar(char key[]) {
    char frase[30];
    printf("Digite a frase a ser descriptografada: \n");
    scanf("%s", frase);
    Cripto(key, frase);
    printf("A frase foi descriptografada com sucesso!\n");
}

int main(void) {
    int escolha = 0;
    do {
        printf("O que deseja fazer?\n 1 - Criptografar\n 2 - Descriptografar\n 3 - Sair\n : ");
        scanf("%d", &escolha);
        switch(escolha) {
            case 1:
                Xor("6789");
                break;
            case 2:
                Descriptografar("6789");
                break;
            case 3:
                break;
            default:
                printf("Escolha entre (1, 2 ou 3)\n");
        }
    }while(escolha != 3);
}