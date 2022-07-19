
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct nodoM{ 
		string informacion;   	//Para guardar el ID del mensaje
		int grado=2;		    //Para guardar el grado del vértice, parte con 2 ya que al comienzo estará conectado al usuario y a la fecha
		int usuario;			//Para guardar la posicion del vecinos que es usuario (arista)
		int fecha;			    //Para guardar la posición de la fecha en que se publico (arista)
		vector<int> vecinos;   //Para guardar las posiciones de las palabras que contiene
};

struct nodoUF{ 
		string informacion;   	//Para guardar el ID del usuario o fecha
		int grado=1;			//Para guardar el grado del vértice, parte en 1 ya que al comienzo estará conectado al mensaje al que pertenece
		vector<int> vecinos;	//Para guardar la posición de los mensajes que ha mandado (Lista de adyacencia)
};

struct nodoP{ 
		string informacion;   	//Para guardar la información correspondiente
		int grado=1;			//Para guardar el grado del vértice (mensajes en los que aparece), aparece al menos uno
		int frecuencia=1;		//Si es de tipo palabra guardamos la frecuencia. (cantidad total de veces que aparece)
		vector<int> vecinos;	//Para guardar la posición de los mensajes en que aparece
};

class Grafo{
		public:
				Grafo(); 																                        //Constructor
				~Grafo(); 																						//Destructor
				void insertar(string TweetID,string TweetDate, vector<string> TweetText, string UserID);		//Para insertar un nodo en el vector correspondiente					
				
				//Para hacer reportes sobre el grafo
				void numVertices(char tipo);																	//Para saber el numero total de vertices
				void numAristas();														   					    //Para saber el numero total de aristas
				void menorGrado();																				//Guarda el menor grado
				void mayorGrado();																				//Guarda el mayor grado

				//Funciones para consultar
				void fechaMasTweets();														//Para preguntar en que fecha se hizo la mayor cantidad de tweets
				void usuarioMasTweets();												    //Para preguntar que usuario fue el que hizo la mayor cantidad de tweets
				void usuariosPalabra(string palabra);										//Para desplegar todos los usuarios que han hecho un tweet con una palabra dada 
				void fechasPalabra(string palabra);										    
				void palabraMasLarga();

		private:
				vector<nodoM> mensajes;
				vector<nodoUF> usuarios;
				vector<nodoUF> fechas;
				vector<nodoP> palabras;

				unordered_map<string,int> uIndex;
				unordered_map<string,int> fIndex;
				unordered_map<string,int> pIndex;

				int maxgrad;															   //Guardará el mayor grado
				char maxgradtipo;														   //Guardará el tipo de dato que tiene el mayor grado
				int m;																	   //Cantidad aristas
				int cantMensajes;														   //Cantidad mensajes
				int cantUsuarios;														   //Cantidad usuarios
				int cantFechas;															   //Cantidad fechas
				int cantPalabras;                                                          //Cantidad palabras

				
};
