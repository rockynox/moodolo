

// -------- PUSH_BUTTON -----------

const int greenButton = D0;
const int greenButtonScore = 3;
int greenButtonState;

const int blueGreenButton = D1;
const int blueGreenButtonScore = 2;
int blueGreenButtonState;

const int blueRedButton = D2;
const int blueRedButtonScore = 1;
int blueRedButtonState;

const int redButton = D3;
const int redButtonScore = 0;
int redButtonState;

// -------- SEVEN SEGMENT SETTING -----------

const int A = D4;
const int B = D5;
const int C = D6;
const int D = D7;
const int E = D8;
const int F = D9;
const int G = D10;

const int voteIndicatorCode = 10;

int tmpScore = 0;
int score = 0;
int numberOfVote = 0;

void setup() {
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(greenButton, INPUT);
    pinMode(blueGreenButton, INPUT);
    pinMode(blueRedButton, INPUT);
    pinMode(redButton, INPUT);


    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(LED_BUILTIN, LOW);

}

void loop() {

    if (isGreenPressed()) {
        tmpScore += greenButtonScore;
        numberOfVote++;
    }
    if (isBlueGreenPressed()) {
        tmpScore += blueGreenButtonScore;
        numberOfVote++;
    }
    if (isBlueRedPressed()) {
        tmpScore += blueRedButtonScore;
        numberOfVote++;
    }
    if (isRedPressed()) {
        tmpScore += redButtonScore;
        numberOfVote++;
    }

    // In millisecond
    delay(1000)

    //Display score
    if (isGreenPressed()) {
        delay(3000);
        if (isGreenPressed()) {
            computeScore();
            displayScore(score);
        }
    }

    //Reset score
    if (isRedPressed()) {
        delay(3000);
        if (isRedPressed()) {
            resetScore();
        }
    }
}

void resetScore() {
    tmpScore = 0;
    score = 0;
}

void computeScore() {
    score = 10 * tmpScore / (greenButtonScore * numberOfVote)
}

bool isGreenPressed() {
    if (digitalRead(greenButton) == 1) {
        return true;
    }
    return false;
}

bool isBlueGreenPressed() {
    if (digitalRead(blueGreenButton) == 1) {
        return true;
    }
    return false;
}

bool isBlueRedPressed() {
    if (digitalRead(blueRedButton) == 1) {
        return true;
    }
    return false;
}

bool isRedPressed() {
    if (digitalRead(redButton) == 1) {
        return true;
    }
    return false;
}

void displayScore(int num) {
    if (num == 0) {
        onA();
        onB();
        onC();
        onD();
        onE();
        onF();
        offG();
    } else if (num == 1) {
        onB();
        onC();
        offA();
        offD();
        offE();
        offF();
        offG();
    } else if (num == 2) {
        onA();
        onB();
        onG();
        onE();
        onD();
        offF();
        offC();
    } else if (num == 3) {
        onA();
        onB();
        onG();
        onC();
        onD();
        offE();
        offF();
    } else if (num == 4) {
        onF();
        onG();
        onB();
        onC();
        offA();
        offE();
        offD();
    } else if (num == 5) {
        onA();
        onF();
        onG();
        onC();
        onD();
        offB();
        offE();
    } else if (num == 6) {
        onA();
        onC();
        onD();
        onE();
        onF();
        onG();
        offB();
    } else if (num == 7) {
        onA();
        onB();
        onC();
        offD();
        offE();
        offF();
        offG();
    } else if (num == 8) {
        onA();
        onB();
        onC();
        onD();
        onE();
        onF();
        onG();
    } else if (num == 9) {
        onA();
        onB();
        onC();
        onF();
        onG();
        offE();
        offD();
    } else if (num == voteIndicatorCode) {
        onA();
        onB();
        onC();
        onF();
        onG();
        onE();
        offD();
    }
}

void onA() { digitalWrite(A, HIGH); }

void offA() { digitalWrite(A, LOW); }

void onB() { digitalWrite(B, HIGH); }

void offB() { digitalWrite(B, LOW); }

void onC() { digitalWrite(C, HIGH); }

void offC() { digitalWrite(C, LOW); }

void onD() { digitalWrite(D, HIGH); }

void offD() { digitalWrite(D, LOW); }

void onE() { digitalWrite(E, HIGH); }

void offE() { digitalWrite(E, LOW); }

void onF() { digitalWrite(F, HIGH); }

void offF() { digitalWrite(F, LOW); }

void onG() { digitalWrite(G, HIGH); }

void offG() { digitalWrite(G, LOW); }