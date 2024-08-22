#define HITAM 15
#define PUTIH 700

int speedmax = 100;
int speedmin = 50;

String warnagaris = "hitam";

int kn_mj = 8;
int kn_md = 9;
int enable1Pin = 10; // KANAN 

// Deklarasi pin untuk motor 2
int kr_mj = 7;
int kr_md = 6;
int enable2Pin = 5; // KIRI

void gerakMaju(int kc_kr,int kc_kn, int durasi) {
  analogWrite(enable1Pin, kc_kn);
  analogWrite(enable2Pin, kc_kr);
  digitalWrite(kn_mj, HIGH);
  digitalWrite(kn_md, LOW);
  digitalWrite(kr_mj, HIGH);
  digitalWrite(kr_md, LOW);
  delay(durasi);
}
void gerakMundur(int kc_kr,int kc_kn, int durasi) {
  analogWrite(enable1Pin, kc_kn);
  analogWrite(enable2Pin, kc_kr);
  digitalWrite(kn_mj, LOW);
  digitalWrite(kn_md, HIGH);
  digitalWrite(kr_mj, LOW);
  digitalWrite(kr_md, HIGH);
  delay(durasi);
}
void stop(int kc_kr,int kc_kn, int durasi) {
  analogWrite(enable1Pin, kc_kn);
  analogWrite(enable2Pin, kc_kr);
  digitalWrite(kn_mj, LOW);
  digitalWrite(kn_md, LOW);
  digitalWrite(kr_mj, LOW);
  digitalWrite(kr_md, LOW);
  delay(durasi);
}
void gerak_kn(int kc_kr,int kc_kn, int durasi) {
  analogWrite(enable1Pin, kc_kn);
  analogWrite(enable2Pin, kc_kr);
  digitalWrite(kn_mj, LOW);
  digitalWrite(kn_md, HIGH);
  digitalWrite(kr_mj, HIGH);
  digitalWrite(kr_md, LOW);
  delay(durasi);
}
void gerak_kr(int kc_kr,int kc_kn, int durasi) {
  analogWrite(enable1Pin, kc_kn);
  analogWrite(enable2Pin, kc_kr);
  digitalWrite(kn_mj, HIGH);
  digitalWrite(kn_md, LOW);
  digitalWrite(kr_mj, LOW);
  digitalWrite(kr_md, HIGH);
  delay(durasi);
}

void blackline(){
        if(analogRead(A0) < HITAM){ 
           gerakMaju(speedmax,speedmin,100);    
        }
        if(analogRead(A1) < HITAM){ 
          gerakMaju(speedmax,speedmin,100);
            
        }
        if(analogRead(A2) < HITAM){ 
          gerakMaju(speedmax,speedmax,100);
            
        }
        if(analogRead(A3) < HITAM){ 
            gerakMaju(speedmin,speedmax,100);
            
        }
        if(analogRead(A4) < HITAM){ 
            gerakMaju(speedmin,speedmax,100);
            
        }
    }
    
void whiteline (){
        if(analogRead(A0) > PUTIH){
            gerakMaju(speedmax,speedmin,100);
            
        }
        if(analogRead(A1) > PUTIH){ 
             gerakMaju(speedmax,speedmin,100);
            
        }
        if(analogRead(A2) > PUTIH){ 
           gerakMaju(speedmax,speedmax,100);
            
        }
        if(analogRead(A3) > PUTIH){ 
            gerakMaju(speedmin,speedmax,100);
            
        }
        if(analogRead(A4) > PUTIH){ 
            gerakMaju(speedmin,speedmax,100);
            
        }
  }
    
void bacagaris(){
    if (warnagaris == "hitam")
    {
        blackline();
    }
    if (warnagaris == "putih")
    {
        whiteline();
    }
  }
void kanan (int time){
    if (warnagaris == "hitam")
    {
        while (!(analogRead(A0) < HITAM && analogRead(A1) < HITAM)){
            bacagaris();
        }
    }
    
    if (warnagaris == "putih")
    {
        while (!(analogRead(A0) > PUTIH && analogRead(A1) > PUTIH)){
            bacagaris();
        }
    }
  gerakMaju(150, 150, 1200);
  gerak_kn(255,255,500);
  }

void kiri (int time){
    if (warnagaris == "hitam")
    {
        while (!(analogRead(A3) < HITAM && analogRead(A4) < HITAM)){
            bacagaris();
        }
    }
    
    if (warnagaris == "putih")
    {
        while (!(analogRead(A3) > PUTIH && analogRead(A4) > PUTIH)){
            bacagaris();
        }
    }
    
   gerakMaju(150, 150, 1200);
   gerak_kr(255,255,500);
  }
void maju (int time){
    if (warnagaris == "hitam"){
        while (!((analogRead(A3) < HITAM && analogRead(A4) < HITAM)||((analogRead(A0) < HITAM && analogRead(A1) < HITAM)))){
            bacagaris();
        }
    }
    
    if (warnagaris == "putih"){
        while (!((analogRead(A3) > PUTIH && analogRead(A4) > PUTIH)||((analogRead(A0) > PUTIH && analogRead(A1) > PUTIH)))){
            bacagaris();
        }
    }
     gerakMaju(speedmax,speedmax,100);
}
void mundur (int time){
    if (warnagaris == "hitam"){
        while (!((analogRead(A3) < HITAM && analogRead(A4) < HITAM)||((analogRead(A0) < HITAM && analogRead(A1) < HITAM )))){
            bacagaris();
        }
    }
    
    if (warnagaris == "putih"){
        while (!((analogRead(A3) > PUTIH && analogRead(A4) > PUTIH)||((analogRead(A0) > PUTIH && analogRead(A1) > PUTIH)))){
            bacagaris();
        }
    }
    gerakMundur(speedmax,speedmax,100);
  }
void berhenti (int time){
     if (warnagaris == "hitam"){
        while (!((analogRead(A3) < HITAM && analogRead(A4) < HITAM)||((analogRead(A0) < HITAM && analogRead(A1) < HITAM)))){
            bacagaris();
        }
    }
    
    if (warnagaris == "putih"){
        while (!((analogRead(A3) > PUTIH && analogRead(A4) > PUTIH)||((analogRead(A0) > PUTIH && analogRead(A1) > PUTIH))))
        {
            bacagaris();
        }
    }
    stop(0,0,1000);
  }
void putar_balik(int time){
     if (warnagaris == "hitam"){
        while (((analogRead(A3) < HITAM && analogRead(A4) < HITAM)||((analogRead(A0) < HITAM && analogRead(A1) < HITAM)))){
            bacagaris();
        }
    }
    
    if (warnagaris == "putih"){
        while (((analogRead(A3) > PUTIH && analogRead(A4) > PUTIH)||((analogRead(A0) > PUTIH && analogRead(A1) > PUTIH)))){
            bacagaris();
        }
    }
  gerakMaju(150, 150, 1200);
  gerak_kr(255,255,1000);
}