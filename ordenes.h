typedef struct {
    char codigo_orden[16];
    char nombre_cliente[50];
    char equipo[40];
    char tipo_trabajo[60];
    float costo_base;
    int horas_trabajo;
} Orden;

void leerCadena(char cadena[], int tamano);
float calcularCostoTotal(Orden orden);

void registrarOrden(Orden ordenes[], int *cantidad);
void listarOrdenes(Orden ordenes[], int cantidad);
void buscarOrden(Orden ordenes[], int cantidad);
void actualizarOrden(Orden ordenes[], int cantidad);
void eliminarOrden(Orden ordenes[], int *cantidad);
void guardarCSV(Orden ordenes[], int cantidad);
void cargarCSV(Orden ordenes[], int *cantidad);