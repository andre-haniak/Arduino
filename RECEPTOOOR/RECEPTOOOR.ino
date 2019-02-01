#include <LiquidCrystal.h> // declara a utilização da biblioteca LiquidCrystal
#include <VirtualWire.h> // declara a utilização da biblioteca VirtualWire

#define Luz_Fundo  7


//cria um objeto tipo LiquidCrystal que chamei de "lcd" nos pinos citados:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  Serial.begin(9600);
lcd.begin(16, 2); // Iniciando o objeto "lcd" de 2 linhas e 16 colunas
pinMode(Luz_Fundo,OUTPUT); //define o pino como saída
digitalWrite(Luz_Fundo,HIGH); // Liga a luz do display.
 
     vw_set_rx_pin(6); // Define o pino 6 do Arduino como entrada 
//de dados do receptor
    vw_setup(2000);             // Bits por segundo
    vw_rx_start();    
}
 
void loop()
{
  uint8_t message[VW_MAX_MESSAGE_LEN];
  uint8_t msgLength = VW_MAX_MESSAGE_LEN;

  String msg;

  if (vw_get_message(message, &msgLength)) //Verifica se tem alguma mensagem disponível
  {
    
    for (int i = 0; i < msgLength; i++)
    {
      msg = msg + (char)message[i];
    }
  
  lcd.print(msg); 
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  lcd.clear();
   //Envia o texto entre aspas para o LCD
  lcd.print(msg);
  lcd.setCursor(0, 1);
  lcd.print("Dispositivo ON");

  msg = "";

  }



}


