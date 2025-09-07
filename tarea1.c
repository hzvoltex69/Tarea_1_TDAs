#include "tdas/list.h"
#include "tdas/extra.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
//===================================================================================================
// FUNCIONES HERRAMIENTAS
//===================================================================================================
typedef struct {
    int  id;
    char descripcion[256];
    int  prioridad;
    char fecha[20];
    char estado[20]; 
} Ticket;

void mostrarMenuPrincipal() {
  puts("========================================");
  puts("          Sistema de gestión de tickets de soporte técnico");
  puts("========================================");

  puts("1) Registrar Nuevo Ticket.");
  puts("2) Modificar Prioridad de Tickets.");
  puts("3) Mostrar lista de Tickets pendientes.");
  puts("4) Procesar siguiente Ticket (segun prioridad y antiguedad).");
  puts("5) Buscar Ticket por ID y Mostrar detalles.");
  puts("6) Salir.");
}

void registrar_nuevo_ticket(List *tickets) {
    printf("\n=== REGISTRAR NUEVO TICKET ===\n");
    
    Ticket *nuevoTicket = (Ticket*)malloc(sizeof(Ticket));
    if (nuevoTicket == NULL) {
        printf("Error: No se pudo crear el ticket.\n");
        return;
    }
    
    printf("Ingrese ID del ticket: ");
    scanf("%d", &nuevoTicket->id);
    printf("Ingrese descripción del problema: ");
    getchar(); 
    fgets(nuevoTicket->descripcion, sizeof(nuevoTicket->descripcion), stdin);
    nuevoTicket->descripcion[strcspn(nuevoTicket->descripcion, "\n")] = '\0';
    nuevoTicket->prioridad = 1; 
  
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(nuevoTicket->fecha, sizeof(nuevoTicket->fecha), "%Y-%m-%d %H:%M:%S", tm_info);
    
    strcpy(nuevoTicket->estado, "pendiente");
    pushBack(tickets, nuevoTicket);
    
    
    printf("\nTicket registrado exitosamente!\n");
    printf("───────────────────────────────────────\n");
    printf("ID: %d\n", nuevoTicket->id);
    printf("Descripción: %s\n", nuevoTicket->descripcion);
    printf("Prioridad: Baja (asignada automáticamente, modificar con OP2)\n");
    printf("Fecha de registro: %s\n", nuevoTicket->fecha);
    printf("Estado: %s\n", nuevoTicket->estado);
    printf("───────────────────────────────────────\n");
}
void mostrar_lista_tickets(List *tickets) {
  printf("tickets en espera: \n");
  
}

int main() {
  char opcion;
  List *tickets = createList(); // puedes usar una lista para gestionar los pacientes

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
      mostrar_lista_tickets(tickets);
      break;
    case '4':
      
      break;
    case '5':
      // Lógica para buscar ticket por ID y mostrar detalles
    case '6':
      puts("Saliendo del sistema de gestión tickets soporte tecnico...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  cleanList(tickets);

  return 0;
}


