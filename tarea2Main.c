#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
#include "list.h" 
#include <windows.h>
void CargarLista(){
      FILE *archivo = fopen("data/song_dataset_.csv", "r");
  if (archivo == NULL) {
    perror("Error al abrir el archivo");
    return;
  }
  char **campos;
  campos = leer_linea_csv(archivo, ',');
  int k=0;
  while ((campos = leer_linea_csv(archivo, ',')) != NULL) {
    k++;
    if (k>10) {
        break;
    }
    printf("ID: %d\n", atoi(campos[0]));
    printf("Título cancion: %s\n", campos[4]);
    List* artistas = split_string(campos[2], ";");
    printf("Artistas: \n");
    for(char *artista = list_first(artistas); artista != NULL; artista = list_next(artistas)){
        printf("  %s\n", artista);
        printf("Album: %s\n", campos[3]);
        printf("Género: %s\n", campos[20]);
        printf("Tempo: %.2f\n", atof(campos[18]));
        printf(" -------------------------------\n");
    }
  }
  fclose(archivo); 
}
int main(){
	SetConsoleOutputCP(65001);
	List* lista = createList();
	if(lista == NULL){
	    return 1;
    }
    int opcion = 0;
    int SubOpcion = 0;
    do{
        printf("\n=========================================\n");
        printf("   SISTEMA GESTIÓN DE LISTA DE ESPERA   \n");
        printf("=========================================\n");
        printf("1. Cargar Lista de Canciones\n");
        printf("2. Buscar Canciones por Genero\n");
        printf("3. Buscar Canciones por Artista\n");
        printf("4. Buscar Canciones por Tempo\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: CargarLista(); break;
            case 2: BuscarPorGenero(lista); break;
            case 3: BuscarPorArtista(lista); break;
            case 4: BuscarPorTempo(lista); break;
            case 5: printf("Saliendo del sistema...\n"); break;
            default: printf("Opción inválida. Intente de nuevo.\n");
        }
    }while (opcion != 6);

    return 0;
}