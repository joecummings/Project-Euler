using System;

class MainClass {
  public static void Main () {
    
    int temp = 0;
    for (int i = 0; i < 1000; i++){
      if ((i % 3 == 0) || (i % 5 == 0)){
        temp += i;
      }
    }
    Console.WriteLine(temp);
    
  }
}
