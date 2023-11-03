
#include <iostream>
#include <cstdlib> // Biblioteca rand
#include <ctime> //Biblioteca do Time
using namespace std; // Essa biblioteca me permite não usar o "STD:: a cada linha"

int main () {

    // função abaixo é responsavel por imprimir qualquer tipo de textp

    cout << "***************************************" <<endl; //endl serve para pular linha
    cout << "* Bem - Vindo ao jogo da adivinhacao! *" <<endl;
    cout << "***************************************" <<endl;

    // Criando um novel de dificuldade para o usuario

    cout <<"Escolha seu nivel de dificuldades " <<endl;
    cout <<"Facil (F), Médio (M) ou Dificil (D)" <<endl;

    char dificuladade;
    cin >> dificuladade;

    int numero_de_tentativas;

    if(dificuladade == 'F'){
        numero_de_tentativas = 15;
    }
    else if(dificuladade =='M'){
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }

    // Responsavel por fazer os numeros serem sorteados de forma aleatoria
    srand(time(NULL));

    // "CONST, permite que eu não coloque outra variavel igual, só consigo mudar ela diretamente nessa linha"
    //"% 100", permite que meu numero secreto seja de 0 a 99
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acerto = true;
    int tentativas = 0;
    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){

    // "cin", é uma variavel que recebe o valor
    int chute;
    cout << "Tentativas  " << tentativas << endl;

    cout << "Chute um numero: ";
    cin >> chute;

    double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
    pontos = pontos - pontos_perdidos;

    cout << "O valor da sua tentativa foi:  " << chute << endl;


    //"bool, variavel que só aceita se for verdadeiro ou falso"
    bool acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;

    if(acertou) {
        cout << " Parabens! Voce acertou o numero secreto!" <<endl;
        nao_acerto = false;
        break;
    }

    else if( maior){
        cout << "Seu numero foi maior que o numero secreto!" <<endl;
    }

    else{
        cout << " Seu chute foi menor que o numero secreto!" <<endl;
       
    }
    } 

    cout << "Fim de Jogo!!!" << endl;

    if(nao_acerto){
        cout << "Você perdeu! Tente novamente! " <<endl;
    }

    else {
    cout << "Voce acertou o numero secreto em " << tentativas << " tentativas " << endl;
    cout.precision(2); // considerando ias casas decimais
    cout << fixed; // pedindo para a virgula ficar no lugar, considerando duas casas decimais
    cout << "Sua pontuacao foi de " << pontos << " pontos. " <<endl; 
    }

}