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
