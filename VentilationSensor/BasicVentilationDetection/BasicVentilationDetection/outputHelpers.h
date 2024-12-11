/*
  Differential Pressure-Based Flow Measurement System
  ---------------------------------------------------
  
  "outputHelpers.h" provides the globally defined attributes  

  Author: J.A. Korten
  Date: 12/11/2024
*/

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