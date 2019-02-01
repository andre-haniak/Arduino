#include <VirtualWire.h>
 
String mensagem;
 
void setup()
{
  Serial.begin(9600);
  vw_set_tx_pin(8);
  vw_setup(2000);   
  Serial.println("Digite o texto que deseja ENVIAR...");
}
 
void loop()
{
  char data[40];
  int numero;
  if (Serial.available() > 0)
  {
    numero = Serial.readBytesUntil (13,data,40);
    data[numero] = 0;
    Serial.print("Valor Enviado: ");
    Serial.print(data);
    Serial.print(" Numero de Caracteres : ");
    Serial.println(strlen(data));
    send(data);
  }  
} 
 
void send (char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx(); 
}
