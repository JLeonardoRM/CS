#include<iostream>
#include<fstream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
using namespace std;

struct persona {
	
	char nombre[25];
	char apellido[25];
	char numeroC[11];
	char correo[50];
}contacto;


void nuevoContacto();
void mostrar();
void busqueda();
void eliminar();

int main()
{
	
	int a;
	do
	{
			system("cls");
			cout << "    Menu:\n\n" << endl;
			cout << "    1) Nuevo Contacto" << endl;
			cout << "    2) Contactos" << endl;
			cout << "    3) Editar Contacto" << endl;
			cout << "    4) Eliminar Contacto" << endl;
			cout << "    5) Salir" << endl;
			cout << "\n\nSelecione el numero de la opcion deseada: ";
			cin>>a;

		switch (a)
		{
		case 1:nuevoContacto();
			break;
		case 2:mostrar();
			break;
		case 3:busqueda();
			break;
		case 4:eliminar();
			break;

		}
	} while (a != 5);
}

void mostrar()
{
	int i=0;
	system("cls");
	cout << "\n";
	ifstream agenda;
	agenda.open("agenda.txt", ios::out | ios::in);
	cout << "Contactos" << endl;
	cout << "_______________________" << endl;
	agenda >> contacto.nombre;
	while (!agenda.eof()) 
	{
		agenda >> contacto.apellido;
		agenda >> contacto.numeroC;
		agenda >> contacto.correo;
		cout << "Nombre: " << contacto.nombre;
		cout << " " << contacto.apellido<<endl;
		cout << "Numero: " << contacto.numeroC << endl;
		cout << "Correo: " << contacto.correo << endl;
		agenda >> contacto.nombre;
		cout << "_______________________" << endl;
	}
	agenda.close();
	system("pause");

}

void busqueda()
{
	int i = 0, elije, z = 0,log,x,y;
	char auxNombre[25], auxN[25];
	while (auxNombre[24])
	{
		auxNombre[i] = '\0';
		i++;
	}
	i = 0;
	while (auxN[24])
	{
		auxN[i] = '\0';
		i++;
	}
	i = 0;
	system("cls");
	cout << "\n";
	ofstream aux;
	ifstream agenda;
	aux.open("AUXagenda.txt", ios::out);
	agenda.open("agenda.txt", ios::in );
	
	cout << "\n Ingrese nombre que desea buscar: " << endl;
	cin >> auxNombre;
	agenda >> contacto.nombre;
	log = strlen(contacto.nombre);
	while (contacto.nombre[i])
	{
		auxN[i] = contacto.nombre[i];
		i++;
	}
	i = 0;
	cout << "_______________________" << endl;
	
	while (!agenda.eof())
	{
		agenda >> contacto.apellido;
		agenda >> contacto.numeroC;
		agenda >> contacto.correo;
		while (contacto.nombre[i])
		{

			if (auxNombre[i] == auxN[i]) 
			{
				z++;
			}
			i++;
		}
		if (z == log)
		{
			do {
				system("cls");
				cout << "Nombre: " << contacto.nombre;
				cout << " " << contacto.apellido << endl;
				cout << "Numero: " << contacto.numeroC << endl;
				cout << "Correo: " << contacto.correo << endl;
				cout << "_______________________" << endl;
				cout << "\n\n¿Desea editar el numero o correo de este contacto?" << endl;
				cout << "  1)si" << endl;
				cout << "  2)no" << endl;
				cin >> elije;
				if (elije == 1) {
					do {
						cout << "\nIngrese Nuevo Numero: ";
						x = 0;
						z = 0;

						cin >> contacto.numeroC;

						while (contacto.numeroC[x])
						{
							if (!isdigit(contacto.numeroC[x]))
							{

								z = 1;
							}
							x++;
						}
						

						log = strlen(contacto.numeroC);
						if (log < 8 || log > 11)
						{
							cout << "error longitud" << endl;
							z = z + 1;
						}

					} while (z != 0);
					do
					{
						
						i = 0; y = 0;
						cout << "\nIngrese Nuevo Correo: ";
						cin >> contacto.correo;
						log = strlen(contacto.correo);
						while (contacto.correo[i])
						{
							if ((contacto.correo[i]) == ('@')) {
								y = 1;
							}
							i++;

						}
						if (y != 0)
						{
							i = 0;
							_strrev(contacto.correo);


							while (contacto.correo[i])
							{
								if ((contacto.correo[i]) == ('m'))
								{
									i++;
									if ((contacto.correo[i]) == ('o'))
									{
										i++;
										if ((contacto.correo[i]) == ('c'))
										{
											i++;
											if ((contacto.correo[i]) == ('.'))
											{
												y = 3;
											}
											i = log;
										}
										i = log;
									}
									i = log;
								}
								else {
									cout << "Error, Debe contener '@' y ''.com''\n";
									Sleep(2000);
								}
								i = log;

							}
							_strrev(contacto.correo);
						}
						else {
							cout << "Error, Debe contener '@' y ''.com''\n";
							Sleep(2000);
						}
					} while (y != 3);
				}

			} while (elije != 2);
		}
		i = 0;
		aux<< contacto.nombre << " " << contacto.apellido << " "<<contacto.numeroC << " " << contacto.correo << endl;
		while (auxN[i])
		{
			auxN[i] = '\0';
			i++;
		}
		i = 0, z = 0;
		agenda >> contacto.nombre;
		log = strlen(contacto.nombre);
		while (contacto.nombre[i])
	{
		auxN[i] = contacto.nombre[i];
		i++;
	}
	i = 0;
		
		
	}

	agenda.close();
	aux.close();
	remove("agenda.txt");
	rename("Auxagenda.txt", "agenda.txt");
	cout << "Contactos Guardados.\n" << endl;
	system("pause");

}

void eliminar()
{
	int i = 0, elije, z = 0, log, x, y;
	char auxNombre[25], auxN[25];
	while (auxNombre[24])
	{
		auxNombre[i] = '\0';
		i++;
	}
	i = 0;
	while (auxN[24])
	{
		auxN[i] = '\0';
		i++;
	}
	i = 0;
	system("cls");
	cout << "\n";
	ofstream aux;
	ifstream agenda;
	aux.open("AUXagenda.txt", ios::out);
	agenda.open("agenda.txt", ios::in);

	cout << "\n Ingrese nombre que desea buscar: " << endl;
	cin >> auxNombre;
	agenda >> contacto.nombre;
	log = strlen(contacto.nombre);
	while (contacto.nombre[i])
	{
		auxN[i] = contacto.nombre[i];
		i++;
	}
	i = 0;
	cout << "_______________________" << endl;

	while (!agenda.eof())
	{
		agenda >> contacto.apellido;
		agenda >> contacto.numeroC;
		agenda >> contacto.correo;
		while (contacto.nombre[i])
		{

			if (auxNombre[i] == auxN[i])
			{
				z++;
			}
			i++;
		}
		if (z == log)
		{
			
				system("cls");
				cout << "Nombre: " << contacto.nombre;
				cout << " " << contacto.apellido << endl;
				cout << "Numero: " << contacto.numeroC << endl;
				cout << "Correo: " << contacto.correo << endl;
				cout << "_______________________" << endl;
				cout << "\n\n¿Desea ELIMINAR este contacto?" << endl;
				cout << "  1)si" << endl;
				cout << "  2)no" << endl;
				cin >> elije;
				

			
		}
		i = 0;
		if (elije != 1) 
		{
			aux << contacto.nombre << " " << contacto.apellido << " " << contacto.numeroC << " " << contacto.correo << endl;
		}
	
		while (auxN[i])
		{
			auxN[i] = '\0';
			i++;
		}
		i = 0, z = 0;
		agenda >> contacto.nombre;
		log = strlen(contacto.nombre);
		while (contacto.nombre[i])
		{
			auxN[i] = contacto.nombre[i];
			i++;
		}
		i = 0;


	}

	agenda.close();
	aux.close();
	remove("agenda.txt");
	rename("Auxagenda.txt", "agenda.txt");
	system("cls");
	cout << "Eliminado.\n" << endl;
	system("pause");

}

void nuevoContacto()
{
	gets_s(contacto.nombre);
	int x=0, i=0, z=0,log=0,auxi=0,y=0;
	int dec=0,space=0;
	string telefono;
	system("cls");
	ofstream agenda;
	ifstream consulta;

	agenda.open("agenda.txt", ios::out | ios::app);
	consulta.open("agenda.txt", ios::in);
	if (agenda.is_open() && consulta.is_open())
	{
		do {


			do {
				system("cls");
				x = 0, i = 0, auxi = 0, z = 0;
				space = 0;
				if (dec != 0)
				{
					x = 1;
					dec = 0;
				}
				do 
				{
					log = 0;
					system("cls");
					cout << "\nIngrese Nombre: ";
					fflush(stdin);
					gets_s(contacto.nombre);
					log = strlen(contacto.nombre);
					if (!isalpha(contacto.nombre[i])) 
					{
						log = 0;
					}
				} while (log == 0);
				
				while (contacto.nombre[i])
				{

					if (!isalpha(contacto.nombre[i]))
					{
						if (!iswspace(contacto.nombre[i]))
						{
						
							auxi = i;
							i = log - 1;
							x = 1;
						}
						else
						{
							while (contacto.nombre[i])
							{
								if (!isalpha(contacto.nombre[i]))
								{
									if (!iswspace(contacto.nombre[i]))
									{
										auxi = i;
										i = log;
										x = 1;
									}
									else
									{
										contacto.apellido[z] = contacto.nombre[i];
										z++;
										i++;
										space++;
										if (space > 1) 
										{
											auxi = i;
											i = log ;
											x = 1;
										}
									}
								}
								else
								{
									contacto.apellido[z] = contacto.nombre[i];
									z++;
									i++;
								}

							}
							i--;
						}
					}
					else {
						contacto.nombre[i] = contacto.nombre[i];
					}

					i++;

				}
				if (z == 0) {
					contacto.nombre[i]=' ';
					contacto.nombre[i+1] = '.';
					contacto.nombre[i + 2] = '\0';
					z++;
				}
			} while (x != 0);


			do {
				system("cls");
				cout << "\nIngrese Numero: ";
				x = 0;
				z = 0;

				cin >> contacto.numeroC;

				while (contacto.numeroC[x])
				{
					if (!isdigit(contacto.numeroC[x]))
					{

						z = 1;
					}
					x++;
				}
				system("cls");

				log = strlen(contacto.numeroC);
				if (log < 8 || log > 11)
				{
					cout << "error longitud" << endl;
					z = z + 1;
				}

			} while (z != 0);//validacion numero

			do
			{
				system("cls");
				i = 0; y = 0;
				cout << "\nIngrese Correo: ";
				cin >> contacto.correo;
				log = strlen(contacto.correo);
				while (contacto.correo[i])
				{
					if ((contacto.correo[i]) == ('@')) {
						y = 1;
					}
					i++;

				}
				if (y != 0)
				{
					i = 0;
					_strrev(contacto.correo);


					while (contacto.correo[i])
					{
						if ((contacto.correo[i]) == ('m'))
						{
							i++;
							if ((contacto.correo[i]) == ('o'))
							{
								i++;
								if ((contacto.correo[i]) == ('c'))
								{
									i++;
									if ((contacto.correo[i]) == ('.'))
									{
										y = 3;
									}
									i = log;
								}
								i = log;
							}
							i = log;
						}
						else {
							cout << "Error, Debe contener '@' y ''.com''";
							Sleep(2000);
						}
						i = log;

					}
					_strrev(contacto.correo);
				}
				else {
					cout << "Error, Debe contener '@' y ''.com''";
					Sleep(2000);
				}
			} while (y != 3);
			agenda << contacto.nombre << " " << contacto.numeroC << " " << contacto.correo << endl;
			cout << "\n\n desea ingresar otro contacto a la agenda? ";
			cout << "\n\n 1=si, 2=no \n" << endl;

			cin >> dec;
	    } while (dec == 1);
	}
	else
	{
		cout << "Error al abrir el archivo";
		system("pause");	
		
	}
	agenda.close();
	
}


