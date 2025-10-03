


#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;

class Pokemon {

	
private:

	struct tEntrenador {
		unordered_set<string> listaPokemons;
		map<int, string> nivelesPokemons;
		unordered_map<string, std::pair<int, unordered_set<string>::iterator>> t_pokemon;
	};


	unordered_map<string,tEntrenador> entrenadores;



public:

	void capturar_pokemon(string e, string p, int n) {
		if (!entrenadores.count(e)) {
			entrenadores[e] = { unordered_set<string>(),map<int, string>() };
		}

		if (entrenadores[e].listaPokemons.count(p)) throw invalid_argument("Pokemon repetido");
		if (entrenadores[e].nivelesPokemons.count(n)) throw invalid_argument("Nivel repetido");

		entrenadores[e].listaPokemons.insert(p);
		entrenadores[e].nivelesPokemons.insert({ n,p });
	}

	pair<string, int>vencer_pokemon(string e,int n) {
		if (!entrenadores.count(e)) throw invalid_argument("Entrenador no existente");
		if (entrenadores[e].listaPokemons.empty()) throw invalid_argument("No tiene pokemons");

		auto iterator = entrenadores[e].nivelesPokemons.end();

		if (iterator->first < n) throw invalid_argument("El pokemon no puede ser vencido");
		
		return { iterator->second ,iterator->first };
	}


	int dia_de_liberacion(string p) {
		int numPokemons = 0;
		for (auto it = entrenadores.begin(); it != entrenadores.end();++it) {
			if (entrenadores[it->first].listaPokemons.count(p)) {
				numPokemons++;

				it->second.listaPokemons.erase(p);
				it->second.nivelesPokemons.erase(it->second.)
			}
		}
	}


};