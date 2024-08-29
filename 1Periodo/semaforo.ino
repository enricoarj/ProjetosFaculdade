//Variaveis dos leds
int verde = 8;
int amarelo = 9;
int vermelho = 10;

//Porta utilizada
void setup () {
    pinMode(verde, OUTPUT);
    pinMode(amarelo, OUTPUT);
    pinMode(vermelho, OUTPUT);
}

//funcionamento dos leds
void loop(){
//liga o led amarelo por 2 segundos
    digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, HIGH);
    digitalWrite(verde, LOW);
    delay(2000);

//desliga o led amarelo e liga o vermelho por 5 segundos
    digitalWrite(amarelo, LOW);
    digitalWrite(vermelho, HIGH);
    delay(5000);

//desliga o led vermelho e liga o verde por 5 segundos
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, HIGH);
    delay(5000);
}
