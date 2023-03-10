/**
 * @file lab2/CalculatorRI.java
 * @author Hrishikesh Vaze (PB09)
 * @date 2023-02-14
 *
 */

//Remote Interface : declares the
//		     remote services

public interface CalculatorRI
          extends java.rmi.Remote 
{
    public long add(long a, long b)
        throws java.rmi.RemoteException;

    public long sub(long a, long b)
        throws java.rmi.RemoteException;

    public long mul(long a, long b)
        throws java.rmi.RemoteException;

    public long div(long a, long b)
        throws java.rmi.RemoteException;

    public long square(long a)
        throws java.rmi.RemoteException;
}

