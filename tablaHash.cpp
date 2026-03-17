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
	public:
    //Agregamos el metodo de insercion
        void insertar(int clave){ //Recibimos nuestra clave a insertar
            int indice = hashModulo(clave); //Calculamos el indice con la funcion hash
            table[indice].push_back(clave); // Insertar en la lista en el indice calculado
        }

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

