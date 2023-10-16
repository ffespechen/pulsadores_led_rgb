/*
  Proyecto didáctico Arduino con mínimos componentes.

  Pulsadores para controlar la intensidad de un LED RGB.
  
  04 (cuatro) Pulsadores sin retención
  04 (cuatro) Resistencias 4k7 Ohm para pull-down
  01 (uno) LED RGB cátodo común 
  03 (tres) Resistencias 220 Ohm
  01 Arduino UNO R3
  01 Protoboard
  Cables M-M cantidad necesaria
 */

#define RGB_ROJO 9
#define RGB_VERDE 10
#define RGB_AZUL 11

#define PULSADOR_ROJO 2
#define PULSADOR_VERDE 3
#define PULSADOR_AZUL 4
#define PULSADOR_APAGAR 5

int r = 0;
int g = 0;
int b = 0;

void setup() {
  pinMode(RGB_ROJO, OUTPUT);
  pinMode(RGB_VERDE, OUTPUT);
  pinMode(RGB_AZUL, OUTPUT);
  
  pinMode(PULSADOR_ROJO, INPUT);
  pinMode(PULSADOR_VERDE, INPUT);
  pinMode(PULSADOR_AZUL, INPUT);
  pinMode(PULSADOR_APAGAR, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(PULSADOR_ROJO) == 1){
    r++;
  }
  if(digitalRead(PULSADOR_VERDE) == 1){
    g++;
  }
  if(digitalRead(PULSADOR_AZUL) == 1){
    b++;
  }
  if(digitalRead(PULSADOR_APAGAR) == 1){
    r=0;
    g=0;
    b=0;
  }
  analogWrite(RGB_ROJO, r);
  analogWrite(RGB_VERDE, g);
  analogWrite(RGB_AZUL, b);
  
  Serial.print("ROJO: ");
  Serial.print(r);
  Serial.print("  VERDE: ");
  Serial.print(g);
  Serial.print("  AZUL: ");
  Serial.print(b);
  Serial.println();
  delay(200);
}
