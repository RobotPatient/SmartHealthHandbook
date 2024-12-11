void updateMeasurement(float differentialPressure) {
  unsigned long currentTime = millis();
  float deltaTime = (currentTime - lastUpdateTime) / 1000.0;  // Convert ms to seconds
  lastUpdateTime = currentTime;

  float flowRate = calculateFlowRate(differentialPressure);  // mL/s
  integratedVolume += flowRate * deltaTime;  // Increment volume

  printMeasurementStatus(flowRate, integratedVolume);
}

void stopMeasurement() {
  isMeasuring = false;
  unsigned long elapsedTime = millis() - measurementStartTime;  // ms
  float elapsedSeconds = elapsedTime / 1000.0;  // Convert to seconds

  printFinalResults(integratedVolume, elapsedSeconds);
}

bool isItTimeToMeasure(unsigned long currentTime) {
  return (currentTime - lastLoopTime >= LOOP_INTERVAL);
}

// --- Sensor Reading Functions ---
float readDifferentialPressure() {
  Wire.beginTransmission(SDP_SENSOR_ADDRESS);
  Wire.write(0x00);  // Command to request pressure reading
  Wire.endTransmission();

  Wire.requestFrom(SDP_SENSOR_ADDRESS, 2);  // Request 2 bytes from the sensor

  if (Wire.available() >= 2) {
    int16_t rawPressure = Wire.read() << 8 | Wire.read();  // Combine MSB and LSB
    return rawPressure / 60.0;  // Convert raw sensor data to Pascals (adjust for your sensor)
  } else {
    Serial.println("Error: No data from sensor");
    return 0.0;
  }
}

// --- Calculation Functions ---
float calculateFlowRate(float differentialPressure) {
  if (differentialPressure <= 0) return 0.0;  // Handle non-physical negative pressure
  float velocity = sqrt(2 * differentialPressure / AIR_DENSITY);  // m/s
  float flowRate = DISCHARGE_COEFFICIENT * ORIFICE_AREA * velocity;  // m^3/s
  return flowRate * 1e6;  // Convert m^3/s to mL/s
}

// --- Output Functions ---
void printMeasurementStatus(float flowRate, float volume) {
  Serial.print("Flow Rate: ");
  Serial.print(flowRate);
  Serial.print(" mL/s, Integrated Volume: ");
  Serial.print(volume);
  Serial.println(" mL");
}

void printFinalResults(float volume, float elapsedTime) {
  Serial.println("Measurement stopped...");
  Serial.print("Total Volume: ");
  Serial.print(volume);
  Serial.println(" mL");
  Serial.print("Elapsed Time: ");
  Serial.print(elapsedTime);
  Serial.println(" seconds");
}