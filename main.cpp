#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Clase base Empleado
class Empleado {
protected:
    string nombre;
    string apellido;
    string direccion;
    string fechaNacimiento;
    string sexo;

public:
    Empleado(string& nombre,string& apellido, string& direccion, string& fechaNacimiento, string& sexo)
        : nombre(nombre),apellido(apellido), direccion(direccion), fechaNacimiento(fechaNacimiento), sexo(sexo) {}

    virtual ~Empleado() {}

    virtual double calcularSalario()= 0;

    string& getNombre() {
        return nombre;
    }
    string& getApellido() {
        return apellido;
    }

    string& getDireccion(){
        return direccion;
    }

    string& getFechaNacimiento(){
        return fechaNacimiento;
    }

    string& getSexo(){
        return sexo;
    }
};

// Clase Gerente
class Gerente : public Empleado {
private:
    double sueldo;

public:
    Gerente(string& nombre, string& apellido, string& direccion, string& fechaNacimiento, string& sexo)
        : Empleado(nombre,apellido, direccion, fechaNacimiento, sexo), sueldo(5000) {}

    double calcularSalario() override {
        double renta=0,descuentos=0;
        
        descuentos=(sueldo * 0.075) - (sueldo * 0.0775);
        renta=(sueldo-2038.10)*0.30;
        return sueldo - descuentos-renta;
    }
};

// Clase Técnico
class Tecnico : public Empleado {
private:
    double sueldo;

public:
    Tecnico(string& nombre, string& apellido, string& direccion,  string& fechaNacimiento,  string& sexo)
        : Empleado(nombre,apellido, direccion, fechaNacimiento, sexo), sueldo(350) {}

    double calcularSalario()  override {
        double descuentos=0;
        descuentos=(sueldo * 0.075) - (sueldo * 0.0775);
        
        return sueldo-descuentos;
    }
};

// Clase Jefe de Área
class JefeArea : public Empleado {
private:
    double sueldo;

public:
    JefeArea( string& nombre, string& apellido, string& direccion,  string& fechaNacimiento,  string& sexo)
        : Empleado(nombre,apellido, direccion, fechaNacimiento, sexo), sueldo(1500) {}

    double calcularSalario()  override {
        double renta=0,descuentos=0;
        
        descuentos=(sueldo * 0.075) - (sueldo * 0.0775);
        renta=(sueldo-2038.10)*0.20;
        return sueldo - descuentos-renta;
    }
};

// Clase Supervisor
class Supervisor : public Empleado {
private:
    double sueldo;

public:
    Supervisor( string& nombre, string& apellido, string& direccion,  string& fechaNacimiento,  string& sexo)
        : Empleado(nombre,apellido, direccion, fechaNacimiento, sexo), sueldo(750) {}

    double calcularSalario()  override {
        double renta=0,descuentos=0;
        
        descuentos=(sueldo * 0.075) - (sueldo * 0.0775);
        renta=(sueldo-2038.10)*0.10;
        return sueldo - descuentos-renta;
    }
};

int main() {
    
    vector<Empleado*> empleados;

    ifstream archivo("empleados.txt");  // Abrir el archivo en modo lectura
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    string linea;
    while (getline(archivo, linea)) {
        // Procesar cada línea del archivo

        // Separar los campos de la línea por comas
        size_t pos = 0;
        string campo;
        string campos[6];  // Array para almacenar los campos de cada registro

        int i = 0;
        while ((pos = linea.find(',')) != string::npos) {
            campo = linea.substr(0, pos);  // Extraer el campo hasta la coma
            campos[i++] = campo;
            linea.erase(0, pos + 2);  // Eliminar el campo y la coma de la línea
        }
        campos[i] = linea;  // El último campo no tiene una coma al final

        // Acceder a cada campo según su posición
        string nombre = campos[0];
        string apellido=campos[1];
        string direccion = campos[2];
        string fechaNacimiento = campos[3];
        string sexo = campos[4];
        string rol = campos[5];

         Empleado* empleado = nullptr;
        if (rol == "Gerente") {
            empleado = new Gerente(nombre,apellido, direccion, fechaNacimiento, sexo);
        } else if (rol == "Tecnico") {
            empleado = new Tecnico(nombre, apellido, direccion, fechaNacimiento, sexo);
        } else if (rol == "JefeArea") {
            empleado = new JefeArea(nombre, apellido,direccion, fechaNacimiento, sexo);
        } else if (rol == "Supervisor") {
            empleado = new Supervisor(nombre,apellido, direccion, fechaNacimiento, sexo);
        }

        if (empleado != nullptr) {
            empleados.push_back(empleado);
        }
    }

    archivo.close();  // Cerrar el archivo después de terminar la lectura

    // Resto del código (menú y operaciones con empleados)...
    int opcion;
    do {
        
        cout << "=== Menu ===" << endl;
        cout << "1. Ordenar empleados alfabeticamente por apellido" << endl;
        cout << "2. Ordenar empleados por salario (de menor a mayor)" << endl;
        cout << "3. Ordenar empleados por salario (de mayor a menor)" << endl;
        cout << "4. Mostrar cantidad de empleados segun sus roles" << endl;
        cout << "5. Agregar nuevo empleado" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
            case 1: {
                cout << "Empleados ordenados alfabeticamente por apellido:" << endl;
                sort(empleados.begin(), empleados.end(), []( Empleado* a,  Empleado* b) {
                    return a->getApellido() < b->getApellido();
                });
                int contador=1;
                for ( auto& empleado : empleados) {
                    
                    cout << contador++<<". " <<empleado->getNombre()<< " "<<empleado->getApellido()<< endl;
                }

                break;
            }
            case 2: {
                cout << "Empleados ordenados por salario (de menor a mayor):" << endl;
                sort(empleados.begin(), empleados.end(), []( Empleado* a,  Empleado* b) {
                    return a->calcularSalario() < b->calcularSalario();
                });
                int contador=1;
                for ( auto& empleado : empleados) {
                    cout <<contador++<<". " <<empleado->getNombre()<<" "<<empleado->getApellido() << " - Salario: $" << empleado->calcularSalario() << endl;
                }

                break;
            }
            case 3: {
                cout << "Empleados ordenados por salario (de mayor a menor):" << endl;
                sort(empleados.begin(), empleados.end(), []( Empleado* a,  Empleado* b) {
                    return a->calcularSalario() > b->calcularSalario();
                });
                int contador=1;
                for ( auto& empleado : empleados) {
                    cout << contador++<<". " <<empleado->getNombre()<<" "<<empleado->getApellido() << " - Salario: $" << empleado->calcularSalario() << endl;
                }

                break;
            }
            case 4: {
                int cantidadGerentes = 0;
                int cantidadTecnicos = 0;
                int cantidadJefesArea = 0;
                int cantidadSupervisores = 0;

                for ( auto& empleado : empleados) {
                    if (dynamic_cast<Gerente*>(empleado) != nullptr) {
                        cantidadGerentes++;
                    } else if (dynamic_cast<Tecnico*>(empleado) != nullptr) {
                        cantidadTecnicos++;
                    } else if (dynamic_cast<JefeArea*>(empleado) != nullptr) {
                        cantidadJefesArea++;
                    } else if (dynamic_cast<Supervisor*>(empleado) != nullptr) {
                        cantidadSupervisores++;
                    }
                }

                cout << "Cantidad de empleados segun sus roles:" << endl;
                cout << "Gerentes: " << cantidadGerentes << endl;
                cout << "Tecnicos: " << cantidadTecnicos << endl;
                cout << "Jefes de Area: " << cantidadJefesArea << endl;
                cout << "Supervisores: " << cantidadSupervisores << endl;

                break;
            }
            case 5: {
                cout << "Ingrese el nombre del nuevo empleado: ";
                string nombre;
                cin.ignore();
                getline(cin, nombre);

                cout << "Ingrese el apellido del nuevo empleado: ";
                string apellido;
                cin.ignore();
                getline(cin, apellido);

                cout << "Ingrese la direccion del nuevo empleado: ";
                string direccion;
                getline(cin, direccion);

                cout << "Ingrese la fecha de nacimiento del nuevo empleado: ";
                string fechaNacimiento;
                getline(cin, fechaNacimiento);

                cout << "Ingrese el sexo del nuevo empleado: ";
                string sexo;
                getline(cin, sexo);

                cout << "Seleccione el rol del nuevo empleado:" << endl;
                cout << "1. Gerente" << endl;
                cout << "2. Tecnico" << endl;
                cout << "3. Jefe de Area" << endl;
                cout << "4. Supervisor" << endl;
                cout << "Ingrese una opcion: ";
                int rol;
                cin >> rol;

                Empleado* nuevoEmpleado = nullptr;
                switch (rol) {
                    case 1:
                        nuevoEmpleado = new Gerente(nombre, apellido, direccion, fechaNacimiento, sexo);
                        break;
                    case 2:
                        nuevoEmpleado = new Tecnico(nombre, apellido, direccion, fechaNacimiento, sexo);
                        break;
                    case 3:
                        nuevoEmpleado = new JefeArea(nombre, apellido, direccion, fechaNacimiento, sexo);
                        break;
                    case 4:
                        nuevoEmpleado = new Supervisor(nombre, apellido, direccion, fechaNacimiento, sexo);
                        break;
                    default:
                        cout << "Opcion invalida. No se creo ningún empleado." << endl;
                        break;
                }

                if (nuevoEmpleado != nullptr) {
                    empleados.push_back(nuevoEmpleado);
                    cout << "Nuevo empleado agregado con exito." <<endl;
                }

                break;
            }
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 6);

    // Liberar memoria de los empleados
    for (const auto& empleado : empleados) {
        delete empleado;
    }
    system("PAUSE");
    return 0;
}
