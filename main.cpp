#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main(){

    string cipherText = "TIPA MELZ EIBE LFYG HREI LSMS PSPT DRSJ ZNRA HBEE UIRU ZOQM GJYA SIAO JTGM NHTT BENE ZWGE TFGE QAEL YOVL OXEO NVDF CISX OQPR ESRN TTBE NGZL KSWB YAKC SJDB TXIU SARR OQZW DVOG LNSM CJAA SMNH LNXE NBWY SMCB WRDP AUTO MWOS ERTX HTTT RTRP GIMG EJDT NEST TSSY SJYM ZOIO RAUE IMLB KIWI LTVI ASPA KVEB OYZG QVLI MXEE HISL TIPA MELZ EIBE LFYG HREX PAUI SBWG DFRB TCOE TUPR MWJV DTZW TIPJ ZGQV LRCP OPXW DEVF DFKS WFCS ZRDM PAUI S";

// vector keys has a size of 83 elements, like possible keys for decryption
    vector<string>keys = {"utter", "descriptive", "caring", "pies", "drawer", "station", "soothe", "year", 
       "agreeable", "seemly", "button", "encourage", "reduce", "bed", "wave", "nosy", "zoo", "hateful", "flaky",      
         "work", "ear", "uneven", "cumbersome", "languid", "box", "devilish", "yawn", "ablaze", "lake", "harbor", "legs",
           "glow", "glossy", "cruel", "warn", "hard", "unique", "card", "hug", "tangible", "hook", "label", "exotic", "account", 
             "imagine", "grain", "tranquil", "book", "pickle", "whistle", "sack", "scissors", "trashy", "puzzled", "bottle", "smile",
               "neighborly", "eatable", "admit", "picayune", "type", "fast", "shy", "anger", "open", "add", "curly", "free", "aftermath",
                  "cherry", "daily", "heal", "rose", "abhorrent", "short", "fine", "guarded", "vase", "fascinated", "fresh", "chickens", "mine", "stare"};

// run a quick for loop to remove the spaces between the cipherText since the letters have been places into groups of 4 so that the word breaks are disguised
    string updated_cipherText; // empty string to store cipherText without spaces
    for(int i = 0; i < cipherText.size(); i++){
        if(cipherText.at(i) != ' '){
            updated_cipherText = updated_cipherText + cipherText.at(i);
        }
    }

// Step 1 : A frequency analysis showing the counts of every letter of our team's encrypted text
/***********
  Some ideas were taken from a youtube video:
  CodeWithBK
  https://youtu.be/8Sl92uxK9Ac?si=9IIpkZV9OfTUyExx
  Created: April, 2024
***********/

    vector<int> frequency(26, 0); // All 26 elements with a default value of 0
    for(int i = 0; i < updated_cipherText.size(); i++){
        if(isalpha(updated_cipherText.at(i))){
            char x = updated_cipherText.at(i);
            frequency.at(x - 'A')++;
        }
    }

    cout << "A frequency analysis showing the counts of every letter of our team's encrypted text: " << endl;
    for(int i = 0; i < 26; i++){
        cout << char('A' + i) << " : " << frequency.at(i) << endl;
    }
    cout << endl;

// Step 2 and 3 : the correct original (decrypted) English plaintext and best key
    string correctText, correctKey; // stores the best decrypted text and key
    int highestScore = 0;  // no key tested yet
    bool firstKey = true; // goal is to loop though every possible keys, haven't processed any keys yet

// Boolean works better since we have to check each keys. And using the concept of score, when firstKey = false, we can compare it
    for(int k = 0; k < keys.size(); k++){
        string currentKey = keys.at(k); // basically we have a container that holds whatever current key being tested
        string decryption; // This will hold the result of decryption with current key

        for(int i = 0; i < updated_cipherText.size(); i++){ // inner loop decrypts each character
            char firstLetter = updated_cipherText.at(i); // basically it gets the current cipherText char
            char key = currentKey.at(i % currentKey.size()); // this is the following individual key character, which stays within 0 1 2 3 4, so it has a fixed sequence

// formula : (C - K + 26) % 26
            int val = (firstLetter - 'A' - (key - 'a') + 26) % 26;
            decryption += 'A' + val;
        }

//  we gotta make sure decrypted text based on common English letters 
/* -----
This code was written with the aid of ChatGPT;
when prompted 'how to score the decrypted text based on English letter frequency?'
the generated text helped me write the following code:
accessed: Oct. 2025
 -------- */
        int currentScore = 0;
        for(int i = 0; i < decryption.size(); i++){
            char letter = decryption.at(i);
            if(letter == 'E' || letter == 'T' || letter == 'A' || letter == 'O' || letter == 'I' || letter == 'N'){
                currentScore = currentScore + 10;
            }
        }

        // need to find the best, now a basic comparison 
        if(firstKey || currentScore > highestScore){
            highestScore = currentScore;
            correctKey = currentKey;
            correctText = decryption;
            firstKey = false;
// here's how the code works;
/* we initialized highest score to 0, lets say current score is 120, so 120 greater than 0 which is true
knowledge from discrete mathematics, so we have( firstKey = true || score = true) and true || true is true, so our code executes
now highest score is 120, lets say utter, and correcttext will be decrypted text with "utter"
and then our first key becomes false;
*/
        }
    }

// creating final string to make text more readable
    string finalText; // empty string which will store the final decrypted text 
    for(int i = 0; i < correctText.size(); i++){ // because in line 98 we changed the decryption with correctText
        finalText = finalText + correctText.at(i);

// we will list the decrypted text with spaces with 4 character, just to read it better
         if(i % 4 == 3){
            finalText += ' ';
         }
    }

    cout << "The correct English plain text: " << finalText << endl;
    cout << "Best key: " << correctKey << endl;

    return 0;
}
