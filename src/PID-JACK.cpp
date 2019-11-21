#include "PID-JACK.h"
#include "OvenTemp.h"


OvenState ovenState = OvenState_OFF;

void PID::reset()
{
  totalError=0;
  lastError=0;
  lastTimestamp=millis()-100;
}

double PID::get(double input)
{
    double dt=(millis()-lastTimestamp)/1000.0;
    if(dt<10)
    {
        dt=10;
    }
    lastTimestamp=millis(); 
    
    double error=target-input;
    totalError+=error*dt;
    double dError=(error-lastError)/dt;
    lastError=error;

    double out = kp*(error+ki*totalError+kd*dError);
    out+=127;
    if(out>255)
    {
      out=255;
    }
    else if(out<0)
    {
      out=0;
    }
    return out;
}

void PID::pidLoop()
{
  double out = get(ovenTemp());
  if (ovenState == OvenState_ON)
  {
    setOvenPower((int)out);
  }
  else
  {
    setOvenPower(0);
  }
}