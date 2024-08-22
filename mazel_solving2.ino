//A0 KANAN A4 KIRI
#include "solving5.h"

void setup() {

  pinMode(kn_mj, OUTPUT);
  pinMode(kn_md, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  pinMode(kr_mj, OUTPUT);
  pinMode(kr_md, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  // Inisialisasi motor berhenti
  digitalWrite(kn_mj, LOW);
  digitalWrite(kn_md, LOW);
  digitalWrite(kr_mj, LOW);
  digitalWrite(kr_md, LOW);

  Serial.begin(9600);
}
void loop() {
    kanan(1);
    maju(1);
}