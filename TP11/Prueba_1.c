#include<stdio.h>

// Estructura para representar un producto
struct Producto {
    char id[20];
    float precio;
    char nombre[100];
};

int main() {
    FILE* datos_parseados;
    FILE* datos_estadisticos;

    datos_parseados = fopen("datos_parseados.csv", "r");
    datos_estadisticos = fopen("datos_estadisticos.txt", "w");

    if (datos_estadisticos == NULL || datos_parseados == NULL) {
        printf("Error al abrir el archivo de datos estadisticos\n");
    } else {
        printf("Archivo de datos estadisticos abierto correctamente\n");

        struct Producto producto_mas_caro;
        struct Producto producto_mas_barato;

        // Inicializar las variables
        producto_mas_caro.precio = -1.0;
        producto_mas_barato.precio = 999999.0;

        // Leer el archivo de datos parseados
        while (fscanf(datos_parseados, "%19[^,],%f,%99[^\n]\n",
                      producto_mas_caro.id, &producto_mas_caro.precio, producto_mas_caro.nombre) != EOF) {

            // Verificar si el producto actual es el más caro
            if (producto_mas_caro.precio > producto_mas_caro.precio) {
                producto_mas_caro = producto_mas_caro;
            }

            // Verificar si el producto actual es el más barato
            if (producto_mas_caro.precio < producto_mas_barato.precio) {
                producto_mas_barato = producto_mas_caro;
            }
        }

        // Imprimir el producto más caro 
        printf("Producto más caro:\nID: %s\nNombre: %s\nPrecio: %.2f\n\n",
               producto_mas_caro.id, producto_mas_caro.nombre, producto_mas_caro.precio);

        // Imprimir el producto más barato 
        printf("Producto más barato:\nID: %s\nNombre: %s\nPrecio: %.2f\n\n",
               producto_mas_barato.id, producto_mas_barato.nombre, producto_mas_barato.precio);

        // Escribir en el archivo de datos_estadisticos_txt
        fprintf(datos_estadisticos, "Producto más caro:\nID: %s\nNombre: %s\nPrecio: %.2f\n\n",
               producto_mas_caro.id, producto_mas_caro.nombre, producto_mas_caro.precio);

        fprintf(datos_estadisticos, "Producto más barato:\nID: %s\nNombre: %s\nPrecio: %.2f\n\n",
               producto_mas_barato.id, producto_mas_barato.nombre, producto_mas_barato.precio);

        fclose(datos_parseados);
        fclose(datos_estadisticos);
    }

    return 0;
}
