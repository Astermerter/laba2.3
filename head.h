#ifndef head
#define head
#include <vector>
using namespace std;
class Lamp {
public:
    Lamp();
    Lamp(float init_force, float init_power, float init_intensivity, int init_x, int init_y, int init_z);
    Lamp(const Lamp& another);

    void setForce(float input_force);
    void setPower(float input_power);
    void setIntensivity(float input_condition); 
    void setPosition(int x, int y, int z);

    float getForce() const;
    float getPower() const;
    float getintensivity() const;
    int* getPosition();

private:
    float force;    // 0-inf
    float power;    // 0-inf
    float intensivity; // 0-1

    int position[3];
};

class LedLamp
{
public:
    LedLamp();
    LedLamp(float red_force, float red_power, float red_intensivity,
        float green_force, float green_power, float green_intensivity,
        float blue_force, float blue_power, float blue_intensivity, int inp_x, int inp_y, int inp_z);
    LedLamp(const LedLamp& another);

    void setResultLamp();


    float getRedLampForce();
    float getGreenLampForce();
    float getBlueLampForce();

    float getRedLampPower();
    float getGreenLampPower();
    float getBlueLampPower();

    float getRedLampIntensivity();
    float getGreenLampIntensivity();
    float getBlueLampIntensivity();

    int* getRedLampPosition();
    int* getGreenLampPosition();
    int* getBlueLampPosition();

    void setRedLampForce(float red_force);
    void setGreenLampForce(float green_force);
    void setBlueLampForce(float blue_force);

    void setRedLampPower(float red_power);
    void setGreenLampPower(float green_power);
    void setBlueLampPower(float blue_power);

    void setRedLampIntensivity(float red_intensivity);
    void setGreenLampIntensivity(float green_intensivity);
    void setBlueLampIntensivity(float blue_intensivity);

    void setRedLampPosition(int* position);
    void setGreenLampPosition(int* position);
    void setBlueLampPosition(int* position);

    float getResultLampForce();
    float getResultLampPower();

    Lamp getResultLamp();

private:
    Lamp red_lamp;
    Lamp blue_lamp;
    Lamp green_lamp;

    Lamp result_lamp;
};

class LampMatrix
{
public:
    LampMatrix();
    LampMatrix(vector<Lamp> inp_lamps);
    LampMatrix(vector<LedLamp> inp_led_lamps);
    LampMatrix(vector<Lamp> inp_lamps, vector<LedLamp> inp_led_lamps);
    LampMatrix(vector<LedLamp> inp_led_lamps, vector<Lamp> inp_lamps);
    LampMatrix(LampMatrix& another);

    void addLamp(Lamp inp_lamps);
    void addLamp(LedLamp inp_led_lamps);

    Lamp getLampByCoordinates(int inp_x, int inp_y, int inp_z);

    void setTargetCoordinates(int inp_x, int inp_y, int inp_z);
    int* getTargetCoordinates();

    float findTotalPower();

    float findTotalIllumination();


private:
    vector<Lamp> lamps;
    int target_coordinates[3];
};

void test();


#endif // !head
