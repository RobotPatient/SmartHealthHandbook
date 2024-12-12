/*
  Differential Pressure-Based Flow Measurement System
  ---------------------------------------------------
  
  "globalSettings.h" provides the globally defined attributes  

  Author: J.A. Korten
  Date: 12/11/2024
*/

// --- Sensor and Physical Constants ---
#define SDP_SENSOR_ADDRESS 0x25            // I2C address of the SDP sensor
const float AIR_DENSITY = 1.2;             // kg/m^3, approximate density of air
const float ORIFICE_AREA = 12.57e-6;       // m^2, area of the 4 mm diameter orifice
const float DISCHARGE_COEFFICIENT = 0.65;  // Typical value for orifice plates

const float PRESSURE_SENSOR_CONVERSION_FACTOR = 60.0 // Used to convert raw sensor data to Pascals (adjust for your sensor)

// --- Threshold and Timing ---
const float PRESSURE_THRESHOLD = 5.0;      // in Pa, start measurement if pressure exceeds this (needs calibration)

// --- Timing and Timekeeping ---
unsigned long lastUpdateTime = 0;          // Time of the last update (ms)
unsigned long lastLoopTime = 0;            // Time of the last loop iteration (ms)
const unsigned long LOOP_INTERVAL = 10;    // ms, loop interval to control frequency

// --- Measurement Variables ---
bool isMeasuring = false;                  // Flag to indicate if measurement is active
unsigned long measurementStartTime = 0;    // Start time of current measurement
float integratedVolume = 0.0;              // Integrated volume (mL)

