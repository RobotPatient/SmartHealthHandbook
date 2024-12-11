// --- Initialization Functions ---
void initializeSerial(int baudrate = 115200) {
  Serial.begin(baudrate);   // Initialize Serial for debugging
  Serial.println("SDP Sensor Initialized...");
}

void initializeI2C() {
  Wire.begin();         // Initialize I2C communication
}

// --- Measurement Control Functions ---
bool shouldStartMeasurement(float differentialPressure) {
  return !isMeasuring && differentialPressure > PRESSURE_THRESHOLD;
}

void startMeasurement() {
  isMeasuring = true;
  measurementStartTime = millis();
  integratedVolume = 0.0;  // Reset integrated volume
  lastUpdateTime = millis();  // Initialize update time
  Serial.println("Measurement started...");
}

bool shouldContinueMeasurement(float differentialPressure) {
  return differentialPressure > PRESSURE_THRESHOLD;
}
