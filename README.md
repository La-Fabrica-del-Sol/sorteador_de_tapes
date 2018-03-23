# Sorteador de tapes d'ampolles
- **Què es?** Es tracta d'una divertida màquina que classifica les tapes d'ampolles de plàstic pel seu color.
- **Per a què serveix?**  Després que els taps d'ampolla hagin estat ordenats per color, es poden reciclar, es tallaran, es fongui i es converteixen en quelcom nou.
- **Puc jugar amb ell?** Per descomptat que pot! Accediu a la Fabrica del Sol i pregunteu-nos.
- **Puc crear el meu propi màquina de sorteador de tapes d'ampolla?** Sí! Vegeu les instruccions a continuació.

## Materials
**1. Arduino Nano**

El Arduino Nano és la versió més petita del popular microcontrolador. Podeu comprar Arduino Nano en línia per uns 5 euros.

![Arduino Nano](/img/arduino_nano.jpg)

**2. Color Sensor Module TCS230 (TCS3200)**

Aquest mòdul de sensor de color pot tenir diferents formes i colors, però la majoria d'ells han de ser compatibles amb aquest projecte. En línia costa entre 5 i 10 euros.

![Color Sensor](/img/color_sensor.jpg)

**3. Micro Servo Motor**

Aquests petits servomotors de 9 grams s'utilitzen sovint en cotxes RC, vaixells RC i avions RC. Solen costar menys de 5 euros.

![Micro Servo Motor](/img/servo.jpg)

## Connexions
Aquí inclourem un diagrama de les connexions utilitzant [Fritzing](http://fritzing.org/home/).

## Codi
Ara que hem muntat la màquina, hem d'indicar què fer amb el nostre codi. Podeu descarregar el codi fen clic dret i deseu-lo aquí- el sketch de Arduino es diu [sorteador_de_tapes_codi.ino](https://raw.githubusercontent.com/La-Fabrica-del-Sol/sorteador_de_tapes/master/sorteador_de_tapes_codi.ino). Per comprendre el que farà el nostre codi, podem escriure-ho de manera senzilla: això es diu pseudocodi
```
### Pseudocodi del Sorteador de tapes d'ampolles###
0. Moveu el braç cap a la posició inicial
1. Marqueu si hi ha un tap de l'ampolla en el braç davant del sensor 
2. Detecta el color del tap de l'ampolla 
3. Moure el braç amb el tap d'ampolla a la pila correcta

```

