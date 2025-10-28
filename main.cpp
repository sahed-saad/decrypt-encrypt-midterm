#include <iostream>
#include <vector>
using namespace std;

int main() {

  string encryptedText =
      "TIPA MELZ EIBE LFYG HREI LSMS PSPT DRSJ ZNRA HBEE UIRU ZOQM GJYA "
      "SIAO JTGM NHTT BENE ZWGE TFGE QAEL YOVL OXEO NVDF CISX OQPR ESRN TTBE "
      "NGZL KSWB YAKC SJDB TXIU SARR OQZW DVOG LNSM CJAA SMNH LNXE NBWY SMCB "
      "WRDP AUTO MWOS ERTX HTTT RTRP GIMG EJDT NEST TSSY SJYM ZOIO RAUE "
      "IMLB KIWI LTVI ASPA KVEB OYZG QVLI MXEE HISL TIPA MELZ EIBE LFYG HREX "
      "PAUI SBWG DFRB TCOE TUPR MWJV DTZW TIPJ ZGQV LRCP OPXW DEVF DFKS "
      "WFCS ZRDM PAUI S";


  vector<int> freq(26, 0);

  
  for (int i = 0; i < encryptedText.size(); i++) {
    char eachLetter = encryptedText.at(i);
    if (isalpha(eachLetter)) {
      freq.at(eachLetter - 'A')++;
    }
  }

  
  cout << "Letter frequencies in ciphertext: " << endl;
  for (int i = 0; i < 26; i++) {
    cout << char('A' + i) << ": " << freq.at(i) << endl;
  }

  cout << endl;

  return 0;
}
