// Video 20: Integracion Modular (DHT + Servomotor + Pantalla OLED + LED Alerta)
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <ESP32Servo.h>

// CAMBIO A HARDWARE REAL: En Wokwi se usa DHT22. Si tu kit fisico trae el sensor azul, cambia a DHT11:
#define DHTTYPE DHT22

// CAMBIO DE ESCENARIO: Temperatura maxima antes de abrir ventilacion (en grados Celsius)
// Aula regular = 28.0 | Sala de servidores o laboratorio = 24.0
const float tempMaxima = 28.0;

#define DHTPIN 15
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo ventanaServo;

const int pinServo = 18;
const int pinLedAlerta = 2;

float temperatura = 0.0;
float humedad = 0.0;
unsigned long tiempoAnterior = 0;
const long intervaloLectura = 2000;

void leerSensores() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (!isnan(t) && !isnan(h)) {
    temperatura = t;
    humedad = h;
  }
}

void controlarVentilacion() {
  if (temperatura > tempMaxima) {
    ventanaServo.write(90);
    digitalWrite(pinLedAlerta, HIGH);
  } else {
    ventanaServo.write(0);
    digitalWrite(pinLedAlerta, LOW);
  }
}

void actualizarPantalla() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("SISTEMA INTEGRADO E2");

  display.setTextSize(2);
  display.setCursor(0, 18);
  display.print(temperatura, 1);
  display.println(" C");

  display.setTextSize(1);
  display.setCursor(0, 45);
  display.print("Humedad: ");
  display.print(humedad, 0);
  display.println("%");

  display.setCursor(0, 56);
  display.println(temperatura > tempMaxima ? "VENTANA: ABIERTA" : "VENTANA: CERRADA");
  display.display();
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  ventanaServo.attach(pinServo);
  pinMode(pinLedAlerta, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Error en OLED");
    for (;;);
  }
  display.setTextColor(WHITE);
}

void loop() {
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior >= intervaloLectura) {
    tiempoAnterior = tiempoActual;
    leerSensores();
    controlarVentilacion();
    actualizarPantalla();
  }
}
