#define RX_PIN 16
#define TX_PIN 17

String receivedString;
char strData[20];   // For string part
float floatData;
int intData;

void parseData(String data) {
    // Copy data to a modifiable buffer
    char buf[data.length() + 1];
    data.toCharArray(buf, sizeof(buf));

    // Extract values
    sscanf(buf, "%[^,],%f,%d", strData, &floatData, &intData);

    // Print extracted data
    Serial.println("Received Data:");
    Serial.print("String: "); Serial.println(strData);
    Serial.print("Float: "); Serial.println(floatData, 2);
    Serial.print("Integer: "); Serial.println(intData);
}

void setup() {
    Serial.begin(115200);  // Debug output
    Serial2.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
}

void loop() {
    if (Serial2.available()) {
        receivedString = Serial2.readStringUntil('\n');  // Read incoming line
        parseData(receivedString);
    }
}
