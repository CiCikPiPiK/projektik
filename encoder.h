#ifndef ENCODER_H
#define ENCODER_H
#include <EEPROM.h>

class encoder{
  public:
  encoder(int INpin, int circuit,int maxImplsPR);
  int getInpuls();
  int getRounds();
  int getAllRounds();
  int mmGet();
  
  template <typename T>
  int getData(T unit){
    if(sizeof(T) == sizeof(double)){
      if(unit == 1){
        m = allRounds/circuit;
        return m;
      }
      if(unit == 10){
        cm = allRounds* 10;
        return cm;
      }
    }
    if(sizeof(T) == sizeof(String)){
      if(unit == "m"){
        m = allRounds/circuit;
        return m; 
      }
      if(unit == "cm"){
        cm = allRounds* 10;
        return cm;
      }
    }
  }
  
  void Run();

  private:
  int updateAll();
//units 
  int mm;
  int m;
  int cm;
//init values
  int maxImplsPR;
  int circuit;
  int INpin;
//data
  int inpuls;
  int allRounds;
  int rounds;
};

#endif
