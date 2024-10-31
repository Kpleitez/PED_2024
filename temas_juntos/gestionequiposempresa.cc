#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <set>

struct Miembro {
    std::string nombre;
    std::string apellido;
    int edad;
    std::string rol;
    Miembro* siguiente;
};

struct Tarea {
    std::string descripcion;
    int prioridad;
    std::string estado; // "pendiente", "en progreso", "completada"
    Tarea* siguiente;
};

struct Equipo {
    std::string nombre;
    std::string proyecto;
    std::string fecha_creacion;
    int max_miembros;
    int total_miembros;
    Miembro* cabeza;
    std::queue<Tarea> cola_tareas;
    Tarea* tareas_completadas; // Lista enlazada de tareas completadas
    std::stack<Miembro> historial_cambios;
    std::set<std::string> miembros_unicos;
};

std::queue<Equipo> equipos;

// Función para crear un equipo
void crearEquipo() {
    Equipo nuevo_equipo;
    std::cout << "Ingrese el nombre del equipo: ";
    std::cin.ignore();
    std::getline(std::cin, nuevo_equipo.nombre);
    std::cout << "Ingrese el nombre del proyecto: ";
    std::getline(std::cin, nuevo_equipo.proyecto);
    std::cout << "Ingrese la fecha de creación del equipo (DD/MM/AAAA): ";
    std::getline(std::cin, nuevo_equipo.fecha_creacion);
    std::cout << "Ingrese la capacidad máxima del equipo: ";
    std::cin >> nuevo_equipo.max_miembros;
    nuevo_equipo.total_miembros = 0;
    nuevo_equipo.cabeza = nullptr;
    nuevo_equipo.tareas_completadas = nullptr;

    equipos.push(nuevo_equipo);
    std::cout << "Equipo creado exitosamente.\n";
}

// Función para agregar una tarea a la cola de tareas de un equipo
void agregarTarea(Equipo& equipo) {
    Tarea* nueva_tarea = new Tarea;
    std::cout << "Descripción de la tarea: ";
    std::cin.ignore();
    std::getline(std::cin, nueva_tarea->descripcion);
    std::cout << "Prioridad (1: Alta, 2: Media, 3: Baja): ";
    std::cin >> nueva_tarea->prioridad;
    nueva_tarea->estado = "pendiente";
    nueva_tarea->siguiente = nullptr;

    equipo.cola_tareas.push(*nueva_tarea);
    std::cout << "Tarea agregada a la cola.\n";
}

// Función para marcar una tarea como "en progreso"
void iniciarTarea(Equipo& equipo) {
    if (equipo.cola_tareas.empty()) {
        std::cout << "No hay tareas pendientes.\n";
        return;
    }

    Tarea& tarea = equipo.cola_tareas.front();
    tarea.estado = "en progreso";
    std::cout << "Tarea en progreso: " << tarea.descripcion << " - Prioridad: " << tarea.prioridad << "\n";
}

// Función para despachar la tarea más antigua y marcarla como completada
void despacharTarea(Equipo& equipo) {
    if (equipo.cola_tareas.empty()) {
        std::cout << "No hay tareas pendientes.\n";
        return;
    }

    Tarea tarea_completada = equipo.cola_tareas.front();
    equipo.cola_tareas.pop();

    // Marcar como completada y agregar a la lista enlazada de tareas completadas
    tarea_completada.estado = "completada";
    tarea_completada.siguiente = equipo.tareas_completadas;
    equipo.tareas_completadas = new Tarea(tarea_completada);

    std::cout << "Tarea completada: " << tarea_completada.descripcion << " - Prioridad: " << tarea_completada.prioridad << "\n";
}

// Generar un reporte de tareas
void reporteTareas(Equipo& equipo) {
    int pendientes = 0, en_progreso = 0, completadas = 0;

    // Contar las tareas pendientes y en progreso en la cola
    std::queue<Tarea> copia = equipo.cola_tareas;
    while (!copia.empty()) {
        if (copia.front().estado == "pendiente") pendientes++;
        else if (copia.front().estado == "en progreso") en_progreso++;
        copia.pop();
    }

    // Contar las tareas completadas en la lista enlazada
    Tarea* temp = equipo.tareas_completadas;
    while (temp != nullptr) {
        completadas++;
        temp = temp->siguiente;
    }

    std::cout << "Reporte de Tareas:\n";
    std::cout << "Pendientes: " << pendientes << "\n";
    std::cout << "En Progreso: " << en_progreso << "\n";
    std::cout << "Completadas: " << completadas << "\n";
}

void agregarMiembro(Equipo& equipo) {
    if (equipo.total_miembros >= equipo.max_miembros) {
        std::cout << "El equipo ha alcanzado su capacidad máxima.\n";
        return;
    }

    Miembro* nuevo_miembro = new Miembro;
    std::cout << "Nombre del miembro: ";
    std::cin.ignore();
    std::getline(std::cin, nuevo_miembro->nombre);
    std::cout << "Apellido del miembro: ";
    std::getline(std::cin, nuevo_miembro->apellido);
    std::cout << "Edad del miembro: ";
    std::cin >> nuevo_miembro->edad;
    std::cout << "Rol del miembro: ";
    std::cin.ignore();
    std::getline(std::cin, nuevo_miembro->rol);

    std::string id = nuevo_miembro->nombre + " " + nuevo_miembro->apellido;
    if (equipo.miembros_unicos.find(id) != equipo.miembros_unicos.end()) {
        std::cout << "Este miembro ya está en el equipo.\n";
        delete nuevo_miembro;
        return;
    }

    nuevo_miembro->siguiente = equipo.cabeza;
    equipo.cabeza = nuevo_miembro;
    equipo.miembros_unicos.insert(id);
    equipo.total_miembros++;
    std::cout << "Miembro agregado exitosamente al equipo.\n";
}

// Función para listar todos los miembros de un equipo
void listarMiembros(const Equipo& equipo) {
    if (equipo.cabeza == nullptr) {
        std::cout << "No hay miembros en el equipo.\n";
        return;
    }

    Miembro* temp = equipo.cabeza;
    while (temp != nullptr) {
        std::cout << "Nombre: " << temp->nombre << " " << temp->apellido
                  << ", Edad: " << temp->edad << ", Rol: " << temp->rol << "\n";
        temp = temp->siguiente;
    }
}
// Función principal para el menú de opciones
int main() {
    int opcion;

    do {
        std::cout << "\n1. Crear equipo\n2. Listar equipos\n3. Buscar equipo\n";
        std::cout << "4. Agregar tarea\n5. Iniciar tarea\n6. Despachar tarea\n";
        std::cout << "7. Reporte de tareas\n8. Agregar miembro\n9. Listar miembros\n0. Salir\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                crearEquipo();
                break;
            case 2:
                if (equipos.empty()) {
                    std::cout << "No hay equipos registrados.\n";
                } else {
                    std::queue<Equipo> copia = equipos;
                    while (!copia.empty()) {
                        Equipo equipo = copia.front();
                        std::cout << "Equipo: " << equipo.nombre << " | Proyecto: " << equipo.proyecto << "\n";
                        copia.pop();
                    }
                }
                break;
            case 3: {
                std::string nombre_equipo;
                std::cout << "Ingrese el nombre del equipo a buscar: ";
                std::cin.ignore();
                std::getline(std::cin, nombre_equipo);
                bool encontrado = false;
                std::queue<Equipo> copia = equipos;
                while (!copia.empty()) {
                    Equipo equipo = copia.front();
                    if (equipo.nombre == nombre_equipo) {
                        std::cout << "Equipo encontrado: " << equipo.nombre << " | Proyecto: " << equipo.proyecto << "\n";
                        encontrado = true;
                        break;
                    }
                    copia.pop();
                }
                if (!encontrado) std::cout << "Equipo no encontrado.\n";
                break;
            }
            case 4: {
                if (equipos.empty()) {
                    std::cout << "No hay equipos registrados.\n";
                    break;
                }
                std::string nombre_equipo;
                std::cout << "Ingrese el nombre del equipo para agregar tarea: ";
                std::cin.ignore();
                std::getline(std::cin, nombre_equipo);
                std::queue<Equipo> copia = equipos;
                while (!copia.empty()) {
                    Equipo& equipo = copia.front();
                    if (equipo.nombre == nombre_equipo) {
                        agregarTarea(equipo);
                        break;
                    }
                    copia.pop();
                }
                break;
            }
            case 5: {
                if (equipos.empty()) {
                    std::cout << "No hay equipos registrados.\n";
                    break;
                }
                std::string nombre_equipo;
                std::cout << "Ingrese el nombre del equipo para iniciar tarea: ";
                std::cin.ignore();
                std::getline(std::cin, nombre_equipo);
                std::queue<Equipo> copia = equipos;
                while (!copia.empty()) {
                    Equipo& equipo = copia.front();
                    if (equipo.nombre == nombre_equipo) {
                        iniciarTarea(equipo);
                        break;
                    }
                    copia.pop();
                }
                break;
            }
            case 6: {
                if (equipos.empty()) {
                    std::cout << "No hay equipos registrados.\n";
                    break;
                }
                std::string nombre_equipo;
                std::cout << "Ingrese el nombre del equipo para despachar tarea: ";
                std::cin.ignore();
                std::getline(std::cin, nombre_equipo);
                std::queue<Equipo> copia = equipos;
                while (!copia.empty()) {
                    Equipo& equipo = copia.front();
                    if (equipo.nombre == nombre_equipo) {
                        despacharTarea(equipo);
                        break;
                    }
                    copia.pop();
                }
                break;
            }
            case 7: {
                if (equipos.empty()) {
                    std::cout << "No hay equipos registrados.\n";
                    break;
                }
                std::string nombre_equipo;
                std::cout << "Ingrese el nombre del equipo para ver reporte de tareas: ";
                std::cin.ignore();
                std::getline(std::cin, nombre_equipo);
                std::queue<Equipo> copia = equipos;
                while (!copia.empty()) {
                    Equipo& equipo = copia.front();
                    if (equipo.nombre == nombre_equipo) {
                        reporteTareas(equipo);
                        break;
                    }
                    copia.pop();
                }
                break;
            }
            case 8: {
              if (equipos.empty()) {
                    std::cout << "No hay equipos registrados.\n";
                    break;
                }
                std::string nombre_equipo;
                std::cout << "Ingrese el nombre del equipo para agregar un miembro: ";
                std::cin.ignore();
                std::getline(std::cin, nombre_equipo);
                std::queue<Equipo> copia = equipos;
                while (!copia.empty()) {
                    Equipo& equipo = copia.front();
                    if (equipo.nombre == nombre_equipo) {
                        agregarMiembro(equipo);
                        break;
                    }
                    copia.pop();
                }  
                break;
            }
            case 9: {
                if (equipos.empty()) {
                    std::cout << "No hay equipos registrados.\n";
                    break;
                }
                std::string nombre_equipo;
                std::cout << "Ingrese el nombre del equipo para listar sus miembros: ";
                std::cin.ignore();
                std::getline(std::cin, nombre_equipo);
                std::queue<Equipo> copia = equipos;
                while (!copia.empty()) {
                    Equipo& equipo = copia.front();
                    if (equipo.nombre == nombre_equipo) {
                        listarMiembros(equipo);
                        break;
                    }
                    copia.pop();
                }
                break;
            }
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida.\n";
        }
    } while (opcion != 0);

    return 0;
}
