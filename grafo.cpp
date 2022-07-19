#include "grafo.h"
#include <iostream>
using namespace std;


//Constructor
Grafo::Grafo(){
	m=0;
	cantMensajes=0;
	cantUsuarios=0;
	cantFechas=0;
	cantPalabras=0;
	maxgrad=0;
}

//Destructor
Grafo::~Grafo(){
	mensajes.clear();
	usuarios.clear();
	fechas.clear();
	palabras.clear();

	mIndex.clear();
	uIndex.clear();
	fIndex.clear();
	pIndex.clear();
}


//Funcion para insertar datos
void Grafo::insertar(string TweetID,string TweetDate, vector<string>  TweetText, string UserID){

	//Primero creamos los nodos que guardaremos, comenzamos por el nodo de mensaje ya que este siempre debe crearse. 
	nodoM mensajeN;
	this->cantMensajes++;					 //Aumentamos la cantidad de mensajes
	mensajeN.informacion=TweetID;    		 //Guardamos el TweetID en la información  
	mensajes.push_back(mensajeN);  			 //Introducimos el nodo en mensajes en la posicion cantMensajes-1

	this -> m+=2;


	//-------------USUARIOS--------------//
	//Primero debemos preguntar si ya existía el nodo asociado a este usuario, para eso buscamos en el mapa, si la clave asociada es distinta de 0 es porque ya existía
	if (uIndex[UserID]==0){
		this->cantUsuarios++; 			    		

		//Creamos el nodo y le agregamos la información correspondiente
		nodoUF usuarioN;         
	    usuarioN.informacion=UserID;
	    usuarioN.vecinos.push_back(cantMensajes-1); 

	    //Ahora lo añadimos al vector de usuarios en la posición cantUsuarios-1
	    usuarios.push_back(usuarioN);
	    uIndex[UserID]=cantUsuarios;

	    mensajes[cantMensajes-1].usuario=cantUsuarios-1; //El indice real en el vector de usuarios es cantUsuarios-1
	}
	else{

		int pos=uIndex[UserID]-1;
		usuarios[pos].vecinos.push_back(cantMensajes-1);
		mensajes[cantMensajes-1].usuario=pos;
		//Aumentamos su grado
		usuarios[pos].grado++;
	}


	//-------------FECHAS--------------//
	//Asimismo hay que buscar primero si ya hemos guardado la fecha como nodo
	if (fIndex[TweetDate]==0){
		this->cantFechas++; 			 //Este es el indice+1 que tendra en el vector de fechas


		//Si no existe creamos el nodo, agregamos la información y las aristas
		nodoUF fechaN;         
	    fechaN.informacion=TweetDate;
	    fechaN.vecinos.push_back(cantMensajes-1); 

	    fechas.push_back(fechaN);
	    fIndex[TweetDate]=cantFechas;

	    mensajes[cantMensajes-1].fecha=cantFechas-1;
	}
	else{

		int pos=fIndex[TweetDate]-1;		
		fechas[pos].vecinos.push_back(cantMensajes-1);
		mensajes[cantMensajes-1].fecha=pos;
		fechas[pos].grado++;
	}




	//-------------PALABRAS--------------//
	//Hay que hacer lo mismo para cada palabra
	for(int i=0; i<TweetText.size(); i++){

		if (pIndex[TweetText[i]]==0){
			this->cantPalabras++;

			nodoP palabraN;
			palabraN.informacion=TweetText[i];
			palabraN.vecinos.push_back(cantMensajes-1);
			palabraN.grado++;

			palabras.push_back(palabraN);
			pIndex[TweetText[i]]=cantPalabras;

			mensajes[cantMensajes-1].vecinos.push_back(cantPalabras-1);
			mensajes[cantMensajes-1].grado++;
			this -> m++;
		}
		else{

			int pos=pIndex[TweetText[i]]-1;
			palabras[pos].vecinos.push_back(cantMensajes-1);  //Agregamos como vecino de la palabra al mensaje

			//Para poder agregar al mensaje como vecino de la palabra tengo que ver si es que ya la había agregado antes (podría estar repetida en el mismo tweet)
			int flag=0;
			for(int j=0; j<i; j++){ 
				int posP = mensajes[cantMensajes-1].vecinos[j];
				if(posP==pos){   //Si la encontre entonces solo le aumento la frecuencia y me salgo del for
					palabras[pos].frecuencia++;
					flag==1;
					break;
				}
			}
			if(flag==0){ 																//Si no la encontró  en el for anterior entonces la agrego sin problemas
				mensajes[cantMensajes-1].vecinos.push_back(pIndex[TweetText[i]]-1);
				mensajes[cantMensajes-1].grado++;
				palabras[pIndex[TweetText[i]]-1].grado++;
				palabras[pIndex[TweetText[i]]-1].frecuencia++;
				this -> m++;
			}	
		}
		if(palabras[pIndex[TweetText[i]]-1].grado > maxgrad){
		 	maxgrad = palabras[pIndex[TweetText[i]]-1].grado ;  //Y preguntamos si es mayor que el grado mayor
		 	maxgradtipo='P';
		}
	}

	//ACTUALIZAR EL GRADO MAYOR

	if(fechas[cantFechas-1].grado > maxgrad){
		maxgrad = fechas[cantFechas-1].grado;
		maxgradtipo='P';
	}
	if(mensajes[cantMensajes-1].grado > maxgrad){
		maxgrad = mensajes[cantMensajes-1].grado; 
		maxgradtipo='M' ;
	}
	if(usuarios[cantUsuarios-1].grado > maxgrad){
		maxgrad = usuarios[cantUsuarios-1].grado;
		maxgradtipo='U';
	}

}



//Funciones para entregar estadisticas sobre el grafo

void Grafo::numVertices(char tipo){
	if(tipo=='M') cout<< "La cantidad de tweets registrados es: "<<cantMensajes<<endl;
	else if(tipo=='U') cout<<"La cantidad de usuarios registrados es: "<< cantUsuarios <<endl;
	else if(tipo=='F') cout<< "La cantidad de fechas registradas es: "<<cantFechas<< endl;
	else cout<<"La cantidad de palabras distintas registradas es: "<<cantPalabras<<endl;
}

void Grafo::numAristas(){
	cout<<"El numero de aristas es: "<< m<<endl;
}


void Grafo::menorGrado(){ 
	string tipo;
	int min=1;	
	for(int i=0; i<cantFechas;i++){
		if(fechas[i].grado <= min){
			min=fechas[i].grado;
			tipo= "Fecha";
		}
	}
	for(int i=0; i<cantPalabras;i++){
		if(palabras[i].grado <= min){
			min=palabras[i].grado;
			tipo= "Palabra";
		} 
	}
	for(int i=0; i<cantMensajes;i++){
		if(mensajes[i].grado <= min){
			min=mensajes[i].grado; 
			tipo="Mensaje";
		}
	}
	for(int i=0; i<cantUsuarios;i++){
		if(usuarios[i].grado <= min){
			min=usuarios[i].grado;
			tipo ="Usuario";
		} 
	}

	cout<<"El menor grado del grafo es: "<<min<<" y el vertice es del tipo " << tipo <<endl;	

}

void Grafo::mayorGrado(){
	string tipo;
	if(maxgradtipo=='P') tipo="Palabra";
	else if(maxgradtipo=='M') tipo = "Mensaje";
	else if(maxgradtipo=='U') tipo="Usuario";
	else tipo= "Fecha";
	cout<<"El mayor grado en el grafo es: "<<maxgrad<<" y el vertice es del tipo " << tipo<<endl;
}

void Grafo::palabraMasLarga(){
	int max=0;
    for(int i=0; i<cantPalabras; i++){
        if(palabras[i].informacion.length() > palabras[max].informacion.length()) max=i; 
    }

    cout<<"La palabra mas larga es: "<<palabras[max].informacion<<" y tiene largo "<<palabras[max].informacion.length()<<endl;

}


//Funciones para hacer consultas

void Grafo::fechaMasTweets(){
	int pos=0;
	for(int i=0; i<cantFechas;i++){
		if(fechas[i].grado > fechas[pos].grado) pos = i; 
	}
	cout<<fechas[pos].informacion<<endl;
	cout<<"Su cantidad de tweets es  "<< fechas[pos].grado<<endl;

}

void Grafo::usuarioMasTweets(){
	int pos=0;
	for(int i=0; i<cantUsuarios;i++){
		if(usuarios[i].grado > usuarios[pos].grado) pos = i; 
	}
	cout<<usuarios[pos].informacion<<endl;
	cout<<"Su cantidad de tweets es  "<< usuarios[pos].grado<<endl;
}

void Grafo::usuariosPalabra(string palabra){
	if(pIndex[palabra]==0){
		cout<<"La palabra no se encuentra en nuestros registros, intente con otra."<<endl;
		return;
	}
	
	vector<string> usuariosP;

	int posP=pIndex[palabra]-1; 							//Posicion en la que esta la palabra en el vector palabra
	for(int i=0; i< palabras[posP].vecinos.size(); i++){ 
		int posM = palabras[posP].vecinos[i]; 				//Posicion de cada mensaje en el vector mensaje
		int posU = mensajes[posM].usuario; 					//Posición del usuario que publicó el mensaje

		//Chequeamos si el mismo usuario no había publicado ya la misma palabra
		if(usuariosP.size()!=0){
			int flag=0;
			for(int j=0; j < usuariosP.size(); j++){
				if(usuarios[posU].informacion.compare(usuariosP[j])==0){
					flag=1;
					break;
				}
			}
			if(flag==0) usuariosP.push_back(usuarios[posU].informacion);
		}
		else usuariosP.push_back(usuarios[posU].informacion);
	}

	for(int j=0; j< usuariosP.size(); j++){
		cout<<usuariosP[j]<<endl;
	}

	cout<<"Y la cantidad de usuarios que la twitteo es: "<<usuariosP.size()<<endl;

}

void Grafo::fechasPalabra(string palabra){
	if(pIndex[palabra]==0){
		cout<<"La palabra no se encuentra en nuestros registros, intente con otra."<<endl;
		return;
	}


	vector<string> fechasP;

	int posP=pIndex[palabra]-1; 						   //Posicion en la que esta la palabra en el vector palabra
	for(int i=0; i< palabras[posP].vecinos.size(); i++){
		int posM = palabras[posP].vecinos[i]; 			   //Posicion de cada mensaje en el vector mensaje
		int posF = mensajes[posM].fecha;				   //Posición del usuario que publicó el mensaje

		if(fechasP.size()!=0){
			int flag=0;
			for(int j=0; j< fechasP.size(); j++){
				if(fechas[posF].informacion.compare(fechasP[j])==0){
					flag=1;
					break;
				}
			}
			if (flag==0) fechasP.push_back(fechas[posF].informacion);
		}
		else fechasP.push_back(fechas[posF].informacion);
	}

	for(int j=0; j< fechasP.size(); j++){
		cout<<fechasP[j]<<endl;
	}
	cout<<"Y la cantidad de fechas en las que se twitteo es: "<<fechasP.size()<<endl;
}

