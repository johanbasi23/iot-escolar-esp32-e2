// Video 17 (HARDWARE REAL): Barrera de Acceso Inteligente via Bluetooth
#include "BluetoothSerial.h"
#include <ESP32Servo.h>

// CAMBIO DE ESCENARIO: Modifica el nombre Bluetooth, la clave y los angulos del servo
const String nombreDispositivo = "Barrera_Aula_ESP32";
const String claveCorrecta = "ESPOL2026";
const int anguloCerrado = 0;
const int anguloAbierto = 90;
const int tiempoAbiertoMs = 4000;

BluetoothSerial SerialBT;
Servo barrera;

const int pinServo = 18;
const int pinLedVerde = 4;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(nombreDispositivo);
  barrera.attach(pinServo);
  pinMode(pinLedVerde, OUTPUT);

  barrera.write(anguloCerrado);
  digitalWrite(pinLedVerde, LOW);
  Serial.println("Bluetooth listo. Empareja tu celular con: " + nombreDispositivo);
}

void loop() {
  if (SerialBT.available()) {
    String mensaje = SerialBT.readStringUntil('\n');
    mensaje.trim();

    if (mensaje == claveCorrecta) {
      SerialBT.println("ACCESO CONCEDIDO - Abriendo barrera");
      digitalWrite(pinLedVerde, HIGH);
      barrera.write(anguloAbierto);
      delay(tiempoAbiertoMs);

      barrera.write(anguloCerrado);
      digitalWrite(pinLedVerde, LOW);
      SerialBT.println("Barrera cerrada nuevamente.");
    } else {
      SerialBT.println("CLAVE INCORRECTA - Acceso denegado");
    }
  }
  delay(50);
}
