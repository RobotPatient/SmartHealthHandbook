/*
  Differential Pressure-Based Flow Measurement System
  ---------------------------------------------------
  
  "initHelpers.h" provides the globally defined attributes  

  Author: J.A. Korten
  Date: 12/11/2024
*/

// --- Initialization Functions ---
void initializeSerial(int baudrate = 115200) {
  Serial.begin(baudrate);   // Initialize Serial for debugging
  Serial.println("SDP Sensor Initialized...");
}

void initializeI2C() {
  Wire.begin();         // Initialize I2C communication
}


