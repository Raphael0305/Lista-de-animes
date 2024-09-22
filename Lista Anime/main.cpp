#include <iostream>
#include <locale.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <conio.h>

using namespace std;

struct animeLista{
	string nomeAnime;
	string Comentario;
};

struct listaTop10{
	int rank;
	string nomeTop;
};
//  AUXILIARES
void systemClear();
void systemPause();
//*******************
// FUNÇÕES PIRNCIPAIS
void menu ();
void cadastrarAnime (vector<animeLista>& anime);
void verTodosAnimes (vector<animeLista>& anime, vector<listaTop10>& top10);
void addTOP10(vector<listaTop10>& top10); // add TOP 10 
void excluirAnime (vector<animeLista>& anime, vector<listaTop10>& top10);

int main(int argc, char** argv) {
	int op;
	setlocale(LC_ALL, "portuguese");
	vector<animeLista> anime;
	vector<listaTop10> top10;
	
	do{
		
		system("cls");
		menu ();
		cin >> op;
		
	
		switch(op){
			
			case 1:
					systemClear();
					cadastrarAnime (anime);
					systemPause();
				break;
			case 2:
					systemClear();
					verTodosAnimes (anime,top10);
					systemPause();
				break;
			case 3:
					systemClear();
					addTOP10(top10);
					systemPause();
				break;
			case 4:
					systemClear();
					excluirAnime (anime, top10);
					systemPause();
				break;
			case 5:

				system("pause");
				break;
			case 6:
				return 0;
				break;		
			default :
				cout << "Essa opção não é valida\n";
				break;		
		}
	}while(true);
		
	
	return 0;
}


void menu (){ //mostrar o menu
	cout << "|=================================|\n";
    cout << "| 1 - Adicionar Anime             |\n";
    cout << "| 2 - Ver Todos os Animes         |\n";
    cout << "| 3 - Adicionar Top 10            |\n";
    cout << "| 4 - Excluir Anime               |\n";
    cout << "| 5 - Salvar                      |\n";
    cout << "| 6 - Sair                        |\n";
    cout << "|=================================|\n";
    cout << "Escolha uma opção: ";
}
//***********************************************************************************************************
//Função para cadastrar animes
void cadastrarAnime (vector<animeLista>& anime){ 
	cout << "+-------------------+\n";
	cout << "| CADASTRO DE ANIME |\n";
	cout << "+-------------------+\n";
	cout << "\n";
	cout << "Press ENTER para voltar\n";
	
	animeLista addAnime;
	
	cout << "\nDigite o nome do Anime\n";
	cin.ignore();
	getline (cin, addAnime.nomeAnime);
	
  	if(addAnime.nomeAnime.empty()){
		cout << "Voltando ao menu...\n";
		return;
	}
	
	cout << "\nComentario\n";
	cin.ignore();
	getline (cin, addAnime.Comentario);
	
	if(addAnime.Comentario.empty()){
		cout << "Voltando ao menu...\n";
		return;
	}
	
	
	
	
	anime.push_back(addAnime);
	cout << "\n Anime Cadastrado\n";
	cout << "\n";
}
//***********************************************************************************************************
//==================================
// LISTA PARA VER TODOS OS ANIMES  |
//==================================

void verTodosAnimes (vector<animeLista>& anime, vector<listaTop10>& top10){
	int OP;
	bool VERIF = true;
	do {
		systemClear();
		cout << "+------------------+\n";
		cout << "| LISTA DE ANIMES  |\n";
		cout << "+------------------+\n";

	                                              // loop para varias coisinhas
		cout << "Qual lista\n";
		cout << " 1 - Lista de Animes\n";
		cout << " 2 - TOP 10\n";
		cout << " 3 - Voltar\n";
		cin >> OP;
	
		switch(OP){
			case 1:
				if(anime.empty()){      // verifica se tem algum valor no vetor
					cout << "\nNão existe anime cadastrado\n";
					systemPause();
					VERIF = true;
					break;
				}else {
					for(const auto& animes : anime){   //mostra os valores
						cout << "===================================================\n";
						cout << "Nome do Anime: " << animes.nomeAnime << "\n";
						cout << "Comentario : " << animes.Comentario << "\n";
						cout << "===================================================\n";
					}	
				}
				VERIF = false;
				break;
			case 2:
				if(top10.empty()){
					cout << "\nNão existe anime cadastrado\n";
					systemPause();
					VERIF = true;
					break;
				}else{
					for(const auto& top : top10){
						cout << "Rank: " << top.rank << "  |   Nome: " << top.nomeTop << "\n";
						cout << "\n";
						VERIF = false;
					}
				}	
				break;
			case 3: 
				return;
				break;
			default:
					cout << "Essa opção não existe \n";
					VERIF = true;
				break;
		}
	
	}while(VERIF);	
}
//***********************************************************************************************************
//====================
// ADICONAR TOP10    |
//===================
void addTOP10(vector<listaTop10>& top10){

	cout << "+==========================+\n";
	cout << "|   ADICIONANDO O TOP 10   |\n";
	cout << "+==========================+\n";
	cout << "\n";
	listaTop10 top; //Declarando a varaiavel que vai pegar os valores 
	string input; // cirando um input auxiliar pra tranformar em int 
	cout << "\n Press ENTER para voltar ao menu\n";
	cout << "\n";
	
	cout << "Nome do anime: ";
	cin.ignore();
	getline(cin, top.nomeTop);
	
	if(top.nomeTop.empty()){     // caso queiraa voltar ao menu sem digitar nada
		cout << "Voltando ao Menu\n";
		return;
	}
	
	cout << "Rank do anime: ";
	cin >> input;
	
	if(input.empty()){
		cout << "Voltando ao Menu\n";
		return;
	}
	
	top.rank = stoi(input);   // fiz esse para que transformar valores string em inteiros, tenho que colocar o try e catch ainda pra ficar melhor\n
	
	top10.push_back(top); // mandando os valores para o vector
}

//***********************************************************************************************************

void excluirAnime (vector<animeLista>& anime, vector<listaTop10>& top10){
	int op;
	string nomeExcluir;
	bool defaul = true; // criado para verificar um valor DEFAULT para voltar as opções
/*	
	if(anime.empty() && top10.empty()){   // verificação de entrada
		cout << "\n";
		cout << "\nNão tem anime cadastrado em nenhuma lista\n";
		cout << "\n";
		return;
	}
*/
	do {  // para caso o valor default seja ativado
		systemClear();
		
		cout << "Qual lista você vai excluir ?\n";
		cout <<" 1 - Lista de Animes \n";
		cout <<" 2 - TOP 10 \n";
		cout <<" 3 - Voltar \n";
		cin >> op;
		
		//variaveis do witch 
		bool voltar = true; // tentei cirar dentro do case 1, ja que é usada la, mas tava dando erro então fui pelo caminho facil hehe
		bool encontrado = true;		
		int resp;
		//variavel case 2
		int rankExcluir;
		bool defaultExcluir = true;
		bool voltar2;
		int escolhaExcluir;		
		switch(op){
			case 1 : 
					if(anime.empty()){
						cout << "Não tem anime cadastrado na Lista\n";
						systemPause();
						defaul = true;
					}
				do {
					defaul = false;
					systemClear();
					cout << "+-------------------+\n";
					cout << "|   Excluir Anime   |\n";
					cout << "+-------------------+\n";
					voltar = false;  //  so esta no case 1, voltar caso de fault seja ativado no case
					encontrado = false; // bolano para entrar o nome do anime e mandar a messagem de não encontrado
					cout << "Press ENTER para voltar\n";
					cout << "\n";
					
					cout << "\nNome do anime que deseja excluir \n";
					cin.ignore();
					getline(cin, nomeExcluir);
					
					if(nomeExcluir.empty()){  // para voltar ao menu
						cout <<" Voltando.. \n";
						return;
					}
				
					for (auto animes : anime){		// Encontrar o anime
						if (nomeExcluir == animes.nomeAnime){ //para encontrar o anime
							
							cout << "Deseja realmente excluir " << animes.nomeAnime << "? \n";
							cout << " 1 - Sim\n";
							cout << " 2 - Não\n";
							cin >> resp; //resposta para o switch
								
							if(resp == 's'){  // tratamento para o switch aceitar as respsota
								resp = 'S';
							}else if(resp == 'n'){
								resp = 'N';
							}
							
							switch(resp){
								case 1:
									    anime.erase(remove_if(anime.begin(), anime.end(), [&nomeExcluir](const animeLista& a) { 
									    
                						return a.nomeAnime == nomeExcluir;  // Comparando o nome do anime
                						
            							}), anime.end());
            							
            							cout << "Excluido com sucesso!\n";
									break;
								case 2:
									cout << "Ação cancelada\n";
									return;
									break;
								default:
									cout << "Essa opção não existe\n";
									systemPause();
									voltar = true;
									break;
							}	// fim do switch			
							encontrado = true;  // boleano avisando que foi encontrado no for o nome do anime 
						} //fim do IF verificar se o nome igual ao escolhido
					} // Fim do LOOP for para rodar todos os nomes de animes
					
					if (encontrado != true){
						cout << "\n";
						cout << "\nAnime não encontrado\n";
						cout <<" Voltando...\n";
						cout << "\n";
						systemPause();
						voltar = true;
					}
				}while(voltar);
				// CARA ISSO FICOU ENORME, EU TIVE QUE COMENTAR TUDO PQ ATÉ EU TAVA PERDIDO KKKKKKKKKKKKKKKKKKKK
				break;
			case 2:
/*
				if(top10.empty()){
					cout << "Não tem anime adicionado no TOP 10\n";
					cout << "\n";
					return;
				}
				*/
				do {
					voltar2 = false;
					defaultExcluir = false;
					cout <<"Qual o rank do anime que deseja excluir ? \n";
					cin >> rankExcluir;
					
					for(auto procura : top10){
						if (rankExcluir == procura.rank){
							encontrado = true;
							do{
								cout << "Deseja mesmo excluir o anime : " << procura.nomeTop << "? \n";
								cout << "1 - Sim \n";
								cout << "2 - Não \n";
								cin >> escolhaExcluir;
							
								switch(escolhaExcluir){
									case 1:
									    top10.erase(remove_if(top10.begin(), top10.end(), [&escolhaExcluir](const listaTop10& a) { 
									    
                						return a.rank == escolhaExcluir;  // Comparando o nome do anime
                						
            							}), top10.end());
										
										cout << "Anime excluido com sucesso!\n";
										cout << "\n";
										return;										
										break;
									case 2 :
										cout << "Ação cancelada\n";
										return;
										break;
									default :
										cout << "Não tem essa opção dog\n";
										systemPause();
										defaultExcluir = true;
										break;
								}
							}while(defaultExcluir);	
						}
					}		
				}while(voltar2);		
				break;
			case 3:
				return;
				break;
			default:
				cout <<"Essa opção não existe dog\n";
				systemPause();
				defaul = true;
				break;
		}
		if(encontrado != true){
			cout << "Esse rank não esta cadastrado\n";
			systemPause();
		}
	}while(defaul);

}
//**************************
// AUXILIARES PARA SYSTEM  |
//**************************
//***********************************************************************************************************
// Função para pausar o sistema
void systemPause() {
#ifdef _WIN32
    system("pause"); // Windows
#else
cout << "Pressione enter para continuar...";
cin.ignore(); // Linux 
#endif
}
//***********************************************************************************************************
// Função para limpar a tela
void systemClear() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux (ou outros sistemas Unix)
#endif
}
//***********************************************************************************************************
