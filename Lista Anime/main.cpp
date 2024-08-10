#include <iostream>
#include <locale.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void cadastrar (string anime[][100],int &quantCadastro);
void listarAnime(string anime[][100], int quantCadastro);

int main(int argc, char** argv) {
	setlocale(LC_ALL, "portuguese");
	
	int op, quantCadastro = 0;
	string anime[2][100];
	
	
	cout <<"Bem vindo a sua Lista de animes \n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	
	while(true){
		
		system("cls");
	
		cout << "|============================|\n";
		cout << "|                            |\n";
		cout << "|  1 - Cadastrar Anime       |\n";
		cout << "|  2 - Excluir Anime         |\n";
		cout << "|  3 - Listar Anime - Top 10 |\n";
		cout << "|  4 - Escrever Top 10       |\n";
		cout << "|  5 - Salvar                |\n";
		cout << "|  6 - Excluir               |\n";
		cout << "|                            |\n";
		cout << "|============================|\n";
		cin >> op;
	
		switch(op){
			case 1: 
				   cadastrar (anime,quantCadastro);
				   system("pause");
				break;
			case 2:
					
				break;
			case 3:
				listarAnime(anime,quantCadastro);
				system("pause");
				break;
			case 4: 
				break;
			case 5: 
				break;	
			case 6: 
				break;	
			default:
				cout << "Não existe esse número!\n";
				break;
		}
	}
	return 0;
}


void cadastrar (string anime[][100],int &quantCadastro){

	
	cout << "Quantos animes você vai cadastrar? \n";
	cin >> quantCadastro;
	cin.ignore();

	for (int i = 0; i < quantCadastro; i ++){
		cout << "Qual o nome do anime ?\n";
		getline(cin, anime[0][i]);
		cout << "\n";
		cout << "Qual o ultimo Ep que você assistiu ? \n";
		getline(cin, anime[1][i]);
		system ("cls");
	}	
		cout << "\n";
}


void listarAnime(string anime[][100], int quantCadastro){
	if (quantCadastro > 0){
		cout << "lista de animes cadastrados\n";
		cout << "\n";
		for(int i = 0; i < quantCadastro; i ++){
		cout << "Anime: " << anime[0][i] << "   |  " << " Último Ep: " << anime[1][i] << "\n";
		cout << "===============================\n";
		}
	}else if(quantCadastro == 0) {
			cout <<"\n";
			cout << "não tem nada cadastrado!\n";
			cout <<"\n";
		}
	
}
