/*char pattern[26][7]={
  "*_", //A,a
  "_***",//B,b
  "_*_*",//C,c
  "_**", //D,d
  "*", //E,e
  "**_*",//F,f
  "__*", //G,g
  "****",//H,h
  "**", //I,i
  "*___",//J,j
  "_*_", //K,k
  "*_**",//L,l
  "__", //M,m
  "_*", //N,n
  "___", //O,o
  "*__*",//P,p
  "__*_",//Q,q
  "*_*", //R,r
  "***", //S,s
  "_", //T,t
  "**_", //U,u
  "***_",//V,v
  "*__", //W,w
  "_**_",//X,x
  "_*__",//Y,y
  "__**" //Z,z
};

const int piezoPin = 9;
char c;
int index1=0,index2=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
  Serial.println("Ready!");
  pinMode(piezoPin,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    c=Serial.read();
    index1=-1;
    //between A and Z
    if(c>='A'&&c<='Z')
    {
      index1=c-65;
    }
    else
    {
      //between a and z
      if(c>='a'&&c<='z')
      {
        index1=c-97;
      }

      //space
      if(c==' ')
      {
        Serial.print(" ");
        index1=26;
      }

      //new line (Enter)
      if(c=='\n')
      {
        Serial.println();
        index1=26;
      }

      // Not a char
      if(!isAscii(c))
      {
        index1=26;
      }

    }

    if(index1>=0&&index1<=25)//if it’s a valid character
    {
      for(index2=0;index2<6;index2++)
      {
        //dit
        if(pattern[index1][index2]=='*')
        {
          dit();
        }
        
        //dah
        if(pattern[index1][index2]=='_')
        {
          dah();
        }

        //null [Each string must end with a null -check ASCII table-]
        if(pattern[index1][index2]=='\0')
        {
          index2=6;
        }

        delay(300);//space between Dit and Dah
      }
    delay(100);//space between Letters
    }
  }
}

void dit()
{
  Serial.print("*");
}
void dah()
{
  Serial.print("_");
}*/

char pattern[26][7]={
  "*_", //A,a
  "_***",//B,b
  "_*_*",//C,c
  "_**", //D,d
  "*", //E,e
  "**_*",//F,f
  "__*", //G,g
  "****",//H,h
  "**", //I,i
  "*___",//J,j
  "_*_", //K,k
  "*_**",//L,l
  "__", //M,m
  "_*", //N,n
  "___", //O,o
  "*__*",//P,p
  "__*_",//Q,q
  "*_*", //R,r
  "***", //S,s
  "_", //T,t
  "**_", //U,u
  "***_",//V,v
  "*__", //W,w
  "_**_",//X,x
  "_*__",//Y,y
  "__**" //Z,z
};

const int piezoPin = 9;
char c;
int index1=0,index2=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
  Serial.println("Ready!");
  pinMode(piezoPin,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    c=Serial.read();
    index1=-1;
    //between A and Z
    if(c>='A'&&c<='Z')
    {
      index1=c-65;
    }
    else
    {
      //between a and z
      if(c>='a'&&c<='z')
      {
        index1=c-97;
      }

      //space
      if(c==' ')
      {
        Serial.print(" ");
        index1=26;
      }

      //new line (Enter)
      if(c=='\n')
      {
        Serial.println();
        index1=26;
      }

      // Not a char
      if(!isAscii(c))
      {
        index1=26;
      }

    }

    if(index1>=0&&index1<=25)//if it’s a valid character
    {
      for(index2=0;index2<6;index2++)
      {
        //dit
        if(pattern[index1][index2]=='*')
        {
          dit();
        }
        
        //dah
        if(pattern[index1][index2]=='_')
        {
          dah();
        }

        //null [Each string must end with a null -check ASCII table-]
        if(pattern[index1][index2]=='\0')
        {
          index2=6;
        }

        delay(300);//space between Dit and Dah
      }
    delay(100);//space between Letters
    }
  }
}

void dit()
{
  Serial.print("*");
  tone(piezoPin, 220, 40);
}
void dah()
{
  Serial.print("_");
  tone(piezoPin, 220, 200);
}





