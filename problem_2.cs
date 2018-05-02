using System;

class Globals {
  
  public static int counter = 0;
  public static int sum = 0;
  
}

class MainClass {
  
  public static int Fib (int prev, int next) {
    
    if (Globals.counter >= 4000000){
      return Globals.sum;
    }
    
    Globals.counter = (next + prev);
    
    if (Globals.counter % 2 == 0){
      Globals.sum += Globals.counter;
    }
    
    return Fib(next, Globals.counter);
  }
  
  public static void Main (){
    
    int result = Fib(1, 2);
    result += 2;
    Console.WriteLine(result);
    
  }
  
}
