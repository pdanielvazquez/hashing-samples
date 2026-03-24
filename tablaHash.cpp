#include <iostream>
#include <list>
#include <vector>

using namespace std;

class tablaHash{
	private:
		int size;
		vector <list<int>> table;
		int hashModulo(int clave){
			return clave % size;
		}
        int hashConteo(int clave){
            return clave / size;
        }
        int numElementos(int indice){
            return table[indice].size();
        }
        float umbralCarga(){
            int totalElementos = 0;
            for (int i = 0; i < size; i++)
            {
                totalElementos += numElementos(i);
            }
            return (float)totalElementos / size;
        }
        // Definir umbral de carga de 75% para redimensionar la tabla hash
        void redimensionar(){
            if (umbralCarga() > 0.75) {
                int nuevoSize = size * 2;
                vector<list<int>> nuevaTable(nuevoSize);
                for (int i = 0; i < size; i++) {
                    for (int clave : table[i]) {
                        int nuevoIndice = clave % nuevoSize;
                        nuevaTable[nuevoIndice].push_back(clave);
                    }
                }
                table = std::move(nuevaTable);
                size = nuevoSize;
                cout << "Tabla hash redimensionada a tamaño: " << size << endl;
            }
        }
	public:
        tablaHash(int s): size(s), table(s){} //Constructor para inicializar el tamaño y la tabla hash
    //Agregamos el metodo de insercion
        void insertar(int clave){ //Recibimos nuestra clave a insertar
            int indice = hashModulo(clave); //Calculamos el indice con la funcion hash
            table[indice].push_back(clave);
            //imprimir el indice calculado y la clave insertada
            cout<<"Clave "<<clave<<" insertada en el indice "<<indice<<endl;
            redimensionar(); // Verificar si es necesario redimensionar la tabla hash

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