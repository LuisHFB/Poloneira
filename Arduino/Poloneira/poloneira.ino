//Entrada
#define sensB 2         //Borneira 20
#define sensM 3         //Borneira 21
#define sensA 4         //Borneira 22
#define sensIndu 5      //Borneira 12
//#define sensCap       //Borneira 11
#define sensPist1A 6    //Borneira 19
//#define sensPist1R    //Borneira 18
#define sensPist2A 7    //Borneira 15
//#define sensPist2R    //Borneira 14
#define sensPist3A 8    //Borneira 17
//#define sensPist3R    //Borneira 16
#define corA 9          //Borneira 10
#define corG 10         //Borneira 8
#define corB 11         //Borneira 9
#define ramp1 12        //Borneira 5
#define ramp2 13        //Borneira 6
#define ramp3 A0        //Borneira 7
#define encoder A1      //Borneira 23
#define botEsteira 1    //Botão para ligar/desligar a esteira

//Saída

#define pist1A A3       //Borneira 4
#define pist1R A2       //Borneira 3
#define pist2 A4        //Borneira 2
#define pist3 A5        //Borneira 1

int contGeralPecas;   //Contador geral de todas as peças que passaram pelos sensores presentes na descida da rampa

const int limiteGeralPecas = 20;

int buff[3][3] = { {2,1,2}, {2,1,1}, {3,3,3} }; // Buffer das posições que precisam ser preenchidas
int contadorRampa1 = 0;
int contadorRampa2 = 0;
int contadorRampa3 = 0;

bool resetar;        //Estado de reset do sistema
int i = 0;


int pecaAtual;
//cores corUltimaPecaSelecionada;


int contGeralPeca = 0;
int contB = 0 ;
int contM = 0 ;
int contA = 0 ;

int contRampa = 0;
int contPos = 0;




void setup() {
  Serial.begin(9600);
  pinMode (sensM, INPUT);
  pinMode (sensB, INPUT);
  pinMode (sensA, INPUT);
  pinMode (sensIndu, INPUT);
  pinMode (sensPist1A, INPUT);
  //pinMode (sensPist1R, INPUT);
  pinMode (sensPist2A, INPUT);
  //pinMode (sensPist2R, INPUT);
  pinMode (sensPist3A, INPUT);
  //pinMode (sensPist3R, INPUT);
  pinMode (ramp1, INPUT);
  pinMode (ramp2, INPUT);
  pinMode (ramp3, INPUT);
  pinMode (encoder, INPUT);
  pinMode (corA, INPUT);
  pinMode (corG, INPUT);
  pinMode (corB, INPUT);

  pinMode (pist1A, OUTPUT);
  pinMode (pist1R, OUTPUT);
  pinMode (pist2, OUTPUT);
  pinMode (pist3, OUTPUT);
  pinMode (botEsteira, OUTPUT);

  
    digitalWrite(pist1A, HIGH);
    digitalWrite(pist1R, LOW);
    digitalWrite(pist2, HIGH);
    digitalWrite(pist3, HIGH);





}

void loop()
{
 int leSensB;
 int leSensM;
 int leSensA;
 leSensB = digitalRead(sensB);
 pecaAtual=0;
  if (leSensB == HIGH)
  { //Levando em conta que este Opto, está associado com as cores amarela e azul (detectadas igualmente pelo sensor)
    while(leSensB == HIGH){ Serial.println("SensB"); delay(1); leSensB = digitalRead(sensB); }
    contGeralPeca++;
    pecaAtual++;
    i=0;
    while (i < 100 && pecaAtual == 1)
    {
      leSensM = digitalRead(sensM);
      if (leSensM == HIGH)
      {
        while(leSensM == HIGH){ Serial.println("SensM"); delay(1); leSensM = digitalRead(sensM); }
        pecaAtual++;
      }
      delay(10);
      i++;
    }
    i = 0;
    while (i < 100 && pecaAtual == 2)
    {
      leSensA = digitalRead(sensA);
      if (leSensA == HIGH)
      {
        while(leSensA == HIGH){ Serial.println("SensA"); delay(1); leSensA = digitalRead(sensA);  }
        pecaAtual++;
      }
      delay(10);
      i++;
    }
    i = 0;
    
    Serial.println(pecaAtual);
  }
  
  

  if (pecaAtual != 0 && contGeralPeca < 21)
  {

 
    if (buff[0][contadorRampa1] == pecaAtual && contadorRampa1 < 3)
    {
      digitalWrite(pist1A, LOW);
      digitalWrite(pist1R, HIGH);
      int leramp1=0;
      int leramp2=0;
      int leramp3=0;
      leramp1 = digitalRead(ramp1);
      leramp2 = digitalRead(ramp2);
      leramp3 = digitalRead(ramp3);
       Serial.println("Avanca Pistao 1");
      while (leramp1 == LOW || leramp1 == LOW  || leramp1 == LOW  )
      {
        leramp1 = digitalRead(ramp1);
        leramp2 = digitalRead(ramp2);
        leramp3 = digitalRead(ramp3);
      }
      
        contadorRampa1++;
        digitalWrite(pist1A, HIGH);
        digitalWrite(pist1R, LOW);
        pecaAtual = 0;
      Serial.println("Recua Pistao 1");
    }

    if (buff[1][contadorRampa2] == pecaAtual && contadorRampa2 < 3)
    {
      digitalWrite(pist2, LOW);
      int leramp1 = digitalRead(ramp1);
      int leramp2 = digitalRead(ramp2);
      int leramp3 = digitalRead(ramp3);
       Serial.println("Avanca Pistao 2");
      while (leramp1 == LOW || leramp1 == LOW  || leramp1 == LOW  )
      {
        leramp1 = digitalRead(ramp1);
        leramp2 = digitalRead(ramp2);
        leramp3 = digitalRead(ramp3);
      }
      
        contadorRampa2++;
        Serial.println("Recua Pistao 2");
        digitalWrite(pist2, HIGH);
        pecaAtual = 0;
      
    }



    if (buff[2][contadorRampa3] == pecaAtual && contadorRampa3 < 3)
    {
      digitalWrite(pist3, LOW);
      int leramp1 = digitalRead(ramp1);
      int leramp2 = digitalRead(ramp2);
      int leramp3 = digitalRead(ramp3);
      Serial.println("Avanca Pistao 3");
      while (leramp1 == LOW || leramp1 == LOW  || leramp1 == LOW  )
      {
        leramp1 = digitalRead(ramp1);
        leramp2 = digitalRead(ramp2);
        leramp3 = digitalRead(ramp3);
      }
      
        contadorRampa3++;
        Serial.println("Recua Pistao 3");
        digitalWrite(pist3, HIGH);
        pecaAtual = 0;
      
    }


  }


  
  else if(contGeralPeca >= 21)
  {
   Serial.println("FINISH HIM");
    digitalWrite(pist1A, LOW);
    digitalWrite(pist1R, HIGH);
    digitalWrite(pist2, LOW);
    digitalWrite(pist3, LOW);
  }
  
}
