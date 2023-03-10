/**
 * @file lab2/CalculatorServer.java
 * @author Hrishikesh Vaze (PB09)
 * @date 2023-02-14
 *
 */

//Server Program 

import java.rmi.Naming;

public class CalculatorServer {

  public CalculatorServer() 
  {
    try
    {
      CalculatorRI c = new CalculatorImpl();
      Naming.rebind("rmi://localhost:1099/CalculatorService", c);
    }
    catch (Exception e) 
    {
      System.out.println("Trouble: " + e);
    }
  }

  public static void main(String args[]) 
  {
    new CalculatorServer();
  }
}

