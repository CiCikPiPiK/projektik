#include "encoder.h"

encoder::encoder(int INpin, int circuit,int maxImplsPR):INpin(INpin),circuit(circuit),maxImplsPR(maxImplsPR){
  Serial.println("Encoder Created");
}
int encoder::getInpuls(){
  return inpuls;
}
int encoder::getRounds(){
  return rounds;
}
int encoder::getAllRounds(){
  return allRounds;
}

void encoder::Run(){
  int mm;
   updateAll();
   mm = (inpuls * circuit)/maxImplsPR;
   this->mm = mm;
   return mm;
}

int encoder::updateAll(){
   if(digitalRead(INpin)){
    inpuls++;
    rounds = inpuls % 400 ? rounds + 1 : rounds;
    if(allRounds != rounds){
      allRounds += rounds;
      EEPROM.write(0, allRounds);
      Serial.println("round added");
    }
  }
}
int encoder::mmGet(){return mm;}
