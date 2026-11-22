// Video 11 (HARDWARE REAL): Alarma de Ocupacion Fuera de Horario con PIR y Hora NTP
#include <WiFi.h>
#include "time.h"

// CREDENCIALES WIFI: Reemplaza con el nombre y clave de tu red WiFi local
const char* ssid = "TU_RED";
const char* password = "TU_CLAVE";

// CAMBIO DE ESCENARIO: Zona horaria y horario de vigilancia (formato 24 horas)
// Ecuador / Colombia / Peru = -5 | Mexico Centro = -6 | Argentina / Chile = -3
const long gmtOffset_sec = -5 * 3600;
const int daylightOffset_sec = 0;

// Jornada completa: vigila desde las 18:00 (6 PM) hasta las 07:00 (7 AM)
// Jornada matutina: cambia horaInicioVigilancia a 13 (1 PM)
const int horaInicioVigilancia = 18;
const int horaFinVigilancia = 7;

const char* ntpServer = "pool.ntp.org";
const int pinPIR = 14;
const int pinBuzzer = 27;

void setup() {
  Serial.begin(115200);
  pinMode(pinPIR, INPUT);
  pinMode(pinBuzzer, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado. Sincronizando hora NTP...");
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Esperando sincronizacion NTP...");
    delay(2000);
    return;
  }

  int horaActual = timeinfo.tm_hour;
  int movimiento = digitalRead(pinPIR);
  bool fueraDeHorario = (horaActual >= horaInicioVigilancia || horaActual < horaFinVigilancia);

  if (fueraDeHorario && movimiento == HIGH) {
    Serial.printf("ALERTA! Movimiento fuera de horario a las %02d:%02d\n", horaActual, timeinfo.tm_min);
    tone(pinBuzzer, 1000);
    delay(500);
    noTone(pinBuzzer);
  } else {
    noTone(pinBuzzer);
  }
  delay(500);
}
