#include <iostream>
#include <list>
#include <vector>

using namespace std;

class tablaHash{
	private:
		static const vector<int>& seriePrimos() {
			static const vector<int> primos = {
				5, 11, 23, 47, 97, 197, 397, 797, 1597, 3203, 6421
			};
			return primos;
		}
		int size;
		int inserts;
		int indicePrimoActual;
		float umbral;
		vector <list<int>> table;
		int hashModulo(int clave) const{
			return clave % size;
		}
		int buscarIndicePrimo(int s) const {
			const vector<int>& primos = seriePrimos();
			for (int i = 0; i < primos.size(); i++) {
				if (primos[i] >= s) {
					return i;
				}
			}
			return primos.size() - 1;
		}
		void rehashing() {
			const vector<int>& primos = seriePrimos();
			if (indicePrimoActual + 1 < primos.size()) {
				indicePrimoActual++;
			}
			int nuevoTam = primos[indicePrimoActual];
			vector<list<int>> tablaAnterior = table;

			size = nuevoTam;
			table = vector<list<int>>(size);

			for (const list<int>& bucket : tablaAnterior) {
				for (int clave : bucket) {
					int indice = hashModulo(clave);
					table[indice].push_back(clave);
				}
			}
		}
	public:
	        tablaHash(int s)
			: inserts(0), umbral(0.75) {
			indicePrimoActual = buscarIndicePrimo(s);
			size = seriePrimos()[indicePrimoActual];
			table = vector<list<int>>(size);
		} //Constructor para inicializar el tamaño y la tabla hash
	    //Agregamos el metodo de insercion
	        void insertar(int clave){ //Recibimos nuestra clave a insertar
	            int indice = hashModulo(clave); //Calculamos el indice con la funcion hash
	            table[indice].push_back(clave);
	            inserts++;
	            //imprimir el indice calculado y la clave insertada
	            cout<<"Clave "<<clave<<" insertada en el indice "<<indice<<endl;
	            if ((float)inserts / size >= umbral) {
	            	rehashing();
	            }
	        }
	        //metodo imprimir
        void imprimir(){
            for (int i = 0; i < size; i++)
            {
                cout<<i<<": " << endl;
                for (int num:table[i])
                {
                    cout<< num<<"-> ";
                }

                cout<<"null"<<endl;
                
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
