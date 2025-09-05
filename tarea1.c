#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//===================================================================================================
// FUNCIONES HERRAMIENTAS
//===================================================================================================

void mostrarMenuPrincipal() {
  puts("========================================");
  puts("          Sistema de gestión de tickets de soporte técnico");
  puts("========================================");

  puts("1) Registrar Nuevo Ticket.");
  puts("2) Modificar Prioridad de Tickets.");
  puts("3) Procesar siguiente Ticket (segun de urgencia).");
  puts("4) Mostrar lista de Tickets pendientes.");
  puts("5) Salir.");
}

void registrar_nuevo_ticket(List *pacientes) {
  printf("Registrar nuevo ticket\n");

}

void mostrar_lista_tickets(List *pacientes) {
  printf("tickets en espera: \n");
  
}

int main() {
  char opcion;
  List *tickets = list_create(); // puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrar_nuevo_ticket(tickets);
      break;
    case '2':
      // Lógica para asignar prioridad
      break;
    case '3':
      // Logica pa procesar siguiente ticket
      break;
    case '4':
      mostrar_lista_ticket(tickets);
      break;
    case '5':
      puts("Saliendo del sistema de gestión tickets soporte tecnico...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '5');

  // Liberar recursos, si es necesario
  list_clean(tickets);

  return 0;
}

