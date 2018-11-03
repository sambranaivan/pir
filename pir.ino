
unsigned long now;//tiempo de espera
unsigned long espera;


///pines
#define pinPrecencia 4
#define pinLuz 2
#define pinRele 3
#define led 13


void setup() {
  pinMode(4,INPUT);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
  now = millis();
  espera = 10000;//10 minutos
}

void loop() {

if(presencia())
{
  Serial.println("Presencia Detectada");  
  digitalWrite(5,HIGH);
  now = millis();  
}
else
{
  digitalWrite(5,LOW);
  Serial.println("no");  
  if(timer())
  {
    Serial.println("Tiempo Cumplido");  
    if(luzPrendida())
    {
      // now = millis();
      toggleRele();  
    }
    else
    {
      now = millis();
    }
  }
 

}

delay(100);
   
}

bool timer()
{
  unsigned long diff = (millis() - now);
  
  Serial.print(diff);
  Serial.print("-->");
  Serial.println(espera);
  if((millis() - now) >= espera)
  {
      return true;    
    }
    else{
      return false;
      }

}

bool presencia(){

  return digitalRead(pinPrecencia);
  }

bool luzPrendida()
{
  if(!digitalRead(pinLuz))
  {
    Serial.println("Luz Prendida");
  }
  else
  {
    Serial.println("Apagada");
  }
  return !digitalRead(pinLuz);
}

bool luzApagada()
{
  return digitalRead(pinLuz);
}

void prenderLuz()
{
  toggleRele();
}
void apagarLuz()
{
  toggleRele();
}

void toggleRele()
{
  digitalWrite(pinRele,!digitalRead(pinRele));
}
