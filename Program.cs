using System;

namespace TrigonometricCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Trigonometric Calculator");
            Console.WriteLine("1. Calculate sin, cos, tg, ctg in degrees");
            Console.WriteLine("2. Calculate sin, cos, tg, ctg in radians");
            Console.Write("Enter your choice (1/2): ");
            string choice = Console.ReadLine();
            
            if (choice == "1")
            {
                Console.Write("Enter angle in degrees: ");
                string angleDegrees = Console.ReadLine();
                if (double.TryParse(angleDegrees, out double angleDeg)
                {
                    double angleRad = angleDeg * Math.PI / 180;
                    CalculateTrigonometricFunctions(angleRad);
                }
                else
                {
                    Console.WriteLine("Invalid input. Please enter a valid angle.");
                }
            }
            else if (choice == "2")
            {
                Console.Write("Enter angle in radians: ");
                string angleRadians = Console.ReadLine();
                if (double.TryParse(angleRadians, out double angleRad)
                {
                    CalculateTrigonometricFunctions(angleRad);
                }
                else
                {
                    Console.WriteLine("Invalid input. Please enter a valid angle.");
                }
            }
            else
            {
                Console.WriteLine("Invalid choice. Please enter 1 or 2.");
            }
        }
        
        static void CalculateTrigonometricFunctions(double angle)
        {
            try
            {
                double sin = Math.Sin(angle);
                double cos = Math.Cos(angle);
                double tg = Math.Tan(angle);
                double ctg = 1 / tg;
                
                Console.WriteLine("sin: " + sin);
                Console.WriteLine("cos: " + cos);
                Console.WriteLine("tg: " + tg);
                Console.WriteLine("ctg: " + ctg);
            }
            catch (DivideByZeroException)
            {
                Console.WriteLine("Error: Cannot calculate ctg because tg is zero.");
            }
        }
    }
}