#define DEBUG 0
class RGB
{
    private:
        int redPin,grnPin,bluPin;
        long start_Val[3], ob_Val[3];
        int step;
        int delay_time, stop_time;

    public:
        RGB(int redPin,int grPin,int bluPin, int delay_time, int stop_time);
        void update(void);
        void nextColor(int r, int g, int b);
        void nextColor(void);
            

};

        RGB::RGB(int redPin,int grPin,int bluPin, int delay_time, int stop_time): redPin (redPin), grnPin (grnPin), bluPin (bluPin), delay_time (delay_time), stop_time (stop_time)
        {
          pinMode(redPin, OUTPUT);   // sets the pins as output
          pinMode(grnPin, OUTPUT);   
          pinMode(bluPin, OUTPUT); 

            for (int i=0;i<3;i++)
            {
                start_Val[i]=0; ob_Val[i]= 0; 
            }
            step=0;
            nextColor();
        };
        
        void RGB::update(void)
        {
           if (++step >255)
           {
               nextColor();
               delay(stop_time);
           }
#if DEBUG
           
           Serial.print("Start: ");Serial.print(start_Val[0]);Serial.print(" ");Serial.print(start_Val[1]);Serial.print(" ");Serial.print(start_Val[2]);Serial.print(" ");
           
           Serial.print("ob: ");Serial.print(ob_Val[0]);Serial.print(" ");Serial.print(ob_Val[1]);Serial.print(" ");Serial.print(ob_Val[2]);Serial.print(" ");
           Serial.print("Step: "); Serial.print(step);Serial.print(" ");
          Serial.print( (start_Val[0]+(ob_Val[0]-start_Val[0])*step/255));Serial.print(" ");
          Serial.print( (start_Val[1]+(ob_Val[1]-start_Val[1])*step/255));Serial.print(" ");
          Serial.print( (start_Val[2]+(ob_Val[2]-start_Val[2])*step/255));Serial.println(" ");
#endif
           analogWrite(redPin, start_Val[0]+(ob_Val[0]-start_Val[0])*step/255);
           analogWrite(grnPin, start_Val[1]+(ob_Val[1]-start_Val[1])*step/255);
           analogWrite(bluPin, start_Val[2]+(ob_Val[2]-start_Val[2])*step/255);
           delay(delay_time);

        };
         void RGB::nextColor(int r, int g, int b)
        {
            step=0;
            start_Val[0]=ob_Val[0];
            start_Val[1]=ob_Val[1];
            start_Val[2]=ob_Val[2];
            ob_Val[0]=r;
            ob_Val[1]=g;
            ob_Val[2]=b;

        };
/*
       void RGB::nextColor(void)
        {
            step=0;
            start_Val[0]=ob_Val[0];
            start_Val[1]=ob_Val[1];
            start_Val[2]=ob_Val[2];
            ob_Val[0]=random(256);
            ob_Val[1]=random(256);
            ob_Val[2]=random(256);            
        };
*/
       void RGB::nextColor(void)
        {
            step=0;
            start_Val[0]=ob_Val[0];
            start_Val[1]=ob_Val[1];
            start_Val[2]=ob_Val[2];
            int rand= random(8);
            switch(rand)
            {
            case 0:
                ob_Val[0]=255;ob_Val[1]=0;ob_Val[2]=0;
                break;
            case 1:
                ob_Val[0]=0;ob_Val[1]=255;ob_Val[2]=0;
                break;
            case 2:
                ob_Val[0]=0;ob_Val[1]=0;ob_Val[2]=255;
                break;
            case 3:
                ob_Val[0]=255;ob_Val[1]=255;ob_Val[2]=0;
                break;
            case 4:
                ob_Val[0]=255;ob_Val[1]=0;ob_Val[2]=255;
                break;
            case 5:
                ob_Val[0]=0;ob_Val[1]=255;ob_Val[2]=255;
                break;
            default:
                ob_Val[0]=random(256);
                ob_Val[1]=random(256);
                ob_Val[2]=random(256);            
        }

        };


int redPin = 9;   // Red LED,   connected to digital pin 9
int grnPin = 10;  // Green LED, connected to digital pin 10
int bluPin = 11;  // Blue LED,  connected to digital pin 11



RGB lampada(redPin,grnPin,bluPin,30,1000);
void setup()
{
#if DEBUG
    Serial.begin(9600);
#endif
}


void loop()
{
  int r = map( analogRead(A2), 0, 1023, 0, 255);
  int g = map( analogRead(A3), 0, 1023, 0, 255);
  int b = map( analogRead(A4), 0, 1023, 0, 255);
if (r <20) r=0;
if (g <20) g=0;
if (b <20) b=0;

if ((r < 20) && (g<20) && (b <20))
  {
   lampada.update();
  } 
 else 
 {
  analogWrite(9,r);
  analogWrite(10,g);
  analogWrite(11,b);
  delay(50);
  }
  

}


