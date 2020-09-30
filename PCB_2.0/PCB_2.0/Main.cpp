//programa: administrador de tareas...modo consola.....
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> //libreriass.....
#include<Windows.h>
#include <string>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string>
#include<string.h>
#include<cstring>//libreriass.....
#include "CabeceraAuxiliar.h" //invocacion del archivo auxiliar hederrr.....para la llamada de funciones.....
#define NUMPROCESOS    10 // establece la cantidad maxima de procesos a desplegar e incializar....................!!

using namespace std;
//funciones prototipo
void linea();
void cargarprocesos();
void mostrarProcesos();
void actualizarProcesos();
void despliegueproceso(int id);
void modificacionestado(int idb);
void modificarProceso();
void modificacioncarga(int idb, int ran);
void infosystem();
void infoswinlong();
void infowininit();
void infocsrss();
void infossmss();
void infoShellhost();
void infoexplorer();
void infodllhost();
void infolsass();
void infoservices();
//varibles globales

//............................
struct procesos {//estructura de variables que almacenaran los datos..... 
	char pid[10];
	char nombre[15];
	double memoria;
	int cpu;
	int rafaga;
	int idestado;
	string estado = " ";
	string consumoe = " ";
	procesos* siguiente;
};

// incializazacion de la estructura datos predifinidoss......procesos que se visualizaran......!!
struct procesos procesosini[] = {
								 {"12256","System",8.61,13,1,0," "," "},
								 {"45625","winlong",8.61,2,1,0," "," "},
								 {"75363","wininit",8.61,6,1,0," "," "},
								 {"68943","csrss",8.61,6,1,0," "," "},
								 {"28933","Ssmss",8.61,6,1,0," "," "},
								 {"79943","Shellhost",8.61,6,1,0," "," "},
								 {"28963","explorer",8.61,6,1,0," "," "},
								 {"18953","dllhost",8.61,6,1,0," "," "},
								 {"68973","Lsass",8.61,6,1,0," "," "},
								 {"25963","services",8.61,6,1,0," "," "},
};

// funciones/procedemitos que  utiliza el programa.............................

void cargarprocesos() { // funcion que visualiza la carga de procesoss...a la aplicacion....
	//procesos *Procesocarga = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	//Procesocarga = procesosini; // carga los elementos inicializados a la estructura nodo creado......					
	system("color 0A");
	char tab = '\t';
	int porcentaje = 10;
	int idproc = 0;
	//"Bloqueado","Iniciando","Ejecuntado", "Terminado", "Prueba" ;
	cout << tab << tab << "  Cargando procesos................... ! espere....." << endl;
	cout << tab << tab << " _____________________________________________________" << endl;

	for (int i = 0; i < NUMPROCESOS; i++)
	{
		srand((unsigned)time(NULL));//obtener el numero aleatroio
		int ale = 1 + rand() % 4;
		modificacioncarga(idproc, ale);//carga el estado aleatroio
		idproc = idproc++;
		cout << tab << tab << tab << "Cargando ....... [" << porcentaje << "-% ]......." << endl;
		porcentaje = porcentaje + 10;
		Sleep(600);
	}

	cout << tab << tab << " ______________________________________________________" << endl;
	cout << tab << tab << "       Carga de procesos finalizado....!!!          " << endl;
	Sleep(600);
}

void cargarprocesosauto() { // funcion que visualiza la carga de procesoss...a la aplicacion....
	//procesos *Procesocarga = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	//Procesocarga = procesosini; // carga los elementos inicializados a la estructura nodo creado......					
	system("color 0A");
	char tab = '\t';
	int porcentaje = 10;
	int idproc = 0;
	cout << tab << tab << "  Reiniciando procesos........... ! espere....." << endl;
	for (int i = 0; i < NUMPROCESOS; i++)
	{
		srand((unsigned)time(NULL));//obtener el numero aleatroio
		int ale = 1 + rand() % 4;
		modificacioncarga(idproc, ale);//carga el estado aleatroio
		idproc = idproc++;
		cout << tab << tab << tab << "Cargando ....... [" << porcentaje << "-% ]......." << endl;
		porcentaje = porcentaje + 10;
		Sleep(100);
	}
	cout << tab << tab << " ______________________________________________________" << endl;
	cout << tab << tab << "       Carga de procesos finalizado....!!!          " << endl;
	Sleep(200);
}

void mostrarProcesos() {
	color(2);
	cout << endl;
	char tab = '\t'; //variable que permite la tabulacion en forma horizantal_ para tabular las columnas......
	int cantidadprocesos; // define la cantidad incial de procesos o registross.....
	struct procesos* Elemento; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Elemento = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	cout << ".........................................PROCESOS EN EJECUACION..........................................." << endl; //cabecera
	cout << " |         NOMBRE      |   PID      |       ESTADO    |   MEMORIA    |   CPU  | ENERGIA |   IDESTADO     |" << endl;// titulo de columnas...
	cout << ("=========================================================================================================") << endl; //separdor....
	for (cantidadprocesos = 0; cantidadprocesos < NUMPROCESOS; cantidadprocesos++) //bucle que dibuja los procesos encontrados......
	{
		
			color(Elemento->idestado); //le implementa el color deacuerdo a su estado.
			//dibuaja la tabulacion y extrae el dato correpondiente de la estructura.....
			cout << tab << "-> " << Elemento->nombre << tab << "-> " << Elemento->pid << tab << "->" << Elemento->estado << tab << "->"
				<< setprecision(2) << Elemento->memoria << "-MB." << tab << "->" << Elemento->cpu << "-%" << tab << "-> " << Elemento->consumoe << tab << "-> " << Elemento->idestado << tab << "-> " << Elemento->rafaga << endl;
		//pausa un lapso de tiempo de forma automatica.......
		Sleep(200);
		Elemento++; // incrementa el indice de la estructur para mostrar el seguiente.....
	}

}




void actualizarProcesos() {
	color(2);
	cout << endl;
	char tab = '\t'; //variable que permite la tabulacion en forma horizantal_ para tabular las columnas......
	int cantidadprocesos; // define la cantidad incial de procesos o registross.....
	struct procesos* Elemento; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Elemento = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	cout << ".........................................PROCESOS EN EJECUACION..........................................." << endl; //cabecera
	cout << " |         NOMBRE      |   PID      |       ESTADO    |   MEMORIA    |   CPU  | ENERGIA |   IDESTADO     |" << endl;// titulo de columnas...
	cout << ("=========================================================================================================") << endl; //separdor....
	for (cantidadprocesos = 0; cantidadprocesos < NUMPROCESOS; cantidadprocesos++) //bucle que dibuja los procesos encontrados......
	{
		if (Elemento->idestado == 5)
		{
			color(3);
			cout << tab << "-> " << Elemento->nombre<<tab<< "...Finalizado"<<endl;
		}
		else
		{
			color(Elemento->idestado); //le implementa el color deacuerdo a su estado.
			//dibuaja la tabulacion y extrae el dato correpondiente de la estructura.....
			cout << tab << "-> " << Elemento->nombre << tab << "-> " << Elemento->pid << tab << "->" << Elemento->estado << tab << "->"
			<< setprecision(2) << Elemento->memoria << "-MB." << tab << "->" << Elemento->cpu << "-%" << tab << "-> " << Elemento->consumoe << tab << "-> " << Elemento->idestado << tab << "-> " << Elemento->rafaga << endl;
		}
			
			//pausa un lapso de tiempo de forma automatica.......
			Sleep(200);	
		Elemento++; // incrementa el indice de la estructur para mostrar el seguiente.....
	}
		
}

void despliegueproceso(int id) {
	color(3);
	cout << endl;
	struct procesos* Procesodetalle; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Procesodetalle = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	char tab = '\t'; //variable que permite la tabulacion en forma horizantal_ para tabular las columnas......
	Sleep(500);
	cout << ".........................................DETALLE DE PROCESO [" << Procesodetalle[id].nombre << "]....................." << endl; //cabecera

	cout << " |         NOMBRE      |   PID      |       ESTADO    |   MEMORIA    |   CPU  | ENERGIA |     RAFAGA CPU     |" << endl;
	cout << ("=====================================================================================================================") << endl; //separdor....
	cout << tab << "-> " << Procesodetalle[id].nombre << tab << "-> " << Procesodetalle[id].pid << tab << "->" << Procesodetalle[id].estado << tab << "->"
		<< setprecision(2) << Procesodetalle[id].memoria << "-MB." << tab << "->" << Procesodetalle[id].cpu << "-%" << tab << "-> " << Procesodetalle[id].consumoe << tab << "-> " << Procesodetalle[id].rafaga << endl;

}



void modificacioncarga(int idb, int ran) {
	procesos* Procesobloq = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Procesobloq = procesosini;// carga los elementos inicializados a la estructura nodo creado......
	char tab = '\t';
	switch (ran)
	{

	case 1: Procesobloq[idb].memoria = (ran / 1.3); Procesobloq[idb].cpu = (ran * 15); Procesobloq[idb].rafaga = (ran * 2);
		Procesobloq[idb].idestado = 1; Procesobloq[idb].estado = "Nuevo....."; Procesobloq[idb].consumoe = "Alta"; break;
	case 2: Procesobloq[idb].memoria = (ran / 2.7); Procesobloq[idb].cpu = (ran * 18); Procesobloq[idb].rafaga = (ran * 2);
		Procesobloq[idb].idestado = 2; Procesobloq[idb].estado = "Listo....."; Procesobloq[idb].consumoe = "Alta"; break;
	case 3: Procesobloq[idb].memoria = (ran / 3.3); Procesobloq[idb].cpu = (ran * 6); Procesobloq[idb].rafaga = (ran * 2);
		Procesobloq[idb].idestado = 3; Procesobloq[idb].estado = "Bloqueado."; Procesobloq[idb].consumoe = "Baja"; break;
	case 4: Procesobloq[idb].memoria = (ran / 0.7); Procesobloq[idb].cpu = (ran * 20); Procesobloq[idb].rafaga = (ran * 2);
		Procesobloq[idb].idestado = 4; Procesobloq[idb].estado = "Ejecucion."; Procesobloq[idb].consumoe = "Alta"; break;
	case 5: Procesobloq[idb].memoria = (ran / 3.6); Procesobloq[idb].cpu = (ran * 3); Procesobloq[idb].rafaga = (ran * 2);
		Procesobloq[idb].idestado = 5; Procesobloq[idb].estado = "Terminado.."; Procesobloq[idb].consumoe = "Baja"; break;
	}
}
void actualizarEstados() {
	procesos* Procesobloq = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Procesobloq = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	int estadoactual;
	for (int row = 0; row < NUMPROCESOS; row++)
	{
		switch (Procesobloq->idestado)
		{
		case 1: Procesobloq->memoria = (25.2); Procesobloq->cpu = (45);
			Procesobloq->idestado = 2; Procesobloq->estado = "Listo....."; Procesobloq->consumoe = "Alta";
			break;
		case 2:	Procesobloq->memoria = (2.61); Procesobloq->cpu = (47);
			Procesobloq->idestado = 3; Procesobloq->estado = "Bloqueado."; Procesobloq->consumoe = "Alta";
			break;
		case 3: Procesobloq->memoria = (23.2); Procesobloq->cpu = (61);
			Procesobloq->idestado = 4; Procesobloq->estado = "Ejecucion."; Procesobloq->consumoe = "Alta";
			break;
		case 4: Procesobloq->memoria = (0.12); Procesobloq->cpu = (0);
			Procesobloq->idestado = 5; Procesobloq->estado = "Terminado.."; Procesobloq->consumoe = "Baja";
			break;
		case 5: Procesobloq->memoria = (0.12); Procesobloq->cpu = (0);
			Procesobloq->idestado = 5; Procesobloq->estado = "Terminado.."; Procesobloq->consumoe = "Baja";
			break;
		}

		Procesobloq++;
	}
	
}


void modificacionestado(int idb) {
	color(4);
	procesos* Procesobloq = new procesos; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Procesobloq = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	string estadoactual;
	Sleep(300);
	estadoactual = Procesobloq[idb].estado;
	char mcomando;
	if (estadoactual == "Terminado..")
	{
		cout << endl;
		char tab = '\t';

		cout << tab << "| opcion de cambio: [n]'Nuevo'|" << endl;
		cout << ("[inserte-comando-modificacion] ==>"); mcomando = getchar();
		do
		{
			if (mcomando == 'n')
			{
				Procesobloq[idb].memoria = (25.2); Procesobloq[idb].cpu = (45); Procesobloq[idb].idestado=1;
				Procesobloq[idb].estado = "Nuevo....."; Procesobloq[idb].consumoe = "Alta";
				Sleep(100);
				cout << "El procesos cambio de estado a [Nuevo] ";
				cout << endl;
			}
			else
			{
				cout << "el proceso solo tiene la opcion [Nuevo]" << endl << endl;
				return;
			}
		} while (mcomando != 'n');
	}

	if (estadoactual == "Nuevo.....")
	{
		cout << endl;
		char tab = '\t';

		cout << tab << "| opcion de cambio: [l]'Listo' |" << endl;
		cout << ("[inserte-comando-modificacion] ==>"); mcomando = getchar();
		do
		{
			if (mcomando == 'l')
			{
				Procesobloq[idb].memoria = (2.61); Procesobloq[idb].cpu = (47);Procesobloq[idb].idestado =2;
				Procesobloq[idb].estado = "Listo....."; Procesobloq[idb].consumoe = "Alta";
				Sleep(100);
				cout << "El proceso cambio de estado a [Listo]";
				cout << endl;
			}
			else
			{
				cout << "el proceso solo tiene la opcion [Listo]" << endl << endl;
				return;
			}
		} while (mcomando != 'l');
	}

	if (estadoactual == "Listo.....")
	{
		cout << endl;
		char tab = '\t';

		cout << tab << "| opcion de cambio: [e]'Ejecutar'|" << endl;
		cout << ("[inserte-comando-modificacion] ==>"); mcomando = getchar();
		do
		{
			if (mcomando == 'e')
			{
				Procesobloq[idb].memoria = (23.2); Procesobloq[idb].cpu = (61); Procesobloq[idb].idestado = 4;
				Procesobloq[idb].estado = "Ejecucion."; Procesobloq[idb].consumoe = "Alta";
				Sleep(100);
				cout << "El proceso cambio de estado a: [Ejecucion]";
				cout << endl;
				
			}
			else
			{
				cout << "el proceso solo tiene la opcion [Ejecutado]" << endl << endl;
				return;
			}
		} while (mcomando != 'e');
	}

	if (estadoactual == "Ejecucion.")
	{
		cout << endl;
		char tab = '\t';
		cout << tab << "| opcion de cambio: [t]'Terminar' | [b]'Bloquear' |" << endl;
		cout << ("[inserte-comando-modificacion] ==>"); mcomando = getchar();
		do
		{
			if (mcomando == 't')
			{
				Procesobloq[idb].memoria = (0.12); Procesobloq[idb].cpu = (0); Procesobloq[idb].idestado = 5;
				Procesobloq[idb].estado = "Terminado.."; Procesobloq[idb].consumoe = "Baja";
				Sleep(100);
				cout << "El proceso cambio de estado a [Terminado] ";
				cout << endl;
				
			}

			else if (mcomando == 'b')
			{
				Procesobloq[idb].memoria = (0.9); Procesobloq[idb].cpu = (11); Procesobloq[idb].idestado = 3;
				Procesobloq[idb].estado = "Bloqueado."; Procesobloq[idb].consumoe = "Baja";
				Sleep(100);
				cout << "El proceso cambio de estado a: [Bloqueado] ";
				cout << endl;
				
			}

			else
			{
				cout << "el proceso solo tiene la opcion [Terminado o Bloqueado]" << endl << endl;
				return;
			}
		} while (mcomando == ('t' || 'b'));
	}

	if (estadoactual == "Bloqueado.")
	{
		cout << endl;
		char tab = '\t';
		cout << tab << "| opcion de cambio: [l]'Listo' |" << endl;
		cout << ("[inserte-comando-modificacion]==>"); mcomando = getchar();

		do
		{
			if (mcomando == 'l')
			{
				Procesobloq[idb].memoria = (3.57); Procesobloq[idb].cpu = (25); Procesobloq[idb].idestado = 2;
				Procesobloq[idb].estado = "Listo....."; Procesobloq[idb].consumoe = "Alta";
				Sleep(100);
				cout << "El proceso cambio de estado a [Listo] ";
				cout << endl;
				
			}
			else
			{
				cout << "el proceso solo tiene la opcion [Listo]" << endl << endl;
				return;
			}
		} while (mcomando != 'l');
	}

}

//------------------------------------------------------
void modificarProceso() { // funcion que dibuja una tabla con los procesos en ejecucion y con los datos de la cabecera...
	struct procesos* Elemento; // define la estructura y crea una estructa de tipo nodo para carga los registros....
	Elemento = procesosini; // carga los elementos inicializados a la estructura nodo creado......
	bool repetirdetalle = true;
	char busquedaproceso[15];
	int c = 2;
	int idproceso = 1;
	cout << "[Ingrese proceso]=> ";
	cin.getline(busquedaproceso, 15);
	do
	{
		switch (idproceso)
		{
		case 1: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infosystem();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;

		case 2: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infoswinlong();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 3: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infowininit();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 4: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infocsrss();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 5: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infossmss();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 6: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infoShellhost();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 7: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infoexplorer();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;
			}; break;
		case 8: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infodllhost();
				despliegueproceso(idp);
				modificacionestado(idp);
				cout << endl;
				
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			}; break;
		case 9: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infolsass();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			};  break;
		case 10: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				infoservices();
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				idproceso = idproceso++;

			};  break;
		case 11: c = strcmp(busquedaproceso, Elemento[idproceso - 1].nombre);
			if (c == 0)
			{
				int idp = idproceso - 1;
				despliegueproceso(idp);
				modificacionestado(idp);
				repetirdetalle = false;
			}
			else
			{
				cout << "El proceso no Existe" << endl;
				repetirdetalle = false;
			}; break;

		}

	} while (repetirdetalle);

}


// funcion que opera los modulos del programa.....conforme comandos......

void modulos()
{
	bool repetirmodulos = true; // variable que valida el bucle do-while......
	int idbfor = 0;
	char comandomodulo[15]; // variable que almacena los caracteres ingresados....(comando-palabra)....
	//int mod = 0; //variable que almacena la cantidad de caracteres  ingresados ...........
	int v1, v2, v3, v4, v5,v6,v7,v8; // variable que almacena el resultado de la comparacion de comandos.....
	bool repetirprocesos=true;
	do //incio del bucle......
	{
		linea();
		//dibujo del cursor... pide el comando.......
		cin.getline(comandomodulo, 15); //....guarda los caracters ingresados...a la varible...
		int mod = (strlen(comandomodulo)); // se crea una variable, que almacena un numero de caracteres ingresados....como comando....
		switch (mod) //condicinal que se ejecuta conforme la cantidad de caracteres ingresados......
		{
		case 1:		v1 = strcmp(comandomodulo, "h"); // modulo de ayuda:: muestra los comandos establecidos  se ejecuta con 'h'
			if (v1 == 0) //comprueba que el caracter se correcto......
			{
				help(); // ejecuta la funcion de modulo de informacion o ayuda....
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl; // mensaje de error... caracter invalido...
			};  break;
		case 2:		v2 = strcmp(comandomodulo, "cl"); // funcio que limpia la pantalla....
			if (v2 == 0)
			{
				cout << "En desarrollo...";
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}; break;
		case 3:		v8 = strcmp(comandomodulo, "cls"); // funcio que limpia la pantalla....
			if (v8 == 0)
			{
				system("cls");
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}; break;

		case 5:		v3 = strcmp(comandomodulo, "salir");// funcio  que cierra la aplicacion......
			if (v3 == 0)
			{
				repetirmodulos = false;
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			};  break;
		case 7:		v4 = strcmp(comandomodulo, "detalle");// modulo de procesos.....
			if (v4 == 0) {

				cout << "En desarrollo";
				
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}
			break;
		case 8:		v4 = strcmp(comandomodulo, "procesos");// modulo de procesos.....
			if (v4 == 0) {
				system("cls");
				mostrarProcesos();
				for (int f = 0; f < 4; f++)
				{
					actualizarEstados();
					actualizarProcesos();
					Sleep(300);
				}
				cout << "  --- Todos los procesos han finalizado...!!"; fechahora();
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}
			break;
		case 9:		v5 = strcmp(comandomodulo, "modificar");// modulo modificar.....
			if (v5 == 0)
			{
				modificarProceso();
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}; break;
		case 10: v6 = strcmp(comandomodulo, "actualizar");// modulo actualizar.....
			if (v6 == 0) {
				
				cout << "modulo en desarrollo.......!! ";
				
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}
			break;
		case 11:     v7 = strcmp(comandomodulo, "restablecer");// modulo de detalles......
			if (v7 == 0)
			{
				cargarprocesosauto();
				cout << endl;
				
			}
			else
			{
				cout << "Error en sintaxis de comando....!!" << endl;
			}; break;

		}

	} while (repetirmodulos);


}

//funcion que maneja la estructura principal del programa...........iniciliaza y reliza iteraciones......

void estructuraprincipal() {
	char tab = '\t';
	bool repetirproceso = true; //valida bucle do -while
	char comandoincio[15]; //almacena los caracters ingresados.......
	int comandingresado = 1; // valor de validacion....comand1
	int comandosalida = 1; // valor de validadion _comand2
	do
	{
		system("cls"); //limpia pantalla-.....
		system("color 03"); //establece color de letra......
		logoinicio();
		cout << tab << tab << ".................[B -I - E - N - V - E - N - I - D - O ]................." << endl;
		cout << tab << tab << "--------Inserte comando de incio.... /o [salir]:cerrar aplicacion--------" << endl; //mensaje de inicio.....
		cout << endl;
		linea(); //pide comando.......
		cin.getline(comandoincio, 15);//guarda el comando ingresado.....
		comandosalida = strcmp(comandoincio, "salir"); // compara los caracteres ingresado...
		comandingresado = strcmp(comandoincio, "pcb");// compara los caracteres ingresado...

		if (comandosalida == 0) // valida comando de cierre de procesos.....
		{
			repetirproceso = false; // rompe ciclo bucle...
			cout << "  salio del programa...!!" << endl; // mensaje de cierre de programa.....
			pausar();
		}
		if (comandingresado == 0) // valida ingreso a la estructura principal del programa......
		{

			cargarprocesos(); //incia carga de procesoos.... llama a la funcio cargar procesos...
			Sleep(500); // tiempo para ejecutar programa principal.....
			system("color f"); // establece color de texto del programa principal...
			system("cls"); //limpia la consola.....
			help(); //llama al menu principal desde auxiliardibujos-auxiliar hdeder
			modulos();//invoca a la funcion modulos....modulos del programa......
			repetirproceso = false; // rompe el bucle  do -while....
			cout << "Salio del programa administrador v1-2020" << endl;//confirmaciondel cierre del programa.......
		}

	} while (repetirproceso);

}

//funcion principal de la aplicacion.........
int main()
{
	estructuraprincipal(); //invoca a la estructura principal de la aplicacion......
}

