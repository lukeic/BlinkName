int led = D6;
int isOn = true;
int defaultDelayBetweenLetters = 2000;

void setup() {
    pinMode(led, OUTPUT);

    Particle.function("sendMyNameInMorseCode", ledToggle);

    digitalWrite(led, LOW);
}

void loop() {}

int ledToggle(String command) {
    if (command == "on") {
        isOn = true;
        while (isOn) {
            sendMyName();
        }
        return 1;
    } else if (command == "off") {
        isOn = false;
        digitalWrite(led, LOW);
        return 0;
    } else {
        return -1;
    }
}

void sendDot() {
    digitalWrite(led, HIGH);
    delay(250);
    digitalWrite(led, LOW);
    delay(250);
}

void sendDash() {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(250);
}

void sendMyName() {
    // L
    sendDot();
    sendDash();
    sendDot();
    sendDot();
    delay(defaultDelayBetweenLetters);

    // U
    sendDot();
    sendDot();
    sendDash();
    delay(defaultDelayBetweenLetters);

    // K
    sendDash();
    sendDot();
    sendDash();
    delay(defaultDelayBetweenLetters);

    // E
    sendDot();
    delay(defaultDelayBetweenLetters);
}
