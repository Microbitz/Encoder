volatile int IRQcount;
volatile int IRQcount0;
int pin = 12;
int pin_irq = 0; //IRQ that matches to pin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  attachInterrupt(pin_irq, IRQcounter, FALLING);
}

void IRQcounter() {
  IRQcount++;
  IRQcount0 = map(IRQcount, 0 , 518, 0 , 360);
  if (IRQcount == 518) {
    IRQcount = 0;
  }
}

void loop() {
  int result = IRQcount0;
  if (result<10){
    Serial.print("00");
    goto sendd;
    }
    if (result<100){
    Serial.print("0");
    }
  sendd:
  Serial.print(result);
  Serial.println("X");
}
