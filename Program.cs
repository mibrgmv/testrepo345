using System;

namespace TrigonometricCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Trigonometric Calculator");
            Console.WriteLine("-----------------------");
            Console.WriteLine("1. Calculate in degrees");
            Console.WriteLine("2. Calculate in radians");
            Console.Write("Choose an option: ");
            string option = Console.ReadLine();
            
            if (option == "1")
            {
                Console.Write("Enter angle in degrees: ");
                string angleInDegrees = Console.ReadLine();
                if (double.TryParse(angleInDegrees, out double degrees))
                {
                    double radians = degrees * Math.PI / 180;
                    CalculateTrigonometricFunctions(radians);
                }
                else
                {
                    Console.WriteLine("Invalid input. Please enter a numeric value.");
                }
            }
            else if (option == "2")
            {
                Console.Write("Enter angle in radians: ");
                string angleInRadians = Console.ReadLine();
                if (double.TryParse(angleInRadians, out double radians))
                {
                    CalculateTrigonometricFunctions(radians);
                }
                else
                {
                    Console.WriteLine("Invalid input. Please enter a numeric value.");
                }
            }
            else
            {
                Console.WriteLine("Invalid option. Please choose a valid option.");
            }
        }
        
        static void CalculateTrigonometricFunctions(double angleInRadians)
        {
            try
            {
                double sine = Math.Sin(angleInRadians);
                double cosine = Math.Cos(angleInRadians);
                double tangent = Math.Tan(angleInRadians);
                double cotangent = 1 / tangent;
                
                Console.WriteLine("Sine: " + sine);
                Console.WriteLine("Cosine: " + cosine);
                Console.WriteLine("Tangent: " + tangent);
                Console.WriteLine("Cotangent: " + cotangent);
            }
            catch (DivideByZeroException)
            {
                Console.WriteLine("Cannot calculate cotangent. Tangent is zero.");
            }
        }
    }
}