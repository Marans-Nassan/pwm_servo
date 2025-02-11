# Controle de Movimento de Braço com PWM e Raspberry Pi Pico

## Descrição

Este projeto tem como objetivo controlar o movimento de um braço utilizando PWM (modulação por largura de pulso) em um Raspberry Pi Pico. O sistema ajusta a posição de um servo-motor de acordo com valores pré-definidos e movimenta o braço entre três posições utilizando interrupções e temporizadores.

## Objetivos

- Compreender o uso de PWM no controle de servo-motores.
- Aplicar interrupções e temporizadores no Raspberry Pi Pico para controlar o movimento do servo.
- Desenvolver um projeto prático para controle de movimento em sistemas embarcados.

## Componentes Utilizados

- Raspberry Pi Pico
- Servo-motor (controlado via PWM)
- Resistores (caso necessário para ajuste de sinal)

## Configuração de Hardware

### Pinos Utilizados

- **Servo-motor**:
  - Pino GPIO 22 (para controle do PWM)

## Instalação e Compilação

1. Configure o ambiente de desenvolvimento do Raspberry Pi Pico (SDK do Pico e CMake).
2. Clone este repositório.
3. Compile o código utilizando CMake e o SDK do Pico.
4. Carregue o arquivo `.uf2` gerado para o Raspberry Pi Pico.

## Funcionamento

- O sistema utiliza PWM para controlar a posição do servo-motor, movendo-o entre três posições predefinidas.
- Após a inicialização, o braço se move automaticamente entre essas posições por 5 segundos.
- O movimento do braço é feito em um loop contínuo, ajustando a posição de acordo com o limite inferior (`angmin`) e superior (`angmax`).

### Pinos e Funções

- **GPIO 22**: Controla o servo-motor via PWM.
- **Função `pwm_setup`**: Configura o PWM para o controle do servo-motor.
- **Função `pwm_acao`**: Ajusta o duty cycle do PWM para definir a posição do servo-motor.
- **Função `turn_off_callback`**: Alarme para alternar entre três posições do servo-motor (inicial, média e baixa).
- **Função `movimentacao`**: Controla o movimento contínuo do braço, alternando a posição do servo entre os valores de `angmin` e `angmax`.

## Como Usar

1. **Iniciar o sistema**: Ao ligar o Raspberry Pi Pico, o servo-motor será inicializado na posição definida por `nivel_inici`.
2. **Movimentação automática**: O braço se moverá automaticamente entre três posições predefinidas, alternando entre elas a cada 5 segundos.
3. **Movimento contínuo**: Após o alarme de 5 segundos, o braço começará a se mover entre os limites `angmin` e `angmax` de forma contínua.

## Motivação

Este projeto foi desenvolvido com o objetivo de aplicar conceitos de PWM e interrupções para o controle de dispositivos como servo-motores em microcontroladores, proporcionando uma maneira prática de compreender a movimentação de atuadores.

## Autor

Hugo Martins Santana (TIC370101267)

## Licença

Creative Commons Zero v1.0 Universal