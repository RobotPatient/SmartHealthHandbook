// --- Sensor and Physical Constants ---
#define SDP_SENSOR_ADDRESS 0x25  // I2C address of the SDP sensor
const float AIR_DENSITY = 1.2;  // kg/m^3, approximate density of air
const float ORIFICE_AREA = 12.57e-6;  // m^2, area of the 4 mm diameter orifice
const float DISCHARGE_COEFFICIENT = 0.65;  // Typical value for orifice plates

// --- Threshold and Timing ---
const float PRESSURE_THRESHOLD = 5.0;  // Pa, start measurement if pressure exceeds this
const unsigned long LOOP_INTERVAL = 10;  // ms, loop interval to control frequency

// --- Measurement Variables ---
bool isMeasuring = false;         // Flag to indicate if measurement is active
unsigned long measurementStartTime = 0;  // Start time of current measurement
float integratedVolume = 0.0;     // Integrated volume (mL)
unsigned long lastUpdateTime = 0;  // Time of the last update (ms)
unsigned long lastLoopTime = 0;    // Time of the last loop iteration (ms)