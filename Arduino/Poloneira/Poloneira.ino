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

//#define endEsteira    //Borneira 13
//Saída

#define pist1A A2       //Borneira 4
#define pist1R A3       //Borneira 3
#define pist2 A4        //Borneira 2
#define pist3 A5        //Borneira 1

void setup() {
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
  //pinMode (corA, INPUT);
  //pinMode (corG, INPUT);
  //pinMode (corB, INPUT);
  //pinMode (endEsteira, INPUT);
  

  pinMode (pist1A, OUTPUT);
  pinMode (pist1R, OUTPUT);
  pinMode (pist2, OUTPUT);
  pinMode (pist3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
