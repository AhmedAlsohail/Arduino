int pin2=2;
int pin3=3;
int pin4=4;
int pin5=5;

int num = 0;
void setup() {
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
}

void loop() {
  while(true){
    showBinary(num);
    num++;
    if(num > 15)
      num = 0;
    delay(1000);
  }
}

void showBinary(int decimal){
    int binary = 0, remainder, product = 1;
    // Convert to binary
    while (decimal != 0) {
      remainder = decimal % 2;
      binary = binary + (remainder * product);
      decimal = decimal / 2;
      product *= 10;
      }
      // Check first digit and turn on/off pin5.
      if(binary%10 > 0){
        digitalWrite(pin5, HIGH);
      }else{
        digitalWrite(pin5, LOW);
      }
    
    // Go to next digit
      binary=binary/10;
  
    // Check second digit and turn on/off pin4.
    if(binary%10 > 0){
      digitalWrite(pin4, HIGH);
    }else{
      digitalWrite(pin4, LOW);
    }
    
    // Go to next digit
      binary=binary/10;
      
    // Check thid digit and turn on/off pin3.
    if(binary%10 > 0){
      digitalWrite(pin3, HIGH);
    }else{
      digitalWrite(pin3, LOW);
    }
    
    // Go to next digit
      binary=binary/10;
  
    // Check forth digit and turn on/off pin2.
    if(binary%10 > 0){
      digitalWrite(pin2, HIGH);
    }else{
      digitalWrite(pin2, LOW);
    }  
}
