using System;

namespace TrigonometricCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Trigonometric Calculator");
            Console.WriteLine("------------------------");
            Console.WriteLine("1. Calculate in degrees");
            Console.WriteLine("2. Calculate in radians");
            Console.WriteLine("3. Exit");
            Console.Write("Choose an option: ");
            string option = Console.ReadLine();

            while (option != "3")
            {
                switch (option)
                {
                    case "1":
                        CalculateInDegrees();
                        break;
                    case "2":
                        CalculateInRadians();
                        break;
                    default:
                        Console.WriteLine("Invalid option. Please choose a valid option.");
                        break;
                }

                Console.WriteLine("1. Calculate in degrees");
                Console.WriteLine("2. Calculate in radians");
                Console.WriteLine("3. Exit");
                Console.Write("Choose an option: ");
                option = Console.ReadLine();
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
            }
        }

        static void CalculateTrigonometricFunctions(double angleInRadians)
        {
            try
            {
                double sin = Math.Sin(angleInRadians);
                double cos = Math.Cos(angleInRadians);
                double tg = Math.Tan(angleInRadians);
                double ctg = 1 / tg;

                Console.WriteLine($"Sin: {sin}");
                Console.WriteLine($"Cos: {cos}");
                Console.WriteLine($"Tg: {tg}");
                Console.WriteLine($"Ctg: {ctg}");
            }
            catch (DivideByZeroException)
            {
                Console.WriteLine("Cannot calculate Ctg for this angle.");
            }
        }
    }
}