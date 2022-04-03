import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class processing extends PApplet {



Serial myPort;
String  val;
String newval;

int mode = 0;
int modes = 1;

// --- Ultrasonic sensors stuff ---

float scale = 1;

public void setup()
{
    //String portName = Serial.list()[0];
    //print(portName);
    String portName = "COM4";
    myPort = new Serial(this, portName, 9600);

    
}

public void draw()
{
    background(255, 255, 255, 255);
    if (myPort.available() > 0)
    {
        newval = myPort.readStringUntil('\n');
    }
    else
    {
        //println("no port available");    
    }
    if (newval == null)
        println(val);
    else
    {
        val = newval;
        println(val);
    }

    if (mode == 0) //Ultrasonic sensors
    {
        surface.setTitle("Ultrasonic sensors viewer");
        fill(0, 0, 0);
        ellipse(500, 500, 100, 100);
        if (val != null && val.charAt(0) == 'u')
        {
            String startingval = val.substring(2, val.length() - 2);
            String[] separatedvals = split(startingval, ", ");
            //println(separatedvals);
            int i = 0;
            for (String s: separatedvals)
            {
                int dist = PApplet.parseInt(split(s, ":")[0]);
                int angle = PApplet.parseInt(split(s, ":")[1]);
                //angle = i * 360 / 5;
                println(s);
                println(angle);

                fill(0, 0, i * 255 / 5);

                ellipse(scale * dist * cos(radians(angle)) + 500,
                        scale * dist * sin(radians(angle)) + 500, 25, 25);
                i += 1;
                
            }

        }
    }
}
  public void settings() {  size(1000, 1000); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "processing" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
