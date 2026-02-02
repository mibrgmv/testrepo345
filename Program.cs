using System;

namespace TrigonometricCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Trigonometric Calculator");
            Console.WriteLine("1. Calculate in degrees");
            Console.WriteLine("2. Calculate in radians");
            Console.WriteLine("3. Exit");
            Console.Write("Choose an option: ");
            string option = Console.ReadLine();

            switch (option)
            {
                case "1":
                    CalculateInDegrees();
                    break;
                case "2":
                    CalculateInRadians();
                    break;
                case "3":
                    Environment.Exit(0);
                    break;
                default:
                    Console.WriteLine("Invalid option. Please choose a valid option.");
                    Main(args);
                    break;
            }
        }

        static void CalculateInDegrees()
        {
            Console.Write("Enter angle in degrees: ");
            string angleInput = Console.ReadLine();
            if (double.TryParse(angleInput, out double angleInDegrees))
            {
                double angleInRadians = angleInDegrees * Math.PI / 180;
                CalculateTrigonometricFunctions(angleInRadians);
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter a valid number.");
                CalculateInDegrees();
            }
        }

        static void CalculateInRadians()
        {
            Console.Write("Enter angle in radians: ");
            string angleInput = Console.ReadLine();
            if (double.TryParse(angleInput, out double angleInRadians))
            {
                CalculateTrigonometricFunctions(angleInRadians);
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter a valid number.");
                CalculateInRadians();
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

                Console.WriteLine($"Sine: {sine}");
                Console.WriteLine($"Cosine: {cosine}");
                Console.WriteLine($"Tangent: {tangent}");
                Console.WriteLine($"Cotangent: {cotangent}");
            }
            catch (DivideByZeroException)
            {
                Console.WriteLine("Cannot calculate cotangent. Tangent is zero.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An error occurred: {ex.Message}");
            }
        }
    }
}