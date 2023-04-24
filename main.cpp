/*
 * Jogo de forca implementado através da aula da Alura para raciocinio e lógica
 * de programação. O programa consiste em que enquanto o jogador não enforcar e 
 * não acertar a palavra, ele deve chutar uma letra para acertar a palavra.
 * o método nao_acertou() é utilizada para caso o jogador não tenha acertado as 
 * letras na palavra secreta, ele continuará jogando.
 * já o nao_enforcou() dá o limite de tentativas para o jogador, que são no max.
 * 5 chutes errados.
 * após isso o chute é mandado para o map de tipo char e booleano denominado 
 * CHUTOU.
 * após ser mandado é feita a identificação através da função letra_existe() se o
 * chute existe na PALAVRA_SECRETA ou não.
 *  para fazer a comparação do chute com a letra na palavra,
 * é utilizado um laço FOR com um CHAR  que percorre toda a STRING. A partir
 * disso, é feita a procura da letra dentro do MAP <> CHUTOU, caso a letra
 * da String esteja contida no chute, será feito o retorno da(s) letra(s)
 * na palavra secreta.
 * caso o chute não corresponda, a funçao Letra_existe() nos ajuda a identificar.
 * é utilizado um vetor dinamico chamadado VECTOR<>chute_errados que armazena os 
 * chutes que não correspondem na PALAVRA_SECRETA. após armazenados 
 * é feito um FOR no qual percorre o chutes errados e retorna os chutes errados 
 * ao usuário, para que ele não repita o mesmo chute.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;
const string PALAVRA_SECRETA = "MELANCIA";
 map<char,bool>chutou;
 vector<char>chute_errados;

bool letra_existe(char chute){
    for (char letra : PALAVRA_SECRETA){
        if(letra == chute){
            return true;
        }
    }
    return false;
}
bool nao_acertou(){
    for(char letra : PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}     
bool nao_enforcou(){
   return chute_errados.size() < 5;
}
void imprime_chutes_errados(){
      cout << "chutes errados: ";
        for (char letra : chute_errados){
            cout << letra << " ";
        }
}
void imprime_palavra(){
    for (char letra : PALAVRA_SECRETA){
        if(chutou[letra]){
                cout << letra << " ";
            }else {
                cout << " _ ";
            }
            
        }
}
void chuta(){
     char chute;
        
        cout << "faça o chute: ";
        cin >> chute;
        
        chutou[chute] = true;;
        if(letra_existe(chute)){
            cout << "\n Seu chute está na palavra secreta" << endl;
        } else {
            cout << "seu chute não está palavra secreta" << endl;
            chute_errados.push_back(chute);
           
        }
}
void leArquivo(){
    
    ifstream arquivo;
    
    arquivo.open("forca.txt");//abre o arquivo
    int quantidade_palavras;
    arquivo >> quantidade_palavras; 
    cout << "O arquivo possui " << quantidade_palavras << " Palavras";
    for (int i=0; i<quantidade_palavras; i++){
        string PalavraLida;
        arquivo >> PalavraLida;
        cout << "Na linha " << i << " : " << PalavraLida << endl;
        
    }
}

//faz o mapeamento das letras

int main(int argc, char** argv) {
    leArquivo();
     
    while (nao_acertou() && nao_enforcou()){
        imprime_chutes_errados();
        
        cout << endl;
        
        imprime_palavra();
        
        cout << endl;
        
        chuta();
    }
    cout << "FIM DE JOGO\n";
    cout << "a palavra era: MELANCIA\n";
    
    if(nao_acertou()){
        cout << "Perdeu";
    }else{
        cout << "Ganhou";
                
    }
    return 0;
}

