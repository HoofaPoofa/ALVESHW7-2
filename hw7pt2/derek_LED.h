#ifndef AAAA_h
#define AAAA_h
#include <string>
#include <sstream>
using namespace std;

class LED{
   private:
      string path;
      int number;
      virtual void writeLED(string filename, string value);
      virtual void removeTrigger();
   public:
      LED(int number);
      virtual void turnOn();
      virtual void turnOff();
      virtual void flash(string delayms);
      virtual void outputState();
      virtual ~LED();
      virtual void blink(int num);
};
#endif
