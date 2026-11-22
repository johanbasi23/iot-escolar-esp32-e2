# Video 20 | Integración de Proyectos: cómo combinar sensores sin que el código falle[cite: 2]

- **Simulación en Wokwi:** `https://wokwi.com/projects/481251428533014529`
- **Librerías requeridas:** `DHT sensor library`, `ESP32Servo`, `Adafruit SSD1306`, `Adafruit GFX Library`[cite: 2].
- **Conexiones:** Sensor DHT (`SDA` en `GPIO 15`), Servomotor (`PWM` en `GPIO 18`), OLED I2C (`SDA` en `GPIO 21`, `SCL` en `GPIO 22`), LED Alerta (`GPIO 2` con resistencia de 220 Ω a `GND`)[cite: 2].
- **Nota de Hardware Real:** Cambiar `#define DHTTYPE DHT22` por `DHT11` si utilizas el sensor azul del kit físico[cite: 2].
