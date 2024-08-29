//Autor: Enrico Araujo
//Carrega a biblioteca LiquidCrystal, biblioteca do LCD
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados pelo display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  //Define o tamanho do LCD
  lcd.begin(16, 2);
}
 
void loop()
{
  lcd.clear(); //Limpa a tela
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(2, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("AUTOR: Enrico Araujo");
  lcd.setCursor(6, 1);
  lcd.print("Hello World");
  delay(250);
    
  //Rolagem para a esquerda
  for (int posicao = 0; posicao < 8; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }    
  //Rolagem para a direita
  for (int posicao = 0; posicao < 6; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
}