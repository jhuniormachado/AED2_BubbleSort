//
// Algoritmo de ordenação: Bubble sort
//
// Por: Kleyson de Melo Lopes e Lázaro Júnior Machado Pontes
//
// Declarações usadas para demonstração do algoritmo Bubble Sort
// e suas adaptações.
//
// Observação: código construído com base na revisão/no padrão C++17
// da linguagem de programação C++ e em Microsoft Visual C++17. Tornando
// dispensável o uso de bibliotecas como cstdlib no código atual.
//

#include <iostream>
#include <ctime>

using namespace std;

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Funções básicas
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Preenche o vetor com valores pseudo-aleatórios
void preencherVetor(int tam, int * vetor){
    // Função de semente para a função rand, para obter
    // números diferentes a cada execução, para isso,
    // recebendo como argumento o horário atual.
    srand(time(NULL));
    for (int i = 0; i<tam; i++){
        vetor[i] = rand()%100;
    }
};

// Imprime o vetor em stdout
void exibirVetor(int tam, int * vetor){
    for(int i = 0; i < tam; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
};

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Automatização do pré-teste com 100.000 valores de entrada
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Organiza o vetor com primeira metade crescente e
// segunda metade decrescente.
void centro(int tam, int * vetor){
    for (int p=1; p<tam; p++){
        for (int i = 0; i < tam/2; i++){
            if (vetor[i] > vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
            }
        }
        for (int i = tam/2; i < tam-1; i++){
            if (vetor[i] < vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
            }
        }
    }
}

// Organiza o vetor com primeira metade decrescente e
// segunda metade crescente.
void lados(int tam, int * vetor){
    for (int p=1; p<tam; p++){
        for (int i = 0; i < tam/2; i++){
            if (vetor[i] < vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
            }
        }
        for (int i = tam/2; i < tam-1; i++){
            if (vetor[i] > vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
            }
        }
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Algoritmo principal Bubble Sort crescente e suas adaptações
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Função Bubble Sort original
void crescente(int tam, int * vetor){
    for (int p=1; p<tam; p++){
        for (int i = 0; i < tam-p; i++){
            if (vetor[i] > vetor[i+1]){ 
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
            }
        }
    }
}

// Função Bubble Sort otimizada
void crescenteOti(int tam, int * vetor){
    for (int p=1; p<tam; p++){
        // trocado indica se após todas as iterações no passo
        // atual houve troca de posições no vetor ou não, se
        // o valor for 1, significa que houve troca e o vetor
        // ainda não está completamente organizado no passo
        // atual, devendo continuar o processo de organização,
        // se o valor for 0, significa que o vetor já está
        // organizado, não sendo necessária novos passo ou
        // iterações.
        // trocado só será verificado no passo subsequente ao
        // passo no qual houve alteração;
        int trocado = 0;
        for (int i = 0; i < tam-p; i++){
            if (vetor[i] > vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                trocado = 1;
            }
        }
        if (trocado == 0){
            break;
        }
    }
}

// Função Bubble Sort recursiva
// Pode resultar em sobrecarga de pilha com entradas
// muito grandes.
void crescenteRec(int tam, int * vetor){
    if (tam == 1){
        return;
    }
    for (int i = 0; i < tam-1; i++){
        if (vetor[i] > vetor[i+1]){
            int temp = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = temp;
        }
    }
    crescenteRec(tam-1, vetor);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Algoritmo principal Bubble Sort decrescente e suas adaptações
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Função Bubble Sort decrescente
void decrescente(int tam, int * vetor){
    for (int p=1; p<tam; p++){
        for (int i = 0; i < tam-p; i++){
            if (vetor[i] < vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
            }
        }
    }
}

// Função Bubble Sort decrescente otimizada
void decrescenteOti(int tam, int * vetor){
    for (int p=1; p<tam; p++){
        // trocado indica se após todas as iterações no passo
        // atual houve troca de posições no vetor ou não, se
        // o valor for 1, significa que houve troca e o vetor
        // ainda não está completamente organizado no passo
        // atual, devendo continuar o processo de organização,
        // se o valor for 0, significa que o vetor já está
        // organizado, não sendo necessária novos passo ou
        // iterações.
        // trocado só será verificado no passo subsequente ao
        // passo no qual houve alteração;
        int trocado = 0;
        for (int i = 0; i < tam-p; i++){
            if (vetor[i] < vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                trocado = 1;
            }
        }
        if (trocado == 0){
            break;
        }
    }
}

// Função Bubble Sort recursiva
// Pode resultar em sobrecarga de pilha com entradas
// muito grandes.
void decrescenteRec(int tam, int * vetor){
    if (tam == 1){
        return;
    }
    for (int i = 0; i < tam-1; i++){
        if (vetor[i] < vetor[i+1]){
            int temp = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = temp;
        }
    }
    decrescenteRec(tam-1, vetor);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Função principal
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int main(){
    int tam;
    cout << "Digite o tamanho do vetor a criar: ";
    cin >> tam;
    cout << endl;

    // Alocação dinâmica do espaço de memória do
    // vetor.
    int * vetor;
    vetor = (int *) malloc(tam*sizeof(int));

    preencherVetor(tam, vetor);
    cout << "Entrada:" << endl;
    exibirVetor(tam, vetor);
    crescente(tam, vetor);
    cout << "Saida:" << endl;;
    exibirVetor(tam, vetor);

    // Para medição do tempo em uma bateria de 10
    // execuções, descomente o for seguinte e comente
    // as linhas de 232 até 237.
    // Substitua "crescente(tam, vetor);" pela
    // função que desejar medir o tempo de execução.
    /*
    for (int i = 1; i <= 10; i++){
        preencherVetor(tam, vetor);
        int inicio=clock();
        crescente(tam, vetor);
        int fim=clock();
        cout << "Tempo de execucao do algoritmo" << i << ":\t" << (fim-inicio)/double(CLOCKS_PER_SEC)*1000 << endl;
    }
    */
    
    // Liberação do espaço de memória do vetor
    free(vetor);

    // Para sistemas Microsoft Windows, pausa o console.
    cout << endl;
    system("pause");
    return 0;
}