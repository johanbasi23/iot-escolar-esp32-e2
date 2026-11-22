// Video 17 (SIMULACION WOKWI): Barrera de Acceso Inteligente (Prueba por Monitor Serie)
#include <ESP32Servo.h>

// CAMBIO DE ESCENARIO: Modifica la clave de acceso y los angulos de la barrera
const String claveCorrecta = "ESPOL2026";
const int anguloCerrado = 0;
const int anguloAbierto = 90;
const int tiempoAbiertoMs = 4000;

Servo barrera;
const int pinServo = 18;
const int pinLedVerde = 4;

void setup() {
  Serial.begin(115200);
  barrera.attach(pinServo);
  pinMode(pinLedVerde, OUTPUT);

  barrera.write(anguloCerrado);
  digitalWrite(pinLedVerde, LOW);
  Serial.println("Simulacion lista. Escribe la clave en el Monitor Serie y presiona Enter:");
}

void loop() {
  if (Serial.available()) {
    String mensaje = Serial.readStringUntil('\n');
    mensaje.trim();

    if (mensaje == claveCorrecta) {
      Serial.println("ACCESO CONCEDIDO - Abriendo barrera");
      digitalWrite(pinLedVerde, HIGH);
      barrera.write(anguloAbierto);
      delay(tiempoAbiertoMs);

      barrera.write(anguloCerrado);
      digitalWrite(pinLedVerde, LOW);
      Serial.println("Barrera cerrada nuevamente.");
    } else {
      Serial.println("CLAVE INCORRECTA - Acceso denegado");
    }
  }
  delay(50);
}
