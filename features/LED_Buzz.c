#include "pico/stdlib.h"

// Função para iniciar os LEDS e Buzzer
void initLed(const uint gpio[3], const uint buzz)
{
    for (uint i = 0; i < 3; i++)
    {
        gpio_init(gpio[i]);
        gpio_set_dir(gpio[i], GPIO_OUT);
        gpio_put(gpio[i], 0);
    }
    gpio_init(buzz);
    gpio_set_dir(buzz, GPIO_OUT);
    gpio_put(buzz, 0);
}

// Função para ligar os LEDS e Buzzer
void ligaGPIO(uint gpio)
{
    gpio_put(gpio, 1);
}

// Exibe uma mensagem informativa inicial no terminal
void menu()
{
    printf("\t## Acionamento de LED e Buzzer pelo Teclado 4x4 ##\n");
    printf("Possui os seguintes comandos:\n");
    printf("1 - Aperte A para ligar o LED Azul\n");
    printf("2 - Aperte B para ligar o LED Rosa\n");
    printf("3 - Aperte C para ligar o LED Roxo\n");
    printf("4 - Aperte D para ligar o Buzzer\n");
    printf("5 - Aperte * para acionar o efeito de piscar nos LEDs\n");
    printf("6 - Aperte # para ativar o Buzzer por 1 segundo\n");
    printf("7 - Aperte 2 para ligar o LED Azul e LED Rosa\n");
    printf("8 - Aperte 3 para ligar o LED Azul, LED Rosa e LED Rosa\n");
    printf("9 - Aperte 4 para ligar o LED Azul e LED Roxo\n");
    printf("10 - Aperte 5 para ligar o LED Rosa e LED Roxo\n");
    printf("Obs: É necessário segurar a tecla por alguns segundos até que o comando seja registrado\n");
}

// Função para gerar um tom no buzzer
void buzzer_tone(uint gpio, int duration_ms, int frequency_hz)
{
    for (int i = 0; i < duration_ms * frequency_hz / 1000; i++)
    {
        gpio_put(gpio, 1); // Liga o buzzer
        busy_wait_us(500000 / frequency_hz); // Espera metade do período
        gpio_put(gpio, 0); // Desliga o buzzer
        busy_wait_us(500000 / frequency_hz); // Espera a outra metade
    }
}
