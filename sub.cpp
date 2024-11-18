#include "head.h"
#include <iostream>
#include <assert.h>
#include <vector>
#include <cmath>
using namespace std;

Lamp::Lamp() {
    force = 0;
    power = 0;
    intensivity = 0;
    position[0] = 0; position[1] = 0; position[2] = 0;
}

Lamp::Lamp(float init_force, float init_power, float init_intensivity, int init_x, int init_y, int init_z) {
    if (init_force >= 0)
        force = init_force; 
    else 
        force = 0;
    if (init_power >= 0)
        power = init_power;
    else
        power = 0;
    if (init_intensivity >= 0)
        intensivity = init_intensivity;
    else
        intensivity = 0;

    position[0] = init_x; position[1] = init_y; position[2] = init_z;
}

Lamp::Lamp(const Lamp& another) {
    force = another.force;
    power = another.power;
    intensivity = another.intensivity;
    for (int i = 0; i < 3; ++i) {
        position[i] = another.position[i];
    }
}

void Lamp::setForce(float input_force) {
    if (input_force >= 0)
        force = input_force;
    else
        force = 0;
}

void Lamp::setPower(float input_power) {
    if (input_power >= 0)
        power = input_power;
    else
        power = 0;
}

void Lamp::setIntensivity(float input_intensivity) {
    if (input_intensivity >= 0)
        intensivity = input_intensivity;
    else
        intensivity = 0;
}

void Lamp::setPosition(int x, int y, int z)
{
    position[0] = x; position[1] = y; position[2] = z;
};

float Lamp::getForce() const {
    return force;
}

float Lamp::getPower() const {
    return power;
}

float Lamp::getintensivity() const {
    return intensivity;
}

int* Lamp::getPosition(){
    return position;
}

// ==========================================================================================================

LedLamp::LedLamp()
    :red_lamp(),
    blue_lamp(),
    green_lamp(),
    result_lamp()
{

}

LedLamp::LedLamp(float red_force, float red_power, float red_intensivity,
    float green_force, float green_power, float green_intensivity,
    float blue_force, float blue_power, float blue_intensivity, int inp_x, int inp_y, int inp_z)
    : red_lamp(red_force, red_power, red_intensivity, inp_x, inp_y, inp_z),
    blue_lamp(blue_force, blue_power, blue_intensivity, inp_x, inp_y, inp_z),
    green_lamp(green_force, green_power, green_intensivity, inp_x, inp_y, inp_z),
    result_lamp(0,0,0, inp_x, inp_y, inp_z)
{
    setResultLamp();
}

LedLamp::LedLamp(const LedLamp& another)
    : red_lamp(another.red_lamp),
    green_lamp(another.green_lamp),
    blue_lamp(another.blue_lamp),
    result_lamp(another.result_lamp)
{
    setResultLamp();
}

void LedLamp::setResultLamp()
{
    result_lamp.setForce(red_lamp.getForce() * red_lamp.getintensivity()
        + green_lamp.getForce() * green_lamp.getintensivity()
        + blue_lamp.getForce() * blue_lamp.getintensivity());

    result_lamp.setPower(red_lamp.getPower() * red_lamp.getintensivity()
        + green_lamp.getPower() * green_lamp.getintensivity()
        + blue_lamp.getPower() * blue_lamp.getintensivity());

    result_lamp.setIntensivity(1);
    result_lamp.setPosition(red_lamp.getPosition()[0], red_lamp.getPosition()[1], red_lamp.getPosition()[2]);
}

float LedLamp::getRedLampForce() { return red_lamp.getForce(); }
float LedLamp::getGreenLampForce() { return green_lamp.getForce(); }
float LedLamp::getBlueLampForce() { return blue_lamp.getForce(); }

float LedLamp::getRedLampPower() { return red_lamp.getPower(); }
float LedLamp::getGreenLampPower() { return green_lamp.getPower(); }
float LedLamp::getBlueLampPower() { return blue_lamp.getPower(); }

float LedLamp::getRedLampIntensivity() { return red_lamp.getintensivity(); }
float LedLamp::getGreenLampIntensivity() { return green_lamp.getintensivity(); }
float LedLamp::getBlueLampIntensivity() { return blue_lamp.getintensivity(); }

int* LedLamp::getRedLampPosition() { return red_lamp.getPosition(); }
int* LedLamp::getGreenLampPosition() { return green_lamp.getPosition(); }
int* LedLamp::getBlueLampPosition() { return blue_lamp.getPosition(); }

//========================================
//========================================
void LedLamp::setRedLampForce(float red_force) { red_force >= 0 ? red_lamp.setForce(red_force) : red_lamp.setForce(0); } // очень грустные вырожения, но мне бы было грустнее сели бы количество строк выросло в 4 раза =(
void LedLamp::setGreenLampForce(float green_force) { green_force >= 0 ? green_lamp.setForce(green_force) : green_lamp.setForce(0); } // их нужно чувствовать, они все +- одинаковы
void LedLamp::setBlueLampForce(float blue_force) { blue_force >= 0 ? blue_lamp.setForce(blue_force) : blue_lamp.setForce(0); } // если ставить значения ламп вручную, то обязательно в конце запустить функцию setResultLamp();

void LedLamp::setRedLampPower(float red_power) { red_power >= 0 ? red_lamp.setPower(red_power) : red_lamp.setPower(0); }
void LedLamp::setGreenLampPower(float green_power) { green_power >= 0 ? green_lamp.setPower(green_power) : green_lamp.setPower(0); }
void LedLamp::setBlueLampPower(float blue_power) { blue_power >= 0 ? blue_lamp.setPower(blue_power) : blue_lamp.setPower(0); }

void LedLamp::setRedLampIntensivity(float red_intensivity) { red_intensivity >= 0 or red_intensivity <= 1 ? red_lamp.setIntensivity(red_intensivity) : red_lamp.setIntensivity(0); }
void LedLamp::setGreenLampIntensivity(float green_intensivity) { green_intensivity >= 0 or green_intensivity <= 1 ? green_lamp.setIntensivity(green_intensivity) : green_lamp.setIntensivity(0); }
void LedLamp::setBlueLampIntensivity(float blue_intensivity) { blue_intensivity >= 0 or blue_intensivity <= 1 ? blue_lamp.setIntensivity(blue_intensivity) : blue_lamp.setIntensivity(0); }

void LedLamp::setRedLampPosition(int* position) { red_lamp.setPosition(position[0], position[1], position[2]); }
void LedLamp::setGreenLampPosition(int* position) { green_lamp.setPosition(position[0], position[1], position[2]); }
void LedLamp::setBlueLampPosition(int* position) { blue_lamp.setPosition(position[0], position[1], position[2]); }
//========================================
//========================================
float LedLamp::getResultLampForce() { return result_lamp.getForce(); }
float LedLamp::getResultLampPower() { return result_lamp.getPower(); }

Lamp LedLamp::getResultLamp() { return result_lamp; }

//================================================================================================================

LampMatrix::LampMatrix()
{
    lamps = std::vector<Lamp>();
    target_coordinates[0] = 0; target_coordinates[1] = 0; target_coordinates[2] = 0;
}

LampMatrix::LampMatrix(vector<Lamp> inp_lamps)
{
    lamps = inp_lamps;
    target_coordinates[0] = 0; target_coordinates[1] = 0; target_coordinates[2] = 0;
}
LampMatrix::LampMatrix(vector<LedLamp> inp_led_lamps)
{
    for (auto& lamp : inp_led_lamps) {
        lamps.push_back(lamp.getResultLamp());
    }
    target_coordinates[0] = 0; target_coordinates[1] = 0; target_coordinates[2] = 0;
}
LampMatrix::LampMatrix(vector<Lamp> inp_lamps, vector<LedLamp> inp_led_lamps)
{
    lamps = inp_lamps;
    for (auto& lamp : inp_led_lamps) {
        lamps.push_back(lamp.getResultLamp());
    }
    target_coordinates[0] = 0; target_coordinates[1] = 0; target_coordinates[2] = 0;
}
LampMatrix::LampMatrix(vector<LedLamp> inp_led_lamps, vector<Lamp> inp_lamps)
{
    lamps = inp_lamps;
    for (auto& lamp : inp_led_lamps) {
        lamps.push_back(lamp.getResultLamp());
    }
    target_coordinates[0] = 0; target_coordinates[1] = 0; target_coordinates[2] = 0;
}
LampMatrix::LampMatrix(LampMatrix& another)
{
    lamps = another.lamps;
    copy(another.target_coordinates, another.target_coordinates + 3, target_coordinates);
}



void LampMatrix::addLamp(Lamp inp_lamp)
{
    lamps.push_back(inp_lamp);
}

void LampMatrix::addLamp(LedLamp inp_ledlamp)
{
    lamps.push_back(inp_ledlamp.getResultLamp());
}

Lamp LampMatrix::getLampByCoordinates(int inp_x, int inp_y, int inp_z)
{
    for (auto& lamp : lamps) {
        auto pos = lamp.getPosition();
        if (pos[0] == inp_x && pos[1] == inp_y && pos[2] == inp_z)
            return lamp;
    }
    return Lamp();
}

void LampMatrix::setTargetCoordinates(int inp_x, int inp_y, int inp_z)
{
    target_coordinates[0] = inp_x; target_coordinates[1] = inp_y; target_coordinates[2] = inp_z;
}

float LampMatrix::findTotalPower()
{
    double total_power = 0;
    for (auto& lamp : lamps)
    {
        total_power += lamp.getPower() * lamp.getintensivity();
    }
    return total_power;
}

int* LampMatrix::getTargetCoordinates()
{
    return target_coordinates;
}

float LampMatrix::findTotalIllumination()
{
    float totalIllumination = 0;
    float illumination;

    for (auto& lamp : lamps)
    {
        float x = lamp.getPosition()[0] - target_coordinates[0];
        float y = lamp.getPosition()[1] - target_coordinates[1];
        float z = lamp.getPosition()[2] - target_coordinates[2];

        float distance = sqrt(x * x + y * y + z * z);
        
        if (distance != 0) {
            illumination = (lamp.getForce() * lamp.getintensivity()) / (distance * distance);
            
            totalIllumination += illumination;
        }
    }
    return totalIllumination;
}


void test() {
    const float epsilon = 0.0001f;
    LampMatrix matrix;
    assert(matrix.findTotalPower() == 0);
    assert(matrix.findTotalIllumination() == 0);

    vector<Lamp> lamps = { Lamp(10, 10, 0.5, 1, 1, 1), Lamp(20, 20, 0.7, 2, 2, 2) };
    LampMatrix matrix_lamps(lamps);

    assert(matrix_lamps.findTotalPower() == 19);
    assert(matrix_lamps.findTotalIllumination() == 34.0f / 12.0f);

    LedLamp led1(10, 10, 0.5, 15, 15, 0.6, 20, 20, 0.7, 1, 1, 1), led2(5, 5, 0.3, 10, 10, 0.4, 15, 15, 0.6, 2, 2, 2);
    vector<LedLamp> led_lamps = { led1, led2 };
    LampMatrix matrix_led_lamps(led_lamps);
    assert(matrix_led_lamps.findTotalPower() == 42.5); 
    assert(std::fabs(matrix_led_lamps.findTotalIllumination() - 126.5f / 12.0f) < epsilon);

    LampMatrix matrix_mixed(lamps, led_lamps);
    assert(matrix_mixed.findTotalPower() == 61.5f);
    assert(std::fabs(matrix_mixed.findTotalIllumination() - 126.5f / 12.0f - 34.0f / 12.0f) < epsilon);

    matrix.setTargetCoordinates(10, 10, 10);
    int* target_coords = matrix.getTargetCoordinates();
    assert(target_coords[0] == 10);
    assert(target_coords[1] == 10);
    assert(target_coords[2] == 10);

    LampMatrix matrix_copy(matrix);
    assert(matrix_copy.findTotalPower() == matrix.findTotalPower());
    assert(matrix_copy.findTotalIllumination() == matrix.findTotalIllumination());
    cout << "All Tests Passed =)" << endl;
}