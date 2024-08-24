#include <iostream>
#include <locale.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

void menu ();
void cadastrarAnime (vector<pair<string, string> >& animes); // ADICIONAR ANIMES 
void listarAnime (const vector<pair<string,string > >& animes, vector<pair<string, int>>& top10); // MOSTRAR OS ANIMES ADICIONADOS E O TOP 10 
void excluirAnime (vector<pair<string, string >>& animes, string& nomeRemover); // EXLUIR ANIME DA LISTA PRINCIPAL *ADICIONAR ANIMES*
void listartop10 (vector<pair<string, int>>& top10); // PARA CADASTRAR O TOP10
void exluirTop10 (vector<pair<string, int>>& top10, int& rank); // EXCLUIR ANIME DA LISTA "TOP10"
void salvarAnimes(vector<pair<string, string >>& animes); // Salvar Animes(salva em um arquivo txt);
void carregarAnimes(vector<pair<string, string>>& animes); // carregar anime


int main(int argc, char** argv) {
	setlocale(LC_ALL, "portuguese");
	string nomeRemover; // parametro para excluir do vetor anime
	vector<pair<string, string > > animes; // vetor anime
	vector<pair<string, int >> top10; // vetor top10
	bool encontrado = false;
	int op, numerorank, ope; // op = opção menu. numero rank = paramentro pra excluir algo do vetor top10 .   ope = opção dentro do case excluir  
	 
	 
	 carregarAnimes(animes);
	 
	while(true){
		
		system("cls");
		menu ();
		cin >> op;
		
	
		switch(op){
			
			case 1:
				system("cls");
				cadastrarAnime (animes);
				system("pause");
				break;
			case 2:
				listarAnime (animes, top10);
				system("pause");
				break;
			case 3:
				listartop10 (top10);
				system("pause");
				break;
			case 4:
				
				cout << "De qual você vai excluir? \n";
				cout << " 1 - Lista animes \n";
				cout << " 2 - Top 10 \n";
				cin >> ope;
				switch(ope){
					case 1:
						cout << "Qual o nome do anime que deseja excluir? \n";
						cin.ignore();
						getline(cin,nomeRemover);
						
						encontrado = false;
						
						for (auto& nomes : animes){
							if(nomeRemover == nomes.first){
								encontrado = true;
								cout << "Deseja mesmo remover: " << nomes.first << " ? (S/N)\n";
								char pergunta;
								cin >> pergunta;
								
								if(pergunta == 'S' || pergunta == 's'){
									excluirAnime (animes, nomeRemover);
									cout << "Anime excluído com sucesso!\n";
									break;
								}else {
									cout << "Ação cancelada\n";
									encontrado = true;  // Para evitar a mensagem de erro.
									break;
								}
							}
						}

						if(!encontrado){
							cout << "Anime não encontrado\n";
						}
						break;
					case 2:
						int rankExcluir;
						
						cout << "Em qual rank está o anime que você deseja excluir? ";
						cin >> rankExcluir;
						encontrado = false;
						
						for(auto& numero : top10){
							if(rankExcluir == numero.second){
								encontrado = true;
								cout << "Deseja mesmo apagar o anime: " << numero.first << "? (S/N)\n";
								char confirme;
								cin >> confirme;
								if(confirme == 'S' || confirme == 's'){
									exluirTop10 (top10, rankExcluir);
									cout << "Anime excluído com sucesso!\n";
								}else {
									cout << "Ação cancelada\n";
								}
								break;  // Sai do loop ao encontrar e confirmar exclusão
							}
						}

						if(!encontrado){
							cout << "Não foi possível encontrar esse rank\n";
						}
						break;
					default:
						cout << "Essa opção não existe\n";
						break;
				}
				system("pause");
				break;
			case 5:
				salvarAnimes(animes);
				system("pause");
				break;
			case 6:
				return 0;
				break;		
			default :
				cout << "Essa opção não é válida\n";
				break;		
		}
	}
		
	
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


void cadastrarAnime (vector<pair<string, string > >& animes){ 

	string nomeAnime, comentario;
	
	cin.ignore();
	cout << "Qual o nome do Anime?\n";
	getline(cin, nomeAnime);
	
	cout << "Escreva um comentário\n";
	getline(cin, comentario);  // getline para pegar palavras com distanciamento entre elas
	
	animes.push_back(make_pair(nomeAnime, comentario)); // para alocar os valores dentro do vetor 
	cout << "\n";
	cout << "Cadastro completo!\n";
	cout << "Quantidade: " << animes.size();
	cout << "\n";
}

void listarAnime (const vector<pair<string, string > >& animes, vector<pair<string, int>>& top10){
	int op;
	if(animes.empty() && top10.empty()){  // if para saber se o vetor está vazio ou não, se for true retorna o cout 
		cout << "Não tem nada cadastrado\n";
		return;
	}
	
	cout << "Deseja ver qual lista? \n";
	cout << "\n";
	cout << "1 - Listar todos \n";
	cout << "2 - Listar top 10 \n";
	cin >> op;
	
	switch(op){
		case 1:
				for(const auto& lista : animes){ // for para rodar todos os elementos do vetor
					cout << "\n";
					cout << "===============================================================================\n";
					cout << "ANIME: " << lista.first << " | " << "Comentário: " << lista.second << "\n";
					cout << "===============================================================================\n";
				}
			break;
		case 2: 
			for(const auto& lista2 : top10){
					cout << "\n";
					cout << "===============================================================================\n";
					cout << "ANIME: " << lista2.first << " | " << "RANK: " << lista2.second << "\n";
					cout << "===============================================================================\n";
				}
			break;
		default :
					cout << "Não existe essa opção\n";
			break;
	}
}
 
void listartop10 (vector<pair<string, int>>& top10){  // está listar mas é para escrever o top10
	string nome;
	int rank;
	
	cin.ignore();
	cout << "Digite o nome do anime:\n";
    getline(cin, nome);  

    cout << "\nEm qual rank vai ficar?\n";
    cin >> rank;

    top10.push_back(make_pair(nome, rank)); // alocando o valor das variáveis no vetor top10

    for (const auto& anime : top10) {  // rodando a lista de animes
        cout << "Nome do anime: " << anime.first << " | Rank: " << anime.second << "\n";
        break; 
    }
}

void excluirAnime (vector<pair<string, string >>& animes, string& nomeRemover){ // excluir da lista principal 

	auto lixeira = remove_if (animes.begin(), animes.end(), [&nomeRemover] (const pair<string,string>& p){
		return p.first == nomeRemover;
	});// soft função para alocar o valor selecionado em rank para a última posição do vetor 
	
	animes.erase(lixeira, animes.end()); // para excluir o último comando do vetor,

}

void exluirTop10 (vector<pair<string, int>>& top10, int& rank){  // excluir do top10
	
	 auto lixeira = remove_if(top10.begin(), top10.end(), [&rank](const pair<string,int>& r){ // soft função para alocar o valor selecionado em rank para a última posição do vetor 
		return r.second == rank;
	});
	
	top10.erase(lixeira, top10.end()); // para excluir o último comando do vetor,
}


void salvarAnimes(vector<pair<string, string >>& animes){
	
	ofstream arquivo("animes.txt");
	
	if(arquivo.is_open()){
		for(const auto& anime : animes){
			arquivo << anime.first << " | " << anime.second << "\n";
		}
		arquivo.close();
		cout << "Animes salvos com sucesso!\n";
	}else {
		cout << "Não foi possível salvar os animes. \n";
	}
	
}

void carregarAnimes(vector<pair<string, string>>& animes) {
    ifstream arquivo("animes.txt");
    if (arquivo.is_open()) {
        string linha;
        while (getline(arquivo, linha)) {
            stringstream ss(linha);
            string nomeAnime, comentario;
            if (getline(ss, nomeAnime, '|')) { // Modificado para separar por '|'
                getline(ss, comentario);
                animes.push_back(make_pair(nomeAnime, comentario));
            }
        }
        arquivo.close();
        cout << "Animes carregados com sucesso!\n";
    } else {
        cout << "Não foi possível abrir o arquivo de animes. Verifique se o arquivo existe.\n";
    }
}

