#include "display.h"
#include "encoder.h"
#define START 11
#define END 12

encoder enc = encoder(8,15,400);
Display dis = Display();
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("ON");
}

void loop() {
  if(digitalRead(START)){
    dis.show(0,"mesured lenght: ") ;
    dis.show(12,1,"mm") ;
    while(digitalRead(!END)){
      enc.Run();
      dis.show(1,String(enc.mmGet())) ;

    }
  }
  
}
