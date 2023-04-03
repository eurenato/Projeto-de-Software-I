#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void perguntaserespostas(){
    int a, resposta;
    char opcao, jogarnovamente;
    printf("bem-vindo ao jogo de perguntas e respostas!\n");

    do {
        for(a = 1; a <= 5; a++) {
            switch (a) {
                case 1:
                    printf("1: Qual o verdadeiro nome do Bruno Mars?\n");
                    printf("a) Peter\nb) Gabriel\nc) Jack\nd) Arthur\n");
                    resposta = 'a';
                    break;

                case 2:
                    printf("2: Quantas cores tem o arco-íris?\n");
                    printf("a) 10\nb) 7\nc) 14\nd) 8\n");
                    resposta = 'b';
                    break;

                case 3:
                    printf("3: De onde é a invenção do chuveiro elétrico?\n");
                    printf("a) Japão\nb) Brasil\nc) Estados Unidos\nd) Inglaterra\n");
                    resposta = 'b';
                    break;

                case 4:
                    printf("4: Em qual nível de teste é avaliada uma unidade de código?\n");
                    printf("a) Unidade\nb) Componente\nc) Integração\nd) Sistemas\n");
                    resposta = 'a';
                    break;

                case 5:
                    printf("5: Quem pintou o teto da Capela Sistina?\n");
                    printf("a) Rafael\nb) Donatello\nc) Leonardo da Vinci\nd) Michelangelo\n");
                    resposta = 'd';
                    break;
            }

            printf("\nescolha a alternativa correta: ");
            scanf(" %c", &opcao);
            opcao = tolower(opcao); // converter a opção para letra minúscula

            if(opcao == resposta) {
                printf("você acertou!\n");
            } else {
                printf("você errou, a resposta correta é: %c\n", resposta);
            }
        }

        printf("quer jogar novamente? (S/N) ");
        scanf(" %c", &jogarnovamente);
        jogarnovamente = toupper(jogarnovamente);

    } while(jogarnovamente == 'S');
}

void cobranacaixa() {
    int caixas[5] = {0, 0, 0, 0, 0};
    int sorteio, a, vencedor = 0;
    char nome1[50], nome2[50], jogarnovamente;
    printf("bem-vindo ao jogo da cobra na caixa\n");
    printf("jogador 1, digite seu primeiro nome: ");
    scanf("%s", nome1);
    printf("jogador 2, digite seu primeiro nome: ");
    scanf("%s", nome2);

    sorteio = rand() % 2 + 1;
    printf("o jogador %d comeca\n", sorteio);
    caixas[rand() % 5] = 1;
    caixas[rand() % 5] = 2;

    while(vencedor == 0){
        printf("%s, escolha uma caixa de 1 a 5: ", sorteio == 1 ? nome1 : nome2);
        scanf("%d", &a);
        if(caixas[a - 1] == 0){
            printf("caixa vazia\n");
            caixas[a - 1] = -1;
        }else if(caixas[a - 1] == 1){
            printf("voce encontrou a cobra, game over\n");
            vencedor = (sorteio == 1) ? 2 : 1;
        }else if(caixas[a - 1] == 2){
            printf("voce encontrou o botao, parabens %s voce venceu\n", sorteio == 1 ? nome1 : nome2);
            vencedor = sorteio;
        }
        if(sorteio == 1){
            sorteio = 2;
        }else {
            sorteio = 1;
        }
    }
    printf("quer jogar novamente? (S/N) ");
    scanf(" %c", &jogarnovamente);
    jogarnovamente = toupper(jogarnovamente);
    if(jogarnovamente == 'S'){
        cobranacaixa();
    }
        
    



    
}

int main() {
    int numero;
    char comecarjogo;

    do {
        printf("Click Jogos\n");
        printf("escolha uma opção:\n");
        printf("1: perguntas e respostas\n");
        printf("2: cobra na caixa\n");
        printf("3: sair\n");
        scanf("%d", &numero);

        switch(numero) {
            case 1:
                printf("esse é um jogo em que o computador faz uma pergunta e apresenta quatro alternativas, pedindo ao usuário que escolha a alternativa correta.\n");
                printf("quer começar o jogo? (S/N) ");
                scanf(" %c", &comecarjogo);
                comecarjogo = toupper(comecarjogo);
                 if(comecarjogo == 'S') {
                    perguntaserespostas();
                }
                break;

            case 2:
                printf("esse é um jogo de sorte, onde ganha o jogador que descobrir a caixa que contém o botão e perde aquele que descobrir a caixa com a cobra.\n");
                printf("quer começar o jogo? (S/N) ");
                scanf(" %c", &comecarjogo);
                comecarjogo = toupper(comecarjogo);
                if(comecarjogo == 'S'){
                    cobranacaixa();
                    
                }
                break;
            case 3:
                printf("obrigado por ter jogado\n");
                break;

            default:
                printf("opcao invalida\n");
        }

    } while(numero != 3);

    return 0;
}