// Video 05: Eco-Semaforo (Migracion de Wokwi a ESP32 Real)

// CAMBIO DE ESCENARIO: Ajusta los tiempos de cada luz en milisegundos (1000 ms = 1 seg)
// Cruce escolar lento: tiempoVerde = 5000 | Prueba rapida en clase: tiempoVerde = 2000
const int tiempoVerde = 3000;
const int tiempoAmarillo = 1000;
const int tiempoRojo = 3000;

const int pinRojo = 19;
const int pinAmarillo = 18;
const int pinVerde = 5;

void setup() {
  Serial.begin(115200);
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  Serial.println("Eco-Semaforo iniciado correctamente.");
}

void loop() {
  Serial.println("Estado: VERDE - Paso libre");
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinRojo, LOW);
  delay(tiempoVerde);

  Serial.println("Estado: AMARILLO - Precaucion");
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarillo, HIGH);
  digitalWrite(pinRojo, LOW);
  delay(tiempoAmarillo);

  Serial.println("Estado: ROJO - Detenerse");
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinRojo, HIGH);
  delay(tiempoRojo);
}
