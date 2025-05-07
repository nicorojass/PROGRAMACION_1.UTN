#include "mocks.h"

void cargaNombre(char n[])
{
    char nombres[][30]=
    {
        "Juan", "Maria", "Carlos", "Ana", "Luis", "Laura", "Pedro", "Sofia", "Jorge", "Lucia",
        "Miguel", "Valentina", "Jose", "Isabella", "David", "Camila", "Alejandro", "Paula", "Daniel", "Fernanda",
        "Andres", "Valeria", "Manuel", "Mariana", "Ricardo", "Gabriela", "Felipe", "Daniela", "Javier", "Alejandra",
        "Roberto", "Victoria", "Raul", "Juana", "Fernando", "Antonella", "Diego", "Ximena", "Arturo", "Adriana",
        "Eduardo", "Natalia", "Alberto", "Claudia", "Francisco", "Andrea", "Antonio", "Patricia", "Ruben", "Monica",
        "Sergio", "Alicia", "Enrique", "Carolina", "�scar", "Rosa", "Pablo", "Teresa", "Hugo", "Sara",
        "Guillermo", "Elena", "Rodrigo", "Beatriz", "Salvador", "Julia", "Emilio", "Raquel", "Mario", "Diana",
        "Alfonso", "Olga", "Armando", "Angelica", "Gerardo", "Silvia", "Rafael", "Carmen", "Jaime", "Irene",
        "Ignacio", "Pilar", "Hector", "Concepcion", "Cesar", "Lourdes", "Victor", "Consuelo", "Ramon", "Eva",
        "Alfredo", "Luisa", "Julio", "Amparo", "Joaquin", "Rocio", "Gustavo", "Manuela", "Lorenzo", "Veronica", "Lorenzo", "Veronica"
    };
    strcpy(n, nombres[rand()%(sizeof(nombres)/30)]);
}

void cargaApellido(char apellido[])
{
    char apellidos[][30] = {"Garcia", "Rodriguez", "Gonzalez", "Fernandez", "Lopez",
                            "Martinez", "Sanchez", "Perez", "Gomez", "Martin",
                            "Jimenez", "Ruiz", "Hernandez", "Diaz", "Moreno",
                            "Alvarez", "Munoz", "Romero", "Alonso", "Gutierrez",
                            "Navarro", "Torres", "Dominguez", "Vazquez", "Ramos",
                            "Gil", "Ramirez", "Serrano", "Blanco", "Suarez",
                            "Molina", "Morales", "Ortega", "Delgado", "Castro",
                            "Ortiz", "Rubio", "Marin", "Sanz", "Iglesias",
                            "Medina", "Cortes", "Garrido", "Castillo", "Santos",
                            "Lozano", "Guerrero", "Cano", "Prieto", "Mendez",
                            "Cruz", "Calvo", "Gallego", "Vidal", "Leon",
                            "Herrera", "Marquez", "Pena", "Flores", "Cabrera",
                            "Campos", "Vega", "Fuentes", "Carrasco", "Diez",
                            "Reyes", "Caballero", "Nunez", "Aguilar", "Pascual",
                            "Santana", "Herrero", "Montero", "Lorenzo", "Hidalgo",
                            "Gimenez", "Ibanez", "Ferrer", "Duran", "Santiago",
                            "Benitez", "Mora", "Vicente", "Vargas", "Arias",
                            "Carmona", "Crespo", "Roman", "Pastor", "Soto",
                            "Saez", "Velasco", "Moya", "Soler", "Parra",
                            "Esteban", "Bravo", "Gallardo", "Rojas", "Pardo"
                           };
    strcpy(apellido, apellidos[rand()% (sizeof(apellidos) / 30)]);
}

void cargaDni(char dni[]){
    itoa(rand ()% 10000 * 1033, dni, 10);
}

int cargaLegajo(){
    return rand()% 10000;
}

int cargaArregloAlumnosAuto(stAlumno a[], int dim){
    int i;
    for (i = 0; i < dim; i++){
        a[i].id = i+1;
        cargaNombre(a[i].nombre);
        cargaApellido(a[i].apellido);
        cargaDni(a[i].dni);
        a[i].legajo = cargaLegajo();
    }
    return i;
}
