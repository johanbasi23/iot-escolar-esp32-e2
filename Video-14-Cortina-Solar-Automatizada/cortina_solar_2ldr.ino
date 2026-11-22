// Video 14: Cortina Solar Automatizada con dos sensores de luz (LDR)
#include <ESP32Servo.h>

// CAMBIO DE ESCENARIO: Tolerancia de diferencia de luz entre ambos sensores (0 a 4095)
// Dia muy soleado (evitar movimientos bruscos) = 500 | Dia nublado = 150
const int margenTolerancia = 300;
const int pasoAngulo = 5; // Grados que gira en cada ajuste

Servo cortinaServo;
const int pinLdrIzq = 34;
const int pinLdrDer = 35;
const int pinServo = 18;
int anguloActual = 90;

void setup() {
  Serial.begin(115200);
  cortinaServo.attach(pinServo);
  cortinaServo.write(anguloActual);
}

void loop() {
  int luzIzq = analogRead(pinLdrIzq);
  int luzDer = analogRead(pinLdrDer);
  int diferencia = luzIzq - luzDer;

  if (abs(diferencia) > margenTolerancia) {
    if (diferencia > 0 && anguloActual < 180) {
      anguloActual += pasoAngulo;
    } else if (diferencia < 0 && anguloActual > 0) {
      anguloActual -= pasoAngulo;
    }
    cortinaServo.write(anguloActual);
  }

  Serial.printf("Izq: %d | Der: %d | Angulo Cortina: %d°\n", luzIzq, luzDer, anguloActual);
  delay(200);
}
