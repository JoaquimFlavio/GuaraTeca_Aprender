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

#ifndef GuaraTeca_Aprender_H 
#define GuaraTeca_Aprender_H  

    #define Control_SensorDHT           Ativada
    #define Control_Buzzer              Ativada
    #define Control_SensorUltrassonico  Ativada
    #define Control_SensorRefletancia   Ativada
    #define Control_SensorUltrassonico  Ativada
    #define Control_PonteH              Ativada
    #define Control_MotorShield         Ativada
    #define Control_Servo               Ativada
    
#include <GuaraTeca_includes.h>

class Led{
    public:
        Led(uint8_t pin_adquiri);
        void liga(float temp = 0);
        void desliga(float temp = 0);
    private:
        uint8_t _pino;
};

class caixaSom : public Buzzer{
    public:
        caixaSom(uint8_t pino);
        void apita(int tempo);
        void toque(int frequencia, int tempo);
        void musica(uint8_t opc);
    private:
        uint8_t _pino;
};

class Botao{
    public:
        Botao(uint8_t pino);
        int estado();
    private:
        uint8_t _pino;
};

class Sensor_temperatura : public SensorDHT{
    public:
        Sensor_temperatura(uint8_t pino);
        float temperatura();
        float umidade();
};

class Sensor_ultrassonico : public SensorUltrassonico{
    public:
        Sensor_ultrassonico(uint8_t pino1, uint8_t pino2);//TP, EP
        int leitura();
    private:
        uint8_t _pino1, _pino2;
};

class Sensor_linha : public SensorRefletancia{
    public:
        Sensor_linha(uint8_t pino);
        int leitura();
    private:
        uint8_t _pino;
};

class Servo_motor : public Servo{
    public:
        Servo_motor(uint8_t pino);
        void posicao(int x);
    private:
        uint8_t _pino;
};

class Motor_shield : public MotorShield{
    public:
        Motor_shield(uint8_t porta);
        Motor_shield(uint8_t p1, uint8_t p2);
        void frente(float temp = 0);
        void esquerda(float temp = 0);
        void direita(float temp = 0);
        void tras(float temp = 0);
        void para();

        void horario(unsigned int temp);
        void anti_horario(unsigned int temp);
        void velocidade(unsigned int velocidade);
    private:
        uint8_t _porta;
        uint8_t _porta2;
        int V1, V2;
};

#endif 
