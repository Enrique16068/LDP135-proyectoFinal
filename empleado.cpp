#include <iostream>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

//PROYECTO FINAL DE LÓGICA DE PROGRAMACIÓN 

//Clases
class Empleado{ 
    private: //Atributos
        string nombre;
        string apellido;
        int dui;
    public: //Metodo
        float ISSS = 7.5;
        float AFP = 7.75;
        float renta;
        Empleado(string,string, int); //Constructor
        virtual void prestacionesLaborales(); //Polimorfismo para ISSS, AFP y renta
};
class Gerente : public Empleado {
    private: 
        double sueldo;
    public:
        Gerente(string, string, int, double);
        void prestacionesLaborales();
};
class jefeDeArea : public Empleado {
    private:
        double sueldo;
    public:
        jefeDeArea(string, string, int, double);
        void prestacionesLaborales();
};
class supervisor : public Empleado{
    private:
        double sueldo;
    public:
        supervisor(string, string, int, double);
        void prestacionesLaborales();
};
class tecnico : public Empleado{
    private:
        double sueldo;
    public:
        tecnico(string, string, int, double);
        void prestacionesLaborales();
};
//Constructores
Empleado :: Empleado(string _nombre , string _apellido, int _dui){
    nombre = _nombre;
    apellido = _apellido;
    dui = _dui;
}
Gerente :: Gerente(string _nombre, string _apellido, int _dui, double sueldo1) : Empleado(_nombre,_apellido,_dui){
    sueldo = sueldo1;
}
jefeDeArea :: jefeDeArea(string _nombre, string _apellido, int _dui, double sueldo2) : Empleado(_nombre,_apellido,_dui){
    sueldo = sueldo2;
}
supervisor :: supervisor(string _nombre, string _apellido, int _dui, double sueldo3) : Empleado(_nombre,_apellido,_dui){
    sueldo = sueldo3;
}
tecnico :: tecnico(string _nombre, string _apellido, int _dui, double sueldo4) : Empleado(_nombre,_apellido,_dui){
    sueldo = sueldo4;
}
//Generando el polimorfismo
void Empleado :: prestacionesLaborales(){
    float sueldo, exceso, renta;
    //Renta
    if (sueldo <= 472.00){  //Tramo I 
        renta = 0;
    }
    else if (sueldo > 472.01 && sueldo <= 895.24){ //Tramo II
        exceso = sueldo - 472;
        renta = exceso * 0.10 + 17.67;
    }
    else if (sueldo > 895.25 && sueldo <= 2038.10){ //Tramo III
        exceso = sueldo - 895.24;
        renta = exceso * 0.20 + 60;
    }
    else if (sueldo >= 2038.11){     //Tramo IV
        exceso = sueldo - 2038.10;
        renta = exceso * 0.30 + 288.57;
    }
}
void Gerente :: prestacionesLaborales(){
    sueldo = 5000.00;
    Empleado :: prestacionesLaborales();
}
void jefeDeArea :: prestacionesLaborales(){
    sueldo = 1500.00;
    Empleado :: prestacionesLaborales();
}
void supervisor :: prestacionesLaborales(){
    sueldo = 750.00;
    Empleado :: prestacionesLaborales();
}
void tecnico ::prestacionesLaborales(){
    sueldo = 350.00;
    Empleado :: prestacionesLaborales();
}
//Creando Archivo donde se guardarán los empleados
void listaDeEmpleados(){
    ofstream listaDeEmpleados_Archivo;
    string agregandoEmpleado;

    listaDeEmpleados_Archivo.open("Lista de Empleados y sus Cargos.txt",ios::out);//Abriendo el archivo

    if (listaDeEmpleados_Archivo.fail()){
        cout<<"¡Vaya! Al parecer ha ocurrido un problema. No posees la Planilla. Ponte en contacto con alguien de soporte (Miembro del grupo)";
    }
    listaDeEmpleados_Archivo << " .EMPRESA 'PLOMERIA HERMANOS MARIO'. "<<endl;
    listaDeEmpleados_Archivo << "           .EMPLEADOS: "<<endl;
    listaDeEmpleados_Archivo << " .GERENTE: "<<endl;
    listaDeEmpleados_Archivo <<" 1. Roman Edgardo Mendoza Arias. "<<endl;
    listaDeEmpleados_Archivo <<" 2. Gustavo Enrique Menéndez Galdámez. "<<endl;
    listaDeEmpleados_Archivo <<" 3. Emerson Steven Bueno Salvin. "<<endl;
    listaDeEmpleados_Archivo <<" 4. Yonathan Eliú Juárez Mangandi.  "<<endl;
    listaDeEmpleados_Archivo <<" 5. Agustín Pio Barrios. "<<endl;
    listaDeEmpleados_Archivo << " .JEFE DE ÁREA: "<<endl;
    listaDeEmpleados_Archivo <<" 1. Gustavo Adrian Cerati. "<<endl;
    listaDeEmpleados_Archivo <<" 2. Carlos Alberto Garcia Moreno. "<<endl;
    listaDeEmpleados_Archivo << " .SUPERVISOR: "<<endl;
    listaDeEmpleados_Archivo <<" 1. Rubén Albarrán. "<<endl;
    listaDeEmpleados_Archivo <<" 2. Juan Valdivia. "<<endl;
    listaDeEmpleados_Archivo <<" 3. Andrés Segovia. "<<endl;
    listaDeEmpleados_Archivo << " .TÉCNICO: "<<endl;
    listaDeEmpleados_Archivo <<" 1. Ana María Orozco. "<<endl;
    listaDeEmpleados_Archivo <<" 2. Jorge Enrique Abello. "<<endl;
    listaDeEmpleados_Archivo <<" 3. Natalia Ramírez. "<<endl;
    listaDeEmpleados_Archivo <<" 4. Lorna Cepeda.  "<<endl;
    listaDeEmpleados_Archivo <<" 5. Luis Mesa. "<<endl;
    listaDeEmpleados_Archivo <<" 6. Estefanía Gómez. "<<endl;
    listaDeEmpleados_Archivo <<" 7. Julián Arango. "<<endl;
    listaDeEmpleados_Archivo <<" 8. Mario Duarte. "<<endl;
    listaDeEmpleados_Archivo <<" 9. Dora Cadavid.  "<<endl;
    listaDeEmpleados_Archivo <<" 10. Miguel Varoni. "<<endl;
    listaDeEmpleados_Archivo <<" 11. Sandra Reyes. "<<endl;
    listaDeEmpleados_Archivo <<" 12. Javier Gómez . "<<endl;
    listaDeEmpleados_Archivo <<" 13. Marcela Mar. "<<endl;
    listaDeEmpleados_Archivo <<" 14. Rodolfo Paez.  "<<endl;
    listaDeEmpleados_Archivo <<" 15. Johanna Martinez. "<<endl;

    listaDeEmpleados_Archivo.close();//Cerrado el archivo
}
//Agregando Nuevo empleado
void agregarEmpleadoDespuesDePalabraClave() {
    // Paso 1: Abrir el archivo y leer todas las líneas
    ifstream listaDeEmpleados("Lista de Empleados y sus Cargos.txt");
    vector<string> lineas;
    string linea;
    while (getline(listaDeEmpleados, linea)) {
        lineas.push_back(linea);
    }
    listaDeEmpleados.close();

    // Paso 2: Pedir al usuario que ingrese el nuevo Empleado a agregar
    string nuevoEmpleado;
    cout << " .Ingrese el nuevo Empleado que desea agregar: "<<endl;
    getline(cin, nuevoEmpleado);

    // Paso 3: Crear un vector de palabras clave y buscar una línea que contenga una de ellas
    vector<string> palabrasClave = {" .GERENTE: ", " .JEFE DE ÁREA: ", " .SUPERVISOR: ", " .TÉCNICO: "};
    int indicePalabraClave = -1;
    for (int i = 0; i < lineas.size(); i++) {
        for (const string& palabra : palabrasClave) {
            if (lineas[i].find(palabra) != string::npos) {
                // Se ha encontrado una línea que contiene una palabra clave
                // La nueva línea se agregará después de esta línea
                indicePalabraClave = i;
                break;
            }
        }
        if (indicePalabraClave != -1) {
            // Se encontró una palabra clave, salir del bucle externo
            break;
        }
    }
    if (indicePalabraClave == -1) {
        // Si no se encuentra ninguna palabra clave, salir de la función
        cout << "No se encontraron palabras clave en el archivo" << endl;
        return;
    }
    // Paso 4: Agregar la nueva línea después de la línea que contiene "Gerente"
    lineas.insert(lineas.begin() + indicePalabraClave + 1, nuevoEmpleado);

    // Paso 5: Escribir el nuevo contenido en el archivo
    ofstream archivoSalida("Lista de Empleados y sus Cargos.txt");
    for (const string& linea : lineas) {
        archivoSalida << linea << endl;
    }
    archivoSalida.close();
}
//Mostrar en orden Alfabetico los empleados
void mostrarInformacionOrdenada() {
    // Paso 1: Abrir el archivo y leer todas las líneas
    ifstream listaDeEmpleados("Lista de Empleados y sus Cargos.txt");
    vector<string> lineas;
    string linea;
    while (getline(listaDeEmpleados, linea)) {
        lineas.push_back(linea);
    }
    listaDeEmpleados.close();

    // Paso 2: Ordenar las líneas alfabéticamente
    sort(lineas.begin(), lineas.end());

    // Paso 3: Mostrar todas las líneas ordenadas alfabéticamente en la consola
    for (const string& linea : lineas) {
        cout << linea << endl;
    }
}


