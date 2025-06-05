# UEA: Programacion Estructurada

## 🛒 Proyecto Final: Sistema de Gestión de Productos en una Tienda

Este proyecto implementa un sistema de gestión de inventario para una tienda, desarrollado en **lenguaje C**. Permite registrar productos, gestionarlos, realizar cálculos de inversión/ganancia y mantener una base de datos persistente utilizando archivos binarios.

---

## 📦 Estructura del Sistema

El programa gestiona productos mediante tres estructuras principales:

### 🧱 Estructuras de datos

```c
typedef struct {
    int dia;
    char mes[50];
    int anio;
} FECHA;

typedef struct {
    char nombre[150];
    char categoria[150];
    int codigo;
    int existencia;
    double precio_compra;
    double precio_venta;
    FECHA caducidad;
} PRODUCTO;

typedef struct {
    PRODUCTO *productos;
    int N;
} BD;
```

## ⚙️ Funcionalidades
El menú del programa permite:
- Agregar Producto
  - Registra un nuevo producto y lo guarda en memoria dinámica.
- Eliminar Producto
  - Elimina un producto por su código, reorganizando el arreglo.
  - Guardar a archivo binario
- Persiste los productos en un archivo binario BD_producto.dat.
  - Leer desde archivo binario
- Recupera la base de datos desde el archivo binario.
  - Mostrar productos
- Muestra todos los productos registrados con sus detalles.
  - Buscar producto
- Permite buscar por código o por nombre.
  - Calcular capital invertido
- Multiplica existencia por precio de compra y suma.
  - Calcular ganancia total
- Compara capital invertido vs. capital potencial de venta.
  - Ordenar productos por año de caducidad
- Orden ascendente o descendente usando qsort().
  - Ordenar productos por existencia
- Ordena según cantidad disponible.
- Salir del programa

## 🧠 Aprendizajes clave
- Manejo de memoria dinámica con malloc, realloc y free.
- Uso de archivos binarios con fread, fwrite.
- Implementación de estructuras anidadas (struct dentro de struct).
- Uso del algoritmo qsort() con funciones personalizadas de comparación.
- Diseño de menús interactivos en consola.

🔒 Archivos generados
- BD_producto.dat: archivo binario que guarda la base de datos de productos entre ejecuciones.

📌 Notas importantes
- Las operaciones de búsqueda y eliminación requieren que el producto exista y se identifique por su código o nombre.
- Se recomienda evitar códigos duplicados para mantener la integridad de la base de datos.
<!--El sistema no incluye validación avanzada de entrada; está pensado para fines educativos.-->

## ▶️ Ejecución
💻 Compilación (Linux/Mac)

```bash
gcc Proyecto_Final.c -o tienda
./tienda
```
🪟 Compilación (Windows, usando cmd)
```bash
gcc Proyecto_Final.c -o tienda.exe
tienda.exe
```



