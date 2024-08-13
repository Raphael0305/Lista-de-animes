#include <iostream>
#include <locale.h>
#include <vector>
#include <algorithm>
using namespace std;

void menu ();
void cadastrarAnime (vector<pair<string, string> >& animes);
void listarAnime (const vector<pair<string,string > >& animes, vector<pair<string, int>>& top10);
void excluirAnime (vector<pair<string, string > >& animes, string& nomeRemover);
void listartop10 (vector<pair<string, int>>& top10);

int main(int argc, char** argv) {
	setlocale(LC_ALL, "portuguese");
	string nomeRemover;
	vector<pair<string, string > > animes;
	vector<pair<string, int >> top10;
	int op;
	while(true){
		
		system("cls");
		menu ();
		cin >> op;
		
	
		switch(op){
			
			case 1:
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
				cout << "Qual o nome do anime que deseja remover ? \n";
				cin >> nomeRemover;
				excluirAnime (animes,nomeRemover);
				system("pause");
				break;
			case 5:
				system("pause");
				break;
			case 6:
				break;				
		}
	}
		
	
	return 0;
}

void menu (){
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
	int quantCadastrada = 0;
	
	cin.ignore();
	cout << "Qual o nome do Anime?\n";
	getline(cin, nomeAnime);
	
	cout << "Escreva um comentário\n";
	getline(cin, comentario);
	
	animes.push_back(make_pair(nomeAnime, comentario));
	cout << "\n";
	quantCadastrada ++;
	cout << "Cadastro completo !\n";
	cout << "\n";
}

void listarAnime (const vector<pair<string, string > >& animes, vector<pair<string, int>>& top10){
	int op;
	if(animes.empty() && top10.empty()){
		cout << "não tem nada cadastrado\n";
		return;
	}
	
	cout << "Deseja ver qual lista? \n";
	cout << "\n";
	cout << "1 - Listar todos \n";
	cout << "2 listar top 10 \n";
	cin >> op;
	
	switch(op){
		case 1:
				for(const auto& lista : animes){
					cout << "\n";
					cout << "===============================================================================\n";
					cout << "anime: " << lista.first << "| " << "Comentario : " << lista.second << "\n";
					cout << "===============================================================================\n";
				}
			break;
		case 2: 
			for(const auto& lista2 : top10){
					cout << "\n";
					cout << "===============================================================================\n";
					cout << "anime: " << lista2.first << "| " << "Comentario : " << lista2.second << "\n";
					cout << "===============================================================================\n";
				}
			break;
		default :
					cout << "não existe essa opção";
			break;
	}
}

void listartop10 (vector<pair<string, int>>& top10){
	
	string nome;
	int rank;
	
	system("cls");
	cout <<"Digite o nome do anime\n";
	cin >> nome;
	cout << "\n";
	cout << "Qual posição você vai querer colocalo\n";
	cin >> rank;
	
	top10.push_back(make_pair(nome,rank));
	
	for(const auto anime : top10){
		cout << "nome do anime " << anime.first << " |  rank " << anime.second << "\n";
		break;
	}


}

void excluirAnime (vector<pair<string, string >>& animes,string& nomeRemover){
	auto lixeira = remove_if (animes.begin(), animes.end(), [&nomeRemover] (const pair<string,string>& p){
		return p.first == nomeRemover;
	});
	
	animes.erase(lixeira, animes.end());

}
