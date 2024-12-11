/*
  Differential Pressure-Based Flow Measurement System
  ---------------------------------------------------
  This program is designed to measure and compute airflow 
  through an orifice plate based on differential pressure readings.

  Features:
  - Uses an SDP sensor (e.g., SDP610) to measure differential pressure via I2C.
  - Calculates flow rate and integrates volume over time.
  - Automatically starts and stops measurements based on a pressure threshold.
  - Prints real-time and final results to the Serial Monitor.

  Dependencies:
  - Wire library for I2C communication. (This could be made more generic e.g. use SERCOM instead of the default Wire)
  - Sensor-specific constants for calibration and scaling.

  Handbook of Smart Health - Smart Manikin for Life Support Training

  Author: J.A. Korten
  Date: 12/11/2024
*/

#include <Wire.h>
#include "globalSettings.h"
#include "helperMethods.h"

void setup() {
  initializeSerial();
  initializeI2C();
}

void loop() {
  unsigned long currentTime = millis();

  if (isItTimeToMeasure(currentTime)) {
    lastLoopTime = currentTime;
    float differentialPressure = readDifferentialPressure();

    if (shouldStartMeasurement(differentialPressure)) {
      startMeasurement();
    }

    if (isMeasuring) {
      if (shouldContinueMeasurement(differentialPressure)) {
        updateMeasurement(differentialPressure);
      } else {
        stopMeasurement();
      }
    }
  }
}



