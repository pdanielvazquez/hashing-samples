#include <iostream>
#include <vector>

class tablaHash {
	int size, inserts;
	float umbral;

		const int ELIMINADO = -1;

	std::vector <int> table;
	int hashModulo(const int clave) const {
		return clave % size;
	}

	void linear_probe(int indice, int clave) {
		int check = indice;
		bool flag = false;
		while (table[indice] != 0 && table[indice] != ELIMINADO) {			
			if (flag && indice == check) return;
			flag = true;
			indice++;
			if (indice >= size) {
				indice = 0;
			}
		}
		table[indice] = clave;
	}

	void redimensionar(const int clave) {
		int new_size = size * 2;
		std::vector <int> new_table(new_size);
		for (int nc : table) {
			int indice = hashModulo(nc);
			new_table[indice] = nc;
		}
		size = new_size;
	}
public:
	tablaHash(int s): size(s), table(s) {
		inserts = 0;
		umbral = 0.7;
	}
	float getLoad() const {
		return (float)inserts / (float)size;
	}
	void insertar(const int clave) {
		const int indice = hashModulo(clave);
		linear_probe(indice, clave);

		std::cout<<"Clave "<<clave<<" insertada en el indice "<<indice<<std::endl;
		inserts++;
		if ((float)inserts/(float)size >= umbral) {
			redimensionar(clave);
		}
	}
	bool buscar(const int clave) const {
	int indice = hashModulo(clave);
	int inicio = indice;
	bool flag = false;

	while (table[indice] != 0) {
		if (table[indice] == clave) {
			return true;
		}

		indice++;
		if (indice >= size) indice = 0;

		if (flag && indice == inicio) break;
		flag = true;
	}

	return false;
}

bool borrar(const int clave) {
	int indice = hashModulo(clave);
	int inicio = indice;
	bool flag = false;

	while (table[indice] != 0) {
		if (table[indice] == clave) {
			table[indice] = ELIMINADO;
			std::cout << "Clave " << clave << " eliminada\n";
			return true;
		}

		indice++;
		if (indice >= size) indice = 0;

		if (flag && indice == inicio) break;
		flag = true;
	}

	std::cout << "Clave " << clave << " no encontrada\n";
	return false;
}
	//metodo imprimir
	void imprimir(){
		for (int i = 0; i < size; i++) {
			std::cout<< i << " |: " << table[i] << std::endl;
		}
	}
};


int main(){
	//crear tabla hash
	tablaHash hash(5) ;
	//insertar elementos
	hash.insertar(10);

	hash.insertar(15);
	hash.insertar(20);
	hash.insertar(32);
	hash.insertar(7);

	hash.imprimir();


}