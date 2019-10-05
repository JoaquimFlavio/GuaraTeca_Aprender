//Copyright 2017 Joaquim Fl�vio Almeida Quirino Gomes, D�mis Carlos ----*
//Fonseca Gomes, Marcos Dias da Concei��o e Diego de Castro Rodrigues---*
//----------------------------------------------------------------------*
//Este arquivo � parte da Biblioteca de Fun��es Guar�Teca---------------*
//A Guar�Teca � um software livre; voc� pode redistribu�-lo e/ou--------* 
//modific�-lo sob os termos da Licen�a P�blica Geral GNU como publicada-*
//pela Funda��o do Software Livre (FSF); na vers�o 3 da Licen�a,--------*
//ou (a seu crit�rio) qualquer vers�o posterior.------------------------*
//
//Este programa � distribu�do na esperan�a de que possa ser �til,-------* 
//mas SEM NENHUMA GARANTIA; sem uma garantia impl�cita de ADEQUA��O-----*
//a qualquer MERCADO ou APLICA��O EM PARTICULAR. Veja a-----------------*
//Licen�a P�blica Geral GNU para mais detalhes.-------------------------*
//
//Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU junto---*
//com este programa. Se n�o, veja <http://www.gnu.org/licenses/>--------*

#include <GuaraTeca_Aprender.h> 

Led::Led(uint8_t pin_adquiri){
    _pino = pin_adquiri;
    pinMode(_pino, OUTPUT);
}

void Led::liga(float temp){
    digitalWrite(_pino , HIGH);
    delay(temp);
}
void Led::desliga(float temp){
    digitalWrite(_pino , LOW);
    delay(temp);

}
//--------------------------------------------------------------
caixaSom::caixaSom(uint8_t pino){
    _pino = pino;
    Buzzer::iniciaBuzzer(pino);
}
void caixaSom::apita(int tempo){
    Buzzer::beepSimples(_pino, tempo);
}
void caixaSom::toque(int frequencia, int tempo){
    Buzzer::beep(_pino, frequencia, tempo);
}
void caixaSom::musica(uint8_t opc){
    switch(opc){
        case 1:
            Buzzer::mario(_pino);
        break;
        case 2:
            Buzzer::marcha(_pino);
        break;
    }
}
//--------------------------------------------------------------
Botao::Botao(uint8_t pino){
    _pino = pino;
    pinMode(_pino, INPUT);
}
int Botao::estado(){
    return analogRead(_pino);
}
//--------------------------------------------------------------
Sensor_temperatura::Sensor_temperatura(uint8_t pino) : SensorDHT(pino, 1){}

float Sensor_temperatura::temperatura(){
    SensorDHT::leitura_temperatura();
}
float Sensor_temperatura::umidade(){
    SensorDHT::leitura_umidade();   
}
//--------------------------------------------------------------
Sensor_ultrassonico::Sensor_ultrassonico(uint8_t pino1, uint8_t pino2) : SensorUltrassonico(){
    _pino1 = pino1;
    _pino2 = pino2;

    SensorUltrassonico::iniciaSensorUltrassonico(_pino1, _pino2);    
}
int Sensor_ultrassonico::leitura(){
    return SensorUltrassonico::leitura(_pino1, _pino2);
}
//--------------------------------------------------------------
Sensor_linha::Sensor_linha(uint8_t pino) : SensorRefletancia(){
    _pino = pino;

    SensorRefletancia::iniciaSensorRefletancia(_pino);
}
int Sensor_linha::leitura(){
    return SensorRefletancia::leitura(_pino);
}
//--------------------------------------------------------------
Servo_motor::Servo_motor(uint8_t pino){
    _pino = pino;

    Servo::iniciaServo(_pino);
}
void Servo_motor::posicao(int x){
    Servo::vaPara(_pino, x);
}
//--------------------------------------------------------------
Motor_shield::Motor_shield(uint8_t porta) : MotorShield(){
    _porta = porta;

    MotorShield::iniciaMotorShield();
    MotorShield::controleDeCorrente(_porta, 255);
}
Motor_shield::Motor_shield(uint8_t p1, uint8_t p2) : MotorShield(){
    _porta = p1;
    _porta2 = p2;

    MotorShield::iniciaMotorShield();
    MotorShield::controleDeCorrente(_porta, 255);
    MotorShield::controleDeCorrente(_porta2, 255);
    V1 = 255;
    V2 = 255;
}
void Motor_shield::frente(float temp){
    MotorShield::sentido1(_porta);
        MotorShield::sentido1(_porta2);
    if (temp > 0.0){
        delay(temp*1000);
        para();
    }
}
void Motor_shield::esquerda(float temp){
    if (temp > 0.0){
        MotorShield::sentido1(_porta);
        MotorShield::sentido2(_porta2);
        delay(temp*1000);
        para();
    }else{
        MotorShield::sentido1(_porta);
        MotorShield::controleDeCorrente(_porta2, (((V2-5)*255)/100));
        MotorShield::sentido2(_porta2);
        MotorShield::controleDeCorrente(_porta2, ((V2*255)/100));
    }
}
void Motor_shield::direita(float temp){
    if (temp > 0.0){
        MotorShield::sentido2(_porta);
        MotorShield::sentido1(_porta2);
        delay(temp*1000);
        para();
    }else{
        MotorShield::controleDeCorrente(_porta, (((V1-5)*255)/100));
        MotorShield::sentido2(_porta);
        MotorShield::sentido1(_porta2);
        MotorShield::controleDeCorrente(_porta, ((V1*255)/100));
    }
}
void Motor_shield::tras(float temp){
    MotorShield::sentido2(_porta);
    MotorShield::sentido2(_porta2); 
    if (temp > 0.0){
        delay(temp*1000);
        para();
    }
}
void Motor_shield::para(){
    MotorShield::controleDeCorrente(_porta, (((V1-20)*255)/100));
    MotorShield::controleDeCorrente(_porta2, (((V2-10)*255)/100));
    MotorShield::trava(_porta);
    MotorShield::trava(_porta2);
    MotorShield::controleDeCorrente(_porta, (((V1)*255)/100));
    MotorShield::controleDeCorrente(_porta2, (((V2)*255)/100));
}

void Motor_shield::horario(unsigned int temp){
    MotorShield::sentido1(_porta);
    //delay(temp);
    //MotorShield::trava(_porta);
}
void Motor_shield::anti_horario(unsigned int temp){
    MotorShield::sentido2(_porta);
    //delay(temp);
    //MotorShield::trava(_porta);
}
void Motor_shield::velocidade(unsigned int velocidade){
    MotorShield::controleDeCorrente(_porta, ((velocidade*255)/100));
    V1 = V2 = velocidade;
}