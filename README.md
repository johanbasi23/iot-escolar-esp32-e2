# iot-escolar-esp32-e2
# Proyectos IoT Escolares con ESP32 y Wokwi — Módulos E2

Repositorio oficial de códigos fuente (`.ino`) y esquemas de simulación (`diagram.json`) para las cápsulas educativas del proyecto **Educación Digital para el desarrollo sostenible en jóvenes de Santa Lucía (Fase 3)**[cite: 1, 2].

## Índice de Cápsulas y Recursos

| N° | Título de la Cápsula | Carpeta Directa | Entorno |
| :--- | :--- | :--- | :--- |
| **05** | Del simulador al ESP32 real: Arduino IDE, drivers y primera carga[cite: 2] | [Ver archivos](./Video-05-Simulador-a-ESP32-Real) | Wokwi / ESP32 Físico |
| **08** | Medidor de Iluminación Natural: ¿hace falta encender la luz?[cite: 2] | [Ver archivos](./Video-08-Medidor-Iluminacion-Natural) | Wokwi |
| **11** | Alarma de Ocupación Fuera de Horario con sensor PIR[cite: 2] | [Ver archivos](./Video-11-Alarma-Ocupacion-PIR-NTP) | Wokwi / ESP32 Físico |
| **14** | Cortina Solar Automatizada con dos sensores de luz[cite: 2] | [Ver archivos](./Video-14-Cortina-Solar-Automatizada) | Wokwi |
| **17** | Barrera de Acceso Inteligente con Bluetooth[cite: 2] | [Ver archivos](./Video-17-Barrera-Acceso-Bluetooth) | Wokwi / ESP32 Físico |
| **20** | Integración de Proyectos: cómo combinar sensores sin que el código falle[cite: 2] | [Ver archivos](./Video-20-Integracion-Proyectos) | Wokwi / ESP32 Físico |

## Instrucciones de Uso Rápido en Wokwi
1. Ingresa a [wokwi.com](https://wokwi.com/) y abre una plantilla en blanco de **ESP32** (*ESP32 Starter Template*).
2. Abre la carpeta del video que deseas probar y copia el contenido del archivo `.ino` dentro de `sketch.ino`.
3. Copia el contenido de `diagram.json` y reemplaza el contenido de la pestaña `diagram.json` en Wokwi para cargar el circuito cableado automáticamente.
4. Si el proyecto utiliza pantalla OLED, servomotor o sensor DHT, instala las librerías correspondientes desde la pestaña *Library Manager*.

## Nota de Seguridad y Migración a Hardware Real
* **Credenciales WiFi:** Por seguridad, los códigos públicos utilizan `"TU_RED"` y `"TU_CLAVE"`. Nunca subas contraseñas reales.
* **Archivos `_esp32_real.ino`:** En los módulos donde la simulación requiere una adaptación (como Bluetooth o WiFi abierto de Wokwi), encontrarás un segundo archivo `.ino` listo para cargar directamente en tu placa física sin modificar la lógica.
