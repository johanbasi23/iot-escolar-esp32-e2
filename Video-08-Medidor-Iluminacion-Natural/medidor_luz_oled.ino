// Video 08: Medidor de Iluminacion Natural con LDR y Pantalla OLED
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// CAMBIO DE ESCENARIO: Porcentaje de luz natural minimo para apagar las luces del aula
// Aula de clases regular = 60 | Pasillo o corredor = 35 | Laboratorio de computo = 75
const int umbralLuzSuficiente = 60;

const int pinLDR = 34;

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Error al iniciar pantalla OLED");
    for (;;);
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  int lecturaAnalogica = analogRead(pinLDR);
  // Mapea la lectura (0 a 4095) a porcentaje de iluminacion (0% a 100%)
  int porcentajeLuz = map(lecturaAnalogica, 0, 4095, 100, 0);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("MONITOR DE LUZ NATURAL");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("Luz: ");
  display.print(porcentajeLuz);
  display.println("%");

  display.setTextSize(1);
  display.setCursor(0, 48);
  if (porcentajeLuz >= umbralLuzSuficiente) {
    display.println("APAGAR LUCES DEL AULA");
  } else {
    display.println("ENCENDER ILUMINACION");
  }
  display.display();
  delay(500);
}
