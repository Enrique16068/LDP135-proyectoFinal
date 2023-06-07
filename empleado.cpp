#include <iostream>
#include <conio.h>

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


